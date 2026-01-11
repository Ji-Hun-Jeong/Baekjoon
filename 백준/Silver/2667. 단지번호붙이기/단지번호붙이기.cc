#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

uint32_t N = 0;
uint32_t Map[25][25] = { 0 };
bool bVisited[25][25] = { false };

std::vector<uint32_t> Complexs;
uint32_t Dfs(uint32_t InHouseX, uint32_t InHouseY)
{
	if (InHouseX < 0 || N <= InHouseX)
		return 0;
	if (InHouseY < 0 || N <= InHouseY)
		return 0;
	if (Map[InHouseY][InHouseX] == 0)
		return 0;
	if (bVisited[InHouseY][InHouseX])
		return 0;

	bVisited[InHouseY][InHouseX] = true;
	uint32_t NumOfHouse = 1;

	uint32_t NextXs[4] = { InHouseX, InHouseX + 1 , InHouseX - 1, InHouseX };
	uint32_t NextYs[4] = { InHouseY + 1, InHouseY , InHouseY, InHouseY - 1 };

	for (size_t i = 0; i < 4; ++i)
	{
		uint32_t NextX = NextXs[i];
		uint32_t NextY = NextYs[i];

		NumOfHouse += Dfs(NextX, NextY);
	}
	return NumOfHouse;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	(std::cin >> N).ignore();
	for (uint32_t i = 0; i < N; ++i)
	{
		std::string Line;
		std::getline(std::cin, Line);
		for (uint32_t j = 0; j < N; ++j)
			Map[i][j] = Line[j] - '0';
	}

	for (uint32_t i = 0; i < N; ++i)
	{
		for (uint32_t j = 0; j < N; ++j)
		{
			uint32_t NumOfHouse = Dfs(j, i);
			if (NumOfHouse == 0)
				continue;
			Complexs.push_back(NumOfHouse);
		}
	}
	std::sort(Complexs.begin(), Complexs.end(), [](uint32_t InX, uint32_t InY)->bool {return InX < InY; });
	std::cout << Complexs.size() << std::endl;
	for (uint32_t NumOfHouse : Complexs)
		std::cout << NumOfHouse << '\n';
}