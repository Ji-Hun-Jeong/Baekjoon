#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { Max = 1001 };
int32_t N, M, X;
struct TEdge
{
	int32_t Vertex;
	int32_t Weight;
};
bool operator < (const TEdge& InA, const TEdge& InB)
{
	return InA.Weight > InB.Weight;
}
std::array<std::vector<TEdge>, Max> Edges1;
std::array<std::vector<TEdge>, Max> Edges2;
std::array<int32_t, Max> Dist1;
std::array<int32_t, Max> Dist2;

void Dijkstra(const std::array<std::vector<TEdge>, Max>& InEdges, int32_t InStart
	, std::array<int32_t, Max>* OutDist)
{
	std::array<bool, Max> bVisited = { false };

	std::priority_queue<TEdge> Edges;
	OutDist->at(InStart) = 0;
	Edges.emplace(InStart, OutDist->at(InStart));

	while (Edges.empty() == false)
	{
		TEdge Edge = Edges.top();
		Edges.pop();

		if (bVisited[Edge.Vertex])
			continue;
		bVisited[Edge.Vertex] = true;

		const auto& AdjEdges = InEdges[Edge.Vertex];
		for (TEdge AdjEdge : AdjEdges)
		{
			if (bVisited[AdjEdge.Vertex])
				continue;
			OutDist->at(AdjEdge.Vertex) = std::min<int32_t>(OutDist->at(AdjEdge.Vertex), Edge.Weight + AdjEdge.Weight);
			Edges.emplace(AdjEdge.Vertex, OutDist->at(AdjEdge.Vertex));
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M >> X;
	for (int32_t i = 1; i <= M; ++i)
	{
		int32_t a, b, c;
		std::cin >> a >> b >> c;
		Edges1[a].emplace_back(b, c);
		Edges2[b].emplace_back(a, c);
	}
	std::fill(Dist1.begin(), Dist1.end(), INT_MAX);
	std::fill(Dist2.begin(), Dist2.end(), INT_MAX);

	Dijkstra(Edges1, X, &Dist1);
	Dijkstra(Edges2, X, &Dist2);

	int32_t Max = 0;
	for (int32_t i = 1; i <= N; ++i)
	{
		Max = std::max<int32_t>(Max, Dist1[i] + Dist2[i]);
	}
	std::cout << Max;
}