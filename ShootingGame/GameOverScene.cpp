#include "DxLib.h"
#include "InputControl.h"
#include "GameOverScene.h"
#include "TitleScene.h"

// �R���X�g���N�^
GameOverScene::GameOverScene()
{
	waitTime = 0;
}

// �f�X�g���N�^
GameOverScene::~GameOverScene()
{

}

// �X�V����
AbstractScene* GameOverScene::Update()
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
void GameOverScene::Draw() const
{
	SetFontSize(150);
	DrawFormatString(320, 250, 0xff0000, "Game Over");

	if (waitTime >= 300)
	{
		SetFontSize(30);
		DrawFormatString(550, 600, 0xffffff, "A : �^�C�g��");
	}
}