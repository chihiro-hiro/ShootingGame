#pragma once
#include "CharaBase.h"
#include "BulletsSpawner.h"

class Player : public CharaBase
{
private:
	int score;
	BulletsSpawner* weapon;

	//デバッグ用
	int hp;

public:
	Player();						// コンストラクタ
	~Player();						// デストラクタ
	void Update() override;			// 更新処理
	void Draw() const override;		// 描画処理
	void Hit(int damage) override;	// ダメージ処理

private:
	void Move();					// 移動処理
};