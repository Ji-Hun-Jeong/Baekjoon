#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int N, M, K;
int nm[100][100];
int mk[100][100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> nm[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			cin >> mk[i][j];
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			int sum = 0;
			for (int k = 0; k < M; ++k)
			{
				sum += nm[i][k] * mk[k][j];
			}
			cout << sum << " ";
		}
		cout << "\n";
	}
}