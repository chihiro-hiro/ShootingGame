#include "DxLib.h"
#include "BulletsSpawner.h"

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

void BulletsSpawner::Shoot()
{

}