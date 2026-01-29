#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>
#include <set>

enum { MaxTeams = 501 };
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t TestK = 0;
	std::cin >> TestK;
	while (TestK--)
	{
		std::set<int32_t> AdjVerticesArray[MaxTeams];
		std::array<int32_t, MaxTeams> RefCount = { 0 };

		int32_t n;
		std::cin >> n;
		int32_t Teams[MaxTeams];
		for (int32_t i = 1; i <= n; ++i)
			std::cin >> Teams[i];

		for (int32_t i = 1; i <= n; ++i)
		{
			int32_t Start = Teams[i];
			for (int32_t j = i + 1; j <= n; ++j)
			{
				int32_t End = Teams[j];
				AdjVerticesArray[Start].insert(End);
				RefCount[End] += 1;
			}
		}

		int32_t m;
		std::cin >> m;

		for (int32_t i = 0; i < m; ++i)
		{
			int32_t a, b;
			std::cin >> a >> b;
			if (AdjVerticesArray[a].contains(b))
				std::swap(a, b);
			AdjVerticesArray[b].erase(a);
			RefCount[a] -= 1;

			AdjVerticesArray[a].insert(b);
			RefCount[b] += 1;
		}

		std::queue<int32_t> Vertices;
		for (int32_t i = 1; i <= n; ++i)
		{
			if (RefCount[i] <= 0)
				Vertices.push(i);
		}

		std::vector<int32_t> Result;
		bool bAmbiguous = false;
		bool bCycle = false;

		for (int32_t i = 0; i < n; ++i) {
			if (Vertices.empty()) { // 더 이상 뽑을 게 없는데 n개를 못 채웠다면 사이클!
				bCycle = true;
				break;
			}
			if (Vertices.size() > 1) { // 선택지가 여러 개라면 순위 모호
				bAmbiguous = true;
			}

			int32_t Vertex = Vertices.front();
			Vertices.pop();
			Result.push_back(Vertex);

			for (int32_t AdjVertex : AdjVerticesArray[Vertex]) {
				RefCount[AdjVertex] -= 1;
				if (RefCount[AdjVertex] == 0)
					Vertices.push(AdjVertex);
			}
		}

		// 최종 판단
		if (bCycle) std::cout << "IMPOSSIBLE";
		else if (bAmbiguous) std::cout << "?";
		else {
			for (int32_t team : Result) std::cout << team << ' ';
		}
		std::cout << '\n';
	}
}