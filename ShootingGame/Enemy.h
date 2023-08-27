#pragma once
#include "CharaBase.h"
#include "NwaySpawner.h"

class Enemy : public CharaBase
{
private:
	int hp;						// �̗�
	int point;					// �X�R�A�̉��Z��
	NwaySpawner* weapon;		// BulletsSpawner�̎q�N���X

public:
	Enemy();						// �R���X�g���N�^
	~Enemy();						// �f�X�g���N�^
	void Update(GameMainScene* gamemain) override;			// �X�V����
	void Draw() const override;		// �`�揈��
	void Hit(int damage) override;			// �_���[�W����
};