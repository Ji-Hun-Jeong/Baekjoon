#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
long long N, B;
long long a[5][5];	// 계속 저장
long long b[5][5];	// 첫 행렬만 저장
long long c[5][5];	// 결과 저장 결국 a로 옮김
void cal(long long n)
{
	if (1 == n)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				long long sum = 0;
				for (int k = 0; k < N; ++k)
				{
					sum += a[i][k] * b[k][j];
				}
				c[i][j] = sum % 1000;
			}
		}
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				long long sum = 0;
				for (int k = 0; k < N; ++k)
				{
					sum += a[i][k] * a[k][j];
				}
				c[i][j] = sum % 1000;
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			a[i][j] = c[i][j] % 1000;
		}
	}
}
void dfs(long long n)
{
	if (1 == n)
		return;
	dfs(n / 2);
	cal(n);
	if (1 == n % 2)
		cal(1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> B;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> a[i][j];
			b[i][j] = a[i][j];
		}
	}
	dfs(B);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << a[i][j] % 1000 << " ";
		}
		cout << "\n";
	}
}
