#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
string str1;
string str2;
int dp[1001][1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	getline(cin, str1);
	getline(cin, str2);
	for (int i = 1; i <= str2.size(); ++i)
	{
		char ch2 = str2[i - 1];
		for (int j = 1; j <= str1.size(); ++j)
		{
			char ch1 = str1[j - 1];
			if (ch2 == ch1)
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int x = str1.size();
	int y = str2.size();
	int length = dp[y][x];
	string result;
	cout << length << endl;
	while (length)
	{
		while(dp[y][x-1] == length)
			--x;
		if (str2[y-1] == str1[x-1])
		{
			result += str1[x-1];
			--x; --y;
			--length;
		}
		else
			--y;
	}
	for (int i = result.size() - 1; i >= 0; --i)
		cout << result[i];
}