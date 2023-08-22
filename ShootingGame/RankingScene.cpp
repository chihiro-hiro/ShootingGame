#include "DxLib.h"
#include "InputControl.h"
#include "RankingScene.h"
#include "TitleScene.h"

// �R���X�g���N�^
RankingScene::RankingScene()
{

}

// �f�X�g���N�^
RankingScene::~RankingScene()
{

}

// �X�V����
AbstractScene* RankingScene::Update()
{
	// �{�^���������ꂽ��
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		return new TitleScene();
	}

	return this;
}

// �`�揈��
void RankingScene::Draw() const
{
	// �f�o�b�O
#if _DEBUG
	DrawFormatString(50, 0, 0xffffff, "�����L���O�\��");
#endif	//_DEBUG

	// �X�y�[�X�L�[�Ń��j���[�ɖ߂�
	//if (g_KeyFlg & PAD_INPUT_M) g_GameState = 0;

	// �����L���O�ꗗ��\��
	SetFontSize(30);
	for (int i = 0; i < RANK_MAX; i++) {
		DrawFormatString(80, 170 + i * 25, 0xFFFFFF, "%2d	%10s	%10d",
			Ranking[i].no, Ranking[i].name, Ranking[i].score);
	}

	SetFontSize(30);
	DrawFormatString(550, 600, 0xffffff, "A : �^�C�g��");

}