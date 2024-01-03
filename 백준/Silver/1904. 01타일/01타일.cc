#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unsigned long long a = 1;
	unsigned long long b = 2;
	unsigned long long c = n;
	for (int i = 2; i < n; ++i)
	{
		c = (a + b) % 15746;
		a = b;
		b = c;
	}
	cout << c ;
}