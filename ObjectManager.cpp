#include "DXUT.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::Update()
{
	for (int i = 1; i < END; i++)
	{
		for (auto iter = m_objList[i].begin(); iter != m_objList[i].end();)
		{
			if ((*iter)->CheckDestroy())
			{
				(*iter)->Release();
				SAFE_DELETE(*iter);
				iter = m_objList[i].erase(iter);
			}
			else if (isMapOut(*iter))
			{
				(*iter)->Release();
				SAFE_DELETE(*iter);
				iter = m_objList[i].erase(iter);
			}
			else
			{
				(*iter)->Update();
				iter++;
			}
		}
	}
}

void ObjectManager::Render()
{
	for (int i = 1; i < END; i++)
	{
		for (auto iter : m_objList[i])
		{
			iter->Render();
		}
	}
}

void ObjectManager::Release()
{
	for (int i = 1; i < END; i++)
	{
		for (auto iter = m_objList[i].begin(); iter != m_objList[i].end();)
		{
			if (*iter == nullptr)
				iter++;
			(*iter)->Release();
			SAFE_DELETE(*iter);
			iter++;
		}
	}
}

Object* ObjectManager::AddObject(const string& key, Object* _obj, Vector2 pos, Tag tag)
{
	_obj->Init();
	_obj->vPos = pos;
	_obj->m_key = key;
	_obj->m_tag = tag;
	m_objList[tag].emplace_back(_obj);
	return _obj;
}

bool ObjectManager::isMapOut(Object* _obj)
{
	if(_obj->m_tag == UI)
		return false;

	return (_obj->vPos.x < 0
		|| _obj->vPos.x > WINSIZEX
		|| _obj->vPos.y < 0
		|| _obj->vPos.y > WINSIZEY);
}

void ObjectManager::ClearAllObject()
{
	for (int i = 1; i < END; i++)
	{
		for (auto iter : m_objList[i])
		{
			if (iter->m_tag == PLAYER)
				iter++;
			iter->isDestroy = true;
		}
	}
}
