#include <iostream>
#include <string>
#include <print>
#include <array>
#include <vector>

std::array<int32_t, 1000001> Parents;

int32_t GetRoot(size_t InValue)
{
	if (InValue == Parents[InValue])
		return InValue;
	return Parents[InValue] = GetRoot(Parents[InValue]);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int32_t N, M;
	std::cin >> N >> M;

	for (int32_t i = 1; i <= N; ++i)
	{
		Parents[i] = i;
	}


	for (int32_t i = 0; i < M; ++i)
	{
		int32_t A, B, C;
		std::cin >> A >> B >> C;

		int32_t RootB = GetRoot(B);
		int32_t RootC = GetRoot(C);
		if (A == 0)
		{
			if (RootB == RootC)
				continue;

			Parents[RootC] = RootB;
		}
		else
		{
			if (RootB == RootC)
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
	}
}