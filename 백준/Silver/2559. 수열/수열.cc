#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { Max = 100001 };

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t N, K;
	std::cin >> N >> K;

	std::array<int32_t, Max> Arr;
	for (int32_t i = 0; i < N; ++i)
		std::cin >> Arr[i];

	int32_t Sum = 0;
	for (int32_t i = 0; i < K; ++i)
		Sum += Arr[i];

	int32_t Max = Sum;
	for (int32_t i = K; i < N; ++i)
	{
		Sum += Arr[i] - Arr[i - K];
		Max = std::max<int32_t>(Max, Sum);
	}
	std::cout << Max;
}