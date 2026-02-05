#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum {Max = 301};
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t N;
	std::cin >> N;
	int32_t Arr[Max] = { 0 };
	int32_t DP[Max] = { 0 };

	for (int32_t i = 1; i <= N; ++i)
		std::cin >> Arr[i];

	DP[1] = Arr[1];
	DP[2] = Arr[1] + Arr[2];

	for (int32_t i = 3; i <= N; ++i)
		DP[i] = std::max<int32_t>(DP[i - 2], DP[i - 3] + Arr[i - 1]) + Arr[i];

	std::cout << DP[N];
}