#pragma once
#include "AbstractScene.h"

class EndScene : public AbstractScene
{
private:
	int waitTime;						// �҂�����
public:
	EndScene();							// �R���X�g���N�^
	~EndScene();						// �f�X�g���N�^
	AbstractScene* Update() override;	// �X�V����
	void Draw() const override;			// �`�揈��
};

