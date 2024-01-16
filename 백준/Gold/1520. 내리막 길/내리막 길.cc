#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int M, N;
int arr[501][501];
int dp[501][501];
pair<int, int> offset[] = { {-1,0},{0,-1},{1,0},{0,1} };
int dfs(int x, int y)
{
	if (-1 != dp[y][x])
		return dp[y][x];
	dp[y][x] = 0;
	for (int i = 0; i < 4; ++i)
	{
		int X = x + offset[i].first;
		int Y = y + offset[i].second;
		if (1 > X || X > N || 1 > Y || Y > M)
			continue;
		if (arr[Y][X] < arr[y][x])
		{
			dp[y][x] += dfs(X, Y);
		}
	}
	return dp[y][x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> M >> N;
	for (int i = 1; i <= M; ++i)
		for (int j = 1; j <= N; ++j)
		{
			cin >> arr[i][j];
			dp[i][j] = -1;
		}		
	dp[M][N] = 1;
	cout << dfs(1, 1);
}