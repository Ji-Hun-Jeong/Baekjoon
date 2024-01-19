#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int DP[2][100001];
int W[101];
int V[101];


int main()
{
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];
	int order = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j - W[i] >= 0) DP[order][j] = max(DP[!order][j], DP[!order][j - W[i]] + V[i]);
			else DP[order][j] = DP[!order][j];
		}
		order = !order;
	}
	cout << DP[!order][K];
}