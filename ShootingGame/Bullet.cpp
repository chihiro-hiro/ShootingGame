#include "DxLib.h"
#include "InputControl.h"
#include "Bullet.h"

// コンストラクタ
Bullet::Bullet()
{
	location.x = 200.0f;
	location.y = 200.0f;
	radius = 10.0f;

	damage = 1;					// ダメージ量
	speed = 2.0f;				// 速度
	angle = 0.0f;				// 角度
	acceleration = 3.0f;		// 速度の変化量
	angulVelocity = 3.0f;		// 角度の変化量
}

// デストラクタ
Bullet::~Bullet()
{

}

// 更新処理
void Bullet::Update()
{
	// 移動処理
	//if (location.y > 10)
	//{
	//	// 上に移動する
	//	location.y -= speed;
	//}
}

// 描画処理
void Bullet::Draw() const
{
	DrawCircle((int)location.x, (int)location.y, (int)radius, 0xff0000, TRUE);
}

// ダメージの値を取得
int Bullet::GetDamage()
{
	return damage;
}