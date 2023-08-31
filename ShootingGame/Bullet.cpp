#include "DxLib.h"
#include "common.h"
#include "InputControl.h"
#include "Bullet.h"

// コンストラクタ
Bullet::Bullet(float x, float y, bool is_enemy)
{
	location.x = x;
	location.y = y;
	radius = 10.0f;

	damage = 1;					// ダメージ量
	speed = 10.0f;				// 速度
	angle = 0.0f;				// 角度
	acceleration = 3.0f;		// 速度の変化量
	angulVelocity = 3.0f;		// 角度の変化量
	isEnemy = is_enemy;
	color = 0xffff00;
}

// デストラクタ
Bullet::~Bullet()
{

}

// 更新処理
void Bullet::Update()
{
	if (isEnemy == TRUE)
	{
		location.y += speed;
	}
	else
	{
		location.y -= speed;
		color = 0x0fffff;
	}
}

// 描画処理
void Bullet::Draw() const
{
	DrawCircle((int)location.x, (int)location.y, (int)radius, color, TRUE);
	DrawCircle((int)location.x, (int)location.y, (int)radius, 0xffffff, FALSE);
}

// ダメージの値を取得
int Bullet::GetDamage()
{
	return damage;
}

bool Bullet::CheckDelete()
{
	// 画面外に行くと消す（上下）
	if (location.y <= -radius || location.y >= SCREEN_HEIGHT + radius)
	{
		return true;
	}

	return false;
}

bool Bullet::CheckEnemyBullet()
{
	return isEnemy;
}
