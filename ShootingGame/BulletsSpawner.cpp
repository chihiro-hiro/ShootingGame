#include "DxLib.h"
#include "BulletsSpawner.h"
#include "GameMainScene.h"

// コンストラクタ
BulletsSpawner::BulletsSpawner()
{
	speed = 1.0f;				// 速度
	angle = 0.0f;				// 角度
	acceleration = 3.0f;		// 速度の変化量
	angulVelocity = 3.0f;		// 角度の変化量
}

// デストラクタ
BulletsSpawner::~BulletsSpawner()
{

}

// 引数にゲームメインシーンのポインタ
void BulletsSpawner::Shoot(GameMainScene* gamemain, float x, float y, bool is_enemy)
{
	gamemain->SpawnBullet(x, y, is_enemy);
}