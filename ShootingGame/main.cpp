#include "DxLib.h"
#include "Fps.h"
#include "InputControl.h"
#include "SceneBase.h"
#include "TitleScene.h"
#include "GameMainScene.h"

// ���C���֐�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lPcmdLine, _In_ int nCmdShow)
{
	SetMainWindowText("ShootingGame");			// �E�B���h�E�^�C�g����ݒ�

	ChangeWindowMode(TRUE);						// �E�C���h�E���[�h�ŋN��

	SetGraphMode(1280, 720, 32);				// �E�C���h�E�̃T�C�Y

	// DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// �`���̎w��i����ʂ���J�n����j
	SetDrawScreen(DX_SCREEN_BACK);

	// �^�C�g�� �V�[���I�u�W�F�N�g�쐬
	//SceneBase* sceneBase = new SceneBase((AbstractScene*) new TitleScene());#if _DEBUG

	// �f�o�b�O
#if _DEBUG
	// �Q�[�����C���e�X�g�p
	SceneBase* sceneBase = new SceneBase((AbstractScene*) new GameMainScene());
#endif	//_DEBUG

	Fps fps;
	
	// ���C�����[�v
	// ESC�ŏI��
	// �̂���back�{�^���ɕύX
	while (ProcessMessage() != -1 && sceneBase->Update() != nullptr && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// ��ʂ̏�����
		ClearDrawScreen();

		// ���͑���̍X�V����
		InputControl::Update();
		
		// �V�[���̕`��J�n
		sceneBase->Draw();

		fps.Update();
		fps.Draw();

		// BACK�{�^���ŋ����I��
		if (InputControl::OnButton(XINPUT_BUTTON_BACK))
		{
			break;
		}

		// ����ʂ̓��e��\��ʂɔ��f����
		ScreenFlip();

		fps.Wait();
	}

	// DX���C�u�����g�p�̏I������
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}