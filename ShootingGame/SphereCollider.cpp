#include "DxLib.h"
#include "SphereCollider.h"

// �R���X�g���N�^
SphereCollider::SphereCollider()
{
    location = 0.0f;
    radius = 0.0f;
}

// �f�X�g���N�^
SphereCollider::~SphereCollider()
{

}

bool SphereCollider::CheckCollision(SphereCollider* collider)
{
    return false;
}