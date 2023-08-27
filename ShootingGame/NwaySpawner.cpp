#include "DxLib.h"
#include "NwaySpawner.h"
#include "GameMainScene.h"

// コンストラクタ
NwaySpawner::NwaySpawner()
{
	speed = 1.0f;				// 速度
	angle = 0.0f;				// 角度
	acceleration = 3.0f;		// 速度の変化量
	angulVelocity = 3.0f;		// 角度の変化量

	numBullets = 10;
	baseAngle = 0.0f;
	angleDiff = 0.0f;
}

// デストラクタ
NwaySpawner::~NwaySpawner()
{

}

// ダメージ処理
void NwaySpawner::Shoot(GameMainScene* gamemain, float x, float y, bool is_enemy)
{
	gamemain->SpawnBullet(x, y, is_enemy);
}