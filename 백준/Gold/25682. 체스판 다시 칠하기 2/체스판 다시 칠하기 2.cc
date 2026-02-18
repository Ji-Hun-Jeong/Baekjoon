#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int arr[2001][2001];
int chess0[2001][2001];
int chess1[2001][2001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	char ch = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> ch;
			if ('W' == ch)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
			if((i+j)%2==0)
			{
				chess0[i][j] = arr[i][j] == 0 ? 0 : 1;
				chess1[i][j] = arr[i][j] == 1 ? 0 : 1;
			}
			else
			{
				chess0[i][j] = arr[i][j] == 1 ? 0 : 1;
				chess1[i][j] = arr[i][j] == 0 ? 0 : 1;
			}
			chess0[i][j] += chess0[i - 1][j] + chess0[i][j - 1] - chess0[i - 1][j - 1];
			chess1[i][j] += chess1[i - 1][j] + chess1[i][j - 1] - chess1[i - 1][j - 1];
		}
	}
	int Min = 2147483647;
	for (int i = k; i <= n; ++i)
	{
		for (int j = k; j <= m; ++j)
		{
			Min = min(Min, min(chess0[i][j] - chess0[i - k][j] - chess0[i][j - k] + chess0[i - k][j - k]
				, chess1[i][j] - chess1[i - k][j] - chess1[i][j - k] + chess1[i - k][j - k]));
		}
	}
	cout << Min;
}