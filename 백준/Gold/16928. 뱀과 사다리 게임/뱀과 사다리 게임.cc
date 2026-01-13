#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

uint32_t N, M;
uint32_t Edges[101] = { 0 };
uint32_t Counts[101] = { 0 };

void Bfs()
{
	std::queue<uint32_t> Spaces;
	Spaces.push(1);

	while (Spaces.empty() == false)
	{
		uint32_t Space = Spaces.front();
		Spaces.pop();

		if (Space == 100)
			return;

		for (size_t i = 1; i <= 6; ++i)
		{
			uint32_t NextSpace = Space + i;
			if (NextSpace > 100)
				continue;
			if (Counts[NextSpace])
				continue;

			uint32_t FinalSpace = NextSpace;
			uint32_t JumpSpace = Edges[NextSpace];
			if (JumpSpace)
				FinalSpace = JumpSpace;

			if (Counts[FinalSpace])
				continue;
			Counts[FinalSpace] = Counts[Space] + 1;
			Spaces.push(FinalSpace);
		}
	}
}
int main()
{
	std::cin >> N >> M;
	for (uint32_t i = 0; i < N; ++i)
	{
		uint32_t X = 0, Y = 0;
		std::cin >> X >> Y;
		Edges[X] = Y;
	}
	for (uint32_t i = 0; i < M; ++i)
	{
		uint32_t U = 0, V = 0;
		std::cin >> U >> V;
		Edges[U] = V;
	}
	Bfs();
	std::cout << Counts[100];
}