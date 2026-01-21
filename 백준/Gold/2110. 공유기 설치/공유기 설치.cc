#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

int32_t N, C;
int32_t Pos[200000];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> C;
	for (int32_t i = 0; i < N; ++i)
		std::cin >> Pos[i];

	std::sort(Pos, Pos + N);

	int32_t Left = 1;
	int32_t Right = Pos[N - 1] - Pos[0];
	int32_t MaxDist = 0;
	while (Left <= Right)
	{
		int32_t Mid = (Left + Right) / 2;

		int32_t Cnt = 1;
		int32_t Prev = Pos[0];
		for (int32_t i = 1; i < N; ++i)
		{
			if (Pos[i] - Prev >= Mid)
			{
				Cnt += 1;
				Prev = Pos[i];
			}
			if (Cnt >= C)
				break;
		}
		if (Cnt >= C)
		{
			Left = Mid + 1;
			MaxDist = std::max<int32_t>(MaxDist, Mid);
		}
		else
			Right = Mid - 1;
	}
	std::cout << MaxDist;
}