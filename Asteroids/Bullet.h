#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "GameEntity.h"

class Bullet : public GameEntity
{
public:
	Bullet(XMVECTOR position,
		XMVECTOR direction,
		int weaponType);

	void Update(System *system);
	void Render(Graphics *graphics) const;

	bool disable;
	float bulletSpeed;
	float maxRange;
	float bulletRadius;

private:

	XMFLOAT3 velocity_;
	float currentdistance;
};

#endif // BULLET_H_INCLUDED
