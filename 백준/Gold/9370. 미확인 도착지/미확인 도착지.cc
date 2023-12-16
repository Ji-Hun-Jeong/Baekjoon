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
int sg, sh, gh;
void Init(int* dist,bool* visited)
{
	for (int i = 1; i <= n; ++i)
	{
		visited[i]= false;
		dist[i] = INF;
	}
}
int Djikstra(const vector<Edge>* node,int* dist,bool* visited,int start, int end)
{
	Init(dist, visited);
	priority_queue<Edge, vector<Edge>, greater<Edge>> q;
	dist[start] = 0;
	q.push({ start,0 });
	while (!q.empty())
	{
		Edge edge = q.top(); q.pop();
		int curNodeNum = edge.destNum;
		if (visited[curNodeNum])
			continue;
		visited[curNodeNum] = true;
		for (const Edge& e : node[curNodeNum])
		{
			int adjNodeNum = e.destNum;
			if (dist[curNodeNum]+ e.distance < dist[adjNodeNum])
			{
				dist[adjNodeNum] = dist[curNodeNum] + e.distance;
				q.push({ adjNodeNum,dist[adjNodeNum] });
			}
		}
	}
	return dist[end];
}
void Calculate()
{
	
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
		vector<Edge> node[2001];
		int firstDjikstraResult[2001];
		int dist[2001];
		bool visited[2001];
		vector<int> vecDestNum;
		vector<int> finalDests;
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for (int i = 0; i < m; ++i)
		{
			int a, b, d;
			cin >> a >> b >> d;
			if ((a == g && b == h) || (a == h) && (b == g))
				gh = d;
			node[a].push_back({ b,d });
			node[b].push_back({ a,d });
		}
		for (int i = 0; i < t; ++i)
		{
			int destNum = 0;
			cin >> destNum;
			vecDestNum.push_back(destNum);
		}
		Djikstra(node,dist,visited,s, n);
		sg = dist[g];
		sh = dist[h];
		for (int dest : vecDestNum)
			firstDjikstraResult[dest] = dist[dest];
		for (int dest : vecDestNum)
		{
			int dist1, dist2;

			dist1 = sg + gh + Djikstra(node, dist, visited, h, dest);
			if (dist1 == firstDjikstraResult[dest])
			{
				finalDests.push_back(dest);
				continue;
			}

			dist2 = sh + gh + Djikstra(node, dist, visited, g, dest);
			if (dist2 == firstDjikstraResult[dest])
			{
				finalDests.push_back(dest);
				continue;
			}
		}
		sort(finalDests.begin(), finalDests.end());
		for (const int& i : finalDests)
			cout << i << " ";
		cout << "\n";
	}
}