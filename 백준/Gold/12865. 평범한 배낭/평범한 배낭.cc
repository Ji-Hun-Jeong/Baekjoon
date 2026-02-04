#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int32_t DP[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int32_t N, K;
    cin >> N >> K;

    for (int32_t i = 0; i < N; ++i)
    {
        int32_t W, V;
        cin >> W >> V;

        for (int32_t j = K; j >= W; --j)
        {
            if (DP[j] < DP[j - W] + V)
            {
                DP[j] = DP[j - W] + V;
            }
        }
    }

    cout << DP[K];

    return 0;
}