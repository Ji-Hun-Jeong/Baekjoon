#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int N, M;
pair<int, int> arr[101];
int dp[10000001][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	int sum = 0;
	int result = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i].first;
		sum += arr[i].first;
	}
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i].second;
		result += arr[i].second;
	}
	int order = 1;
	int m = sum - M;
	for (int j = 1; j <= N; ++j)
	{
		for (int i = 1; i <= m; ++i)
		{
			int idx = i - arr[j].first;
			if (idx >= 0)
				dp[i][order] = max(dp[idx][!order] + arr[j].second, dp[i][!order]);
			else
				dp[i][order] = dp[i][!order];
		}
		order = !order;
	}
	int Max = 0;
	for (int i = 0; i <= m; ++i)
		Max = max(Max, dp[i][!order]);
	cout << result - Max;
}