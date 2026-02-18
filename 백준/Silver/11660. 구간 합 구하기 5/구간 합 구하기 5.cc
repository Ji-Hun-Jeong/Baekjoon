#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { Max = 1025 };
int32_t Sums[Max][Max] = { 0 };
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t N, M;
	std::cin >> N >> M;


	for (int32_t i = 1; i <= N; ++i)
	{
		for (int32_t j = 1; j <= N; ++j)
		{
			std::cin >> Sums[i][j];
			Sums[i][j] += Sums[i - 1][j] + Sums[i][j - 1] - Sums[i - 1][j - 1];
		}
	}
	
	for (int32_t i = 0; i < M; ++i)
	{
		int32_t x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		int32_t Sum = Sums[x2][y2] - (Sums[x2][y1 - 1] + Sums[x1 - 1][y2] - Sums[x1 - 1][y1 - 1]);
		std::cout << Sum << '\n';
	}
}