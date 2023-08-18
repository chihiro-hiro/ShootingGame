#include "DxLib.h"
#include "InputControl.h"
#include "GameOverScene.h"
#include "TitleScene.h"

// �R���X�g���N�^
GameOverScene::GameOverScene()
{

}

// �f�X�g���N�^
GameOverScene::~GameOverScene()
{

}

// �X�V����
AbstractScene* GameOverScene::Update()
{
	// A�{�^���Ń^�C�g���֑J��
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		return new TitleScene();
	}

	return this;
}

// �`�揈��
void GameOverScene::Draw() const
{
#if _DEBUG
	DrawFormatString(50, 0, 0xff0000, "�Q�[���I�[�o�[");
	DrawFormatString(200, 0, 0xffffff, "A : �^�C�g��");
#endif	//_DEBUG
}