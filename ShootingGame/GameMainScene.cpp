#include "DxLib.h"
#include "GameMainScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

// �f�o�b�O�p
int color = 0xffffff;

// �R���X�g���N�^
GameMainScene::GameMainScene()
{
	life = 3;				// �c�@
	enemy = new Enemy;
	bullet = new Bullet;
}

// �f�X�g���N�^
GameMainScene::~GameMainScene()
{

}

// �X�V����
AbstractScene* GameMainScene::Update()
{
	// �v���C���[�̍X�V����
	player.Update();

	bullet->Update();

	// �����蔻��̃`�F�b�N
	HitCheck();

	// �X�e�[�W�N���A
	//return new GameClearScene();

	// �c�@��0
	//return new GameOverScene();

	return this;
}

// �`�揈��
void GameMainScene::Draw() const
{
	// �f�o�b�O
#if _DEBUG
	DrawFormatString(0, 0, color, "�Q�[�����C��");
#endif	//_DEBUG

	// �v���C���[�̕`�揈��
	player.Draw();

	// �G�l�~�[�̕`�揈��
	enemy->Draw();

	// �e�̕`�揈��
	bullet->Draw();
}

// �����蔻��̃`�F�b�N
void GameMainScene::HitCheck()
{
	// �v���C���[�Ƃ̓����蔻��
	if (player.CheckCollision(bullet) == true)
	{
		color = 0xff0000;

		// �_���[�W����
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

	// �G�Ƃ̓����蔻��
	if (enemy->CheckCollision(bullet) == true)
	{
		color = 0x0000ff;

		// �_���[�W����
		enemy->Hit(bullet->GetDamage());
		
		//bullet = nullptr;
	}
}

// �e�̔z��ɐV�����f�[�^���쐬����
void GameMainScene::SpawnBullet()
{

}