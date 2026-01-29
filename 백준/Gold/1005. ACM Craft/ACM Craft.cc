#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { MaxBuilding = 1001 };
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t TestK = 0;
	std::cin >> TestK;
	while (TestK--)
	{
		int32_t N, K;
		std::array<int32_t, MaxBuilding> BuildTimes = { 0 };
		std::cin >> N >> K;

		for (int32_t i = 1; i <= N; ++i)
			std::cin >> BuildTimes[i];

		std::vector<int32_t> AdjBuildingsArray[MaxBuilding];
		int32_t RefCount[MaxBuilding] = { 0 };
		for (int32_t i = 0; i < K; ++i)
		{
			int32_t a, b;
			std::cin >> a >> b;
			AdjBuildingsArray[a].push_back(b);
			RefCount[b] += 1;
		}
		int32_t W;
		std::cin >> W;

		std::queue<int32_t> Buildings;
		std::array<int32_t, MaxBuilding> MaxBuildTimes = BuildTimes;
		for (int32_t i = 1; i <= N; ++i)
		{
			if (RefCount[i] == 0)
				Buildings.push(i);
		}

		while (Buildings.empty() == false)
		{
			int32_t Building = Buildings.front();
			Buildings.pop();

			const auto& AdjBuildings = AdjBuildingsArray[Building];
			for (int32_t AdjBuilding : AdjBuildings)
			{
				MaxBuildTimes[AdjBuilding] = std::max(MaxBuildTimes[Building] + BuildTimes[AdjBuilding]
					, MaxBuildTimes[AdjBuilding]);
				RefCount[AdjBuilding] -= 1;
				if (RefCount[AdjBuilding] == 0)
					Buildings.push(AdjBuilding);
			}
		}
		std::cout << MaxBuildTimes[W] << '\n';
	}
}