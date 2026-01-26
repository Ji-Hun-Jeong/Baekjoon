#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

enum { MaxVertex = 10001 };
int32_t N, M;
struct TEdge
{
	int32_t Vertex;
	int32_t Weight;
};
std::vector<TEdge> Edges[MaxVertex];
int32_t Island1, Island2;
bool Bfs(size_t InMaxWeight)
{
	bool bVisited[MaxVertex] = { false };
	bVisited[Island1] = true;

	std::queue<int32_t> Vertices;
	Vertices.push(Island1);

	while (Vertices.empty() == false)
	{
		int32_t Island = Vertices.front();
		Vertices.pop();

		const auto& AdjIslands = Edges[Island];
		for (TEdge AdjIsland : AdjIslands)
		{
			int32_t NextIsland = AdjIsland.Vertex;
			int32_t Weight = AdjIsland.Weight;

			if (Weight < InMaxWeight)
				continue;

			if (bVisited[NextIsland])
				continue;

			bVisited[NextIsland] = true;
			Vertices.emplace(NextIsland);
			if (NextIsland == Island2)
				return true;
		}
	}
	return false;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;
	size_t Left = 1000000000;
	size_t Right = 0;
	for (int32_t i = 1; i <= M; ++i)
	{
		int32_t A, B, C;
		std::cin >> A >> B >> C;
		Edges[A].emplace_back(B, C);
		Edges[B].emplace_back(A, C);
		Left = std::min(Left, size_t(C));
		Right = std::max(Right, size_t(C));
	}
	std::cin >> Island1 >> Island2;

	while (Left <= Right)
	{
		size_t Mid = (Left + Right) / 2;

		bool bReach = Bfs(Mid);
		if (bReach)
			Left = Mid + 1;
		else
			Right = Mid - 1;
	}
	std::cout << Right;
}