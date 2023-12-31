#pragma once
#include "SphereCollider.h"

class Bullet : public SphereCollider
{
private:
	int damage;					// ダメージ量
	float speed;				// 速度
	float angle;				// 角度
	float acceleration;			// 速度の変化量
	float angulVelocity;		// 角度の変化量
	bool isEnemy;				// 誰から発射されたか
	int color;					// 弾の色

public:
	Bullet(float x, float y, bool is_enemy);					// コンストラクタ
	~Bullet();					// デストラクタ
	void Update();				// 更新処理
	void Draw() const;			// 描画処理
	int GetDamage();			// ダメージの値を取得
	bool CheckDelete();			// 弾が画面内にいるか
	bool CheckEnemyBullet();	// 敵の弾かのチェック
};