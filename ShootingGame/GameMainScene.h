#pragma once
//#include "SceneBase.h"
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

#define ENEMY_NUM	(10)				// �G�̍ő吔
#define BULLET_NUM	(100)				// �e�̍ő吔
#define STEGE_MAX	(3)					// �X�e�[�W�̍ő吔

class GameMainScene : public AbstractScene
{
private:
	Player player;						// Player�̃I�u�W�F�N�g��
	int life;							// �c�@
	Enemy* enemy[ENEMY_NUM];			// Enemy�̃|�C���^�z��
	Bullet* bullet[BULLET_NUM];			// Bullet�̃|�C���^�z��
	int livingEnemies;					// �����Ă���G�̐�
	int stageNum;						// �X�e�[�W��
	int waitTime;						// �X�e�[�W�J�ڎ��̑҂�����
	bool isClear;
	int timeLimit;						// ��������
	int fpsCount;

public:
	GameMainScene();					// �R���X�g���N�^
	~GameMainScene();					// �f�X�g���N�^
	AbstractScene* Update() override;	// �X�V����
	void Draw() const override;			// �`�揈��

	void HitCheck();					// �����蔻��̃`�F�b�N
	void SpawnBullet(float x, float y, bool is_enemy);					// �e�̔z��ɐV�����f�[�^���쐬����
	void ChangeStage();
};