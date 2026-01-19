#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

int32_t N, M;
const int32_t MaxSize = 100000;
int32_t A[MaxSize] = { 0 };
int32_t B[MaxSize] = { 0 };

bool Search(int32_t InValue)
{
	int32_t Left = 0;
	int32_t Right = N - 1;

	while (Left <= Right)
	{
		int32_t Mid = (Left + Right) / 2;
		if (A[Mid] == InValue)
			return true;
		else if (A[Mid] < InValue)
			Left = Mid + 1;
		else if (A[Mid] > InValue)
			Right = Mid - 1;
	}
	return false;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	for (int32_t i = 0; i < N; ++i)
		std::cin >> A[i];
	std::cin >> M;
	for (int32_t i = 0; i < M; ++i)
		std::cin >> B[i];

	std::sort(A, A + N);

	for (int32_t i = 0; i < M; ++i)
	{
		std::cout << Search(B[i]) << '\n';
	}
}