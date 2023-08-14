#pragma once
//#include "SceneBase.h"
#include "AbstractScene.h"

class TitleScene : public AbstractScene
{
public:
	TitleScene();						// コンストラクタ
	~TitleScene();						// デストラクタ
	AbstractScene* Update() override;	// 更新処理
	void Draw() const override;			// 描画処理
};