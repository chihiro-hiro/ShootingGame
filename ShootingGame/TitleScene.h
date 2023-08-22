#pragma once
//#include "SceneBase.h"
#include "AbstractScene.h"

class TitleScene : public AbstractScene
{
private:
	int menu_number;					// メニュー選択
	int menu_y;							// カーソルのY座標
	bool input_flg;						// パッド入力のありなし

public:
	TitleScene();						// コンストラクタ
	~TitleScene();						// デストラクタ
	AbstractScene* Update() override;	// 更新処理
	void Draw() const override;			// 描画処理
};