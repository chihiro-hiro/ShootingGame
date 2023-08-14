#pragma once
#include "CharaBase.h"
#include "NwaySpawner.h"

class Enemy : public CharaBase
{
private:
	int hp;						// 体力
	int point;					// スコアの加算量
	NwaySpawner* weapon;		// BulletsSpawnerの子クラス

public:
	Enemy();						// コンストラクタ
	~Enemy();						// デストラクタ
	void Update() override;			// 更新処理
	void Draw() const override;		// 描画処理
	void Hit() override;			// ダメージ処理
};