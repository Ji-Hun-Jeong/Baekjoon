#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

char sameCheck(string* str, int startX, int finishX, int startY, int finishY)
{
	char ch = str[startY][startX];
	for (int i = startY; i < finishY; ++i)
	{
		for (int j = startX; j < finishX; ++j)
		{
			if (ch != str[i][j])
			{
				return 'n';
			}
		}
	}
	return ch;
}
void quard(string* str, int startX, int finishX, int startY, int finishY)
{
	int diffX = finishX - startX;
	int diffY = finishY - startY;
	char ch = sameCheck(str, startX, finishX, startY, finishY);
	switch (ch)
	{
	case 'n':
		cout << "(";
		quard(str, startX, startX + diffX / 2, startY, startY + diffY / 2);
		quard(str, startX + diffX / 2, finishX, startY, startY + diffY / 2);
		quard(str, startX, startX + diffX / 2, startY + diffY / 2, finishY);
		quard(str, startX + diffX / 2, finishX, startY + diffY / 2, finishY);
		cout << ")";
		break;
	default:
		cout << ch;
		break;
	}
}
int main()
{
	int n;
	(cin >> n).ignore();
	string* pStr = new string[n];
	for (int i = 0; i < n; ++i)
	{
		getline(cin, pStr[i]);
	}
	quard(pStr, 0, n, 0, n);
}
