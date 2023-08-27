#include "DxLib.h"
#include "NwaySpawner.h"
#include "GameMainScene.h"

// �R���X�g���N�^
NwaySpawner::NwaySpawner()
{
	speed = 1.0f;				// ���x
	angle = 0.0f;				// �p�x
	acceleration = 3.0f;		// ���x�̕ω���
	angulVelocity = 3.0f;		// �p�x�̕ω���

	numBullets = 10;
	baseAngle = 0.0f;
	angleDiff = 0.0f;
}

// �f�X�g���N�^
NwaySpawner::~NwaySpawner()
{

}

// �_���[�W����
void NwaySpawner::Shoot(GameMainScene* gamemain, float x, float y, bool is_enemy)
{
	gamemain->SpawnBullet(x, y, is_enemy);
}