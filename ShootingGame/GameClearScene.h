#pragma once
#include "AbstractScene.h"

class GameClearScene : public AbstractScene
{
public:
	GameClearScene();					// �R���X�g���N�^
	~GameClearScene();					// �f�X�g���N�^
	AbstractScene* Update() override;	// �X�V����
	void Draw() const override;			// �`�揈��
};