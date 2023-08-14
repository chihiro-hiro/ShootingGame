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

	// �{�^���������ꂽ��
	return new TitleScene();

	//return this;
}

// �`�揈��
void GameClearScene::Draw() const
{
#if _DEBUG
	DrawFormatString(0, 0, 0xffffff, "�Q�[���N���A");
#endif	//_DEBUG
}