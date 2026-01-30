#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>

enum { MaxProblem = 32001 };
int32_t N, M;
std::vector<int32_t> AfterProblemArray[MaxProblem];
int32_t RefCount[MaxProblem];
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;
	for(int32_t i =0;i<M;++i)
	{
		int32_t A, B;
		std::cin >> A >> B;
		AfterProblemArray[A].push_back(B);
		RefCount[B] += 1;
	}


	std::priority_queue<int32_t, std::vector<int32_t>, std::greater<int32_t>> Problems;
	for (int32_t i = 1; i <= N; ++i)
	{
		if (RefCount[i] == 0)
			Problems.push(i);
	}

	while (Problems.empty() == false)
	{
		int32_t Problem = Problems.top();
		Problems.pop();

		std::cout << Problem << " ";

		const auto& AfterProblems = AfterProblemArray[Problem];
		for (int32_t AfterProblem : AfterProblems)
		{
			RefCount[AfterProblem] -= 1;
			if (RefCount[AfterProblem] == 0)
				Problems.push(AfterProblem);
		}
	}
}