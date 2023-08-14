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
	// ボタンが押されたら
	return new TitleScene();

	//return this;
}

// 描画処理
void GameOverScene::Draw() const
{
#if _DEBUG
	DrawFormatString(0, 0, 0xffffff, "ゲームオーバー");
#endif	//_DEBUG
}