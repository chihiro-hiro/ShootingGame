#include "DxLib.h"
#include "SphereCollider.h"

// コンストラクタ
SphereCollider::SphereCollider()
{
    location.x = 0.0f;
    location.y = 0.0f;
    radius = 0.0f;
}

// デストラクタ
SphereCollider::~SphereCollider()
{

}

// 円同士の当たり判定
bool SphereCollider::CheckCollision(SphereCollider* collider)
{
    // 円１
    float circle1_x = location.x;
    float circle1_y = location.y;
    float circle1_radius = radius;

    // 円２
    float circle2_x = collider->location.x;
    float circle2_y = collider->location.y;
    float circle2_radius = collider->radius;

    // 当たり判定用の計算
    float circle3_x = location.x - collider->location.x;
    float circle3_y = location.y - collider->location.y;
    float circle3 = circle3_x * circle3_x + circle3_y * circle3_y;
    float circle3_radius = radius + collider->radius;

    if (circle3 <= circle3_radius * circle3_radius)
    {
        return true;
    }

    return false;
}