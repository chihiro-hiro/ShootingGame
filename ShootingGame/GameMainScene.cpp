#include "DxLib.h"
#include "GameMainScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

// デバッグ用
int color = 0xffffff;

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

// 更新処理
AbstractScene* GameMainScene::Update()
{
	// プレイヤーの更新処理
	player.Update();

	bullet->Update();

	// 当たり判定のチェック
	HitCheck();

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
	DrawFormatString(0, 0, color, "ゲームメイン");
#endif	//_DEBUG

	// プレイヤーの描画処理
	player.Draw();

	// エネミーの描画処理
	enemy->Draw();

	// 弾の描画処理
	bullet->Draw();
}

// 当たり判定のチェック
void GameMainScene::HitCheck()
{
	// プレイヤーとの当たり判定
	if (player.CheckCollision(bullet) == true)
	{
		color = 0xff0000;

		// ダメージ処理
		player.Hit(bullet->GetDamage());

		//bullet = nullptr;
	}
	else if (player.CheckCollision(enemy) == true)
	{
		color = 0x00ffff;
	}
	else
	{
		color = 0xffffff;
	}

	// 敵との当たり判定
	if (enemy->CheckCollision(bullet) == true)
	{
		color = 0x0000ff;

		// ダメージ処理
		enemy->Hit(bullet->GetDamage());
		
		//bullet = nullptr;
	}
}

// 弾の配列に新しくデータを作成する
void GameMainScene::SpawnBullet()
{

}