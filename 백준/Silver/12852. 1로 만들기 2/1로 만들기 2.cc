#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
const int INF = 1000001;
int dp[1000001];
int result[1000001];
int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = INF;
	}
	dp[1] = 0;
	result[1] = -1;
	for (int i = 2; i <= N; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		result[i] = i - 1;
		if (i % 3 == 0 && dp[i / 3] + 1 < dp[i])
		{
			dp[i] = dp[i / 3] + 1;
			result[i] = i / 3;
		}
		if (i % 2 == 0 && dp[i / 2] + 1 < dp[i])
		{
			dp[i] = dp[i / 2] + 1;
			result[i] = i / 2;
		}
	}
	int idx = N;
	cout << dp[N] << "\n";
	cout << N << " ";
	while (result[idx] != -1)
	{
		cout << result[idx] << " ";
		idx = result[idx];
	}
}