#include "DxLib.h"
#include "InputControl.h"
#include "Bullet.h"

// コンストラクタ
Bullet::Bullet()
{
	damage = 1;					// ダメージ量
	speed = 1.0f;				// 速度
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
	// ボタンが押されたら発射
}

// 描画処理
void Bullet::Draw() const
{
	DrawCircle(200, 100, 10, 0xff0000, TRUE);
}

// ダメージ処理
void Bullet::GetDamage()
{

}