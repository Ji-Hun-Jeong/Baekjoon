#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int arr[501][501];
int dp[501][501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			cin >> arr[i][j];
	dp[1][1] = arr[1][1];
	int Max = dp[1][1];
	for (int i = 2; i <= n; ++i)
	{
		dp[i][1] = dp[i - 1][1] + arr[i][1];
		dp[i][i] = dp[i - 1][i - 1] + arr[i][i];
		for (int j = 2; j < i; ++j)
		{
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}
	for (int i = 1; i <= n; ++i)
		Max = max(Max, dp[n][i]);
	cout << Max;
}