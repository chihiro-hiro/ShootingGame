#pragma once

class BulletsSpawner
{
private:
	float speed;				// ���x
	float angle;				// �p�x
	float acceleration;			// ���x�̕ω���
	float angulVelocity;		// �p�x�̕ω���

public:
	BulletsSpawner();			// �R���X�g���N�^
	~BulletsSpawner();			// �f�X�g���N�^
	virtual void Shoot();		// �����ɃQ�[�����C���V�[���̃|�C���^
};