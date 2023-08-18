#include "DxLib.h"
#include "InputControl.h"
#include "GameOverScene.h"
#include "TitleScene.h"

// コンストラクタ
GameOverScene::GameOverScene()
{

}

// デストラクタ
GameOverScene::~GameOverScene()
{

}

// 更新処理
AbstractScene* GameOverScene::Update()
{
	// Aボタンでタイトルへ遷移
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		return new TitleScene();
	}

	return this;
}

// 描画処理
void GameOverScene::Draw() const
{
#if _DEBUG
	DrawFormatString(50, 0, 0xff0000, "ゲームオーバー");
	DrawFormatString(200, 0, 0xffffff, "A : タイトル");
#endif	//_DEBUG
}