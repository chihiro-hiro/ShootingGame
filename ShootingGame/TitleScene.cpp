#include "DxLib.h"
#include "InputControl.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "RankingScene.h"

// コンストラクタ
TitleScene::TitleScene()
{

}

// デストラクタ
TitleScene::~TitleScene()
{

}

// 更新処理
AbstractScene* TitleScene::Update()
{
	// Aボタンでゲームメインへ遷移
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		return new GameMainScene();
	}

	// ゲームメインが選択された
	//return new GameMainScene();

	// ランキング画面が選択された
	//return new RankingScene();
	
	return this;
}

// 描画処理
void TitleScene::Draw() const
{
	// デバッグ
#if _DEBUG
	DrawFormatString(50, 0, 0xffffff, "タイトル");
	DrawFormatString(200, 0, 0xffffff, "A : ゲームメイン");
#endif	//_DEBUG
}