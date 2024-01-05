#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int dp[1000001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	std::fill(dp, dp + 1000001, 1000001);
	dp[1] = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i * 3 <= n)
			dp[i * 3] = min(dp[i * 3], dp[i] + 1);
		if (i * 2 <= n)
			dp[i * 2] = min(dp[i * 2], dp[i] + 1);
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
	}
	cout << dp[n];
}