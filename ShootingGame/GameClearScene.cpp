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

	// ボタンが押されたら
	return new TitleScene();

	//return this;
}

// 描画処理
void GameClearScene::Draw() const
{
#if _DEBUG
	DrawFormatString(0, 0, 0xffffff, "ゲームクリア");
#endif	//_DEBUG
}