#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

int32_t K, V, E;
const int32_t MaxVertex = 20001;

bool Bfs(std::queue<int32_t>* EdgeInfos)
{
	char Colors[MaxVertex] = { 0 };
	
	for (int32_t i = 1; i <= V; ++i)
	{
		if (Colors[i])
			continue;

		std::queue<int32_t> Vertices;
		Vertices.emplace(i);
		Colors[i] = 1;

		while (Vertices.empty() == false)
		{
			int32_t Vertex = Vertices.front();
			Vertices.pop();

			std::queue<int32_t>& EdgeInfo = EdgeInfos[Vertex];
			char Color = Colors[Vertex];
			while (EdgeInfo.empty() == false)
			{
				int32_t NextVertex = EdgeInfo.front();
				EdgeInfo.pop();

				if (Colors[NextVertex] && Colors[NextVertex] == Color)
					return true;
				else
					Colors[NextVertex] = Color == 1 ? 2 : 1;

				Vertices.emplace(NextVertex);
			}
		}
	}
	return false;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> K;
	while (K--)
	{
		std::queue<int32_t> EdgeInfos[MaxVertex];
		std::cin >> V >> E;
		for (int32_t i = 0; i < E; ++i)
		{
			int32_t u = 0;
			int32_t v = 0;
			std::cin >> u >> v;
			EdgeInfos[u].push(v);
			EdgeInfos[v].push(u);
		}
		if (Bfs(EdgeInfos))
			std::cout << "NO\n";
		else
			std::cout << "YES\n";
	}
}