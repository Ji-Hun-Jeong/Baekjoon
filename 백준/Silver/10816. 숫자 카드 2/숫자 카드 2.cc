#include <iostream>

int arr[20000001];
int main()
{
	int N, M;
	int value = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &value);
		arr[10000000 + value] += 1;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &value);
		printf("%d ", arr[10000000 + value]);
	}
}