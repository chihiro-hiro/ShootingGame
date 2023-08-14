#pragma once
#include "AbstractScene.h"

class GameClearScene : public AbstractScene
{
public:
	GameClearScene();					// コンストラクタ
	~GameClearScene();					// デストラクタ
	AbstractScene* Update() override;	// 更新処理
	void Draw() const override;			// 描画処理
};