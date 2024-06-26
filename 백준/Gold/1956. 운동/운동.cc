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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin >> V >> E;
	for (int i = 1; i <= V; ++i)
		fill(arrNode[i]+1, arrNode[i]+V+1, INF);
	for (int i = 1; i <= V; ++i)
		arrNode[i][i] = 0;
	for (int i = 0; i < E; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arrNode[a][b] = c;
	}
	Floyd();
	int ans = INF;
	int v = V % 2;
	for (int i = 1; i <= V; ++i)
	{
		for (int j = 1; j <= V; ++j)
		{
			if (i == j)
				continue;
			ans = min(ans, arrNode[i][j] + arrNode[j][i]);
		}
	}
	if (ans == INF)
		ans = -1;
	cout << ans;
}