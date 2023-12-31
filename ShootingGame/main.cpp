#include "DxLib.h"
#include "common.h"
#include "Fps.h"
#include "InputControl.h"
#include "SceneBase.h"
#include "TitleScene.h"
#include "GameMainScene.h"

// メイン関数
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lPcmdLine, _In_ int nCmdShow)
{
	SetMainWindowText("ShootingGame");						// ウィンドウタイトルを設定

	ChangeWindowMode(TRUE);									// ウインドウモードで起動

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);			// ウインドウのサイズ

	// DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// 描画先の指定（裏画面から開始する）
	SetDrawScreen(DX_SCREEN_BACK);

	// タイトル シーンオブジェクト作成
	SceneBase* sceneBase = new SceneBase((AbstractScene*) new TitleScene());

	Fps fps;
	
	// メインループ
	while (ProcessMessage() != -1 && sceneBase->Update() != nullptr)
	{
		// 画面の初期化
		ClearDrawScreen();

		// 入力操作の更新処理
		InputControl::Update();
		
		// シーンの描画開始
		sceneBase->Draw();

		fps.Update();
		//fps.Draw();

		// BACKボタンで強制終了
		if (InputControl::OnButton(XINPUT_BUTTON_BACK))
		{
			break;
		}

		// 裏画面の内容を表画面に反映する
		ScreenFlip();

		fps.Wait();
	}

	// DXライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了
	return 0;
}