#pragma once
#include "CharaBase.h"
#include "NwaySpawner.h"

class Enemy : public CharaBase
{
private:
	int hp;						// 体力
	int point;					// スコアの加算量
	NwaySpawner* weapon;		// BulletsSpawnerの子クラス
	int interval;				// 弾を発射する間隔
	//bool shoudMove;				// 移動するか
	bool shoudMoveRight;		// 右に移動するか

public:
	Enemy(float x, float y, float set_speed);					// コンストラクタ
	~Enemy();						// デストラクタ
	void Update(GameMainScene* gamemain) override;			// 更新処理
	void Draw() const override;		// 描画処理
	void Hit(int damage) override;			// ダメージ処理
	int GetHp();
	int GetPoint();
};