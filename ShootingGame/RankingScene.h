#pragma once
#include "AbstractScene.h"

#define RANK_MAX (5)			// �����L���O�͏��5�ʂ܂�
#define NAME_MAX (11)			// ���O�̃T�C�Y

class RankingScene : public AbstractScene
{
public:
	RankingScene();						// �R���X�g���N�^
	~RankingScene();					// �f�X�g���N�^
	AbstractScene* Update() override;	// �X�V����
	void Draw() const override;			// �`�揈��

public:
	//�����L���O�f�[�^
	typedef struct
	{
		int no;						// ����
		char name[NAME_MAX];		// ���O�@10Byte
		long score;					// �X�R�A
	} RankingData;

	RankingData		Ranking[RANK_MAX];

};