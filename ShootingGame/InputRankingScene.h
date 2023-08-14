#pragma once
#include "AbstractScene.h"

class InputRankingScene : public AbstractScene
{
public:
	InputRankingScene();				// コンストラクタ
	~InputRankingScene();				// デストラクタ
	AbstractScene* Update() override;	// 更新処理
	void Draw() const override;			// 描画処理
};