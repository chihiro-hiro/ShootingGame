#pragma once
#include "SphereCollider.h"

class GameMainScene;

class CharaBase : public SphereCollider
{
protected:
	float speed;
	int image;

public:
	CharaBase();					// �R���X�g���N�^
	~CharaBase();					// �f�X�g���N�^
	virtual void Update(GameMainScene* gamemain);			// �X�V����		// �����ɃQ�[�����C���V�[���̃|�C���^
	virtual void Draw() const;		// �`�揈��
	virtual void Hit(int damage);	// �_���[�W����
};