#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

int32_t A[1000000] = { 0 };
std::vector<int32_t> Arr;
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t N = 0;
	std::cin >> N;

	for (int32_t i = 0; i < N; ++i)
		std::cin >> A[i];
	
	Arr.reserve(N);
	Arr.push_back(A[0]);
	for (int32_t i = 1; i < N; ++i)
	{
		if (A[i] > Arr.back())
			Arr.push_back(A[i]);
		else
		{
			auto Iter = std::lower_bound(Arr.begin(), Arr.end(), A[i]);
			*Iter = A[i];
		}
	}
	std::cout << Arr.size();
}