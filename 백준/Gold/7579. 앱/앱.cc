#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int N, M;
pair<int, int> arr[101];
int dp[10001][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	int sum = 0;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i].first;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i].second;
		sum += arr[i].second;
	}
	for (int j = 1; j <= N; ++j)
	{
		for (int i = 0; i <= sum; ++i)
		{
			int idx = i - arr[j].second;
			if (idx >= 0)
				dp[i][j] = max(dp[idx][j - 1] + arr[j].first, dp[i][j - 1]);
			else
				dp[i][j] = dp[i][j - 1];
		}
	}
	for (int i = 0; i <= sum; ++i)
	{
		if (dp[i][N] >= M)
		{
			cout << i;
			break;
		}
	}
}