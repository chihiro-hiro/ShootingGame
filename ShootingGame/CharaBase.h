#pragma once
#include "SphereCollider.h"

class CharaBase : public SphereCollider
{
private:
	float speed;
	int image;

public:
	CharaBase();					// �R���X�g���N�^
	~CharaBase();					// �f�X�g���N�^
	virtual void Update();			// �X�V����
	virtual void Draw() const;		// �`�揈��
	virtual void Hit();				// �_���[�W����
};