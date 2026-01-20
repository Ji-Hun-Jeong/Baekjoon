#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

int32_t K, N;
int32_t Lan[10000];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> K >> N;

	size_t Left = 0;
	size_t Right = 0;
	for (int32_t i = 0; i < K; ++i)
	{
		std::cin >> Lan[i];
		Right = std::max<int32_t>(Right, Lan[i]);
	}

	int32_t MaxLength = 0;
	while (Left <= Right)
	{
		int32_t Mid = (Left + Right) / 2;
		int32_t Cnt = 0;
		if (Mid == 0)
		{
			Left = Mid + 1;
			continue;
		}
		for (int32_t i = 0; i < K; ++i)
			Cnt += Lan[i] / Mid;

		if (Cnt < N)
			Right = Mid - 1;
		else
		{
			MaxLength = std::max<int32_t>(MaxLength, Mid);
			Left = Mid + 1;
		}
	}
	std::cout << MaxLength;
}