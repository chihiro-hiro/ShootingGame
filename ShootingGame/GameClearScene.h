#pragma once
#include "AbstractScene.h"

class GameClearScene : public AbstractScene
{
private:
	int waitTime;							// �҂�����
public:
	GameClearScene();					// �R���X�g���N�^
	~GameClearScene();					// �f�X�g���N�^
	AbstractScene* Update() override;	// �X�V����
	void Draw() const override;			// �`�揈��
};