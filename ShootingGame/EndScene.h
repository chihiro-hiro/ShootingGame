#pragma once
#include "AbstractScene.h"

class EndScene : public AbstractScene
{
private:
	int waitTime;						// 待ち時間
public:
	EndScene();							// コンストラクタ
	~EndScene();						// デストラクタ
	AbstractScene* Update() override;	// 更新処理
	void Draw() const override;			// 描画処理
};

