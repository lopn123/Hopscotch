#pragma once
#include "singleton.h"

struct texture
{
    LPDIRECT3DTEXTURE9 texturePtr;
    D3DXIMAGE_INFO info;

    texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
        :texturePtr(texturePtr), info(info)
    {

    }

    void CenterRender(Vector2 pos, float rot = 0, Vector2 size = { 1,1 }, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
    void Release();
};

struct vecTexture
{
    vector<texture*> vecTex;

public:
    vecTexture();
    ~vecTexture();

    void AddImage(texture* image);
    texture* FindImage(int count = 0);
};

class ImageManager :
    public singleton< ImageManager>
{
private:
    LPD3DXSPRITE sprite;
    map<string, texture*> images;
    map<string, vecTexture*> vecImages;
    LPD3DXFONT lpFont;

    void Release();
public:
    ImageManager();
    virtual ~ImageManager();

    void Begin();
    void End();
    void LostDevice();
    void ResetDevice();

    void CenterRender(texture* texturePtr, Vector2 pos, float rot = 0, Vector2 size = { 1,1 }, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
    void drawText(const string& str, Vector2 pos, float size = 50, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));

    texture* AddImage(const string& key, const string& path);
    texture* FindImage(const string& key);
    vecTexture* AddVecImage(const string& key, const string& path, int max);
    vecTexture* FindVecImage(const string& key);
};

#define IMAGE ImageManager::GetInstance()