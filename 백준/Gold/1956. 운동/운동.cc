#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
#define INF 987654321
int arrNode[401][401];
int V, E;
void Floyd()
{
	for (int k = 1; k <= V; ++k)
	{
		for (int i = 1; i <= V; ++i)
		{
			for (int j = 1; j <= V; ++j)
			{
				arrNode[i][j] = min(arrNode[i][j], arrNode[i][k] + arrNode[k][j]);
			}
		}
	}
}
int main()
{
	cin >> V >> E;
	for (int i = 0; i <= V; ++i)
	{
		for (int j = 0; j <= V; ++j)
		{
			if (i == j)
			{
				arrNode[i][j] = 0;
			}
			else
			{
				arrNode[i][j] = INF;
			}	
		}
	}
	for (int i = 0; i < E; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arrNode[a][b] = c;
	}
	Floyd();
	int min = INF;
	int v = V % 2;
	for (int i = 1; i <= V; ++i)
	{
		for (int j = 1; j <= V; ++j)
		{
			if (i == j)
				continue;
			if (arrNode[i][j] + arrNode[j][i] < min)
				min = arrNode[i][j] + arrNode[j][i];
		}
	}
	if (min == INF)
		min = -1;
	cout << min;
}