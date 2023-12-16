#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
#define INF 987654321
int n, m, t, s, g, h;
struct Edge
{
	int destNum;
	int distance;
};
bool operator >(const Edge& first, const Edge& second)
{
	return first.distance > second.distance;
}
vector<Edge> node[2001][2];
int dist[2001][2];
bool visited[2001][2];
vector<int> vecDestNum;
vector<int> finalDests;
int sg, sh, gh;
void InsertEdge(int u, int v, int dist)
{
	node[u][0].push_back({ v,dist });
	node[v][0].push_back({ u,dist });

	node[u][1].push_back({ v,dist });
	node[v][1].push_back({ u,dist });
}
void Init(int order)
{
	for (int i = 1; i <= n; ++i)
	{
		visited[i][order] = false;
		dist[i][order] = INF;
	}
}
int Djikstra(int start, int end, int order)
{
	Init(order);
	priority_queue<Edge, vector<Edge>, greater<Edge>> q;
	dist[start][order] = 0;
	q.push({ start,0 });
	while (!q.empty())
	{
		Edge edge = q.top(); q.pop();
		int curNodeNum = edge.destNum;
		if (visited[curNodeNum][order])
			continue;
		visited[curNodeNum][order] = true;
		for (const Edge& e : node[curNodeNum][order])
		{
			int adjNodeNum = e.destNum;
			if (dist[curNodeNum][order] + e.distance < dist[adjNodeNum][order])
			{
				dist[adjNodeNum][order] = dist[curNodeNum][order] + e.distance;
				q.push({ adjNodeNum,dist[adjNodeNum][order] });
			}
		}
	}
	return dist[end][order];
}
void Calculate()
{
	for (int dest : vecDestNum)
	{
		int first, second, third;
		int dist1,dist2;

		first = sg;
		second = gh;
		third = Djikstra(h, dest, 1);
		dist1 = first + second + third;

		first = sh;
		second = gh;
		third = Djikstra(g, dest, 1);
		dist2 = first + second + third;
		if (dist1 < INF && dist2 < INF)
		{
			int path = min(dist1, dist2);
			if (path == dist[dest][0])
			{
				finalDests.push_back(dest);
			}
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
	while (testK--)
	{
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for (int i = 0; i < m; ++i)
		{
			int a, b, d;
			cin >> a >> b >> d;
			if ((a == g && b == h) || (a == h) && (b == g))
				gh = d;
			InsertEdge(a, b, d);
		}
		for (int i = 0; i < t; ++i)
		{
			int destNum = 0;
			cin >> destNum;
			vecDestNum.push_back(destNum);
		}
		Djikstra(s, n, 0);
		sg = dist[g][0];
		sh = dist[h][0];
		Calculate();
		sort(finalDests.begin(), finalDests.end());
		for (const int& i : finalDests)
			cout << i << " ";
		cout << "\n";
		finalDests.clear();
		vecDestNum.clear();
		for (int i = 1; i <= n; ++i)
		{
			node[i][0].clear();
			node[i][1].clear();
		}
	}
}