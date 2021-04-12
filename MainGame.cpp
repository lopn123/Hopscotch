#include "DXUT.h"
#include "MainGame.h"
#include "Title.h"
#include "Stage.h"

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}

void MainGame::Init()
{
	ShowCursor(true);
	srand(time(NULL));

	CAMERA->Reset();
	AddImages();

	SCENE->AddScene("Title", new Title);
	SCENE->AddScene("Stage", new Stage);
	SCENE->ChangeScene("Title");
}

void MainGame::Update()
{
	OBJECT->Update();
	SCENE->Update();
	CAMERA->Update();
}

void MainGame::Render()
{
	CAMERA->SetTransform();

	IMAGE->Begin();

	SCENE->Render();
	OBJECT->Render();

	IMAGE->End();
}

void MainGame::Release()
{
	CameraManager::ReleaseInstance();
	ImageManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	SceneManager::ReleaseInstance();
}

void MainGame::LostDevice()
{
	IMAGE->LostDevice();
}

void MainGame::ResetDevice()
{
	IMAGE->ResetDevice();
}

void MainGame::AddImages()
{
	IMAGE->AddImage("Player", "Player/Player");

	IMAGE->AddImage("SpeedEnemy", "Enemy/SpeedEnemy");
	IMAGE->AddImage("TpEnemy", "Enemy/TpEnemy");
	IMAGE->AddImage("BigEnemy", "Enemy/BigEnemy");
	IMAGE->AddImage("FlashEnemy", "Enemy/FlashEnemy");
	IMAGE->AddImage("Stage1Boss", "Enemy/Stage1Boss");
	IMAGE->AddImage("Stage2Boss", "Enemy/Stage2Boss");

	IMAGE->AddImage("Bullet", "Bullet/Bullet");
	IMAGE->AddImage("ExplosionBullet", "Bullet/ExplosionBullet");

	IMAGE->AddImage("HpItem", "Item/HpItem");
	IMAGE->AddImage("InvinItem", "Item/InvinItem");
	IMAGE->AddImage("SpeedItem", "Item/SpeedItem");

	IMAGE->AddImage("PlayerHit", "Effect/PlayerHit");
	IMAGE->AddVecImage("EnemyDeadEffect", "Effect/EnemyDeadEffect", 10);
	IMAGE->AddVecImage("TpEffect", "Effect/TpEffect", 5);
	IMAGE->AddVecImage("Stage1Explosion", "Effect/Stage1Explosion", 23);
	IMAGE->AddVecImage("Stage1BossExplosion", "Effect/Stage1BossExplosion", 24);
	IMAGE->AddVecImage("Stage2BossExplosion", "Effect/Stage2BossExplosion/1", 32);
	IMAGE->AddVecImage("Stage2BossExplosion2", "Effect/Stage2BossExplosion/2", 32);
	IMAGE->AddVecImage("HpItemGetEffect", "Effect/HpItemGetEffect", 24);
	IMAGE->AddVecImage("InvinItemGetEffect", "Effect/InvinItemGetEffect", 24);
	IMAGE->AddVecImage("SpeedItemGetEffect", "Effect/SpeedItemGetEffect", 24);
	IMAGE->AddVecImage("BulletExplosionEffect", "Effect/BulletExplosionEffect", 24);
	IMAGE->AddVecImage("FlashEffect", "Effect/FlashEffect", 30);

	IMAGE->AddImage("GameStart", "Ui/GameStart");
	IMAGE->AddImage("GameStartOn", "Ui/GameStartOn");
	IMAGE->AddImage("HowTo", "Ui/HowTo");
	IMAGE->AddImage("HowToOn", "Ui/HowToOn");
	IMAGE->AddImage("Exit", "Ui/Exit");
	IMAGE->AddImage("ExitOn", "Ui/ExitOn");
	IMAGE->AddImage("BarBackground", "Ui/BarBackground");
	IMAGE->AddImage("HpBar", "Ui/HpBar");
	IMAGE->AddImage("ScoreBoard", "Ui/ScoreBoard");
	IMAGE->AddImage("Guide", "Ui/Guide");
	IMAGE->AddImage("Clear", "Ui/Clear");
	IMAGE->AddImage("GameOver", "Ui/GameOver");

	IMAGE->AddImage("stage", "Scene/stage");
	IMAGE->AddImage("stage2", "Scene/stage2");
	IMAGE->AddImage("black", "Scene/black");
	IMAGE->AddImage("bigBlack", "Scene/bigBlack");
	IMAGE->AddImage("Title", "Scene/Title");
}
