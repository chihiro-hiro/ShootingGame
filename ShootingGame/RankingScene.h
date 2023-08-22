#pragma once
#include "AbstractScene.h"

#define RANK_MAX (5)			// ランキングは上位5位まで
#define NAME_MAX (11)			// 名前のサイズ

class RankingScene : public AbstractScene
{
public:
	RankingScene();						// コンストラクタ
	~RankingScene();					// デストラクタ
	AbstractScene* Update() override;	// 更新処理
	void Draw() const override;			// 描画処理

public:
	//ランキングデータ
	typedef struct
	{
		int no;						// 順位
		char name[NAME_MAX];		// 名前　10Byte
		long score;					// スコア
	} RankingData;

	RankingData		Ranking[RANK_MAX];

};