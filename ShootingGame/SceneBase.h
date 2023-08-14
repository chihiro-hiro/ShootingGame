#pragma once
#include "AbstractScene.h"

class SceneBase : public AbstractScene
{
private:
	AbstractScene* mScene; // 現在のシーン

public:
	// コンストラクタ
	SceneBase(AbstractScene* scene) : mScene(scene) {}

	// デストラクタ
	~SceneBase()
	{
		delete mScene;
	};

	// 描画以外の更新を実装
	AbstractScene* Update() override;

	// 描画に関することを実装
	void Draw() const override;
};