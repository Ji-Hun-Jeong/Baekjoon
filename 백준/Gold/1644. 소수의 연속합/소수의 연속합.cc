#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define SIZE 4000001
bool arr[SIZE];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	vector<int> vec;
	vec.reserve(n);
	int range = sqrt(n);
	for (int i = 2; i <= range; ++i)
	{
		if (arr[i])continue;
		for (int j = 2; i * j <= n; ++j)
		{
			arr[i * j] = true;
		}
	}
	for (int i = 2; i <= n; ++i)
	{
		if (!arr[i])
			vec.push_back(i);
	}
	int low = 0;
	int high = 0;
	int cnt = 0;
	int value = vec[low];
	while (high < vec.size())
	{
		if (value == n)
			++cnt;
		if (value <= n)
		{
			++high;
			if (high >= vec.size())
				break;
			value += vec[high];
		}
		else
		{
			value -= vec[low];
			++low;
		}
	}
	cout << cnt;
}