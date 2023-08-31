#include "DxLib.h"
#include "InputControl.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "RankingScene.h"
#include "EndScene.h"

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
	// カーソル移動
	if (input_flg == FALSE)
	{
		if (0.4f < InputControl::TipLeftLStick(STICKL_Y))
		{
			input_flg = TRUE;
			if (--menu_number < 0)
			{
				menu_number = 2;
			}
		}
		else if (InputControl::TipLeftLStick(STICKL_Y) < -0.4f)
		{
			input_flg = TRUE;
			if (++menu_number > 2)
			{
				menu_number = 0;
			}
		}
	}
	else if(0.4f > InputControl::TipLeftLStick(STICKL_Y) && InputControl::TipLeftLStick(STICKL_Y) > -0.4f)
	{
		input_flg = FALSE;
	}

	// カーソル位置の更新
	menu_y = menu_number * 100;

	// Aボタンで画面遷移
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		if (menu_number == 0)
		{
			return new GameMainScene();
		}
		else if (menu_number == 1)
		{
			//return new RankingScene();
		}
		else if (menu_number == 2)
		{
			return new EndScene();
		}
	}
	
	return this;
}

// 描画処理
void TitleScene::Draw() const
{
	SetFontSize(100);
	DrawFormatString(350, 150, 0xffffff, "Shooting Game");

	SetFontSize(70);
	DrawFormatString(550, 400, 0xffffff, "Start");
	DrawFormatString(550, 500, 0xffffff, "Ranking");
	DrawFormatString(550, 600, 0xffffff, "END");

	// カーソルの描画
	DrawTriangle(500, 410 + menu_y, 530, 430 + menu_y, 500, 450 + menu_y, 0xff0000, TRUE);
}