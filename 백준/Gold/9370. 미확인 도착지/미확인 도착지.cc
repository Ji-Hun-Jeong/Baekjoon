#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

enum { MaxVertex = 2001 };
int32_t n, m, t;
int32_t s, g, h;

struct TEdge
{
	int32_t Vertex;
	int32_t Weight;
};

bool operator < (const TEdge& InA, const TEdge& InB)
{
	return InA.Weight > InB.Weight;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t T;
	std::cin >> T;
	while (T--)
	{
		std::cin >> n >> m >> t;
		std::cin >> s >> g >> h;

		std::vector<TEdge> VertexEdges[MaxVertex];
		for (int32_t i = 0; i < m; ++i)
		{
			int32_t a, b, d;
			std::cin >> a >> b >> d;
			if ((a == g && b == h) || (a == h && b == g))
				d = 2 * d - 1;
			else
				d = 2 * d;
			VertexEdges[a].emplace_back(b, d);
			VertexEdges[b].emplace_back(a, d);
		}
		int32_t MinDist[MaxVertex];
		std::fill(MinDist + 1, MinDist + n + 1, INT_MAX);
		MinDist[s] = 0;
		
		std::priority_queue<TEdge> Edges;
		Edges.emplace(s, 0);
		while (Edges.empty() == false)
		{
			TEdge Edge = Edges.top();
			Edges.pop();

			int32_t Vertex = Edge.Vertex;
			int32_t Weight = Edge.Weight;

			if (MinDist[Vertex] < Weight)
				continue;

			const auto& AdjEdges = VertexEdges[Vertex];
			for (const auto& AdjEdge : AdjEdges)
			{
				int32_t NextVertex = AdjEdge.Vertex;
				int32_t NextWeight = AdjEdge.Weight;

				int32_t FinalWeight = MinDist[Vertex] + NextWeight;
				if (FinalWeight < MinDist[NextVertex])
				{
					MinDist[NextVertex] = FinalWeight;
					Edges.emplace(NextVertex, FinalWeight);
				}
			}
		}

		int32_t Dest[101];
		for (int32_t i = 1; i <= t; ++i)
			std::cin >> Dest[i];
		std::sort(Dest + 1, Dest + t + 1);
		for (int32_t i = 1; i <= t; ++i)
		{
			int32_t Index = Dest[i];
			if (MinDist[Index] != INT_MAX && MinDist[Index] % 2 == 1)
				std::cout << Index << " ";
		}
		std::cout << '\n';
	}
}