#pragma once

// 当たり判定用のクラス
class SphereCollider
{
public:
	SphereCollider();			// コンストラクタ
	~SphereCollider();			// デストラクタ
	bool CheckCollision(SphereCollider* collider);		// 円同士の当たり判定

protected:
	struct Location				//中心座標
	{
		float x;
		float y;
	};

	Location location;			// 中心座標
	float radius;				// 半径
};