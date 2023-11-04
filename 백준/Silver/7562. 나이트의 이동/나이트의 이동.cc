#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define SIZE 301

int n, startX, startY, endX, endY;
int chess[SIZE][SIZE];
pair<int, int> pos[] = { {-1,2},{-2,1},{-2,-1},{-1,-2},{1,2},{2,1},{2,-1},{1,-2} };
void bfs()
{
	if (startX == endX && startY == endY)
	{
		cout << 0 << '\n';
		return;
	}
	queue<pair<int,int>> q;
	q.push({ startX,startY });
	while (!q.empty())
	{
		pair<int, int> curPos = q.front();
		q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int x = curPos.first + pos[i].first;
			int y = curPos.second + pos[i].second;
			if (0 <= x && x < n && 0 <= y && y < n)
			{
				if (!chess[y][x])
				{
					chess[y][x] = chess[curPos.second][curPos.first] + 1;
					q.push({ x,y });
				}
			}
		}
		if (chess[endY][endX])
		{
			cout << chess[endY][endX] << '\n';
			return;
		}
	}
}
void clear()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			chess[i][j] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int testK = 0;
	cin >> testK;
	for (int i = 0; i < testK; ++i)
	{
		cin >> n;
		cin >> startX >> startY >> endX >> endY;
		bfs();
		clear();
	}
}