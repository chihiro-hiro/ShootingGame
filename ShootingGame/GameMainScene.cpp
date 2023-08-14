#include "DxLib.h"
#include "GameMainScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"

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

// �����蔻��̃`�F�b�N
void GameMainScene::HitCheck()
{

}

// �e�̔z��ɐV�����f�[�^���쐬����
void GameMainScene::SpawnBullet()
{

}

// �X�V����
AbstractScene* GameMainScene::Update()
{
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
	DrawFormatString(0, 0, 0xffffff, "�Q�[�����C��");
#endif	//_DEBUG

	// �v���C���[�̕`�揈��
	player.Draw();

	// �G�l�~�[�̕`�揈��
	enemy->Draw();

	// �e�̕`�揈��
	bullet->Draw();
}