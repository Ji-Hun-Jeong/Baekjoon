#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define SIZE 100001
int minTimes[SIZE];
int m, n;
void push(queue<int>& q, int idx, int time)
{
	if (0 == minTimes[idx])
	{
		q.push(idx);
		minTimes[idx] = time;
	}
}
void bfs()
{
	queue<int> q;
	q.push(n);
	if (n == m)
	{
		cout << 0;
		return;
	}
	while (!q.empty())
	{
		int idx = q.front();
		q.pop();
		int time = minTimes[idx] + 1;
		if (0 <= idx - 1)
		{
			push(q, idx - 1, time);
		}
		if (idx + 1 < SIZE)
		{
			push(q, idx + 1, time);
		}
		if (idx * 2 < SIZE)
		{
			push(q, idx * 2, time);
		}
		if (minTimes[m] != 0)
		{
			cout << minTimes[m];
			return;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	bfs();
}