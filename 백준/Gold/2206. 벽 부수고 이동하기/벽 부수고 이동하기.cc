#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Info
{
	int num;
	int cnt[2];
	bool visited[2];
};
int n, m;
#define SIZE 1000
Info arr[SIZE][SIZE];
pair<int, int> offset[] = { {-1,0},{1,0},{0,1},{0,-1} };
void bfs()
{
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	arr[0][0].cnt[0] = 1;
	arr[0][0].cnt[1] = 1;
	arr[0][0].visited[0] = false;
	arr[0][0].visited[1] = true;
	// 벽을 뚫고 온건 0번에 아직 뚫지 않은건 1번에
	while (!q.empty())
	{
		pair<int, int> idx = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int adjX = idx.first + offset[i].first;
			int adjY = idx.second + offset[i].second;
			if (0 <= adjX && adjX < m && 0 <= adjY && adjY < n)
			{
				if (1 == arr[adjY][adjX].num)	// 벽인 경우
				{
					if (arr[idx.second][idx.first].visited[1])	// 지금까지 벽을 통과했냐가 중요한게 아니라 여기까지 벽을 통과하지 않고 온게 있느냐가 중요한것
					{
						if (!arr[adjY][adjX].visited[0])
						{
							arr[adjY][adjX].visited[0] = true;
							arr[adjY][adjX].cnt[0] = arr[idx.second][idx.first].cnt[1] + 1;
							q.push({ adjX,adjY });
						}
					}
				}
				else
				{
					if (arr[idx.second][idx.first].visited[0])
					{
						if (!arr[adjY][adjX].visited[0])
						{
							arr[adjY][adjX].visited[0] = true;
							arr[adjY][adjX].cnt[0] = arr[idx.second][idx.first].cnt[0] + 1;
							q.push({ adjX,adjY });
						}
					}
					if (arr[idx.second][idx.first].visited[1])
					{
						if (!arr[adjY][adjX].visited[1])
						{
							arr[adjY][adjX].visited[1] = true;
							arr[adjY][adjX].cnt[1] = arr[idx.second][idx.first].cnt[1] + 1;
							q.push({ adjX,adjY });
						}
					}
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
	for (int i = 0; i < n; ++i)
	{
		string str;
		getline(cin, str);
		for (int j = 0; j < m; ++j)
			arr[i][j].num = str[j] - '0';
	}
	bfs();
	if (!arr[n - 1][m - 1].visited[0] && !arr[n - 1][m - 1].visited[1])
		cout << -1;
	else if (arr[n - 1][m - 1].visited[0] && arr[n - 1][m - 1].visited[1])
		cout << (arr[n - 1][m - 1].cnt[0] < arr[n - 1][m - 1].cnt[1] ? arr[n - 1][m - 1].cnt[0] : arr[n - 1][m - 1].cnt[1]);
	else if (arr[n - 1][m - 1].visited[0])
		cout << arr[n - 1][m - 1].cnt[0];
	else
		cout << arr[n - 1][m - 1].cnt[1];
}