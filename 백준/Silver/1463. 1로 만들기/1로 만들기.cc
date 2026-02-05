#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum {Max = 1000001};
uint16_t DP[Max];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t N;
	std::cin >> N;
	std::fill(DP, DP + Max, USHRT_MAX);
	DP[1] = 0;
	for (int32_t i = 1; i <= N; ++i)
	{
		int32_t _3 = i * 3;
		int32_t _2 = i * 2;
		int32_t _1 = i + 1;
		if (_3 <= N)
			DP[_3] = std::min<uint16_t>(DP[i] + 1, DP[_3]);
		if (_2 <= N)
			DP[_2] = std::min<uint16_t>(DP[i] + 1, DP[_2]);
		if (_1 <= N)
			DP[_1] = std::min<uint16_t>(DP[i] + 1, DP[_1]);
	}
	std::cout << DP[N];
}