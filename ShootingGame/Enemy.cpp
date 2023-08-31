#include "DxLib.h"
#include "common.h"
#include "Enemy.h"

// コンストラクタ
Enemy::Enemy(float x, float y, float set_speed)
{
	speed = set_speed;
	isEnemy = TRUE;

	location.x = x;
	location.y = y;
	radius = 30.0f;

	hp = 3;
	point = 100;
	weapon = new NwaySpawner();
	interval = 0;
	shoudMoveRight = TRUE;
}

// デストラクタ
Enemy::~Enemy()
{

}

// 更新処理
void Enemy::Update(GameMainScene* gamemain)
{
	// 左右移動処理
	if (shoudMoveRight == TRUE)
	{
		location.x += speed;

		if (location.x >= SCREEN_WIDTH - radius)
		{
			location.x = SCREEN_WIDTH - radius;
			shoudMoveRight = FALSE;
		}
	}
	else
	{
		location.x -= speed;

		if (location.x <= radius)
		{
			location.x = radius;
			shoudMoveRight = TRUE;
		}
	}

	// 弾を発射するタイミング
	if (++interval >= 15)
	{
		if (GetRand(100) >= 80)
		{
			weapon->Shoot(gamemain, location.x, location.y, isEnemy);
		}
		interval = 0;
	}

}

// 描画処理
void Enemy::Draw() const
{	
	DrawCircle((int)location.x, (int)location.y, (int)radius, 0xff0000, TRUE);
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

int Enemy::GetHp()
{
	return hp;
}

int Enemy::GetPoint()
{
	return point;
}
