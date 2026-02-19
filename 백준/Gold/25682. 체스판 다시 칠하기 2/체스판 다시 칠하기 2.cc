#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { Max = 2001 };
char Board[Max][Max] = { 0 };
int32_t ChessB[Max][Max];
int32_t ChessW[Max][Max];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t N, M, K;
	std::cin >> N >> M >> K;

	for (int32_t i = 1; i <= N; ++i)
	{
		for (int32_t j = 1; j <= M; ++j)
		{
			std::cin >> Board[i][j];
			ChessW[i][j] = ChessW[i][j - 1] + ChessW[i - 1][j] - ChessW[i - 1][j - 1];
			ChessB[i][j] = ChessB[i][j - 1] + ChessB[i - 1][j] - ChessB[i - 1][j - 1];
			int32_t V = (i + j) % 2;
			if (V == 1)
			{
				if (Board[i][j] == 'B')
					ChessB[i][j] += 1;
				else
					ChessW[i][j] += 1;
			}
			else
			{
				if (Board[i][j] == 'W')
					ChessB[i][j] += 1;
				else
					ChessW[i][j] += 1;
			}
		}
	}
	int32_t Min = INT_MAX;
	for (int32_t i = K; i <= N; ++i)
	{
		for (int32_t j = K; j <= M; ++j)
		{
			Min = std::min<int32_t>(Min, ChessW[i][j] - (ChessW[i - K][j] + ChessW[i][j - K] - ChessW[i - K][j - K]));
			Min = std::min<int32_t>(Min, ChessB[i][j] - (ChessB[i - K][j] + ChessB[i][j - K] - ChessB[i - K][j - K]));
		}
	}
	std::cout << Min;
}