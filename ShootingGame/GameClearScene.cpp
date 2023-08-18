#include "DxLib.h"
#include "InputControl.h"
#include "GameClearScene.h"
#include "TitleScene.h"
#include "InputRankingScene.h"

// コンストラクタ
GameClearScene::GameClearScene()
{

}

// デストラクタ
GameClearScene::~GameClearScene()
{

}

// 更新処理
AbstractScene* GameClearScene::Update()
{
	// ランキング内だったら
	//return new InputRankingScene();

	// Aボタンでタイトルへ遷移
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		return new TitleScene();
	}

	return this;
}

// 描画処理
void GameClearScene::Draw() const
{
#if _DEBUG
	DrawFormatString(50, 0, 0xffff00, "ゲームクリア");
	DrawFormatString(200, 0, 0xffffff, "A : タイトル");
#endif	//_DEBUG
}