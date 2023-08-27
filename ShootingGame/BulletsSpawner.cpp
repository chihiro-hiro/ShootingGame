#include "DxLib.h"
#include "BulletsSpawner.h"
#include "GameMainScene.h"

// �R���X�g���N�^
BulletsSpawner::BulletsSpawner()
{
	speed = 1.0f;				// ���x
	angle = 0.0f;				// �p�x
	acceleration = 3.0f;		// ���x�̕ω���
	angulVelocity = 3.0f;		// �p�x�̕ω���
}

// �f�X�g���N�^
BulletsSpawner::~BulletsSpawner()
{

}

// �����ɃQ�[�����C���V�[���̃|�C���^
void BulletsSpawner::Shoot(GameMainScene* gamemain, float x, float y, bool is_enemy)
{
	gamemain->SpawnBullet(x, y, is_enemy);
}