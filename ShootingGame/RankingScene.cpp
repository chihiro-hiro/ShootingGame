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
	//return new TitleScene();

	return this;
}

// �`�揈��
void RankingScene::Draw() const
{
	// �f�o�b�O
#if _DEBUG
	DrawFormatString(50, 0, 0xffffff, "�����L���O�\��");
#endif	//_DEBUG
}