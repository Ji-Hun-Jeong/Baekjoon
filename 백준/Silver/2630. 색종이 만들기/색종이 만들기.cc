#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { Max = 128 };
int32_t N;
bool Paper[Max][Max];
int32_t NumWhite = 0;
int32_t NumBlue = 0;

enum class EPaperType
{
	White,
	Blue,
	Devide
};
void Devide(int32_t InStartX, int32_t InEndX, int32_t InStartY, int32_t InEndY)
{
	int32_t Sum = 0;
	for (int32_t i = InStartY; i <= InEndY; ++i)
		for (int32_t j = InStartX; j <= InEndX; ++j)
			Sum += Paper[i][j];
	
	EPaperType PaperType;
	if (Sum == 0)
		PaperType = EPaperType::White;
	else if (Sum == (InEndX + 1 - InStartX) * (InEndY + 1 - InStartY))
		PaperType = EPaperType::Blue;
	else
		PaperType = EPaperType::Devide;

	switch (PaperType)
	{
	case EPaperType::White:
		NumWhite += 1;
		break;
	case EPaperType::Blue:
		NumBlue += 1;
		break;
	case EPaperType::Devide:
	{
		int32_t HalfSizeX = (InEndX + InStartX) / 2;
		int32_t HalfSizeY = (InEndY + InStartY) / 2;
		Devide(InStartX, HalfSizeX, InStartY, HalfSizeY);
		Devide(InStartX, HalfSizeX, HalfSizeY + 1, InEndY);
		Devide(HalfSizeX + 1, InEndX, InStartY, HalfSizeY);
		Devide(HalfSizeX + 1, InEndX, HalfSizeY + 1, InEndY);
	}
		break;
	default:
		break;
	}
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

	Devide(0, N - 1, 0, N - 1);
	std::cout << NumWhite << '\n' << NumBlue;
}