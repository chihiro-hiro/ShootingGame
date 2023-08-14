#include "DxLib.h"
#include "GameMainScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

// コンストラクタ
GameMainScene::GameMainScene()
{
	life = 3;				// 残機
	enemy = new Enemy;
	bullet = new Bullet;
}

// デストラクタ
GameMainScene::~GameMainScene()
{

}

// 当たり判定のチェック
void GameMainScene::HitCheck()
{

}

// 弾の配列に新しくデータを作成する
void GameMainScene::SpawnBullet()
{

}

// 更新処理
AbstractScene* GameMainScene::Update()
{
	// ステージクリア
	//return new GameClearScene();

	// 残機が0
	//return new GameOverScene();

	return this;
}

// 描画処理
void GameMainScene::Draw() const
{
	// デバッグ
#if _DEBUG
	DrawFormatString(0, 0, 0xffffff, "ゲームメイン");
#endif	//_DEBUG

	// プレイヤーの描画処理
	player.Draw();

	// エネミーの描画処理
	enemy->Draw();

	// 弾の描画処理
	bullet->Draw();
}