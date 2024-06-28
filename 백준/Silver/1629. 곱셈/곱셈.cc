#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int f(int a, int b, int c)
{
	unsigned int Double = 1;
	unsigned long long result = a % c;
	while (Double != b)
	{
		if (Double * 2 <= b)
		{
			result = (result * result) % c;
			Double *= 2;
		}
		else if (Double * 2 > b)
		{
			result = (result * f(a, b - Double, c)) % c;
			return result;
		}
	}
	return result;
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << f(a, b, c);
}