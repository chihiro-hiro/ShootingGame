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
	Player player;						// Player�̃I�u�W�F�N�g��
	int life;							// �c�@
	Enemy* enemy;						// Enemy�̃|�C���^�z��
	Bullet* bullet[BULLET_NUM];			// Bullet�̃|�C���^�z��

public:
	GameMainScene();					// �R���X�g���N�^
	~GameMainScene();					// �f�X�g���N�^
	AbstractScene* Update() override;	// �X�V����
	void Draw() const override;			// �`�揈��

	void HitCheck();					// �����蔻��̃`�F�b�N
	void SpawnBullet(float x, float y, bool is_enemy);					// �e�̔z��ɐV�����f�[�^���쐬����
};