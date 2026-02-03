#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { Max = 2, D = 1000000007 };
// 1000000007
size_t Matrix1[Max][Max] = { 1,1,1,0 };
size_t Matrix2[Max][Max] = { 1,1,1,0 };
void Mul(const size_t InSrc1[][Max], const size_t InSrc2[][Max], size_t InDst[][Max])
{
	size_t Temp[Max][Max] = { 0 };

	for (int32_t i = 0; i < Max; ++i)
		for (int32_t j = 0; j < Max; ++j)
			for (int32_t k = 0; k < Max; ++k)
			{
				Temp[i][j] += (InSrc1[i][k] * InSrc2[k][j]) % D;
				Temp[i][j] %= D;
			}

	for (int32_t i = 0; i < Max; ++i)
		for (int32_t j = 0; j < Max; ++j)
			InDst[i][j] = Temp[i][j];
}

void Devide(size_t InN)
{
	if (InN <= 1)
		return;
	Devide(InN / 2);
	Mul(Matrix2, Matrix2, Matrix2);
	if (InN % 2 == 1)
		Mul(Matrix1, Matrix2, Matrix2);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	size_t N = 0;
	std::cin >> N;

	Devide(N);

	std::cout << Matrix2[1][0];
}