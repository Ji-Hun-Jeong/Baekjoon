#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

enum { MaxCity = 101 };
int32_t n, m;
int32_t Dist[MaxCity][MaxCity];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);	

	std::cin >> n >> m;
	for (int32_t i = 1; i <= n; ++i)
	{
		for (int32_t j = 1; j <= n; ++j)
		{
			Dist[i][j] = INT_MAX;
			if (i == j)
				Dist[i][j] = 0;
		}
	}
	for (int32_t i = 0; i < m; ++i)
	{
		int32_t a, b, c;
		std::cin >> a >> b >> c;
		Dist[a][b] = std::min(Dist[a][b], c);
	}

	for (int32_t k = 1; k <= n; ++k)
	{
		for (int32_t i = 1; i <= n; ++i)
		{
			for (int32_t j = 1; j <= n; ++j)
			{
				if (Dist[i][k] == INT_MAX || Dist[k][j] == INT_MAX)
					continue;
				Dist[i][j] = std::min(Dist[i][j], Dist[i][k] + Dist[k][j]);
			}
		}
	}
	
	for (int32_t i = 1; i <= n; ++i)
	{
		for (int32_t j = 1; j <= n; ++j)
		{
			if (Dist[i][j] == INT_MAX)
				std::cout << 0 << ' ';
			else
				std::cout << Dist[i][j] << ' ';
		}
		std::cout << '\n';
	}
}