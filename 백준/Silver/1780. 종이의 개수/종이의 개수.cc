#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

constexpr int32_t Pow(int32_t InX, int32_t InP) {
	return (InP == 0) ? 1 : InX * Pow(InX, InP - 1);
}
constexpr int32_t MaxValue = Pow(3, 7); 
enum {Max = MaxValue};

int32_t N;
int32_t Paper[Max][Max];
enum class EState { Zero, One, NOne, Devide };

int32_t Nums[3];
void Devide(int32_t InX, int32_t InY, int32_t InSize)
{
	int32_t Sum = 0;
	bool bDirty = false;
	for (int32_t i = InY; i < InY + InSize; ++i)
		for (int32_t j = InX; j < InX + InSize; ++j)
		{
			Sum += Paper[i][j];
			if (Paper[i][j] == 1 || Paper[i][j] == -1)
				bDirty = true;
		}

	EState State;
	if (Sum == 0 && bDirty == false)
		State = EState::Zero;
	else if (Sum == InSize * InSize)
		State = EState::One;
	else if (-Sum == InSize * InSize)
		State = EState::NOne;
	else
		State = EState::Devide;

	if (State == EState::Devide)
	{
		int32_t DevideSize = InSize / 3;
		int32_t X1 = InX + DevideSize;
		int32_t X2 = X1 + DevideSize;
		int32_t Y1 = InY + DevideSize;
		int32_t Y2 = Y1 + DevideSize;
		Devide(InX, InY, DevideSize);
		Devide(X1, InY, DevideSize);
		Devide(X2, InY, DevideSize);
		Devide(InX, Y1, DevideSize);
		Devide(X1, Y1, DevideSize);
		Devide(X2, Y1, DevideSize);
		Devide(InX, Y2, DevideSize);
		Devide(X1, Y2, DevideSize);
		Devide(X2, Y2, DevideSize);
	}
	else
		Nums[static_cast<size_t>(State)] += 1;

}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;

	for (int32_t i = 0; i < N; ++i)
		for (int32_t j = 0; j < N; ++j)
			std::cin >> Paper[i][j];

	Devide(0, 0, N);

	std::cout << Nums[static_cast<size_t>(EState::NOne)] << '\n';
	std::cout << Nums[static_cast<size_t>(EState::Zero)] << '\n';
	std::cout << Nums[static_cast<size_t>(EState::One)];
}