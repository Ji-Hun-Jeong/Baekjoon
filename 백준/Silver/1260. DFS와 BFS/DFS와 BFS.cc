#include <iostream>
#include <vector>
#include <queue>

uint32_t NumOfVertex = 0;
uint32_t NumOfEdge = 0;
std::priority_queue<uint32_t, std::vector<uint32_t>, std::greater<uint32_t>> EdgeInfos[1001];
bool bVisited[1001] = { false };

void Dfs(uint32_t InVertex)
{
	bVisited[InVertex] = true;
	std::cout << InVertex << " ";
	auto EdgeInfo = EdgeInfos[InVertex];
	while (EdgeInfo.empty() == false)
	{
		uint32_t Vertex = EdgeInfo.top();
		EdgeInfo.pop();

		if (bVisited[Vertex])
			continue;

		Dfs(Vertex);
	}
}

std::queue<uint32_t> NextVertexList;
void Bfs(uint32_t InVertex)
{
	bVisited[InVertex] = true;
	std::cout << InVertex << " ";
	auto EdgeInfo = EdgeInfos[InVertex];
	while (EdgeInfo.empty() == false)
	{
		uint32_t NextVertex = EdgeInfo.top();
		EdgeInfo.pop();

		if (bVisited[NextVertex])
			continue;

		NextVertexList.push(NextVertex);
	}

	while (NextVertexList.empty() == false)
	{
		uint32_t NextVertex = NextVertexList.front();
		NextVertexList.pop();

		if (bVisited[NextVertex])
			continue;

		Bfs(NextVertex);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	uint32_t StartVertex = 0;
	std::cin >> NumOfVertex >> NumOfEdge >> StartVertex;
	for (uint32_t i = 0; i < NumOfEdge; ++i)
	{
		uint32_t U = 0;
		uint32_t V = 0;
		std::cin >> U >> V;
		EdgeInfos[U].push(V);
		EdgeInfos[V].push(U);
	}
	Dfs(StartVertex);
	for (uint32_t i = 1; i <= NumOfVertex; ++i)
		bVisited[i] = false;
	std::cout << std::endl;
	Bfs(StartVertex);
}