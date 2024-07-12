#include "stdafx.h"
#include "CharacterMove.h"

CharacterMove::CharacterMove(int initialX, int initialY)
{
	x = initialX;
	y = initialY;
}

void CharacterMove::MoveUp()
{
	y += -1;
}

void CharacterMove::MoveLeft()
{
	x += -1;
}

void CharacterMove::MoveRight()
{
	x += 1;
}

void CharacterMove::MoveDown()
{
	y += 1;
}

Vec2 CharacterMove::GetPosition() const
{
	return Vec2(x, y);
}
