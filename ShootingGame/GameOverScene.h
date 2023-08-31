#pragma once
#include "AbstractScene.h"

class GameOverScene : public AbstractScene
{
private:
	int waitTime;						// 待ち時間
public:
	GameOverScene();					// コンストラクタ
	~GameOverScene();					// デストラクタ
	AbstractScene* Update() override;	// 更新処理
	void Draw() const override;			// 描画処理
};