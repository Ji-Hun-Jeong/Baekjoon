#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int arr[1001];
int dp1[1001];
int dp2[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	std::fill(dp1, dp1 + 1001, 1);
	std::fill(dp2, dp2 + 1001, 1);
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (arr[i] > arr[j])
				dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}
	for (int i = n; i >= 1; --i)
	{
		for (int j = i; j <= n; ++j)
		{
			if (arr[i] > arr[j])
				dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}
	int Max = 1;
	for (int i = 1; i <= n; ++i)
	{
		Max = max(Max, dp1[i] + dp2[i] - 1);
	}
	cout << Max;
}