#include"DxLib.h"

// メイン関数
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lPcmdLine, _In_ int nCmdShow)
{
	SetMainWindowText("ShootingGame");			// ウィンドウタイトルを設定

	ChangeWindowMode(TRUE);						// ウインドウモードで起動

	SetGraphMode(1280, 720, 32);				// ウインドウのサイズ

	// DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// 描画先の指定（裏画面から開始する）
	SetDrawScreen(DX_SCREEN_BACK);

	// 変数定義
	//SceneManager scenManager(dynamic_cast<AbstractScene*>(new TitleScene));

	// メインループ
	while (ProcessMessage() != -1)
	{
		//// 入力操作の更新処理
		//InputControl::Update();

		//scenManager.Update();
		//scenManager.Draw();
		//if (scenManager.Change() == nullptr)
		//{
		//	break;
		//}

		ScreenFlip(); // 裏画面の内容を表画面に反映する

	}

	// DXライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了
	return 0;
}
