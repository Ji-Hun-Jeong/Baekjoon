#include <iostream>
#include <string>
using namespace std;
int N = 0;
int arr[2187][2187] = { 0 };
int a = 0, b = 0, c = 0;
bool Check(int sx, int sy, int n)
{
	for (int i = sy; i < sy + n; ++i)
		for (int j = sx; j < sx + n; ++j)
			if (arr[sy][sx] != arr[i][j])
				return false;
	return true;
}
void f(int sx, int sy, int n)
{
	bool check = Check(sx, sy, n);
	if (check)
	{
		arr[sy][sx] == -1 ? ++a : (arr[sy][sx] == 0 ? ++b : ++c);
		return;
	}
	f(sx, sy, n / 3);
	f(sx + n / 3, sy, n / 3);
	f(sx + n * 2 / 3, sy, n / 3);
	f(sx, sy + n / 3, n / 3);
	f(sx + n / 3, sy + n / 3, n / 3);
	f(sx + n * 2 / 3, sy + n / 3, n / 3);
	f(sx, sy + n * 2 / 3, n / 3);
	f(sx + n / 3, sy + n * 2 / 3, n / 3);
	f(sx + n * 2 / 3, sy + n * 2 / 3, n / 3);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];
	f(0, 0, N);
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}