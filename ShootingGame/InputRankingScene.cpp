#include "DxLib.h"
#include "InputControl.h"
#include "InputRankingScene.h"
#include "RankingScene.h"

// �R���X�g���N�^
InputRankingScene::InputRankingScene()
{

}

// �f�X�g���N�^
InputRankingScene::~InputRankingScene()
{

}

// �X�V����
AbstractScene* InputRankingScene::Update()
{
	// ����{�^���������ꂽ
	return new RankingScene;

	//return this;
}

// �`�揈��
void InputRankingScene::Draw() const
{
	// �f�o�b�O
#if _DEBUG
	DrawFormatString(0, 0, 0xffffff, "�����L���O�o�^");
#endif	//_DEBUG
}