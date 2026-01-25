#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

enum { MaxVertex = 20001 };
int32_t N, E;
struct TEdgeInfo
{
	int32_t Vertex;
	int32_t Weight;
};
bool operator < (const TEdgeInfo& InA, const TEdgeInfo& InB)
{
	return InA.Weight > InB.Weight;
}
std::vector<TEdgeInfo> VertexEdgeInfos[MaxVertex];

int32_t Dijkstra(int32_t InStart, int32_t InFinish)
{
	int32_t MinDist[MaxVertex];
	std::fill(MinDist + 1, MinDist + N + 1, INT_MAX);

	std::priority_queue<TEdgeInfo> EdgeInfos;
	EdgeInfos.emplace(InStart, 0);
	MinDist[InStart] = 0;

	while (EdgeInfos.empty() == false)
	{
		TEdgeInfo EdgeInfo = EdgeInfos.top();
		EdgeInfos.pop();

		int32_t Vertex = EdgeInfo.Vertex;
		int32_t Weight = EdgeInfo.Weight;

		if (Vertex == InFinish)
			break;

		if (Weight > MinDist[Vertex])
			continue;

		const auto& AdjEdgeInfos = VertexEdgeInfos[Vertex];
		for (TEdgeInfo AdjEdgeInfo : AdjEdgeInfos)
		{
			int32_t AdjVertex = AdjEdgeInfo.Vertex;
			int32_t AdjWeight = AdjEdgeInfo.Weight;

			int32_t FinalAdjWeight = Weight + AdjWeight;
			if (FinalAdjWeight < MinDist[AdjVertex])
			{
				MinDist[AdjVertex] = FinalAdjWeight;
				EdgeInfos.emplace(AdjVertex, FinalAdjWeight);
			}
		}
	}
	return MinDist[InFinish];
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> E;

	for (int32_t i = 1; i <= E; ++i)
	{
		int32_t a, b, c;
		std::cin >> a >> b >> c;
		VertexEdgeInfos[a].emplace_back(b, c);
		VertexEdgeInfos[b].emplace_back(a, c);
	}
	int32_t v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;

	int32_t Tov1 = Dijkstra(1, v1);
	int32_t Tov2 = Dijkstra(1, v2);
	int32_t Tov1v2 = Dijkstra(v1, v2);
	int32_t Tov1N = Dijkstra(v1, N);
	int32_t Tov2N = Dijkstra(v2, N);
	if (Tov1v2 == INT_MAX)
	{
		std::cout << -1;
		return 0;
	}

	int32_t Final = -1;
	if (Tov1 != INT_MAX && Tov2N != INT_MAX)
		Final = Tov1 + Tov1v2 + Tov2N;

	if (Tov2 != INT_MAX && Tov1N != INT_MAX)
	{
		int32_t B = Tov2 + Tov1v2 + Tov1N;
		Final = std::min(Final, B);
	}

	std::cout << Final;
}