#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define SIZE 100
int n, m, h;
int arr[SIZE][SIZE][SIZE];
struct Info
{
	int x;
	int y;
	int z;
};
Info offset[] = { {-1,0,0},{1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
queue<Info> q;
void bfs()
{
	while (!q.empty())
	{
		Info pos = q.front();
		q.pop();
		for (int i = 0; i < 6; ++i)
		{
			int adjX = pos.x + offset[i].x;
			int adjY = pos.y + offset[i].y;
			int adjZ = pos.z + offset[i].z;
			if (0 <= adjX && adjX < m && 0 <= adjY && adjY < n && 0 <= adjZ && adjZ < h && 0 == arr[adjZ][adjY][adjX])
			{
				arr[adjZ][adjY][adjX] = arr[pos.z][pos.y][pos.x] + 1;
				q.push({ adjX,adjY,adjZ });
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> m >> n >> h;
	for (int k = 0; k < h; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> arr[k][i][j];
				if (1 == arr[k][i][j])
					q.push({ j,i,k });
			}
		}
	}
	bfs();
	int max = -1;
	for (int k = 0; k < h; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (0 == arr[k][i][j])
				{
					cout << -1;
					return 0;
				}
				if (max < arr[k][i][j])
					max = arr[k][i][j];
			}
		}
	}
	cout << max - 1;
}