#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int N, C;
int arr1[30];
vector<int> result1;
vector<int> result2;
void dfs(int* arr, long long sumOfArr, int n, int end, vector<int>& result)
{
	if (n == end)
	{
		if (sumOfArr <= C)
			result.push_back(sumOfArr);
		return;
	}
	dfs(arr, sumOfArr, n + 1, end, result);
	dfs(arr, sumOfArr + arr[n], n + 1, end, result);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> C;
	for (int i = 0; i < N; ++i)
		cin >> arr1[i];
	dfs(arr1, 0, 0, N / 2, result1);
	dfs(arr1, 0, N / 2, N, result2);
	std::sort(result2.begin(), result2.end());
	int cnt = 0;
	for (int i = 0; i < result1.size(); ++i)
	{
		int sum = C - result1[i];
		int low = 0;
		int high = result2.size() - 1;
		int mid = 0;
		while (low <= high)
		{
			mid = (low + high) / 2;
			int midValue = result2[mid];
			if (midValue < sum)
				low = mid + 1;
			else if (midValue > sum)
				high = mid - 1;
			else
			{
				break;
			}
		}
		int j = mid;
		for (; j < result2.size(); ++j)
		{
			if (result2[j] > sum)
			{
				break;
			}
		}
		cnt += j;
	}
	cout << cnt;
}