#pragma once
#include <Siv3D.hpp>
#include <vector>
class MazeGenerator
{
public:
	MazeGenerator(int width, int height);

	void generate();
	void draw() const;

	// 壁との当たり判定を行う関数
	bool isWall(int x, int y) const;

	// 迷路の幅と高さを取得する関数
	int getWidth() const;
	int getHeight() const;

	// 壁のコライダーを取得する関数
	Array<RectF> GetWallColliders() const;

private:
	void backtrack(int x, int y);
	void removeDeadEnds(); // 行き止まりを排除する関数
	void surroundWithWalls(); // 迷路の周りを壁で囲む関数

	int width;
	int height;
	std::vector<std::vector<bool>> maze; // 2次元配列をstd::vectorで定義
};
