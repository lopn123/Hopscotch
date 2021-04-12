#include "DXUT.h"
#include "SceneManager.h"

SceneManager::SceneManager()
	:nowScene(nullptr), nextScene(nullptr)
{
}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::Update()
{
	if (nextScene)
	{
		if (nowScene)
		{
			nowScene->Release();
		}
		nextScene->Init();
		nowScene = nextScene;
		nextScene = nullptr;
	}
	if (nowScene)
	{
		nowScene->Update();
	}
}

void SceneManager::Render()
{
	if (nowScene)
		nowScene->Render();
}

void SceneManager::Release()
{
	if (nowScene)
		nowScene->Release();

	for (auto iter : scenes)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	scenes.clear();
}

Scene* SceneManager::AddScene(const string& key, Scene* scene)
{
	if(!scene || scenes.find(key) != scenes.end())
		return nullptr;

	scenes.insert(make_pair(key, scene));
	return scene;
}

Scene* SceneManager::ChangeScene(const string& key)
{
	auto find = scenes.find(key);
	if(find == scenes.end())
		return nullptr;

	OBJECT->ClearAllObject();
	nextScene = find->second;
	return nextScene;
}
