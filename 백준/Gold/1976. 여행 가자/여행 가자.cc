#include <iostream>
#include <string>
#include <print>
#include <array>
#include <vector>

std::array<int32_t, 201> Arr;

int32_t GetRoot(int32_t InNode)
{
	if (Arr[InNode] == InNode)
		return InNode;
	return Arr[InNode] = GetRoot(Arr[InNode]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int32_t N, M;
	std::cin >> N >> M;

	for (int32_t i = 1; i <= N; ++i)
		Arr[i] = i;

	for (int32_t i = 1; i <= N; ++i)
	{
		int32_t Root1 = GetRoot(i);
		for (int32_t j = 1; j <= N; ++j)
		{
			int32_t Conn;
			std::cin >> Conn;
			if (Conn == 1)
			{
				int32_t Root2 = GetRoot(j);
				if (Root1 == Root2)
					continue;
				Arr[Root2] = Root1;
			}
		}
	}

	std::vector<int32_t> Roots;
	for (int32_t i = 0; i < M; ++i)
	{
		int32_t Plan;
		std::cin >> Plan;
		Roots.push_back(GetRoot(Plan));
	}

	for (size_t i = 0; i < Roots.size() - 1; ++i)
	{
		if (Roots[i] != Roots[i + 1])
		{
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n";

}