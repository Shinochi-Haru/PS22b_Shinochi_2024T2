#pragma once
# include <Siv3D.hpp>
class CharacterMove
{
private:
	int x, y;
public:
	//コンストラクタ
	CharacterMove(int initialX, int initialY);

	//移動の関数たち
	void MoveUp();
	void MoveLeft();
	void MoveRight();
	void MoveDown();

	// キャラクターの位置を取得する関数
	Vec2 GetPosition() const;
};

