#include "SceneBase.h"

// �X�V����
AbstractScene* SceneBase::Update()
{
	AbstractScene* p = mScene->Update();

	if (p != mScene)
	{
		delete mScene;
		mScene = p; // ���ɕ\���������V�[��
	};

	return p;
}

// �`�揈��
void SceneBase::Draw() const
{
	mScene->Draw();
}