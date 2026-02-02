#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	size_t N, K;
	std::cin >> N >> K;

	size_t Left = 1;
	size_t Right = N * N;
	while (Left <= Right)
	{
		size_t Mid = (Left + Right) / 2;
		size_t Count = 0;
		for (int32_t i = 1; i <= N; ++i)
			Count += std::min(Mid / i, N);

		if (Count >= K)
			Right = Mid - 1;
		else
			Left = Mid + 1;
	}
	std::cout << Left;
}