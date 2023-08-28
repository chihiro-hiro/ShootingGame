#include "DxLib.h"
#include "common.h"
#include "InputControl.h"
#include "Player.h"

// コンストラクタ
Player::Player()
{
	speed = 5.0f;
	isEnemy = FALSE;

	location.x = 640.0f;
	location.y = 550.0f;
	radius = 40.0f;

	score = 0;
	weapon = new BulletsSpawner();
	
	//デバッグ用
	hp = 100000;
}

// デストラクタ
Player::~Player()
{
	delete weapon;
}

// 更新処理
void Player::Update(GameMainScene* gamemain)
{
	// 左スティックで移動
	Move();
	
	// Aボタンで攻撃
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		weapon->Shoot(gamemain, location.x, location.y, isEnemy);
	}

}

// 描画処理
void Player::Draw() const
{
	// デバッグ
#if _DEBUG
	DrawFormatString(20, 20, 0xffffff, "hp = %d", hp);
#endif	//_DEBUG

	DrawCircle((int)location.x, (int)location.y, (int)radius, 0xffffff, TRUE);
}

// ダメージ処理
void Player::Hit(int damage)
{
	//デバッグ用
	hp -= damage;
}

int Player::GetScore()const
{
	return score;
}

void Player::SetScore(int set_score)
{
	score += set_score;
}

// 移動処理（左スティック）
void Player::Move()
{
	// 左右移動
	if (0.4f < InputControl::TipLeftLStick(STICKL_X))
	{
		// 右
		location.x += speed;
	}
	else if (InputControl::TipLeftLStick(STICKL_X) < -0.4f)
	{
		// 左
		location.x -= speed;
	}

	// 上下移動
	if (0.4f < InputControl::TipLeftLStick(STICKL_Y))
	{	
		// 上
		location.y -= speed;
	}
	else if (InputControl::TipLeftLStick(STICKL_Y) < -0.4f)
	{
		// 下
		location.y += speed;
	}

	// 左右の移動制御
	if (location.x <= radius)
	{
		location.x = radius;
	}
	else if (location.x >= SCREEN_WIDTH - radius)
	{
		location.x = SCREEN_WIDTH - radius;
	}

	// 上下の移動制御
	if (location.y <= radius)
	{
		location.y = radius;
	}
	else if (location.y >= SCREEN_HEIGHT - radius)
	{
		location.y = SCREEN_HEIGHT - radius;
	}
}