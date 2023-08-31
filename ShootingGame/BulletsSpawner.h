#pragma once

class GameMainScene;

class BulletsSpawner
{
protected:
	float speed;				// ���x
	float angle;				// �p�x
	float acceleration;			// ���x�̕ω���
	float angulVelocity;		// �p�x�̕ω���

public:
	BulletsSpawner();			// �R���X�g���N�^
	~BulletsSpawner();			// �f�X�g���N�^
	virtual void Shoot(GameMainScene* gamemain, float x, float y, bool is_enemy);
};