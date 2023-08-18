#include "DxLib.h"
#include "InputControl.h"
#include "RankingScene.h"
#include "TitleScene.h"

// コンストラクタ
RankingScene::RankingScene()
{

}

// デストラクタ
RankingScene::~RankingScene()
{

}

// 更新処理
AbstractScene* RankingScene::Update()
{
	// ボタンが押されたら
	//return new TitleScene();

	return this;
}

// 描画処理
void RankingScene::Draw() const
{
	// デバッグ
#if _DEBUG
	DrawFormatString(50, 0, 0xffffff, "ランキング表示");
#endif	//_DEBUG
}