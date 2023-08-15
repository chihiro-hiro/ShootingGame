#pragma once

// 当たり判定用のクラス
class SphereCollider
{
private:
	//float radius;

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

	//float location;				// 中心座標　x,yが必要
	Location location;			// 中心座標
	float radius;				// 半径
};