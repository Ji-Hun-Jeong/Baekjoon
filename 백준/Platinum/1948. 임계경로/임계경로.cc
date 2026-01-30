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
std::vector<TEdge> AdjCityArray[MaxCity];
int32_t RefCount[MaxCity];
int32_t Start, End;
struct TCity
{
	// 이전 도시번호와 그 도시로부터 왔을 때의 시간
	std::vector<TEdge> PrevCitys;
};
TCity CityInfos[MaxCity];
TCity FinalInfos[MaxCity];
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
		AdjCityArray[a].emplace_back(b, c);
		RefCount[b] += 1;
	}
	std::cin >> Start >> End;

	std::queue<int32_t> Citys;
	Citys.push(Start);
	while (Citys.empty() == false)
	{
		int32_t City = Citys.front();
		Citys.pop();

		// 먼저 지금까지 나한테 온 최댓값 거리 구하고 그것만 남기고 나머지 다 버리기
		TCity CityInfo = CityInfos[City];
		const auto& PrevCitys = CityInfo.PrevCitys;
		int32_t MaxTime = 0;
		for (TEdge PrevCity : PrevCitys)
			MaxTime = std::max(MaxTime, PrevCity.Time);

		TCity& FinalInfo = FinalInfos[City];
		FinalInfo.PrevCitys.reserve(PrevCitys.size());
		for (TEdge PrevCity : PrevCitys)
		{
			if (PrevCity.Time == MaxTime)
				FinalInfo.PrevCitys.push_back(PrevCity);
		}

		const auto& NextCitys = AdjCityArray[City];
		for (TEdge NextCityInfo : NextCitys)
		{
			TEdge MyInfo;
			MyInfo.City = City;
			MyInfo.Time = MaxTime + NextCityInfo.Time;
			CityInfos[NextCityInfo.City].PrevCitys.push_back(MyInfo);
			RefCount[NextCityInfo.City] -= 1;
			if (RefCount[NextCityInfo.City] == 0)
				Citys.emplace(NextCityInfo.City);
		}
	}
	// 여기서부터는 이제 돌아가야함
	std::queue<int32_t> BackCitys;
	BackCitys.push(End);
	bVisited[End] = true;

	int32_t Num = 0;
	while (BackCitys.empty() == false)
	{
		int32_t City = BackCitys.front();
		BackCitys.pop();

		const auto& FinalInfo = FinalInfos[City];
		for (TEdge PrevCity : FinalInfo.PrevCitys)
		{
			Num += 1;
			if (bVisited[PrevCity.City])
				continue;
			bVisited[PrevCity.City] = true;
			BackCitys.push(PrevCity.City);
		}
	}
	std::cout << FinalInfos[End].PrevCitys[0].Time << "\n" << Num;
}