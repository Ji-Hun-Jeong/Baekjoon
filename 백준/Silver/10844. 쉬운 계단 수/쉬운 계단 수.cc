#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n;
int cnt = 0;
int arr[10][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i < 10; ++i)
		arr[i][0] = 1;
	for (int j = 1; j < n; ++j)
	{
		for (int i = 0; i < 10; ++i)
		{
			if (0 == i)
				arr[i][j] = arr[i + 1][j - 1];
			else if (9 == i)
				arr[i][j] = arr[i - 1][j - 1];
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i + 1][j - 1];
			arr[i][j] %= 1000000000;
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		sum = (sum + arr[i][n - 1]) % 1000000000;
	}
	cout << sum;
}