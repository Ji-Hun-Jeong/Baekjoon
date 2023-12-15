#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int N, K;
int arr[100001];
bool visited[100001];
void Bfs()
{
	queue<int> q;
	q.push(N);
	visited[N] = true;
	while (!q.empty())
	{
		int idx = q.front();
		q.pop();
		if (idx * 2 <= 100000)
		{
			if (!visited[idx * 2])
			{
				q.push(idx * 2);
				visited[idx * 2] = true;
				arr[idx * 2] = arr[idx];
			}
		}
        if (0 <= idx - 1)
		{
			if (!visited[idx - 1])
			{
				q.push(idx - 1);
				visited[idx - 1] = true;
				arr[idx - 1] = arr[idx] + 1;
			}
		}
		if (idx + 1 <= 100000)
		{
			if (!visited[idx + 1])
			{
				q.push(idx + 1);
				visited[idx + 1] = true;
				arr[idx + 1] = arr[idx] + 1;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> K;
	Bfs();
	cout << arr[K];
}