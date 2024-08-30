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
	// 500x1000ピクセルのウィンドウを作成
	Window::Resize(500, 1000);

	// 25x50セルの迷路を作成
	MazeGenerator maze(50, 100);

	// 迷路を生成
	maze.generate();
	// キャラクターを迷路の通路の中央にスポーンさせる
	Vec2 spawnPosition{};
	for (int y = 1; y < maze.getHeight() - 1; ++y)
	{
		for (int x = 1; x < maze.getWidth() - 1; ++x)
		{
			if (!maze.isWall(x, y))
			{
				spawnPosition = Vec2(x * 20 + 10, y * 20 + 10); // 通路の中央にスポーン
				break;
			}
		}
		if (spawnPosition != Vec2(0, 0))
		{
			break;
		}
	}

	CharacterMove character(spawnPosition.x, spawnPosition.y);
	Vec2 cameraPosition = character.GetPosition();
	while (System::Update())
	{
		// キャラクターの現在位置を取得
		Vec2 character_position = character.GetPosition();
		Vec2 new_position = character_position;

		// キーボードの入力に応じてキャラクターを動かす
		if (KeyW.pressed()) new_position.y -= 1;
		if (KeyS.pressed()) new_position.y += 1;
		if (KeyA.pressed()) new_position.x -= 1;
		if (KeyD.pressed()) new_position.x += 1;

		// キャラクターのコライダーを取得
		Circle newCollider(new_position, 7);

		// 壁のコライダーを取得
		Array<RectF> wallColliders = maze.GetWallColliders();

		// 壁との衝突をチェック
		bool collision = false;
		for (const auto& wallCollider : wallColliders)
		{
			if (newCollider.intersects(wallCollider))
			{
				collision = true;
				break;
			}
		}

		if (!collision)
		{
			character.SetPosition(new_position.x, new_position.y);
		}
		else
		{
			// 壁に当たった場合、移動をキャンセル
			if (KeyW.pressed()) character.MoveDown();
			if (KeyS.pressed()) character.MoveUp();
			if (KeyA.pressed()) character.MoveRight();
			if (KeyD.pressed()) character.MoveLeft();
		}

		// キャラクターの位置取得
		character_position = character.GetPosition();

		// カメラをキャラクターの位置に追従させる
		Vec2 cameraPosition = character_position;

		// カメラをキャラクターの位置に追従させる
		const Transformer2D t(Mat3x2::Translate(Scene::Center() - cameraPosition));

		//キャラの描画
		//Circle(character_position, 7).draw();
		character.GetCollider().draw(Palette::Red);
		// 迷路を描画
		maze.draw();
	}
}
