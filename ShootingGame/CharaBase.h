#pragma once
#include "SphereCollider.h"

class GameMainScene;

class CharaBase : public SphereCollider
{
protected:
	float speed;
	int image;
	bool isEnemy;

public:
	CharaBase();					// コンストラクタ
	~CharaBase();					// デストラクタ
	virtual void Update(GameMainScene* gamemain);			// 更新処理		// 引数にゲームメインシーンのポインタ
	virtual void Draw() const;		// 描画処理
	virtual void Hit(int damage);	// ダメージ処理
};