#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int arr[10001];
int dp[10001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1], arr[2]) + arr[3];
	int Max = max(max(dp[1], dp[2]), dp[3]);
	for (int i = 4; i <= n; ++i)
	{
		dp[i] = max(max(dp[i - 2], dp[i - 3] + arr[i - 1]), dp[i - 4] + arr[i - 1]) + arr[i];
		Max = max(Max, dp[i]);
	}
	cout << Max;
}