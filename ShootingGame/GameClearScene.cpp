#include "DxLib.h"
#include "InputControl.h"
#include "GameClearScene.h"
#include "TitleScene.h"
#include "InputRankingScene.h"

// コンストラクタ
GameClearScene::GameClearScene()
{
	waitTime = 0;
}

// デストラクタ
GameClearScene::~GameClearScene()
{

}

// 更新処理
AbstractScene* GameClearScene::Update()
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
void GameClearScene::Draw() const
{
	SetFontSize(150);
	DrawFormatString(320, 250, 0xffff00, "Game Clear");

	if (waitTime >= 300)
	{
		SetFontSize(30);
		DrawFormatString(550, 600, 0xffffff, "A : タイトル");
	}
}