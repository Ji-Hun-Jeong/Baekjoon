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
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	int low = 0;
	int high = n - 1;
	int minLow = 0;
	int minHigh = 0;
	int minValue = 2000000000;
	while (low < high)
	{
		int value = arr[low] + arr[high];
		if (abs(value) <= minValue)
		{
			minValue = abs(value);
			minLow = low;
			minHigh = high;
		}
		if (value > 0)
			--high;
		else if (value < 0)
			++low;
		else
		{
			minLow = low;
			minHigh = high;
			break;
		}	
	}
	cout << arr[minLow] << " " << arr[minHigh];
}