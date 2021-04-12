#include "DXUT.h"
#include "ImageManager.h"

void texture::CenterRender(Vector2 pos, float rot, Vector2 size, D3DCOLOR color)
{
	IMAGE->CenterRender(this, pos, rot, size, color);
}

void texture::Release()
{
	SAFE_RELEASE(texturePtr);
}

vecTexture::vecTexture()
{
}

vecTexture::~vecTexture()
{
	for (auto iter : vecTex)
	{
		iter->Release();
		SAFE_DELETE(iter);
	}
	vecTex.clear();
}

void vecTexture::AddImage(texture* image)
{
	vecTex.push_back(image);
}

texture* vecTexture::FindImage(int count)
{
	return vecTex[count];
}

ImageManager::ImageManager()
{
	D3DXCreateSprite(g_device, &sprite);
}

ImageManager::~ImageManager()
{
	Release();
}

void ImageManager::Release()
{
	for (auto iter : images)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	images.clear();
	for (auto iter : vecImages)
	{
		SAFE_DELETE(iter.second);
	}
	vecImages.clear();
	sprite->Release();
}

void ImageManager::Begin()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}

void ImageManager::End()
{
	sprite->End();
}

void ImageManager::LostDevice()
{
	sprite->OnLostDevice();
}

void ImageManager::ResetDevice()
{
	sprite->OnResetDevice();
}

void ImageManager::CenterRender(texture* texturePtr, Vector2 pos, float rot, Vector2 size, D3DCOLOR color)
{
	if (texturePtr)
	{
		D3DXMATRIXA16 mat;
		Vector2 CenterPos = Vector2(texturePtr->info.Width / 2, texturePtr->info.Height / 2);
		pos -= CenterPos;

		D3DXMatrixTransformation2D(&mat, &CenterPos, 0, &size, &CenterPos, rot, &pos);

		sprite->SetTransform(&mat);
		sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}

void ImageManager::drawText(const string& str, Vector2 pos, float size, D3DCOLOR color)
{
	D3DXMATRIX mat;

	D3DXCreateFontA(g_device, size, 0, 10, 1, FALSE, HANGEUL_CHARSET, 0, 0, 0, "Fixedsys", &lpFont);
	D3DXMatrixTranslation(&mat, pos.x, pos.y, 0);

	sprite->SetTransform(&mat);
	lpFont->DrawTextA(sprite, str.c_str(), str.size(), 0, DT_NOCLIP, color);
	SAFE_RELEASE(lpFont);
}

texture* ImageManager::AddImage(const string& key, const string& path)
{
	auto find = images.find(key);

	if (find == images.end())
	{
		LPDIRECT3DTEXTURE9 texturePtr;
		D3DXIMAGE_INFO info;

		char ch[256];
		sprintf(ch, "./Resource/Image/%s.png", path.c_str());

		if (D3DXCreateTextureFromFileExA(g_device, ch, -2, -2, 0, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, -1, -1, 0, &info, nullptr, &texturePtr) == S_OK)
		{
			texture* text = new texture(texturePtr, info);
			images.insert(make_pair(key, text));
			return text;
		}
		return nullptr;
	}
	return find->second;
}

texture* ImageManager::FindImage(const string& key)
{
	auto find = images.find(key);
	if(find == images.end()) return nullptr;
	return find->second;
}

vecTexture* ImageManager::AddVecImage(const string& key, const string& path, int max)
{
	auto find = vecImages.find(key);

	if (find == vecImages.end())
	{
		vecTexture* vec = new vecTexture();

		for (int i = 1; i <= max; i++)
		{
			LPDIRECT3DTEXTURE9 texturePtr;
			D3DXIMAGE_INFO info;

			char ch[256];
			sprintf(ch, "./Resource/Image/%s/(%d).png", path.c_str(), i);

			if (D3DXCreateTextureFromFileExA(g_device, ch, -2, -2, 0, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, -1, -1, 0, &info, nullptr, &texturePtr) == S_OK)
			{
				texture* text = new texture(texturePtr, info);
				vec->AddImage(text);
			}
		}
		vecImages.insert(make_pair(key, vec));
		return vec;
		
	}
	return find->second;
}

vecTexture* ImageManager::FindVecImage(const string& key)
{
	return vecImages[key];
}
