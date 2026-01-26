#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

enum { MaxVertex = 501 };
int64_t N, M;
struct TEdge
{
	int64_t StartVertex;
	int64_t DestVertex;
	int64_t Weight;
};
std::vector<TEdge> Edges;
int64_t MinDist[MaxVertex];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;
	for (int64_t i = 0; i < M; ++i)
	{
		int64_t A, B, C;
		std::cin >> A >> B >> C;
		Edges.emplace_back(A, B, C);
	}

	std::fill(MinDist + 1, MinDist + 1 + N, INT_MAX);
	MinDist[1] = 0;
	for (int64_t i = 1; i < N; ++i)
	{
		for (TEdge Edge : Edges)
		{
			int64_t StartVertex = Edge.StartVertex;
			int64_t DestVertex = Edge.DestVertex;
			int64_t Weight = Edge.Weight;

			if (MinDist[StartVertex] == INT_MAX)
				continue;

			MinDist[DestVertex] = std::min(MinDist[DestVertex], MinDist[StartVertex] + Weight);
		}
	}
	for (TEdge Edge : Edges)
	{
		int64_t StartVertex = Edge.StartVertex;
		int64_t DestVertex = Edge.DestVertex;
		int64_t Weight = Edge.Weight;

		if (MinDist[StartVertex] == INT_MAX)
			continue;
		if (MinDist[DestVertex] > MinDist[StartVertex] + Weight)
		{
			std::cout << -1;
			return 0;
		}
	}
	for (int64_t i = 2; i <= N; ++i)
	{
		if (MinDist[i] != INT_MAX)
			std::cout << MinDist[i] << '\n';
		else
			std::cout << -1 << '\n';
	}
}