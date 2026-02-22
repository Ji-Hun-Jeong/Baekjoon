#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int arr[100001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int low = 0;
	int high = 0;
	int minLength = 100001;
	int value = arr[low];
	if (value >= s)
	{
		cout << 1;
		return 0;
	}
	while (high < n)
	{
		if (value < s)
		{
			++high;
			if (high >= n)
				break;
			value += arr[high];
		}
		else
		{
			if (minLength > high - low + 1)
				minLength = high - low + 1;
			if (low == high)
				break;
			value -= arr[low];
			++low;
		}
	}
	if (minLength == 100001)
		minLength = 0;
	cout << minLength;
}