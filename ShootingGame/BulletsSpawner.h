#pragma once

class GameMainScene;

class BulletsSpawner
{
protected:
	float speed;				// 速度
	float angle;				// 角度
	float acceleration;			// 速度の変化量
	float angulVelocity;		// 角度の変化量

public:
	BulletsSpawner();			// コンストラクタ
	~BulletsSpawner();			// デストラクタ
	virtual void Shoot(GameMainScene* gamemain, float x, float y, bool is_enemy);
};