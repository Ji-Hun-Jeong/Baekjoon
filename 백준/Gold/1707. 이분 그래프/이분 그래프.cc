#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int u, v;
int V, E;
set<int> s[20001];
bool visited[20001];
void insertEdge(int u, int v)
{
	s[u].insert(v);
	s[v].insert(u);
}
bool bfs(int u)
{
	if (visited[u])
		return true;
	set<int> set[2];
	queue<pair<int, int>> q;
	q.push({ u,0 });
	visited[u] = true;
	while (!q.empty())
	{
		pair<int, int> front = q.front();
		q.pop();
		auto iter = s[front.first].begin();
		for (; iter != s[front.first].end(); ++iter)
		{
			if (!visited[*iter])
			{
				q.push({ *iter,!front.second });
				set[!front.second].insert(*iter);
				visited[*iter] = true;
			}
			else
			{
				if (set[front.second].find(*iter) != set[front.second].end())
					return false;
			}
		}
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int testK = 0;
	cin >> testK;
	while (testK--)
	{
		cin >> V >> E;
		for (int i = 0; i < E; ++i)
		{
			cin >> u >> v;
			insertEdge(u, v);
		}
		bool b = true;
		for (int i = 1; i <= V; ++i)
		{
			b = bfs(i);
			if (!b)
				break;		
		}
		if (b)
			cout << "YES\n";
		else
			cout << "NO\n";
		for (int i = 1; i <= 20000; ++i)
		{
			visited[i] = false;
			s[i].clear();
		}
	}
}