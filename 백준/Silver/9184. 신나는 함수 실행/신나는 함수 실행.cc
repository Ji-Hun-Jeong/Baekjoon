#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int dp[101][101][101];
int w(int a, int b, int c)
{
	if (dp[a + 50][b + 50][c + 50])
		return dp[a + 50][b + 50][c + 50];
	if (a <= 0 || b <= 0 || c <= 0)
	{
		dp[a + 50][b + 50][c + 50] = 1;
	}	
	else if (a > 20 || b > 20 || c > 20)
	{
		dp[a + 50][b + 50][c + 50] = w(20, 20, 20);
	}	
	else if (a < b && b < c)
	{
		dp[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
		dp[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return dp[a + 50][b + 50][c + 50];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (-1 == a && -1 == b && -1 == c)
			break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
}