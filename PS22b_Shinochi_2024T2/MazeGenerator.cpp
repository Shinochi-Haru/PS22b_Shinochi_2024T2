﻿#include "stdafx.h"
#include "MazeGenerator.h"



MazeGenerator::MazeGenerator(int width, int height)
	: width(width), height(height), maze(height, std::vector<bool>(width, true)) // mazeの初期化を修正
{
	// 壁と通路の初期化
	for (auto& row : maze) std::fill(row.begin(), row.end(), true);
}

void MazeGenerator::generate()
{
	// スタート位置を選択し、バックトラッキングを開始
	backtrack(1, 1);
}

void MazeGenerator::backtrack(int x, int y)
{
	// 現在位置を通路とする
	maze[y][x] = false;

	// 移動可能な方向をシャッフル
	Array<Vec2> directions = { Vec2(0, 1), Vec2(1, 0), Vec2(0, -1), Vec2(-1, 0) };
	Shuffle(directions);

	// 移動可能な方向に対してバックトラッキング
	for (const auto& d : directions)
	{
		int nx = x + d.x * 2;
		int ny = y + d.y * 2;

		if (InRange(ny, 1, height - 2) && InRange(nx, 1, width - 2) && maze[ny][nx])
		{
			maze[y + d.y][x + d.x] = false; // 壁を取り除く
			backtrack(nx, ny); // 新しい位置から再帰的にバックトラッキング
		}
	}
}

void MazeGenerator::draw() const
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			if (maze[y][x]) // 壁のセルは黒で描画
			{
				Rect(x * 20, y * 20, 20, 20).draw(Palette::Black);
			}
		}
	}
}
