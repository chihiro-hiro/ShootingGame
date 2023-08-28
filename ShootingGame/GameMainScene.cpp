#include "DxLib.h"
#include "GameMainScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

#include "InputControl.h"

// デバッグ用
//int color = 0xffffff;

// コンストラクタ
GameMainScene::GameMainScene()
{
	life = 3;									// 残機
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i] = nullptr;
	}

	enemy[0] = new Enemy(100.0f,200.0f);

	for (int i = 0; i < BULLET_NUM; i++)
	{
		bullet[i] = nullptr;
	}

	livingEnemies = 1;
	//livingEnemies = ENEMY_NUM;
	stageNum = 1;
}

// デストラクタ
GameMainScene::~GameMainScene()
{
	//delete enemy;
	//delete[] bullet;

	//for (int i = 0; i < BULLET_NUM; i++)
	//{
	//	delete[i] bullet;
	//}
}

// 更新処理
AbstractScene* GameMainScene::Update()
{
	// プレイヤーの更新処理
	player.Update(this);

	// 敵の更新処理
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update(this);
		}
	}

	// 弾の更新処理
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Update();

			if (bullet[i]->CheckDelete() == true)
			{
				bullet[i] = nullptr;
			}
		}
	}

	// 当たり判定のチェック
	HitCheck();

	if (InputControl::OnButton(XINPUT_BUTTON_Y) == 1)
	{
		return new GameOverScene();
	}

	if (InputControl::OnButton(XINPUT_BUTTON_X) == 1)
	{
		return new GameClearScene();
	}

	//if (stageNum > STEGE_MAX && livingEnemies >= 0)
	//{
	// // ゲームクリア
	//	return new GameClearScene();
	//}
	//else if (livingEnemies >= 0)
	//{
	// 	// ステージクリア
	//	return new GameClearScene();
	// stageNum++;
	// ChangeStage();
	//}


	if (life <= 0)
	{
		// 残機が0
		return new GameOverScene();
	}

	return this;
}

// 描画処理
void GameMainScene::Draw() const
{
	// デバッグ
#if _DEBUG
	//DrawFormatString(50, 0, color, "ゲームメイン");
	DrawFormatString(200, 0, 0xffffff, "Y : ゲームオーバー");
	DrawFormatString(200, 20, 0xffffff, "X : ゲームクリア");
	DrawFormatString(0, 50, 0xffffff, "LIFE %2d",life);
	DrawFormatString(300, 50, 0xff0000, "enemys %2d",livingEnemies);
	DrawFormatString(300, 100, 0xffffff, "SCORE %d",player.GetScore());
#endif	//_DEBUG

	// プレイヤーの描画処理
	player.Draw();

	// エネミーの描画処理
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	// 弾の描画処理
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Draw();
		}
	}
}

// 当たり判定のチェック
void GameMainScene::HitCheck()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i] != nullptr)
		{
			// プレイヤーとの当たり判定
			if (player.CheckCollision(bullet[i]) == true && bullet[i]->CheckEnemyBullet() == true)
			{
				//color = 0xff0000;

				// ダメージ処理
				player.Hit(bullet[i]->GetDamage());

				bullet[i] = nullptr;

				life--;

				break;
			}

			for (int j = 0; j < ENEMY_NUM; j++)
			{
				if (enemy[j] != nullptr)
				{
					//敵との当たり判定
					if (enemy[j]->CheckCollision(bullet[i]) == true && bullet[i]->CheckEnemyBullet() == false)
					{
						//color = 0x0000ff;

						// ダメージ処理
						enemy[j]->Hit(bullet[i]->GetDamage());

						bullet[i] = nullptr;

						if (enemy[j]->GetHp() == 0)
						{
							livingEnemies--;
							player.SetScore(enemy[j]->GetPoint());
							enemy[j] = nullptr;
						}
					}
				}
			}
		}
	}
}

// 弾の配列に新しくデータを作成する
void GameMainScene::SpawnBullet(float x, float y, bool is_enemy)
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i] == nullptr)
		{
			bullet[i] = new Bullet(x, y, is_enemy);
			break;
		}
	}
}

void GameMainScene::ChangeStage()
{
	switch (stageNum)
	{
		case 1:
			enemy[0] = new Enemy(100.0f, 200.0f);
			livingEnemies = 1;
			break;
		case 2:
			enemy[0] = new Enemy(50.0f, 150.0f);
			enemy[1] = new Enemy(100.0f, 200.0f);
			enemy[2] = new Enemy(150.0f, 250.0f);
			livingEnemies = 3;
			break;
		case 3:
			enemy[0] = new Enemy(50.0f, 150.0f);
			enemy[1] = new Enemy(100.0f, 200.0f);
			enemy[2] = new Enemy(150.0f, 250.0f);
			enemy[3] = new Enemy(150.0f, 250.0f);
			enemy[4] = new Enemy(150.0f, 250.0f);
			livingEnemies = 5;
			break;
		default:
			break;
	}
}