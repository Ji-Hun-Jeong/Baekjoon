#include <iostream>
#include <string>
#include <climits>
#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <cassert>

enum { Max = 101 };
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

class CSnake
{
public:
	CSnake(TVec2 InFirstPosition)
	{
		Bodys.push_back(InFirstPosition);
	}
	~CSnake() = default;

public:
	TVec2 Move(TVec2 InDirection)
	{
		assert(InDirection != TVec2(0.0f, 0.0f));
		TVec2 NewHeadPosition = GetHead() + InDirection;
		Bodys.push_back(NewHeadPosition);
		return NewHeadPosition;
	}

	void EraseTail()
	{
		Bodys.pop_front();
	}

	TVec2 GetHead()
	{
		return Bodys.back();
	}

	bool IsBody(TVec2 InPosition)
	{
		TVec2 Head = GetHead();
		for(size_t i = 0;i<Bodys.size() - 1;++i)
			if (Bodys[i] == InPosition)
				return true;
		return false;
	}

private:
	std::deque<TVec2> Bodys;

};

TVec2 ChangeLeft(TVec2 InDirection)
{
	if (InDirection == TVec2{ 1, 0 })
		return TVec2{ 0,-1 };
	if (InDirection == TVec2{ -1, 0 })
		return TVec2{ 0,1 };
	if (InDirection == TVec2{ 0, 1 })
		return TVec2{ 1,0 };
	if (InDirection == TVec2{ 0, -1 })
		return TVec2{ -1,0 };
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int32_t N, K;
	std::cin >> N >> K;

	// true는 사과
	bool Board[Max][Max] = { false };
	for (int32_t i = 0; i < K; ++i)
	{
		int32_t Y, X;
		std::cin >> Y >> X;
		Board[Y][X] = true;
	}

	int32_t L;
	std::cin >> L;

	using Dir = std::pair<int32_t, char>;
	std::queue<Dir> Directions;
	for (int32_t i = 0; i < L; ++i)
	{
		Dir D;
		std::cin >> D.first >> D.second;
		Directions.push(D);
	}

	size_t Time = 0;
	CSnake Snake(TVec2{ 1,1 });

	TVec2 Direction{ 1,0 };
	while (true)
	{
		if (Directions.empty() == false)
		{
			Dir DirectionInfo = Directions.front();
			if (DirectionInfo.first == Time)
			{
				Direction = ChangeLeft(Direction);
				if (DirectionInfo.second == 'D')
				{
					Direction.X = -Direction.X;
					Direction.Y = -Direction.Y;
				}
				Directions.pop();
			}
		}
		
		TVec2 NewHead = Snake.Move(Direction);

		if (NewHead.X <= 0 || NewHead.X > N || NewHead.Y <= 0 || NewHead.Y > N)
			break;

		if (Snake.IsBody(NewHead))
			break;

		if (Board[NewHead.Y][NewHead.X])
			Board[NewHead.Y][NewHead.X] = false;
		else
			Snake.EraseTail();

		Time += 1;
	}

	std::cout << Time + 1;
}