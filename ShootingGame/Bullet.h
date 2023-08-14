#pragma once
#include "SphereCollider.h"

class Bullet : public SphereCollider
{
private:
	int damage;					// �_���[�W��
	float speed;				// ���x
	float angle;				// �p�x
	float acceleration;			// ���x�̕ω���
	float angulVelocity;		// �p�x�̕ω���

public:
	Bullet();					// �R���X�g���N�^
	~Bullet();					// �f�X�g���N�^
	void Update();				// �X�V����
	void Draw() const;			// �`�揈��
	void GetDamage();			// �_���[�W����
};