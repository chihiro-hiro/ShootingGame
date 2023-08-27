#include "DxLib.h"
#include "common.h"
#include "InputControl.h"
#include "Bullet.h"


// コンストラクタ
Bullet::Bullet(float x, float y, bool is_enemy)
{
	location.x = x;
	location.y = y;
	//location.x = 200.0f;
	//location.y = 200.0f;
	radius = 15.0f;

	damage = 1;					// ダメージ量
	speed = 2.0f;				// 速度
	angle = 0.0f;				// 角度
	acceleration = 3.0f;		// 速度の変化量
	angulVelocity = 3.0f;		// 角度の変化量
	enemy = is_enemy;
	color = 0xff0000;
}

// デストラクタ
Bullet::~Bullet()
{

}

// 更新処理
void Bullet::Update()
{
	if (enemy == TRUE)
	{
		location.y += speed;
	}
	else
	{
		location.y -= speed;
		color = 0x00ffff;
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

bool Bullet::CheckDraw()
{
	// 画面外に行くと消す
	if (location.y <= -radius || location.y >= SCREEN_HEIGHT - radius)
	{
		return true;
	}

	return false;
}
