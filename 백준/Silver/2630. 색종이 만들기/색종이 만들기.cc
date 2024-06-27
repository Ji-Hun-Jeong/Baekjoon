#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void cal(vector<int>* pVec
	, int startX, int finishX
	, int startY, int finishY
	, int& blue, int& white)
{
	bool check = true;
	int color = pVec[startY][startX];
	for (int i = startY; i < finishY; ++i)
	{
		for (int j = startX; j < finishX; ++j)
		{
			if (color != pVec[i][j])
			{
				check = false;
				break;
			}
		}
	}
	if (check)
	{
		if (1 == color)
			++blue;
		else
			++white;
		return;
	}
	else
	{
		int diffX = finishX - startX;
		int diffY = finishY - startY;
		cal(pVec, startX, startX + diffX / 2, startY, startY + diffY / 2, blue, white);
		cal(pVec, startX, startX + diffX / 2, startY + diffY / 2, finishY, blue, white);
		cal(pVec, startX + diffX / 2, finishX, startY, startY + diffY / 2, blue, white);
		cal(pVec, startX + diffX / 2, finishX, startY + diffY / 2, finishY, blue, white);
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int>* pVec = new vector<int>[n];
	for (int i = 0; i < n; ++i)
	{
		pVec[i].reserve(n);
	}
	int num;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> num;
			pVec[i].push_back(num);
		}
	}
	int blue = 0;
	int white = 0;
	cal(pVec, 0, n, 0, n, blue, white);
	cout << white << endl << blue;
}
