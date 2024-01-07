#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int arr[501];
int dp[501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int idx;
	int maxIdx = 1;
	for (int i = 1; i <= n; ++i)
	{
		cin >> idx;
		maxIdx = max(idx, maxIdx);
		cin >> arr[idx];
	}
	vector<int> vec;
	for (int i = 1; i <= maxIdx; ++i)
	{
		if (arr[i])
			vec.push_back(arr[i]);
	}
	int Max = 1;
	for (int i = 0; i < vec.size(); ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
		{
			if (vec[j] < vec[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		Max = max(dp[i], Max);
	}
	cout << n - Max;
}