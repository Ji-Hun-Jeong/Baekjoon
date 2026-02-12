#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { Max = 100001 };
std::array<int32_t, Max> Arr;
std::array<size_t, Max> Table;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t N, M;
	std::cin >> N >> M;


	size_t Sum = 0;
	for (int32_t i = 0; i < N; ++i)
	{
		std::cin >> Arr[i];
		Sum += Arr[i];
		Table[i] = Sum;
	}

	for (int32_t i = 0; i < M; ++i)
	{
		int32_t A, B;
		std::cin >> A >> B;

		std::cout << Table[B - 1] - Table[A - 1] + Arr[A - 1] << '\n';
	}
}