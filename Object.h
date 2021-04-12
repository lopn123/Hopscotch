#pragma once

enum ObjectTag : char
{
	NONE,
	PLAYER,
	EBULLET,
	ENEMY,
	ITEM,
	EFFECT,
	UI,
	END
}typedef Tag;

class Object
{
public:
	Object();
	virtual ~Object();

	Vector2 vPos;
	texture* image = nullptr;
	string m_key;
	Tag m_tag;
	bool isDestroy = false;

	bool CheckDestroy() { return isDestroy; }

	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
};

