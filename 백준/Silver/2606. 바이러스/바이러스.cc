#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool m_arrVisited[101];
class Graph
{
private:
	vector<int> m_vecVertex[101];
	int m_iVisitNum;
public:
	Graph() 
		: m_iVisitNum(0)
	{}
	~Graph() {}
public:
	int getVisitNum() { return m_iVisitNum; }
	void insertEdge(int start, int end)
	{
		m_vecVertex[start].push_back(end);
		m_vecVertex[end].push_back(start);
	}
	void dfs(int start)
	{
		m_arrVisited[start] = true;
		int idx = 0;
		for (int i = 0; i < m_vecVertex[start].size(); ++i)
		{
			idx = m_vecVertex[start][i];
			if (!m_arrVisited[idx])
			{
				++m_iVisitNum;
				dfs(idx);
			}
		}
	}
};
int main()
{
	Graph* g = new Graph();
	int n, m, start, end;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &start, &end);
		g->insertEdge(start, end);
	}
	g->dfs(1);
	cout << g->getVisitNum();
}