#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { MaxCity = 10001 };
int32_t N, M;
struct TEdge
{
	int32_t City;
	int32_t Time;
};
std::vector<TEdge> EdgesArray[MaxCity];
std::vector<TEdge> BackEdgesArray[MaxCity];
int32_t RefCount[MaxCity];
int32_t MaxTimes[MaxCity];
int32_t Start, End;

bool bVisited[MaxCity];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;
	for (int32_t i = 0; i < M; ++i)
	{
		int32_t a, b, c;
		std::cin >> a >> b >> c;
		EdgesArray[a].emplace_back(b, c);
		BackEdgesArray[b].emplace_back(a, c);
		RefCount[b] += 1;
	}
	std::cin >> Start >> End;

	std::queue<int32_t> Citys;
	Citys.push(Start);
	while (Citys.empty() == false)
	{
		int32_t City = Citys.front();
		Citys.pop();

		int32_t MaxTime = MaxTimes[City];
		const auto& NextCitys = EdgesArray[City];
		for (TEdge NextCityInfo : NextCitys)
		{
			int32_t NextCity = NextCityInfo.City;
			int32_t Time = NextCityInfo.Time;
			MaxTimes[NextCity] = std::max(MaxTimes[NextCity], MaxTime + Time);
			RefCount[NextCityInfo.City] -= 1;
			if (RefCount[NextCityInfo.City] == 0)
				Citys.emplace(NextCityInfo.City);
		}
	}

	Citys.push(End);
	bVisited[End] = true;

	int32_t Num = 0;
	while (Citys.empty() == false)
	{
		int32_t City = Citys.front();
		Citys.pop();

		const auto& BackAdjEdges = BackEdgesArray[City];
		for (TEdge BackEdge : BackAdjEdges)
		{
			int32_t PrevCity = BackEdge.City;
			int32_t Time = BackEdge.Time;

			if (MaxTimes[PrevCity] + Time != MaxTimes[City])
				continue;
			
			Num += 1;
			if (bVisited[PrevCity])
				continue;
			bVisited[PrevCity] = true;
			Citys.push(PrevCity);
		}
	}
	std::cout << MaxTimes[End] << '\n' << Num;
}