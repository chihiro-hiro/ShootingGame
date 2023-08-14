#pragma once

// 当たり判定用のクラス
class SphereCollider
{
private:
	float location;				// 中心座標　x,yが必要
	float radius;

public:
	SphereCollider();			// コンストラクタ
	~SphereCollider();			// デストラクタ
	bool CheckCollision(SphereCollider* collider);
};