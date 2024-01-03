#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
unsigned long long arr[101] = { 1,1,1,2,2,0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 5; i < 101; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 5];
		if (arr[i] < 0)
		{
			int a = 1;
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int N;
		cin >> N;
		cout << arr[N-1] << '\n';
	}
}