#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <array>
#include <cmath>

enum { Max = 10 };
char Board[Max][Max];
bool bVisited[Max][Max][Max][Max];

struct TVec2
{
	int32_t X = 0;
	int32_t Y = 0;
};
TVec2 Offsets[4] = { {-1,0}, {0,-1}, {1,0}, {0,1} };

bool operator == (TVec2 InA, TVec2 InB)
{
	return InA.X == InB.X && InA.Y == InB.Y;
}

bool operator != (TVec2 InA, TVec2 InB)
{
	return !(InA == InB);
}

TVec2 operator + (TVec2 InA, TVec2 InB)
{
	return TVec2{ InA.X + InB.X, InA.Y + InB.Y };
}

TVec2 operator - (TVec2 InA, TVec2 InB)
{
	return TVec2{ InA.X - InB.X, InA.Y - InB.Y };
}

enum class EHoleStateType : uint32_t
{
	None,
	Red,
	Blue,
};

struct TBoardContext
{
	TVec2 Red;
	TVec2 Blue;
	EHoleStateType HoleState = EHoleStateType::None;
	uint32_t Count = 0;
};

TBoardContext Progress(const TBoardContext& InCurrentBoardContext, TVec2 InDirection)
{
	TBoardContext ResultContext = InCurrentBoardContext;
	int32_t RedDist = 0;
	int32_t BlueDist = 0;

	while (Board[ResultContext.Red.Y + InDirection.Y][ResultContext.Red.X + InDirection.X] != '#' &&
		Board[ResultContext.Red.Y][ResultContext.Red.X] != 'O')
	{
		ResultContext.Red = ResultContext.Red + InDirection;
		RedDist += 1;
		if (Board[ResultContext.Red.Y][ResultContext.Red.X] == 'O') break;
	}

	while (Board[ResultContext.Blue.Y + InDirection.Y][ResultContext.Blue.X + InDirection.X] != '#' &&
		Board[ResultContext.Blue.Y][ResultContext.Blue.X] != 'O')
	{
		ResultContext.Blue = ResultContext.Blue + InDirection;
		BlueDist += 1;
		if (Board[ResultContext.Blue.Y][ResultContext.Blue.X] == 'O') break;
	}

	bool bRedHole = (Board[ResultContext.Red.Y][ResultContext.Red.X] == 'O');
	bool bBlueHole = (Board[ResultContext.Blue.Y][ResultContext.Blue.X] == 'O');

	if (bBlueHole)
		ResultContext.HoleState = EHoleStateType::Blue;
	else if (bRedHole)
		ResultContext.HoleState = EHoleStateType::Red;

	if (!bBlueHole && !bRedHole && ResultContext.Red == ResultContext.Blue)
	{
		if (RedDist > BlueDist)
			ResultContext.Red = ResultContext.Red - InDirection;
		else
			ResultContext.Blue = ResultContext.Blue - InDirection;
	}

	return ResultContext;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t N, M;
	std::cin >> N >> M;

	TBoardContext FirstContext;
	for (int32_t i = 0; i < N; ++i)
	{
		for (int32_t j = 0; j < M; ++j)
		{
			std::cin >> Board[i][j];
			if (Board[i][j] == 'R')
			{
				FirstContext.Red.Y = i;
				FirstContext.Red.X = j;
			}
			else if (Board[i][j] == 'B')
			{
				FirstContext.Blue.Y = i;
				FirstContext.Blue.X = j;
			}
		}
	}
	FirstContext.Count = 0;
	FirstContext.HoleState = EHoleStateType::None;

	std::queue<TBoardContext> BoardContexts;
	BoardContexts.push(FirstContext);

	bVisited[FirstContext.Red.Y][FirstContext.Red.X][FirstContext.Blue.Y][FirstContext.Blue.X] = true;

	int32_t FinalAns = -1;

	while (BoardContexts.empty() == false)
	{
		TBoardContext CurrentBoardContext = BoardContexts.front();
		BoardContexts.pop();

		if (CurrentBoardContext.Count >= 10)
			continue;

		for (size_t i = 0; i < 4; ++i)
		{
			TBoardContext NextBoardContext = Progress(CurrentBoardContext, Offsets[i]);
			NextBoardContext.Count = CurrentBoardContext.Count + 1;

			if (NextBoardContext.HoleState == EHoleStateType::Blue)
				continue;

			if (NextBoardContext.HoleState == EHoleStateType::Red)
			{
				FinalAns = NextBoardContext.Count;
				break;
			}

			if (!bVisited[NextBoardContext.Red.Y][NextBoardContext.Red.X][NextBoardContext.Blue.Y][NextBoardContext.Blue.X])
			{
				bVisited[NextBoardContext.Red.Y][NextBoardContext.Red.X][NextBoardContext.Blue.Y][NextBoardContext.Blue.X] = true;
				BoardContexts.push(NextBoardContext);
			}
		}

		if (FinalAns != -1)
			break;
	}

	std::cout << FinalAns << '\n';
}