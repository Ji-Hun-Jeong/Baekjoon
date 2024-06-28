#include <iostream>
#include <string>
#include <cmath>
using namespace std;
long long A = 0, B = 0, C = 0;

long long f(long long n)
{
	if (1 == n)
		return A % C;
	long long value = f(n / 2) % C;
	long long result = value * value % C;
	if (n % 2 == 0)
		return result;
	else
		return (result % C) * (A % C);
}
int main()
{
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> A >> B >> C;
	cout << f(B) % C;
}
