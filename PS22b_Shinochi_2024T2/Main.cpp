# include <Siv3D.hpp>
# include "CharacterMove.h"
#include "MazeGenerator.h"
//パックマン風のゲームを作成
//Vec2 Slerp(Vec2 start, Vec2 end, double percent)
//{
//	double dot = start.dot(end);
//	Clamp(dot, -1.0, 1.0);
//	double theta = acos(dot) * percent;
//	Vec2 relativeVec = end - start * dot;
//	relativeVec.normalize(); // Orthonormal basis
//	return ((start * cos(theta)) + (relativeVec * sin(theta)));
//}

void Main()
{
	CharacterMove character(250, 500);

	// 500x1000ピクセルのウィンドウを作成
	Window::Resize(500, 1000);

	// 25x50セルの迷路を作成
	MazeGenerator maze(50, 100);

	// 迷路を生成
	maze.generate();
	Vec2 cameraPosition = character.GetPosition();
	while (System::Update())
	{
		// キーボードの入力に応じてキャラクターを動かす
		if (KeyW.pressed()) character.MoveUp();
		if (KeyS.pressed()) character.MoveDown();
		if (KeyA.pressed()) character.MoveLeft();
		if (KeyD.pressed()) character.MoveRight();

		// キャラクターの位置取得
		Vec2 character_position = character.GetPosition();

		// カメラをキャラクターの位置に追従させる
		Vec2 cameraPosition = character_position;

		// カメラをキャラクターの位置に追従させる
		const Transformer2D t(Mat3x2::Translate(Scene::Center() - cameraPosition));

		//キャラの描画
		Circle(character_position, 10).draw();

		// 迷路を描画
		maze.draw();
	}
}
