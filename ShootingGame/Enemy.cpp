#include "DxLib.h"
#include "Enemy.h"

// コンストラクタ
Enemy::Enemy()
{
	hp = 3;
	point = 10;
	weapon = new NwaySpawner();
}

// デストラクタ
Enemy::~Enemy()
{

}

// 更新処理
void Enemy::Update()
{
	// 移動処理

}

// 描画処理
void Enemy::Draw() const
{
	DrawCircle(100, 200, 20, 0x00ffff, TRUE);
}

// ダメージ処理
void Enemy::Hit()
{

}