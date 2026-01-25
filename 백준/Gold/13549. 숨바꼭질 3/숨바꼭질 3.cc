#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

enum { MaxVertex = 100001 };
int32_t Times[MaxVertex];
int32_t N, K;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> K;

	std::fill(Times, Times + MaxVertex, INT_MAX);
	Times[N] = 0;
	std::queue<int32_t> Vertices;
	Vertices.emplace(N);

	while (Vertices.empty() == false)
	{
		int32_t Vertex = Vertices.front();
		Vertices.pop();

		if (Vertex == K)
			break;

		int32_t NextVertices[] = { Vertex * 2,  Vertex - 1, Vertex + 1, };
		for (int32_t i = 0; i < 3; ++i)
		{
			int32_t NextVertex = NextVertices[i];
			if (NextVertex >= MaxVertex)
				continue;
			if (Times[NextVertex] != INT_MAX)
				continue;
			int32_t Offset = 1;
			if (i == 0)
				Offset = 0;
			Times[NextVertex] = std::min(Times[NextVertex], Times[Vertex] + Offset);
			Vertices.emplace(NextVertex);
		}
	}

	std::cout << Times[K];
}