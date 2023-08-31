#include "DxLib.h"
#include "InputControl.h"
#include "GameClearScene.h"
#include "TitleScene.h"
#include "InputRankingScene.h"

// �R���X�g���N�^
GameClearScene::GameClearScene()
{
	waitTime = 0;
}

// �f�X�g���N�^
GameClearScene::~GameClearScene()
{

}

// �X�V����
AbstractScene* GameClearScene::Update()
{
	if (waitTime <= 300)
	{
		waitTime++;
	}
	else if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		// A�{�^���Ń^�C�g���֑J��
		return new TitleScene();
	}

	return this;
}

// �`�揈��
void GameClearScene::Draw() const
{
	SetFontSize(150);
	DrawFormatString(320, 250, 0xffff00, "Game Clear");

	if (waitTime >= 300)
	{
		SetFontSize(30);
		DrawFormatString(550, 600, 0xffffff, "A : �^�C�g��");
	}
}