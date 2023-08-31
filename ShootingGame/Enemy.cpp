#include "DxLib.h"
#include "common.h"
#include "Enemy.h"

// �R���X�g���N�^
Enemy::Enemy(float x, float y, float set_speed)
{
	speed = set_speed;
	isEnemy = TRUE;

	location.x = x;
	location.y = y;
	radius = 30.0f;

	hp = 3;
	point = 100;
	weapon = new NwaySpawner();
	interval = 0;
	shoudMoveRight = TRUE;
}

// �f�X�g���N�^
Enemy::~Enemy()
{

}

// �X�V����
void Enemy::Update(GameMainScene* gamemain)
{
	// ���E�ړ�����
	if (shoudMoveRight == TRUE)
	{
		location.x += speed;

		if (location.x >= SCREEN_WIDTH - radius)
		{
			location.x = SCREEN_WIDTH - radius;
			shoudMoveRight = FALSE;
		}
	}
	else
	{
		location.x -= speed;

		if (location.x <= radius)
		{
			location.x = radius;
			shoudMoveRight = TRUE;
		}
	}

	// �e�𔭎˂���^�C�~���O
	if (++interval >= 15)
	{
		if (GetRand(100) >= 80)
		{
			weapon->Shoot(gamemain, location.x, location.y, isEnemy);
		}
		interval = 0;
	}

}

// �`�揈��
void Enemy::Draw() const
{	
	DrawCircle((int)location.x, (int)location.y, (int)radius, 0xff0000, TRUE);
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

int Enemy::GetHp()
{
	return hp;
}

int Enemy::GetPoint()
{
	return point;
}
