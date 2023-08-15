#pragma once
#include "SphereCollider.h"

class CharaBase : public SphereCollider
{
protected:
	float speed;
	int image;

public:
	CharaBase();					// コンストラクタ
	~CharaBase();					// デストラクタ
	virtual void Update();			// 更新処理		// 引数にゲームメインシーンのポインタ
	virtual void Draw() const;		// 描画処理
	virtual void Hit(int damage);	// ダメージ処理
};