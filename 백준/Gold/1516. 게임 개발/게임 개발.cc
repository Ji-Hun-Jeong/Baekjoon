#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { Max = 501 };
int32_t N;
int32_t Counts[Max];
std::array<std::vector<int32_t>, Max> AdjBuildings;
int32_t Times[Max];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	for (int32_t i = 1; i <= N; ++i)
	{
		int32_t Time;
		std::cin >> Time;
		Times[i] = Time;
		while (true)
		{
			int32_t Pre;
			std::cin >> Pre;
			if (Pre == -1)
				break;
			Counts[i] += 1;
			AdjBuildings[Pre].push_back(i);
		}
	}

	std::queue<int32_t> Buildings;
	std::array<int32_t, Max> ResultTimes = { 0 };
	for (int32_t i = 1; i <= N; ++i)
	{
		if (Counts[i] == 0)
		{
			Buildings.emplace(i);
			ResultTimes[i] = Times[i];
		}
	}

	while (Buildings.empty() == false)
	{
		int32_t Building = Buildings.front();
		Buildings.pop();

		const auto& AdjBuilding = AdjBuildings[Building];
		for (size_t i = 0; i < AdjBuilding.size(); ++i)
		{
			int32_t AdjIndex = AdjBuilding[i];
			Counts[AdjIndex] -= 1;
			ResultTimes[AdjIndex] = std::max<int32_t>(ResultTimes[AdjIndex], ResultTimes[Building] + Times[AdjIndex]);
			if (Counts[AdjIndex] == 0)
			{
				Buildings.emplace(AdjIndex);
			}
		}
	}

	for (int32_t i = 1; i <= N; ++i)
		std::cout << ResultTimes[i] << '\n';
}