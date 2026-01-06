#include <iostream>
#include <vector>
#include <queue>

uint32_t NumOfVertex_N = 0;
uint32_t NumOfEdge_M = 0;
uint32_t StartVertex_R = 0;

std::priority_queue<uint32_t> EdgeInfos[100001];
bool bVisited[100001];

uint32_t VisitOrders[100001];
uint32_t CurrentVisitOrder = 0;
void Dfs(uint32_t InVisitVertex)
{
	bVisited[InVisitVertex] = true;
	VisitOrders[InVisitVertex] = ++CurrentVisitOrder;

	auto& EdgeInfo = EdgeInfos[InVisitVertex];
	while (EdgeInfo.empty() == false)
	{
		uint32_t NextVertex = EdgeInfo.top();
		EdgeInfo.pop();

		if (bVisited[NextVertex])
			continue;

		Dfs(NextVertex);
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

	Dfs(StartVertex_R);

	for (uint32_t i = 1; i <= NumOfVertex_N; ++i)
		printf("%d\n", VisitOrders[i]);
}