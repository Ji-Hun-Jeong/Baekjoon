#include <iostream>
#include <vector>
#include <array>

using ull = unsigned long long;
const ull MOD = 1000000000;
int main()
{
	int N = 0;
	std::cin >> N;
	ull DP[10];

	for (int i = 0; i < 10; ++i)
		DP[i] = 1;
	DP[0] = 0;

	while (--N)
	{
		ull BowlArr[10] = { 0 };
		for (int i = 0; i < 10; ++i)
		{
			int Left = i - 1;
			int Right = i + 1;
			if (0 <= Left)
				BowlArr[Left] = (DP[i] + BowlArr[Left]) % MOD;
			if (Right <= 9)
				BowlArr[Right] = (DP[i] + BowlArr[Right]) % MOD;
		}
		for (int i = 0; i < 10; ++i)
			DP[i] = BowlArr[i];
	}

	
	ull Result = 0;
	for (int i = 0; i < 10; ++i)
		Result = (Result + DP[i]) % MOD;
	std::cout << Result;
}