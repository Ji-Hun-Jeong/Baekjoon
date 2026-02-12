#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int arr['z' - 'a' + 1][200001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string str;
	str.reserve(200001);
	getline(cin, str);
	char ch = 0;
	for (int i = 1; i <= str.size(); ++i)
	{
		ch = str[i - 1];
		for (int j = 0; j <= 'z' - 'a'; ++j)
		{
			if (ch - 'a' == j)
				arr[j][i] = arr[j][i - 1] + 1;
			else
				arr[j][i] = arr[j][i - 1];
		}
	}
	int n;
	cin >> n;
	int s, f;
	for (int i = 0; i < n; ++i)
	{
		cin >> ch >> s >> f;
		cout << arr[ch - 'a'][f + 1] - arr[ch - 'a'][s] << '\n';
	}
}