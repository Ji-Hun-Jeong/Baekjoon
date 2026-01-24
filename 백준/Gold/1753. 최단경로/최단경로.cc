#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

enum { MaxVertex = 20001 };
int32_t V, E, K;
bool bVisited[MaxVertex];
int32_t MinDist[MaxVertex];
struct TEdgeInfo
{
	int32_t Vertex;
	int32_t Weight;
};
bool operator < (const TEdgeInfo& InA, const TEdgeInfo& InB)
{
	return InA.Weight > InB.Weight;
}
std::vector<TEdgeInfo> ArrayEdgeInfos[MaxVertex];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> V >> E;
	std::cin >> K;

	std::fill(MinDist + 1, MinDist + V + 1, INT_MAX);
	for (int32_t i = 0; i < E; ++i)
	{
		int32_t u, v, w;
		std::cin >> u >> v >> w;
		ArrayEdgeInfos[u].emplace_back(v, w);
	}
	MinDist[K] = 0;

	std::priority_queue<TEdgeInfo, std::vector<TEdgeInfo>> VertexInfos;
	VertexInfos.emplace(K, 0);
	while (VertexInfos.empty() == false)
	{
		TEdgeInfo VertexInfo = VertexInfos.top();
		VertexInfos.pop();

		int32_t Vertex = VertexInfo.Vertex;
		int32_t Weight = VertexInfo.Weight;

		if (bVisited[Vertex])
			continue;
		bVisited[Vertex] = true;

		const auto& EdgeInfos = ArrayEdgeInfos[Vertex];
		for (TEdgeInfo EdgeInfo : EdgeInfos)
		{
			int32_t AdjVertex = EdgeInfo.Vertex;
			int32_t AdjWeight = EdgeInfo.Weight;

			int32_t FinalWeight = Weight + AdjWeight;
			if (FinalWeight < MinDist[AdjVertex])
			{
				MinDist[AdjVertex] = FinalWeight;
				VertexInfos.emplace(AdjVertex, FinalWeight);
			}
		}
	}
	
	for (int32_t i = 1; i <= V; ++i)
	{
		if (MinDist[i] == INT_MAX)
			std::cout << "INF\n";
		else
			std::cout << MinDist[i] << '\n';
	}
}