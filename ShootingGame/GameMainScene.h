#pragma once
//#include "SceneBase.h"
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

#define ENEMY_NUM
#define BULLET_NUM	(10)

class GameMainScene : public AbstractScene
{
private:
	Player player;						// Playerのオブジェクト化
	int life;							// 残機
	Enemy* enemy;						// Enemyのポインタ配列
	Bullet* bullet[BULLET_NUM];			// Bulletのポインタ配列

public:
	GameMainScene();					// コンストラクタ
	~GameMainScene();					// デストラクタ
	AbstractScene* Update() override;	// 更新処理
	void Draw() const override;			// 描画処理

	void HitCheck();					// 当たり判定のチェック
	void SpawnBullet(float x, float y, bool is_enemy);					// 弾の配列に新しくデータを作成する
};