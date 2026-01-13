#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

uint32_t N, M;
uint32_t Tomato[1000][1000] = { 0 };
uint32_t NumOfAllTomato = 0;
uint32_t NumOfRipeTomato = 0;

struct TTomato
{
	int32_t x;
	int32_t y;
	uint32_t day;
};

std::queue<TTomato> RipeTomatos;
uint32_t MinDay = 0;
void Bfs()
{
	while (RipeTomatos.empty() == false)
	{
		TTomato RipeTomato = RipeTomatos.front();
		RipeTomatos.pop();

		int32_t x = RipeTomato.x;
		int32_t y = RipeTomato.y;

		int32_t NextXs[4] = { x,x - 1,x,x + 1 };
		int32_t NextYs[4] = { y + 1,y,y - 1,y };
		uint32_t NextDay = RipeTomato.day + 1;
		for (size_t i = 0; i < 4; ++i)
		{
			int32_t NextX = NextXs[i];
			int32_t NextY = NextYs[i];

			if (NextX < 0 || NextX >= M)
				continue;
			if (NextY < 0 || NextY >= N)
				continue;
			if (Tomato[NextY][NextX] == -1 || Tomato[NextY][NextX] == 1)
				continue;
			NumOfRipeTomato += 1;
			Tomato[NextY][NextX] = 1;
			RipeTomatos.push({ NextX, NextY, NextDay });
			MinDay = NextDay;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> M >> N;

	for (uint32_t i = 0; i < N; ++i)
	{
		for (uint32_t j = 0; j < M; ++j)
		{
			std::cin >> Tomato[i][j];
			if (Tomato[i][j] == -1)
				continue;
			NumOfAllTomato += 1;
			if (Tomato[i][j] == 1)
			{
				NumOfRipeTomato += 1;
				RipeTomatos.push({ int32_t(j),int32_t(i), 0 });
			}
		}
	}
	Bfs();
	if (NumOfRipeTomato == NumOfAllTomato)
		std::cout << MinDay << std::endl;
	else
		std::cout << -1 << std::endl;
}