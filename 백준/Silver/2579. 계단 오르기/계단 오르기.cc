#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, stair[301];
	int dp[301];


	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stair[i];
	}

	dp[0] = stair[0];
	dp[1] = max(stair[0] + stair[1], stair[1]);
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i = 3; i < n; i++) 
	{
		dp[i] = max(dp[i - 2] + stair[i], stair[i - 1] + stair[i] + dp[i - 3]);
	}
	cout << dp[n - 1] << '\n';
}