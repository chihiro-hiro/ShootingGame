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
	void Update() override;			// 更新処理
	void Draw() const override;		// 描画処理
	void Hit() override;			// ダメージ処理
};