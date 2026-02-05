#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { Max = 1001 };
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t N;
	std::cin >> N;
	std::array<int32_t, Max> Arr = { 0 };
	std::array<int32_t, Max> DP[2] = { 0 };

	for (int32_t i = 1; i <= N; ++i)
		std::cin >> Arr[i];

	// Up
	// UpDown
	DP[0][1] = 1;
	DP[1][1] = 1;

	int32_t Max = 1;
	for (int32_t i = 2; i <= N; ++i)
	{
		for (int32_t j = i - 1; j >= 1; --j)
		{
			if (Arr[j] < Arr[i])
				DP[0][i] = std::max<int32_t>(DP[0][i], DP[0][j] + 1);
			else if (Arr[j] > Arr[i])
			{
				DP[1][i] = std::max<int32_t>(DP[1][i], DP[0][j] + 1);
				DP[1][i] = std::max<int32_t>(DP[1][i], DP[1][j] + 1);
			}
			else
			{
				DP[0][i] = std::max<int32_t>(DP[0][i], DP[0][j]);
				DP[1][i] = std::max<int32_t>(DP[1][i], DP[1][j]);
			}
			DP[0][i] = std::max<int32_t>(DP[0][i], 1);
			DP[1][i] = std::max<int32_t>(DP[1][i], 1);
		}
		Max = std::max<int32_t>(Max, DP[0][i]);
		Max = std::max<int32_t>(Max, DP[1][i]);
	}
	std::cout << Max;
}