#include "DxLib.h"
#include "InputControl.h"
#include "GameOverScene.h"
#include "TitleScene.h"

// コンストラクタ
GameOverScene::GameOverScene()
{
	waitTime = 0;
}

// デストラクタ
GameOverScene::~GameOverScene()
{

}

// 更新処理
AbstractScene* GameOverScene::Update()
{
	if (waitTime <= 300)
	{
		waitTime++;
	}
	else if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		// Aボタンでタイトルへ遷移
		return new TitleScene();
	}

	return this;
}

// 描画処理
void GameOverScene::Draw() const
{
	SetFontSize(150);
	DrawFormatString(320, 250, 0xff0000, "Game Over");

	if (waitTime >= 300)
	{
		SetFontSize(30);
		DrawFormatString(550, 600, 0xffffff, "A : タイトル");
	}
}