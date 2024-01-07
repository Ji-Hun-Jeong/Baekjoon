#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<pair<int, int>> vec;
int dp[100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int num;
	pair<int, int> p;
	for (int i = 0; i < n; ++i)
	{
		cin >> num;
		p.first = num;
		cin >> num;
		p.second = num;
		vec.push_back(p);
	}
	auto um = [](pair<int, int>& a, pair<int, int>& b) {return a.first < b.first; };
	sort(vec.begin(), vec.end(), um);
	dp[0] = 1;
	int Max = dp[0];
	for (int i = 1; i < n; ++i)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 0; --j)
		{
			if (vec[i].second > vec[j].second)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		Max = max(Max, dp[i]);
	}
	cout << n - Max;
}