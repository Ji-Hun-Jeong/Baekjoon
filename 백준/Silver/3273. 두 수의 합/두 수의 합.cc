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
	int x;
	cin >> x;
	sort(arr, arr + n);
	int low = 0;
	int high = n - 1;
	int cnt = 0;
	while (low < high)
	{
		if (x == arr[low] + arr[high])
		{
			++cnt;
			++low;
			--high;
		}
		else if (x < arr[low] + arr[high])
			--high;
		else
			++low;
	}
	cout << cnt;
}