#pragma once
#include "AbstractScene.h"

class RankingScene : public AbstractScene
{
public:
	RankingScene();						// �R���X�g���N�^
	~RankingScene();					// �f�X�g���N�^
	AbstractScene* Update() override;	// �X�V����
	void Draw() const override;			// �`�揈��
};