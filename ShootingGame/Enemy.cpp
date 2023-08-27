#include "DxLib.h"
#include "Enemy.h"

// コンストラクタ
Enemy::Enemy()
{
	speed = 5.0f;

	location.x = 100.0f;
	location.y = 200.0f;
	radius = 40.0f;

	hp = 3;
	point = 10;
	weapon = new NwaySpawner();
}

// デストラクタ
Enemy::~Enemy()
{

}

// 更新処理
void Enemy::Update(GameMainScene* gamemain)
{
	// 移動処理

}

// 描画処理
void Enemy::Draw() const
{
	DrawCircle((int)location.x, (int)location.y, (int)radius, 0x00ffff, TRUE);
}

// ダメージ処理
void Enemy::Hit(int damage)
{
	hp -= damage;

	if (hp <= 0)
	{
		hp = 0;
	}
}