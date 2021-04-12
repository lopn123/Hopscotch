#include "DXUT.h"
#include "Player.h"
#include "AfterImage.h"
#include "PlayerDeadUi.h"


void Player::Init()
{
	OBJECT->player = this;

	PInit();

	image = IMAGE->FindImage("Player");

	timer = new CDXUTTimer;
	damagedTimer = new CDXUTTimer;
	moveTimer = new CDXUTTimer;
}

void Player::Update()
{
	if (hp <= 0)
	{
		OBJECT->AddObject("D", new PlayerDeadUi, { WINSIZEX / 2, WINSIZEY / 2 }, UI);
	}
	else
	{
		if (cam)
		{
			if (CAMERA->camPos.x > vPos.x)
				CAMERA->MoveCam({ -10, 0 });
			else if (CAMERA->camPos.y > vPos.y)
			{
				CAMERA->MoveCam({ 0, -10 });
				CAMERA->viewSize -= {5, 5};
			}
			else
			{
				if (CAMERA->viewSize.x < WINSIZEX)
					CAMERA->viewSize += Vector2(10, 10);
				else
				{
					CAMERA->viewSize = { WINSIZEX, WINSIZEY };
					cam = false;
				}
			}
		}
		else
		{
			if (WORLD->enemyNum > 0 || round(SCENE->st->filledPercent >= 80))
			{
				CAMERA->SetCam(vPos);
				Move();
				OutCheck();
			}

			if (invincible && timer->GetTime() >= 3)
			{
				invincible = false;
				color = D3DCOLOR_XRGB(255, 255, 255);
				timer->Reset();
				timer->Stop();
			}
			if (speedUp && timer->GetTime() >= 4)
			{
				speedUp = false;
				speed -= 4;
				timer->Reset();
				timer->Stop();
			}
			if (speedUp)
			{
				OBJECT->AddObject("AfterImage", new AfterImage, vPos, EFFECT);
			}
			Cheat();
		}
	}

	
}

void Player::Render()
{
	image->CenterRender(vPos, D3DXToRadian(rot), { 1,1 }, color);
}

void Player::Release()
{
	SAFE_DELETE(timer);
	SAFE_DELETE(damagedTimer);
	SAFE_DELETE(moveTimer);
	OBJECT->player = nullptr;
}

void Player::GetItem(Object* obj)
{
	if (obj->m_key == "SpeedItem")
	{
		speedUp = true;
		speed += 4;

		if (invincible)
		{
			invincible = false;
			color = D3DCOLOR_XRGB(255, 255, 255);
			timer->Reset();
		}
		else
			timer->Start();
	}
	else if (obj->m_key == "InvincibleItem")
	{
		invincible = true;
		color = D3DCOLOR_XRGB(32, 166, 72);

		if (speedUp)
		{
			speedUp = false;
			speed -= 4;
			timer->Reset();
		}
		else
			timer->Start();
	}
	else if (obj->m_key == "HpItem")
	{
		if (hp == maxHp)
			WORLD->score += 100;
		else
			hp++;

		if (!timer->IsStopped())
		{
			timer->Reset();
			timer->Stop();

			if (speedUp)
			{
				speedUp = false;
				speed -= 4;
			}
			else if (invincible)
			{
				invincible = false;
				color = D3DCOLOR_XRGB(255, 255, 255);
			}
		}
	}
}

void Player::Move()
{
	if (DXUTIsKeyDown(VK_LEFT))
	{
		rot = 270;
		if (vPos.x - speed < 0)
		{
			move = speed - abs(vPos.x - speed);
		}
		else
		{
			move = speed;
		}

		if (DXUTIsKeyDown(VK_SPACE))
		{
			for (int i = 1; i <= move; i++)
			{
				if (WORLD->map[(int)vPos.y][(int)vPos.x - i] == 0)
				{
					WORLD->map[(int)vPos.y][(int)vPos.x - i] = 5;
					SCENE->st->Fill(vPos.x - i, vPos.y, 255, 255, 255, 255);
				}
			}
			if (!isOut) prevPos = vPos;
			canMoveVal--;
			vPos.x -= move;
		}
		else if(WORLD->map[(int)vPos.y][(int)vPos.x - move] != 0 && WORLD->map[(int)vPos.y][(int)vPos.x - move] != 6)
		{
			vPos.x -= move;
		}
	}
	else if (DXUTIsKeyDown(VK_RIGHT))
	{
		rot = 90;
		if (vPos.x + speed >= WINSIZEX)
		{
			move = speed - abs(vPos.x - (WINSIZEX - 1) + speed);
		}
		else
		{
			move = speed;
		}

		if (DXUTIsKeyDown(VK_SPACE))
		{
			for (int i = 1; i <= move; i++)
			{
				if (WORLD->map[(int)vPos.y][(int)vPos.x + i] == 0)
				{
					WORLD->map[(int)vPos.y][(int)vPos.x + i] = 5;
					SCENE->st->Fill(vPos.x + i, vPos.y, 255, 255, 255, 255);
				}
			}
			if (!isOut) prevPos = vPos;
			canMoveVal--;
			vPos.x += move;
		}
		else if (WORLD->map[(int)vPos.y][(int)vPos.x + move] != 0 && WORLD->map[(int)vPos.y][(int)vPos.x + move] != 6)
		{
			vPos.x += move;
		}
	}
	else if (DXUTIsKeyDown(VK_UP))
	{
		rot = 0;
		if (vPos.y - speed < 0)
		{
			move = speed - abs(vPos.y - speed);
		}
		else
		{
			move = speed;
		}

		if (DXUTIsKeyDown(VK_SPACE))
		{
			for (int i = 1; i <= move; i++)
			{
				if (WORLD->map[(int)vPos.y - i][(int)vPos.x] == 0)
				{
					WORLD->map[(int)vPos.y - i][(int)vPos.x] = 5;
					SCENE->st->Fill(vPos.x, vPos.y - i, 255, 255, 255, 255);
				}
			}
			if (!isOut) prevPos = vPos;
			canMoveVal--;
			vPos.y -= move;
		}
		else if (WORLD->map[(int)vPos.y - move][(int)vPos.x] != 0 && WORLD->map[(int)vPos.y - move][(int)vPos.x] != 6)
		{
			vPos.y -= move;
		}
	}
	else if (DXUTIsKeyDown(VK_DOWN))
	{
		rot = 180;
		if (vPos.y + speed >= WINSIZEY)
		{
			move = speed - abs(vPos.y - (WINSIZEY - 1) + speed);
		}
		else
		{
			move = speed;
		}

		if (DXUTIsKeyDown(VK_SPACE))
		{
			for (int i = 1; i <= move; i++)
			{
				if (WORLD->map[(int)vPos.y + i][(int)vPos.x] == 0)
				{
					WORLD->map[(int)vPos.y + i][(int)vPos.x] = 5;
					SCENE->st->Fill(vPos.x, vPos.y + i, 255, 255, 255, 255);
				}
			}
			if (!isOut) prevPos = vPos;
			canMoveVal--;
			vPos.y += move;
		}
		else if (WORLD->map[(int)vPos.y + move][(int)vPos.x] != 0 && WORLD->map[(int)vPos.y + move][(int)vPos.x] != 6)
		{
			vPos.y += move;
		}
	}
}

void Player::OutCheck()
{
	if (!isOut)
	{
		/*if (damagedTimer->IsStopped()) damagedTimer->Start();

		if (damagedTimer->GetTime() >= 5)
		{
			hp--;
			damagedTimer->Reset();
		}*/
		if (moveTimer->GetTime() >= 1)
		{
			if (canMoveVal < maxMove) canMoveVal += 2;
			moveTimer->Reset();
		}

		if (WORLD->map[(int)vPos.y][(int)vPos.x] == 5)
		{
			speed -= 6;
			damagedTimer->Reset();
			damagedTimer->Stop();
			moveTimer->Reset();
			isOut = true;
		}
	}
	else if (isOut)
	{
		if (canMoveVal <= 0)
		{
			if (moveTimer->GetTime() >= 1)
			{
				if (canMoveVal < maxMove) canMoveVal += 1;
				moveTimer->Reset();
			}
		}

		if (WORLD->map[(int)vPos.y][(int)vPos.x] != 5)
		{
			speed += 6;
			isOut = false;
			SCENE->st->PlayerInBorder();
		}
	}
}

void Player::Cheat()
{
	if (DXUTWasKeyPressed(VK_F1))
	{
		if (invincible) {
			color = D3DCOLOR_XRGB(255, 255, 255);
			invincible = false;
		}
		else
		{
			color = D3DCOLOR_XRGB(32, 166, 72);
			invincible = true;
		}
	}
	else if (DXUTWasKeyPressed(VK_F2))
	{

	}
	else if (DXUTWasKeyPressed(VK_F3))
	{
		maxHp += 2;
		hp += 2;
	}
	else if (DXUTWasKeyPressed(VK_F4))
	{
		hp -= 2;
	}
	else if (DXUTWasKeyPressed(VK_F10))
	{
		isDestroy = true;
		SCENE->ChangeScene("Title");
	}
}
