#include "DxLib.h"
#include "InputControl.h"
#include "Player.h"

// �R���X�g���N�^
Player::Player()
{
	score = 0;
	weapon = new BulletsSpawner;
}

// �f�X�g���N�^
Player::~Player()
{
	delete weapon;
}

// �X�V����
void Player::Update()
{
	// �{�^���������ꂽ��ړ�

}

// �`�揈��
void Player::Draw() const
{
	DrawCircle(100, 100, 20, 0xffffff, TRUE);
}

// �_���[�W����
void Player::Hit()
{

}