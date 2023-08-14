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
	// �Q�[�����C�����I�����ꂽ
	return new GameMainScene;

	// �����L���O��ʂ��I�����ꂽ
	//return new RankingScene;
	
	//return this;
}

// �`�揈��
void TitleScene::Draw() const
{
	// �f�o�b�O
#if _DEBUG
	DrawFormatString(0, 0, 0xffffff, "�^�C�g��");
#endif	//_DEBUG
}