#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int value[501][501];
pair<int, int> matrix[501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> matrix[i].first >> matrix[i].second;
	for (int i = N - 1; i >= 1; --i)
	{
		for (int j = i + 1; j <= N; ++j)
		{
			value[i][j] = 987654321;
			for (int k = i ; k < j; ++k)
			{
				value[i][j] = min(value[i][j], matrix[i].first * matrix[k].second * matrix[j].second + value[i][k] + value[k + 1][j]);
			}
		}
	}
	cout << value[1][N];
}