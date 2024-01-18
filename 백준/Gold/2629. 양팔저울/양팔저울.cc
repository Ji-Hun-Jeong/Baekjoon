#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int N, M;
int nArr[31];
int mArr[8];
int dp[15001][31];
bool findValue[40001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	findValue[0] = true;
	int sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		cin >> nArr[i];
		sum += nArr[i];
	}
	cin >> M;
	for (int i = 1; i <= M; ++i)
		cin >> mArr[i];
	for (int j = 1; j <= N; ++j)
	{
		for (int i = 1; i <= sum; ++i)
		{
			int idx = i - nArr[j];
			if (idx < 0) 
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			else
				dp[i][j] = max(dp[idx][j - 1] + nArr[j], dp[i][j - 1]);
			findValue[dp[i][j]] = true;
		}
	}
	for (int i = 1; i <= M; ++i)
	{
		int j = mArr[i];
		for (; j <= sum; ++j)
		{
			if (findValue[j])
			{
				if (findValue[j - mArr[i]])
				{
					cout << "Y" << " ";
					break;
				}
			}			
		}
		if (j > sum)
			cout << "N" << " ";
	}
}