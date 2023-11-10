#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define SIZE 101
int n, m;
struct Info
{
	int link;
	int cnt;
};
Info arr[SIZE];
void bfs()
{
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int idx = q.front();
		q.pop();
		if (arr[idx].link)
		{
			if (arr[arr[idx].link].cnt)
				arr[arr[idx].link].cnt = min(arr[idx].cnt, arr[arr[idx].link].cnt);
			else
				arr[arr[idx].link].cnt = arr[idx].cnt;
			idx = arr[idx].link;
		}
		for (int i = 1; i <= 6; ++i)
		{
			if (idx + i < SIZE && !arr[idx + i].cnt)
			{
				q.push(idx + i);
				arr[idx + i].cnt = arr[idx].cnt + 1;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int idx = 0;
		int link = 0;
		cin >> idx;
		cin >> link;
		arr[idx].link = link;
	}
	for (int i = 0; i < m; ++i)
	{
		int idx = 0;
		int link = 0;
		cin >> idx;
		cin >> link;
		arr[idx].link = link;
	}
	bfs();
	cout << arr[SIZE - 1].cnt;
}