#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum {Max = 6561};
int32_t N;
bool Screen[Max][Max];
void Draw(int32_t InX, int32_t InY, int32_t InN)
{
	if (InN == 1)
	{
		Screen[InX][InY] = true;
		return;
	}
	int32_t Offset = InN / 3;
	int32_t X1 = InX + Offset;
	int32_t X2 = X1 + Offset;
	int32_t Y1 = InY + Offset;
	int32_t Y2 = Y1 + Offset;

	Draw(InX, InY, Offset);
	Draw(X1, InY, Offset);
	Draw(X2, InY, Offset);

	Draw(InX, Y1, Offset);
	Draw(X2, Y1, Offset);

	Draw(InX, Y2, Offset);
	Draw(X1, Y2, Offset);
	Draw(X2, Y2, Offset);
}

void Present()
{
	for (int32_t i = 0; i < N; ++i)
	{
		for (int32_t j = 0; j < N; ++j)
		{
			if (Screen[i][j])
				std::cout << "*";
			else
				std::cout << " ";
		}
		std::cout << '\n';
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N;
	Draw(0, 0, N);
	Present();
}