#pragma once
//#include "SceneBase.h"
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

#define ENEMY_NUM	(10)				// 敵の最大数
#define BULLET_NUM	(100)				// 弾の最大数
#define STEGE_MAX	(3)					// ステージの最大数

class GameMainScene : public AbstractScene
{
private:
	Player player;						// Playerのオブジェクト化
	int life;							// 残機
	Enemy* enemy[ENEMY_NUM];			// Enemyのポインタ配列
	Bullet* bullet[BULLET_NUM];			// Bulletのポインタ配列
	int livingEnemies;					// 生きている敵の数
	int stageNum;						// ステージ数
	int waitTime;						// ステージ遷移時の待ち時間
	bool isClear;
	int timeLimit;						// 制限時間
	int fpsCount;

public:
	GameMainScene();					// コンストラクタ
	~GameMainScene();					// デストラクタ
	AbstractScene* Update() override;	// 更新処理
	void Draw() const override;			// 描画処理

	void HitCheck();					// 当たり判定のチェック
	void SpawnBullet(float x, float y, bool is_enemy);					// 弾の配列に新しくデータを作成する
	void ChangeStage();
};