#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int Max = 0;
	for (int i = 1; i <= a.size(); ++i)
	{
		for (int j = 1; j <= b.size(); ++j)
		{
			if (a[i-1] == b[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			Max = max(dp[i][j], Max);
		}
	}
	cout << Max;
}