#pragma once

// �����蔻��p�̃N���X
class SphereCollider
{
private:
	//float radius;

public:
	SphereCollider();			// �R���X�g���N�^
	~SphereCollider();			// �f�X�g���N�^
	bool CheckCollision(SphereCollider* collider);		// �~���m�̓����蔻��

protected:
	struct Location				//���S���W
	{
		float x;
		float y;
	};

	//float location;				// ���S���W�@x,y���K�v
	Location location;			// ���S���W
	float radius;				// ���a
};