#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { Max = 125 };
struct TVertex
{
	int32_t X;
	int32_t Y;
	int32_t Coin;
};
bool operator < (const TVertex& InA, const TVertex& InB)
{
	return InA.Coin > InB.Coin;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t C = 0;
	while (true)
	{
		int32_t N;
		int32_t Coins[Max][Max] = { 0 };
		int32_t Result[Max][Max] = { 0 };

		std::cin >> N;
		if (N == 0)
			break;
		for (int32_t i = 0; i < N; ++i)
			for (int32_t j = 0; j < N; ++j)
				Result[i][j] = INT_MAX;

		for (int32_t i = 0; i < N; ++i)
			for (int32_t j = 0; j < N; ++j)
				std::cin >> Coins[i][j];

		std::priority_queue<TVertex> Vertices;
		Result[0][0] = Coins[0][0];
		Vertices.emplace(0, 0, Coins[0][0]);
		while (Vertices.empty() == false)
		{
			TVertex Vertex = Vertices.top();
			Vertices.pop();

			int32_t X = Vertex.X;
			int32_t Y = Vertex.Y;
			int32_t Coin = Vertex.Coin;

			if (Coin > Result[Y][X])
				continue;

			int32_t Xs[] = { -1,0,1,0 };
			int32_t Ys[] = { 0,-1,0,1 };
			for (int32_t i = 0; i < 4; ++i)
			{
				int32_t NextX = X + Xs[i];
				int32_t NextY = Y + Ys[i];
				if (NextX < 0 || NextX >= N || NextY < 0 || NextY >= N)
					continue;

				int32_t NextCoin = Result[Y][X] + Coins[NextY][NextX];
				if (Result[NextY][NextX] <= NextCoin)
					continue;

				Result[NextY][NextX] = NextCoin;
				Vertices.emplace(NextX, NextY, NextCoin);
			}
		}
		std::cout << "Problem " << ++C << ": " << Result[N - 1][N - 1] << '\n';
	}
}