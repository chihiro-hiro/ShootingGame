#pragma once
#include "AbstractScene.h"

class InputRankingScene : public AbstractScene
{
public:
	InputRankingScene();				// �R���X�g���N�^
	~InputRankingScene();				// �f�X�g���N�^
	AbstractScene* Update() override;	// �X�V����
	void Draw() const override;			// �`�揈��
};