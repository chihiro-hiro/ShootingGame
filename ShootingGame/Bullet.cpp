#include "DxLib.h"
#include "InputControl.h"
#include "Bullet.h"

// �R���X�g���N�^
Bullet::Bullet()
{
	location.x = 200.0f;
	location.y = 200.0f;
	radius = 10.0f;

	damage = 1;					// �_���[�W��
	speed = 2.0f;				// ���x
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
	// �ړ�����
	//if (location.y > 10)
	//{
	//	// ��Ɉړ�����
	//	location.y -= speed;
	//}
}

// �`�揈��
void Bullet::Draw() const
{
	DrawCircle((int)location.x, (int)location.y, (int)radius, 0xff0000, TRUE);
}

// �_���[�W�̒l���擾
int Bullet::GetDamage()
{
	return damage;
}