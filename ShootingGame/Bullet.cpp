#include "DxLib.h"
#include "InputControl.h"
#include "Bullet.h"

// �R���X�g���N�^
Bullet::Bullet()
{
	damage = 1;					// �_���[�W��
	speed = 1.0f;				// ���x
	angle = 0.0f;				// �p�x
	acceleration = 3.0f;		// ���x�̕ω���
	angulVelocity = 3.0f;		// �p�x�̕ω���
}

// �f�X�g���N�^
Bullet::~Bullet()
{

}

// �X�V����
void Bullet::Update()
{
	// �{�^���������ꂽ�甭��
}

// �`�揈��
void Bullet::Draw() const
{
	DrawCircle(200, 100, 10, 0xff0000, TRUE);
}

// �_���[�W����
void Bullet::GetDamage()
{

}