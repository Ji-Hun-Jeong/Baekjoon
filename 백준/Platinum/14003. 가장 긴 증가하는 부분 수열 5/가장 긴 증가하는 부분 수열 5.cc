#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
#define SIZE 1000001
int arr[SIZE];
int dp[SIZE];
int path[SIZE];
int idxArr[SIZE];
int result[SIZE];
int bs(int num, int size)
{
	int low = 1;
	int high = size - 1;
	int mid = 0;
	while (true)
	{
		mid = (low + high) / 2;
		if (low > high)
			break;
		if (dp[mid] == num)
			return mid;
		else if (dp[mid] < num)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return mid + 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	int maxSize = 2;
	dp[1] = arr[1];
	idxArr[1] = 1;
	path[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		int idx = bs(arr[i], maxSize);
		if (idx == maxSize)
		{
			++maxSize;
		}	
		dp[idx] = arr[i];
		idxArr[idx] = i;
		path[i] = idx == 1 ? 0 : idxArr[idx - 1];
	}
	cout << maxSize - 1 << endl;
	int size = --maxSize;
	result[maxSize] = dp[maxSize];
	int idx = idxArr[maxSize];
	while (idx)
	{
		result[--maxSize] = arr[path[idx]];
		idx = path[idx];
	}
	for (int i = 1; i <= size; ++i)
		cout << result[i] << " ";
}