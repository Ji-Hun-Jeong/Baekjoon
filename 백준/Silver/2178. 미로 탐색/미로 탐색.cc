#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Vertex
{
	int num;
	bool visited;
	int distance;
};
Vertex vertices[101][101];
int m, n;
struct Info
{
	int x;
	int y;
};
Info offset[4] = { {-1,0},{0,1},{1,0},{0,-1} };
void bfs()
{
	queue<Info> q;
	q.push({ 1,1 });
	vertices[1][1].visited = true;
	while (!q.empty())
	{
		Info pos = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = pos.x + offset[i].x;
			int y = pos.y + offset[i].y;
			if (0 < x && x <= m && 0 < y && y <= n)
			{
				if (!vertices[y][x].visited && 1 == vertices[y][x].num)
				{
					vertices[y][x].distance = vertices[pos.y][pos.x].distance + 1;
					vertices[y][x].visited = true;
					q.push({ x,y });
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	(cin >> n >> m).ignore();
	string str;
	for (int i = 1; i <= n; ++i)
	{
		getline(cin, str);
		for (int j = 1; j <= m; ++j)
		{
			vertices[i][j].num = str[j-1] - '0';
		}
	}
	vertices[1][1].distance = 1;
	bfs();
	cout << vertices[n][m].distance;
}