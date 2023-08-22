#include "DxLib.h"
#include "common.h"
#include "InputControl.h"
#include "Player.h"

// �R���X�g���N�^
Player::Player()
{
	speed = 5.0f;

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
void Player::Update()
{
	// ���X�e�B�b�N�ňړ�
	Move();

	// �U��
	//if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	//{
	//	weapon->Shoot();
	//}

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

	// ��ʍ��E����͂ݏo���Ȃ��悤�ɂ��鏈��
	if (location.x <= radius)
	{
		location.x = radius;
	}
	else if (location.x >= SCREEN_WIDTH - radius)
	{
		location.x = SCREEN_WIDTH - radius;
	}

	// ��ʏ㉺����͂ݏo���Ȃ��悤�ɂ��鏈��
	if (location.y <= radius)
	{
		location.y = radius;
	}
	else if (location.y >= SCREEN_HEIGHT - radius)
	{
		location.y = SCREEN_HEIGHT - radius;
	}
}