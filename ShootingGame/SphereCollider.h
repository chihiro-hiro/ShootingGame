#pragma once

// �����蔻��p�̃N���X
class SphereCollider
{
private:
	float location;				// ���S���W�@x,y���K�v
	float radius;

public:
	SphereCollider();			// �R���X�g���N�^
	~SphereCollider();			// �f�X�g���N�^
	bool CheckCollision(SphereCollider* collider);
};