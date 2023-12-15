#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
#define INT_MAX 214783647
int N, E;
int v1, v2;
int dist[801];
struct Edge
{
	int num;
	int distance;
	friend bool operator>(const Edge& one, const Edge& two);
};
bool operator>(const Edge& one, const Edge& two)
{
	return one.distance > two.distance;
}
struct Node
{
public:
	bool visited = false;
	vector<Edge> vecEdge;
public:
	void InsertEdge(int v, int dis)
	{
		vecEdge.push_back({ v,dis });
	}
};
Node arr[801];
void InsertEdge(int u, int v, int dis)
{
	arr[u].InsertEdge(v, dis);
	arr[v].InsertEdge(u, dis);
}
void Init()
{
	for (int i = 1; i < 801; ++i)
	{
		dist[i] = INT_MAX;
		arr[i].visited = false;
	}
}
int Djikstra(int start, int end)
{
	Init();
	priority_queue<Edge, vector<Edge>, greater<Edge>> q;
	q.push({ start,0 });
	dist[start] = 0;
	while (!q.empty())
	{
		Edge edge = q.top();
		q.pop();
		Node& node = arr[edge.num];
		if (node.visited)
			continue;
		node.visited = true;
		for (int i = 0; i < node.vecEdge.size(); ++i)
		{
			int linkNodeNum = node.vecEdge[i].num;
			if (arr[linkNodeNum].visited)
				continue;
			if (dist[edge.num] + node.vecEdge[i].distance < dist[linkNodeNum])
				dist[linkNodeNum] = dist[edge.num] + node.vecEdge[i].distance;
			q.push({ linkNodeNum, dist[linkNodeNum]});
		}
	}
	return dist[end];
}

int Calculate()
{
	int sum1 = 0, sum2 = 0;
	int first, second, third;
	first = Djikstra(1, v1);
	second = Djikstra(v1, v2);
	third = Djikstra(v2, N);
	sum1 = first + second + third;
	if (INT_MAX == first || INT_MAX == second || INT_MAX == third)
		sum1 = -1;
	
	first = Djikstra(1, v2);
	second = Djikstra(v2, v1);
	third = Djikstra(v1, N);
	sum2 = first + second + third;
	if (INT_MAX == first || INT_MAX == second || INT_MAX == third)
		sum2 = -1;
	return min(sum1, sum2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> E;
	for (int i = 0; i < E; ++i)
	{
		int u, v, d;
		cin >> u >> v >> d;
		InsertEdge(u, v, d);
	}
	cin >> v1 >> v2;
	int result = Calculate();
	cout << result;
}