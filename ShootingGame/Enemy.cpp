#include "DxLib.h"
#include "Enemy.h"

// �R���X�g���N�^
Enemy::Enemy()
{
	hp = 3;
	point = 10;
	weapon = new NwaySpawner();
}

// �f�X�g���N�^
Enemy::~Enemy()
{

}

// �X�V����
void Enemy::Update()
{
	// �ړ�����

}

// �`�揈��
void Enemy::Draw() const
{
	DrawCircle(100, 200, 20, 0x00ffff, TRUE);
}

// �_���[�W����
void Enemy::Hit()
{

}