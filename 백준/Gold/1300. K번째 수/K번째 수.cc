#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

int32_t N, K;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> K;

	size_t Left = 1;
	size_t Right = K;
	size_t Min = K;
	while (Left <= Right)
	{
		size_t Mid = (Left + Right) / 2;
		size_t Cnt = 0;

		for (size_t i = 1; i <= N; ++i)
			Cnt += std::min<size_t>(N, Mid / i);

		if (Cnt >= K)
		{
			Right = Mid - 1;
			Min = std::min<size_t>(Min, Mid);
		}
		else
			Left = Mid + 1;
			
	}
	std::cout << Min;
}