#pragma once
#include "SphereCollider.h"

class CharaBase : public SphereCollider
{
private:
	float speed;
	int image;

public:
	CharaBase();					// コンストラクタ
	~CharaBase();					// デストラクタ
	virtual void Update();			// 更新処理
	virtual void Draw() const;		// 描画処理
	virtual void Hit();				// ダメージ処理
};