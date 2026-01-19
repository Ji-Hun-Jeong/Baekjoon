#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<unsigned long long> dis;
	dis.reserve(n);
	vector<unsigned long long> cost;
	cost.reserve(n);
	unsigned long long in;
	for (int i = 0; i < n-1; ++i)
	{
		cin >> in;
		dis.push_back(in);
	}
	dis.push_back(0);
	for (int i = 0; i < n; ++i)
	{
		cin >> in;
		cost.push_back(in);
	}
	unsigned long long sum = 0;
	for (int i = 0; i < cost.size() - 1; )
	{
		int skip = 1;
		unsigned long long hap = 0;
		if (cost[i] >= cost[i + 1])
		{
			sum += cost[i] * dis[i];
			++i;
		}
		else if (cost[i] < cost[i + 1])
		{
			while (true)
			{
				hap += dis[i + skip - 1];
				if (cost[i] > cost[i + skip])
					break;
				++skip;
			}
			sum += cost[i] * hap;
			i += skip;
		}
	}
	cout << sum;
}
