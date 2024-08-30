#include "stdafx.h"
#include "CharacterMove.h"

CharacterMove::CharacterMove(int initialX, int initialY)
	: collider(initialX, initialY, 7) // コライダーの初期化
{
	x = initialX;
	y = initialY;
}

void CharacterMove::MoveUp()
{
	collider.y -= 1;
}

void CharacterMove::MoveLeft()
{
	collider.x -= 1;
}

void CharacterMove::MoveRight()
{
	collider.x += 1;
}

void CharacterMove::MoveDown()
{
	collider.y += 1;
}

Vec2 CharacterMove::GetPosition() const
{
	return collider.center;
}

void CharacterMove::SetPosition(int newX, int newY)
{
	collider.setPos(newX, newY);
}

Circle CharacterMove::GetCollider() const
{
	return collider;
}


