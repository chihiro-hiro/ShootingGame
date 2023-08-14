#include "DxLib.h"
#include "InputControl.h"
#include "Player.h"

// コンストラクタ
Player::Player()
{
	score = 0;
	weapon = new BulletsSpawner;
}

// デストラクタ
Player::~Player()
{
	delete weapon;
}

// 更新処理
void Player::Update()
{
	// ボタンが押されたら移動

}

// 描画処理
void Player::Draw() const
{
	DrawCircle(100, 100, 20, 0xffffff, TRUE);
}

// ダメージ処理
void Player::Hit()
{

}