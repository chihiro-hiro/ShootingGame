#include "DxLib.h"
#include "Enemy.h"

// �R���X�g���N�^
Enemy::Enemy()
{
	speed = 5.0f;

	location.x = 100.0f;
	location.y = 200.0f;
	radius = 40.0f;

	hp = 3;
	point = 10;
	weapon = new NwaySpawner();
}

// �f�X�g���N�^
Enemy::~Enemy()
{

}

// �X�V����
void Enemy::Update(GameMainScene* gamemain)
{
	// �ړ�����

}

// �`�揈��
void Enemy::Draw() const
{
	DrawCircle((int)location.x, (int)location.y, (int)radius, 0x00ffff, TRUE);
}

// �_���[�W����
void Enemy::Hit(int damage)
{
	hp -= damage;

	if (hp <= 0)
	{
		hp = 0;
	}
}