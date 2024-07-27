#pragma once
#include <Siv3D.hpp>
#include <vector>
class MazeGenerator
{
public:
	MazeGenerator(int width, int height);

	void generate();
	void draw() const;

private:
	void backtrack(int x, int y);
	void removeDeadEnds(); // 行き止まりを排除する関数

	int width;
	int height;
	std::vector<std::vector<bool>> maze; // 2次元配列をstd::vectorで定義
};
