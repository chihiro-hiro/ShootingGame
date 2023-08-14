#include "SceneBase.h"

// 更新処理
AbstractScene* SceneBase::Update()
{
	AbstractScene* p = mScene->Update();

	if (p != mScene)
	{
		delete mScene;
		mScene = p; // 次に表示したいシーン
	};

	return p;
}

// 描画処理
void SceneBase::Draw() const
{
	mScene->Draw();
}