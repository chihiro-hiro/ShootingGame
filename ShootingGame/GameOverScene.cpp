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
	// �{�^���������ꂽ��
	return new TitleScene();

	//return this;
}

// �`�揈��
void GameOverScene::Draw() const
{
#if _DEBUG
	DrawFormatString(0, 0, 0xffffff, "�Q�[���I�[�o�[");
#endif	//_DEBUG
}