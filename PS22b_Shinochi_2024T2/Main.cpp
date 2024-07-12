# include <Siv3D.hpp>
# include "CharacterMove.h"
#include "MazeGenerator.h"
//パックマン風のゲームを作成
void Main()
{
	CharacterMove character(250, 500);

	// 500x1000ピクセルのウィンドウを作成
	Window::Resize(500, 1000);

	// 25x50セルの迷路を作成
	MazeGenerator maze(25, 50);

	// 迷路を生成
	maze.generate();

	while (System::Update())
	{
		//キャラクターの位置取得
		Vec2 character_position = character.GetPosition();
		//キャラの描画
		Circle(character_position, 10).draw();

		// キーボードの入力に応じてキャラクターを動かす
		if (KeyW.pressed()) character.MoveUp();
		if (KeyS.pressed()) character.MoveDown();
		if (KeyA.pressed()) character.MoveLeft();
		if (KeyD.pressed()) character.MoveRight();

		// 迷路を描画
		maze.draw();
	}
}
