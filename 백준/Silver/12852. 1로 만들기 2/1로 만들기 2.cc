#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
int N;
int arr[500];
int rSize = 500;
int result[500];
void Copy(int* const dest, const int* const src, int n)
{
	for (int i = 0; i <= n; ++i)
		dest[i] = src[i];
}
void dfs(int idx)
{
	if (idx >= rSize)
		return;
	int num = arr[idx];
	if (num == 1)
	{
		if (idx < rSize)
		{
			Copy(result, arr, idx);
			rSize = idx;
		}
		return;
	}
	if (0 == num % 3)
	{
		arr[idx+1] = num / 3;
		dfs(idx + 1);
	}
	if (0 == num % 2)
	{
		arr[idx+1] = num / 2;
		dfs(idx + 1);
	}
	arr[idx+1] = num - 1;
	dfs(idx + 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	arr[0] = N;
	dfs(0);
	cout << rSize << "\n";
	for (int i = 0; i <= rSize; ++i)
		cout << result[i] << " ";
}