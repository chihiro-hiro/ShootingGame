#include "DxLib.h"
#include "InputControl.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "RankingScene.h"

// �R���X�g���N�^
TitleScene::TitleScene()
{

}

// �f�X�g���N�^
TitleScene::~TitleScene()
{

}

// �X�V����
AbstractScene* TitleScene::Update()
{
	// A�{�^���ŃQ�[�����C���֑J��
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		return new GameMainScene();
	}

	// �Q�[�����C�����I�����ꂽ
	//return new GameMainScene();

	// �����L���O��ʂ��I�����ꂽ
	//return new RankingScene();
	
	return this;
}

// �`�揈��
void TitleScene::Draw() const
{
	// �f�o�b�O
#if _DEBUG
	DrawFormatString(50, 0, 0xffffff, "�^�C�g��");
	DrawFormatString(200, 0, 0xffffff, "A : �Q�[�����C��");
#endif	//_DEBUG
}