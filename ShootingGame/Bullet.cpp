#include "DxLib.h"
#include "common.h"
#include "InputControl.h"
#include "Bullet.h"

// �R���X�g���N�^
Bullet::Bullet(float x, float y, bool is_enemy)
{
	location.x = x;
	location.y = y;
	radius = 10.0f;

	damage = 1;					// �_���[�W��
	speed = 10.0f;				// ���x
	angle = 0.0f;				// �p�x
	acceleration = 3.0f;		// ���x�̕ω���
	angulVelocity = 3.0f;		// �p�x�̕ω���
	isEnemy = is_enemy;
	color = 0xffff00;
}

// �f�X�g���N�^
Bullet::~Bullet()
{

}

// �X�V����
void Bullet::Update()
{
	if (isEnemy == TRUE)
	{
		location.y += speed;
	}
	else
	{
		location.y -= speed;
		color = 0x0fffff;
	}
}

// �`�揈��
void Bullet::Draw() const
{
	DrawCircle((int)location.x, (int)location.y, (int)radius, color, TRUE);
	DrawCircle((int)location.x, (int)location.y, (int)radius, 0xffffff, FALSE);
}

// �_���[�W�̒l���擾
int Bullet::GetDamage()
{
	return damage;
}

bool Bullet::CheckDelete()
{
	// ��ʊO�ɍs���Ə����i�㉺�j
	if (location.y <= -radius || location.y >= SCREEN_HEIGHT + radius)
	{
		return true;
	}

	return false;
}

bool Bullet::CheckEnemyBullet()
{
	return isEnemy;
}
