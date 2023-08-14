#pragma once
#include "CharaBase.h"
#include "BulletsSpawner.h"

class Player : public CharaBase
{
private:
	int score;
	BulletsSpawner* weapon;

public:
	Player();						// �R���X�g���N�^
	~Player();						// �f�X�g���N�^
	void Update() override;			// �X�V����
	void Draw() const override;		// �`�揈��
	void Hit() override;			// �_���[�W����
};