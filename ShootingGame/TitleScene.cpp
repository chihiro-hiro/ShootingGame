#include "DxLib.h"
#include "InputControl.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "RankingScene.h"

// �R���X�g���N�^
TitleScene::TitleScene()
{
	menu_number = 0;		// ���j���[�I��
	menu_y = 0;				// �J�[�\����Y���W
	input_flg = FALSE;
}

// �f�X�g���N�^
TitleScene::~TitleScene()
{

}

// �X�V����
AbstractScene* TitleScene::Update()
{
	// �㉺�ړ�
	if (0.4f < InputControl::TipLeftLStick(STICKL_Y))
	{

		if (--menu_number < 0)
		{
			menu_number = 1;
		}
	}
	else if (InputControl::TipLeftLStick(STICKL_Y) < -0.4f)
	{
		if (++menu_number > 1)
		{
			menu_number = 0;
		}
	}

	//if (input_flg == FALSE)
	//{
	//	if (0.4f < InputControl::TipLeftLStick(STICKL_Y))
	//	{
	//		input_flg = TRUE;
	//		if (--menu_number < 0)
	//		{
	//			menu_number = 1;
	//		}
	//	}
	//	else if (InputControl::TipLeftLStick(STICKL_Y) < -0.4f)
	//	{
	//		input_flg = TRUE;
	//		if (++menu_number > 1)
	//		{
	//			menu_number = 0;
	//		}
	//	}
	//	else
	//	{
	//		input_flg = FALSE;
	//	}
	//}

	// �J�[�\���ʒu�̍X�V
	menu_y = menu_number * 52;

	// A�{�^���ŉ�ʑJ��
	if (InputControl::OnButton(XINPUT_BUTTON_A) == 1)
	{
		if (menu_number == 0)
		{
			return new GameMainScene();
		}
		else if (menu_number == 1)
		{
			return new RankingScene();
		}
	}
	
	return this;
}

// �`�揈��
void TitleScene::Draw() const
{
	// �f�o�b�O
#if _DEBUG
	SetFontSize(10);
	DrawFormatString(50, 0, 0xffffff, "�^�C�g��");
#endif	//_DEBUG

	//SetFontSize(100);
	//DrawFormatString(350, 150, 0xffffff, "Shooting Game");

	//SetFontSize(70);
	//DrawFormatString(550, 400, 0xffffff, "Start");
	//DrawFormatString(550, 500, 0xffffff, "Ranking");

	//// �J�[�\���̕`��
	//DrawTriangle(240, 300 + menu_y, 260, 315 + menu_y, 240, 330 + menu_y, 0xff0000, TRUE);
}