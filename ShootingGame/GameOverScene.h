#pragma once
#include "AbstractScene.h"

class GameOverScene : public AbstractScene
{
public:
	GameOverScene();					// �R���X�g���N�^
	~GameOverScene();					// �f�X�g���N�^
	AbstractScene* Update() override;	// �X�V����
	void Draw() const override;			// �`�揈��
};