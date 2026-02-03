#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { Max = 100000 };

size_t Devide(const int32_t* InHist, int32_t InLeft, int32_t InRight)
{
    if (InLeft == InRight) 
        return static_cast<size_t>(InHist[InLeft]);

    int32_t Mid = (InLeft + InRight) / 2;

    size_t Value = std::max(Devide(InHist, InLeft, Mid), Devide(InHist, Mid + 1, InRight));

    int32_t L = Mid, R = Mid + 1;
    int32_t Height = std::min(InHist[L], InHist[R]);
    Value = std::max(Value, static_cast<size_t>(Height) * 2);

    while (L > InLeft || R < InRight)
    {
        if (R < InRight && (L == InLeft || InHist[L - 1] < InHist[R + 1]))
        {
            R++;
            Height = std::min(Height, InHist[R]); 
        }
        else
        {
            L--;
            Height = std::min(Height, InHist[L]);
        }
        Value = std::max(Value, static_cast<size_t>(Height) * (R - L + 1));
    }

    return Value;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	while (true)
	{
		int32_t N;
		int32_t Hist[Max];

		std::cin >> N;
		if (N == 0)
			break;

		for (int32_t i = 0; i < N; ++i)
			std::cin >> Hist[i];

		std::cout << Devide(Hist, 0, N - 1) << '\n';
	}
}