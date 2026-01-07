#include <iostream>
#include <vector>
#include <queue>

const size_t MaxIndex = 100001;
uint32_t NumOfVertex_N = 0;
uint32_t NumOfEdge_M = 0;
uint32_t StartVertex_R = 0;

std::priority_queue<uint32_t, std::vector<uint32_t>, std::greater<uint32_t>> EdgeInfos[MaxIndex];
bool bVisited[MaxIndex];
std::queue<uint32_t> BfsVertices;

uint32_t VertexOrders[MaxIndex];
uint32_t CurrentVertexOrder = 0;

void Bfs(uint32_t InVertex)
{
	bVisited[InVertex] = true;
	VertexOrders[InVertex] = ++CurrentVertexOrder;

	auto& EdgeInfo = EdgeInfos[InVertex];

	while (EdgeInfo.empty() == false)
	{
		uint32_t NextVertex = EdgeInfo.top();
		EdgeInfo.pop();

		if (bVisited[NextVertex])
			continue;

		BfsVertices.push(NextVertex);
	}

	while (BfsVertices.empty() == false)
	{
		uint32_t NextVertex = BfsVertices.front();
		BfsVertices.pop();

		if (bVisited[NextVertex])
			continue;

		Bfs(NextVertex);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> NumOfVertex_N >> NumOfEdge_M >> StartVertex_R;
	
	for (uint32_t i = 0; i < NumOfEdge_M; ++i)
	{
		uint32_t U = 0;
		uint32_t V = 0;
		std::cin >> U >> V;

		EdgeInfos[U].push(V);
		EdgeInfos[V].push(U);
	}

	Bfs(StartVertex_R);

	for (uint32_t i = 1; i <= NumOfVertex_N; ++i)
		printf("%d\n", VertexOrders[i]);

}