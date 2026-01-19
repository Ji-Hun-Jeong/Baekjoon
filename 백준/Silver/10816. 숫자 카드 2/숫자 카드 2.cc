#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

int32_t N, M;
const int32_t MaxSize = 500000;
int32_t A[MaxSize] = { 0 };
int32_t B[MaxSize] = { 0 };

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
		int32_t Lower = std::lower_bound(A, A + N, B[i]) - A;
		int32_t Upper = std::upper_bound(A, A + N, B[i]) - A;

		std::cout << Upper - Lower << '\n';
	}
}