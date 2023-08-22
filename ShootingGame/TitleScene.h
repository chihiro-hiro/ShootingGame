#pragma once
//#include "SceneBase.h"
#include "AbstractScene.h"

class TitleScene : public AbstractScene
{
private:
	int menu_number;					// ���j���[�I��
	int menu_y;							// �J�[�\����Y���W
	bool input_flg;						// �p�b�h���͂̂���Ȃ�

public:
	TitleScene();						// �R���X�g���N�^
	~TitleScene();						// �f�X�g���N�^
	AbstractScene* Update() override;	// �X�V����
	void Draw() const override;			// �`�揈��
};