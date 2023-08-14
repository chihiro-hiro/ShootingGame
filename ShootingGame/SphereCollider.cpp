#include "DxLib.h"
#include "SphereCollider.h"

// コンストラクタ
SphereCollider::SphereCollider()
{
    location = 0.0f;
    radius = 0.0f;
}

// デストラクタ
SphereCollider::~SphereCollider()
{

}

bool SphereCollider::CheckCollision(SphereCollider* collider)
{
    return false;
}