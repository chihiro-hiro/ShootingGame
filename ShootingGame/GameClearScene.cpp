#include "DxLib.h"
#include "InputControl.h"
#include "GameClearScene.h"
#include "TitleScene.h"
#include "InputRankingScene.h"

// �R���X�g���N�^
GameClearScene::GameClearScene()
{

}

// �f�X�g���N�^
GameClearScene::~GameClearScene()
{

}

// �X�V����
AbstractScene* GameClearScene::Update()
{
	// �����L���O����������
	//return new InputRankingScene();

	// A�{�^���Ń^�C�g���֑J��
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		return new TitleScene();
	}

	return this;
}

// �`�揈��
void GameClearScene::Draw() const
{
#if _DEBUG
	DrawFormatString(50, 0, 0xffff00, "�Q�[���N���A");
	DrawFormatString(200, 0, 0xffffff, "A : �^�C�g��");
#endif	//_DEBUG
}