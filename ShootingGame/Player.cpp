#include "DxLib.h"
#include "common.h"
#include "InputControl.h"
#include "Player.h"

// �R���X�g���N�^
Player::Player()
{
	speed = 5.0f;
	isEnemy = FALSE;

	location.x = 640.0f;
	location.y = 550.0f;
	radius = 40.0f;

	score = 0;
	weapon = new BulletsSpawner();
	
	//�f�o�b�O�p
	hp = 100000;
}

// �f�X�g���N�^
Player::~Player()
{
	delete weapon;
}

// �X�V����
void Player::Update(GameMainScene* gamemain)
{
	// ���X�e�B�b�N�ňړ�
	Move();
	
	// A�{�^���ōU��
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		weapon->Shoot(gamemain, location.x, location.y, isEnemy);
	}

}

// �`�揈��
void Player::Draw() const
{
	// �f�o�b�O
#if _DEBUG
	DrawFormatString(20, 20, 0xffffff, "hp = %d", hp);
#endif	//_DEBUG

	DrawCircle((int)location.x, (int)location.y, (int)radius, 0xffffff, TRUE);
}

// �_���[�W����
void Player::Hit(int damage)
{
	//�f�o�b�O�p
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

// �ړ������i���X�e�B�b�N�j
void Player::Move()
{
	// ���E�ړ�
	if (0.4f < InputControl::TipLeftLStick(STICKL_X))
	{
		// �E
		location.x += speed;
	}
	else if (InputControl::TipLeftLStick(STICKL_X) < -0.4f)
	{
		// ��
		location.x -= speed;
	}

	// �㉺�ړ�
	if (0.4f < InputControl::TipLeftLStick(STICKL_Y))
	{	
		// ��
		location.y -= speed;
	}
	else if (InputControl::TipLeftLStick(STICKL_Y) < -0.4f)
	{
		// ��
		location.y += speed;
	}

	// ���E�̈ړ�����
	if (location.x <= radius)
	{
		location.x = radius;
	}
	else if (location.x >= SCREEN_WIDTH - radius)
	{
		location.x = SCREEN_WIDTH - radius;
	}

	// �㉺�̈ړ�����
	if (location.y <= radius)
	{
		location.y = radius;
	}
	else if (location.y >= SCREEN_HEIGHT - radius)
	{
		location.y = SCREEN_HEIGHT - radius;
	}
}