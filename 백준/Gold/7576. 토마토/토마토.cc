#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define SIZE 1000
int n, m;
int arr[SIZE][SIZE];
queue<pair<int, int>> q;
pair<int, int> offset[] = { {-1,0},{1,0},{0,1},{0,-1} };
void bfs()
{
	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int adjX = pos.first + offset[i].first;
			int adjY = pos.second + offset[i].second;
			if (0 <= adjX && adjX < m && 0 <= adjY && adjY < n && 0 == arr[adjY][adjX])
			{
				arr[adjY][adjX] = arr[pos.second][pos.first] + 1;
				q.push({ adjX,adjY });
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> m >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> arr[i][j];
			if (1 == arr[i][j])
				q.push({ j,i });
		}
	}
	bfs();
	int max = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (0 == arr[i][j])
			{
				cout << -1;
				return 0;
			}
			if (max < arr[i][j])
				max = arr[i][j];
		}
	}
	cout << max - 1;
}