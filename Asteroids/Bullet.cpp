#include "Bullet.h"
#include "Graphics.h"
#include "ImmediateMode.h"
#include "ImmediateModeVertex.h"

Bullet::Bullet(XMVECTOR position,
	XMVECTOR direction,
	int weaponType)
{
	currentdistance = 0;
	disable = false;

	if (weaponType == 1)
	{
		bulletSpeed = 4.0f;
		maxRange = 250.0f;
		bulletRadius = 3.0f;
	}
	if (weaponType == 2)
	{
		bulletSpeed = 7.0f;
		maxRange = 175.0f;
		bulletRadius = 1.5f;
	}
	if (weaponType == 3)
	{
		bulletSpeed = 2.0f;
		maxRange = 400.0f;
		bulletRadius = 5.0f;
	}

	SetPosition(position);
	XMVECTOR normalisedDirection = XMVector3Normalize(direction);
	XMStoreFloat3(&velocity_, normalisedDirection * bulletSpeed);
}

void Bullet::Update(System *system)
{
	XMVECTOR positionA = GetPosition();
	XMVECTOR positionB;
	XMVECTOR diff;
	positionB = XMVectorAdd(positionA, XMLoadFloat3(&velocity_));
	diff = positionB - positionA;
	currentdistance += sqrtf(XMVectorGetX(XMVector2Dot(diff, diff)));
	SetPosition(positionB);
	if (currentdistance > maxRange)
	{
		disable = true;
	}
}

void Bullet::Render(Graphics *graphics) const
{

	ImmediateModeVertex square[5] =
	{
		{-bulletRadius, -bulletRadius, 0.0f, 0xffffffff},
		{-bulletRadius, bulletRadius, 0.0f, 0xffffffff},
		{ bulletRadius,  bulletRadius, 0.0f, 0xffffffff},
		{ bulletRadius, -bulletRadius, 0.0f, 0xffffffff},
		{-bulletRadius, -bulletRadius, 0.0f, 0xffffffff},
	};

	XMVECTOR position = GetPosition();
	XMMATRIX translationMatrix = XMMatrixTranslation(
		XMVectorGetX(position),
		XMVectorGetY(position),
		XMVectorGetZ(position));

	ImmediateMode *immediateGraphics = graphics->GetImmediateMode();

	immediateGraphics->SetModelMatrix(translationMatrix);
	immediateGraphics->Draw(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP,
		&square[0],
		5);
	immediateGraphics->SetModelMatrix(XMMatrixIdentity());
}
