#include"DxLib.h"

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

	// �ϐ���`
	//SceneManager scenManager(dynamic_cast<AbstractScene*>(new TitleScene));

	// ���C�����[�v
	while (ProcessMessage() != -1)
	{
		//// ���͑���̍X�V����
		//InputControl::Update();

		//scenManager.Update();
		//scenManager.Draw();
		//if (scenManager.Change() == nullptr)
		//{
		//	break;
		//}

		ScreenFlip(); // ����ʂ̓��e��\��ʂɔ��f����

	}

	// DX���C�u�����g�p�̏I������
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}
