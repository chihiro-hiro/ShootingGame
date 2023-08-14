#include "DxLib.h"
#include "InputControl.h"
#include "InputRankingScene.h"
#include "RankingScene.h"

// コンストラクタ
InputRankingScene::InputRankingScene()
{

}

// デストラクタ
InputRankingScene::~InputRankingScene()
{

}

// 更新処理
AbstractScene* InputRankingScene::Update()
{
	// 決定ボタンが押された
	return new RankingScene;

	//return this;
}

// 描画処理
void InputRankingScene::Draw() const
{
	// デバッグ
#if _DEBUG
	DrawFormatString(0, 0, 0xffffff, "ランキング登録");
#endif	//_DEBUG
}