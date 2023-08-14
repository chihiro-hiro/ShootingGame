#pragma once
#include "AbstractScene.h"

class RankingScene : public AbstractScene
{
public:
	RankingScene();						// コンストラクタ
	~RankingScene();					// デストラクタ
	AbstractScene* Update() override;	// 更新処理
	void Draw() const override;			// 描画処理
};