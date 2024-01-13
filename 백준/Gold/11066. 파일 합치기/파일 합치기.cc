#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int arr[501];
int sum[501];
int dp[501][501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--)
	{
		int K;
		cin >> K;
		for (int i = 1; i <= K; ++i)
		{
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		for (int i = K - 1; i >= 1; --i)
		{
			for (int j = i + 1; j <= K; ++j)
			{
				dp[i][j] = 987654321;
				for (int k = i; k <= j; ++k)
				{
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
				}
			}
		}
		cout << dp[1][K] << "\n";
	}
}