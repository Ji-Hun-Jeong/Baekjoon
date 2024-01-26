#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef unsigned long long ulonglong;
ulonglong N;
map<ulonglong, ulonglong> m;
ulonglong dev(ulonglong n)
{
	if (n <= 1) return n;
	auto iter = m.find(n);
	if (iter != m.end()) return iter->second;
	ulonglong mid = n / 2;
	if (0 == n % 2)
	{
		ulonglong a = dev(mid);
		ulonglong b = dev(mid - 1);
		ulonglong r = ((m.find(mid)->second + m.find(mid - 1)->second) * a + m.find(mid)->second * b)% 1000000007;
		m.insert(make_pair(n, r));
		return r;
	}
	else
	{
		ulonglong a = dev(mid + 1);
		ulonglong b = dev(mid);
		ulonglong r = (m.find(mid + 1)->second * a + m.find(mid)->second * b) % 1000000007;
		m.insert(make_pair(n, r));
		return r;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	m.insert(make_pair(0, 0));
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 1));
	cout << dev(N);
}