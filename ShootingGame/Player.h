#pragma once
#include "CharaBase.h"
#include "BulletsSpawner.h"

class Player : public CharaBase
{
private:
	int score;
	BulletsSpawner* weapon;

public:
	Player();						// コンストラクタ
	~Player();						// デストラクタ
	void Update(GameMainScene* gamemain) override;			// 更新処理
	void Draw() const override;		// 描画処理
	void Hit(int damage) override;	// ダメージ処理
	int GetScore()const;
	void SetScore(int set_score);

private:
	void Move();					// 移動処理
};