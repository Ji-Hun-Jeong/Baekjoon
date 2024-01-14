#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int value[501][501];
pair<int, int> matrix[501][501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> matrix[i][i].first >> matrix[i][i].second;
	for (int i = N - 1; i >= 1; --i)
	{
		value[i][i + 1] = matrix[i][i].first * matrix[i][i].second * matrix[i + 1][i + 1].second;
		matrix[i][i + 1].first = matrix[i][i].first;
		matrix[i][i + 1].second = matrix[i + 1][i + 1].second;
		for (int j = i + 2; j <= N; ++j)
		{
			value[i][j] = 987654321;
			for (int k = i ; k < j; ++k)
			{
				int val = matrix[i][k].first * matrix[i][k].second * matrix[k + 1][j].second + value[i][k] + value[k + 1][j];
				if (val < value[i][j])
				{
					matrix[i][j].first = matrix[i][k].first;
					matrix[i][j].second = matrix[k + 1][j].second;
					value[i][j] = val;
				}
			}
		}
	}
	cout << value[1][N];
}