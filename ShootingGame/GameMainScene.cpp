#include "DxLib.h"
#include "GameMainScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

#include "InputControl.h"

// �f�o�b�O�p
int color = 0xffffff;

// �R���X�g���N�^
GameMainScene::GameMainScene()
{
	life = 3;				// �c�@
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		enemy[i] = nullptr;
	}

	enemy[1] = new Enemy();

	for (int i = 0; i < BULLET_NUM; i++)
	{
		bullet[i] = nullptr;
	}
}

// �f�X�g���N�^
GameMainScene::~GameMainScene()
{
	//delete enemy;
	//delete[] bullet;

	//for (int i = 0; i < BULLET_NUM; i++)
	//{
	//	delete[i] bullet;
	//}
}

// �X�V����
AbstractScene* GameMainScene::Update()
{
	// �v���C���[�̍X�V����
	player.Update(this);

	// �G�̍X�V����
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Update(this);
		}
	}

	// �e�̍X�V����
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Update();

			if (bullet[i]->CheckDraw() == true)
			{
				bullet[i] = nullptr;
			}
		}
	}

	// �����蔻��̃`�F�b�N
	HitCheck();

	if (InputControl::OnButton(XINPUT_BUTTON_Y) == 1)
	{
		return new GameOverScene();
	}

	if (InputControl::OnButton(XINPUT_BUTTON_X) == 1)
	{
		return new GameClearScene();
	}

	// �X�e�[�W�N���A
	//return new GameClearScene();

	if (life <= 0)
	{
		// �c�@��0
		return new GameOverScene();
	}

	return this;
}

// �`�揈��
void GameMainScene::Draw() const
{
	// �f�o�b�O
#if _DEBUG
	DrawFormatString(50, 0, color, "�Q�[�����C��");
	DrawFormatString(200, 0, 0xffffff, "Y : �Q�[���I�[�o�[");
	DrawFormatString(200, 20, 0xffffff, "X : �Q�[���N���A");
	DrawFormatString(0, 50, 0xffffff, "LIFE %2d",life);
#endif	//_DEBUG

	// �v���C���[�̕`�揈��
	player.Draw();

	// �G�l�~�[�̕`�揈��
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (enemy[i] != nullptr)
		{
			enemy[i]->Draw();
		}
	}

	//enemy->Draw();

	// �e�̕`�揈��
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i] != nullptr)
		{
			bullet[i]->Draw();
		}
	}
}

// �����蔻��̃`�F�b�N
void GameMainScene::HitCheck()
{
	for (int i = 0; i < BULLET_NUM; i++)
	{
		if (bullet[i] != nullptr)
		{
			// �v���C���[�Ƃ̓����蔻��
			if (player.CheckCollision(bullet[i]) == true && bullet[i]->CheckEnemyBullet() == true)
			{
				color = 0xff0000;

				// �_���[�W����
				player.Hit(bullet[i]->GetDamage());

				bullet[i] = nullptr;

				life--;

				break;
			}

			for (int j = 0; j < ENEMY_NUM; j++)
			{
				if (enemy[j] != nullptr)
				{
					//�G�Ƃ̓����蔻��
					if (enemy[j]->CheckCollision(bullet[i]) == true && bullet[i]->CheckEnemyBullet() == false)
					{
						color = 0x0000ff;

						// �_���[�W����
						enemy[j]->Hit(bullet[i]->GetDamage());

						bullet[i] = nullptr;

						if (enemy[j]->GetHp() == 0)
						{
							enemy[j] = nullptr;
						}
					}
				}
			}
		}
	}
}

// �e�̔z��ɐV�����f�[�^���쐬����
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