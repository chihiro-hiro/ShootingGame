#include "DxLib.h"
#include "SphereCollider.h"

// �R���X�g���N�^
SphereCollider::SphereCollider()
{
    //location = 0.0f;
    radius = 0.0f;
}

// �f�X�g���N�^
SphereCollider::~SphereCollider()
{

}

// �~���m�̓����蔻��
bool SphereCollider::CheckCollision(SphereCollider* collider)
{
    // �~�P
    float circle1_x = location.x;
    float circle1_y = location.y;
    float circle1_radius = radius;

    // �~�Q
    float circle2_x = collider->location.x;
    float circle2_y = collider->location.y;
    float circle2_radius = collider->radius;

    // �����蔻��p�̌v�Z
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