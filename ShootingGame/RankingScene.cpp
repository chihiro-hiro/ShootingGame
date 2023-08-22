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
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		return new TitleScene();
	}

	return this;
}

// 描画処理
void RankingScene::Draw() const
{
	// デバッグ
#if _DEBUG
	DrawFormatString(50, 0, 0xffffff, "ランキング表示");
#endif	//_DEBUG

	// スペースキーでメニューに戻る
	//if (g_KeyFlg & PAD_INPUT_M) g_GameState = 0;

	// ランキング一覧を表示
	SetFontSize(30);
	for (int i = 0; i < RANK_MAX; i++) {
		DrawFormatString(80, 170 + i * 25, 0xFFFFFF, "%2d	%10s	%10d",
			Ranking[i].no, Ranking[i].name, Ranking[i].score);
	}

	SetFontSize(30);
	DrawFormatString(550, 600, 0xffffff, "A : タイトル");

}