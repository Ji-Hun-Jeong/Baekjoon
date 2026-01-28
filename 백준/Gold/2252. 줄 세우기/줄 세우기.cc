#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <list>

int32_t N, M;
enum { MaxNode = 32001 };
int32_t Inputs[MaxNode];
std::vector<int32_t> Edges[MaxNode];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;
	for (int32_t i = 0; i < M; ++i)
	{
		int32_t A, B;
		std::cin >> A >> B;

		Edges[A].push_back(B);
		Inputs[B] += 1;
	}

	std::queue<int32_t> Nodes;
	for (int32_t i = 1; i <= N; ++i)
		if (Inputs[i] == 0)
		{
			Inputs[i] -= 1;
			Nodes.emplace(i);
		}

	std::vector<int32_t> Result;
	Result.reserve(N);
	while (Nodes.empty() == false)
	{
		int32_t Node = Nodes.front();
		Nodes.pop();
		Result.push_back(Node);

		for (int32_t NextNode : Edges[Node])
		{
			Inputs[NextNode] -= 1;
			if (Inputs[NextNode] == 0)
				Nodes.emplace(NextNode);
		}
	}

	for (int32_t Value : Result)
		std::cout << Value << " ";
}