#include "DxLib.h"
#include "InputControl.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "RankingScene.h"

// コンストラクタ
TitleScene::TitleScene()
{
	menu_number = 0;		// メニュー選択
	menu_y = 0;				// カーソルのY座標
	input_flg = FALSE;
}

// デストラクタ
TitleScene::~TitleScene()
{

}

// 更新処理
AbstractScene* TitleScene::Update()
{
	// 上下移動
	if (0.4f < InputControl::TipLeftLStick(STICKL_Y))
	{

		if (--menu_number < 0)
		{
			menu_number = 1;
		}
	}
	else if (InputControl::TipLeftLStick(STICKL_Y) < -0.4f)
	{
		if (++menu_number > 1)
		{
			menu_number = 0;
		}
	}

	//if (input_flg == FALSE)
	//{
	//	if (0.4f < InputControl::TipLeftLStick(STICKL_Y))
	//	{
	//		input_flg = TRUE;
	//		if (--menu_number < 0)
	//		{
	//			menu_number = 1;
	//		}
	//	}
	//	else if (InputControl::TipLeftLStick(STICKL_Y) < -0.4f)
	//	{
	//		input_flg = TRUE;
	//		if (++menu_number > 1)
	//		{
	//			menu_number = 0;
	//		}
	//	}
	//	else
	//	{
	//		input_flg = FALSE;
	//	}
	//}

	// カーソル位置の更新
	menu_y = menu_number * 52;

	// Aボタンで画面遷移
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		if (menu_number == 0)
		{
			return new GameMainScene();
		}
		else if (menu_number == 1)
		{
			return new RankingScene();
		}
	}
	
	return this;
}

// 描画処理
void TitleScene::Draw() const
{
	// デバッグ
#if _DEBUG
	SetFontSize(10);
	DrawFormatString(50, 0, 0xffffff, "タイトル");
#endif	//_DEBUG

	//SetFontSize(100);
	//DrawFormatString(350, 150, 0xffffff, "Shooting Game");

	//SetFontSize(70);
	//DrawFormatString(550, 400, 0xffffff, "Start");
	//DrawFormatString(550, 500, 0xffffff, "Ranking");

	//// カーソルの描画
	//DrawTriangle(240, 300 + menu_y, 260, 315 + menu_y, 240, 330 + menu_y, 0xff0000, TRUE);
}