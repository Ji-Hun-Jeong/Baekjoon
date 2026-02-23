#include <iostream>
#include <string>
#include <climits>
#include <array>
#include <vector>
#include <cassert>
#include <set>
#include <queue>

enum { Max = 20 };
int32_t N;

struct TVec2
{
	int32_t X = 0;
	int32_t Y = 0;
};

bool operator == (TVec2 InA, TVec2 InB)
{
	return InA.X == InB.X && InA.Y == InB.Y;
}

TVec2 operator + (TVec2 InA, TVec2 InB)
{
	return TVec2{ InA.X + InB.X , InA.Y + InB.Y };
}

TVec2 operator - (TVec2 InA, TVec2 InB)
{
	return TVec2{ InA.X - InB.X , InA.Y - InB.Y };
}

struct TBlock
{
	int32_t Value = 0;
};

struct TBoardContext
{
	TBlock Blocks[Max][Max];
	size_t MaxValue = 0;
	uint32_t Count = 0;
};

class CBoardController
{
public:
	CBoardController() = default;
	~CBoardController() = default;

public:
	TVec2 GetStart(TVec2 InDirection)
	{
		int32_t StartX = 0, StartY = 0;
		if (InDirection == TVec2(-1, 0))
		{
			StartX = 0;
			StartY = 0;
		}
		else if (InDirection == TVec2(1, 0))
		{
			StartX = N - 1;
			StartY = 0;
		}
		else if (InDirection == TVec2(0, 1))
		{
			StartX = 0;
			StartY = N - 1;
		}
		else if (InDirection == TVec2(0, -1))
		{
			StartX = 0;
			StartY = 0;
		}
		else
			assert(0);
		return TVec2{ StartX, StartY };
	}

	struct TBlockInfo
	{
		TVec2 Pos;
		TBlock Block;
		int32_t Priority = 0;
		bool operator > (const TBlockInfo& InOther) const
		{
			return Priority > InOther.Priority;
		}
	};

	TBoardContext ProgressOneTilt(const TBoardContext& InCurrentContext, TVec2 InDirection)
	{
		Collisions.clear();

		TBoardContext Result = InCurrentContext;

		std::priority_queue<TBlockInfo, std::vector<TBlockInfo>, std::greater<TBlockInfo>> BlockInfos;
		TVec2 StartXY = GetStart(InDirection);
		for (int32_t i = 0; i < N; ++i)
		{
			for (int32_t j = 0; j < N; ++j)
			{
				if (InCurrentContext.Blocks[i][j].Value != 0)
				{
					TBlockInfo BlockInfo;
					BlockInfo.Pos = TVec2{ j,i };
					BlockInfo.Block = InCurrentContext.Blocks[i][j];
					BlockInfo.Priority = std::abs(i - StartXY.Y) * N + std::abs(j - StartXY.X);
					BlockInfos.push(BlockInfo);
					Result.MaxValue = std::max<size_t>(Result.MaxValue, InCurrentContext.Blocks[i][j].Value);
				}
			}
		}

		while (BlockInfos.empty() == false)
		{
			const TBlockInfo& BlockInfo = BlockInfos.top();
			TVec2 PrevPosition = BlockInfo.Pos;
			TVec2 NextPosition = GetNextBlockPosition(Result, PrevPosition, BlockInfo.Block, InDirection);
			if (PrevPosition != NextPosition)
			{
				int32_t Value = Result.Blocks[PrevPosition.Y][PrevPosition.X].Value;
				if (IsExist(Result, NextPosition))
				{
					TBlock ExistBlock = Result.Blocks[NextPosition.Y][NextPosition.X];
					size_t CollisionKey = GetCollisionKey(NextPosition);
					if (Collisions.contains(CollisionKey) == false && ExistBlock.Value == BlockInfo.Block.Value)
					{
						Value *= 2;
						Result.MaxValue = std::max<size_t>(Result.MaxValue, Value);
						Collisions.insert(CollisionKey);
					}
					else
						NextPosition = NextPosition - InDirection;
				}
				Move(PrevPosition, NextPosition, Value, &Result);
			}
			BlockInfos.pop();
		}

		return Result;
	}

	void Move(TVec2 InPosition, TVec2 InNextPosition, int32_t InValue, TBoardContext* OutBoardContext)
	{
		OutBoardContext->Blocks[InPosition.Y][InPosition.X].Value = 0;
		OutBoardContext->Blocks[InNextPosition.Y][InNextPosition.X].Value = InValue;
	}

	bool IsExist(const TBoardContext& InContext, TVec2 InPosition)
	{
		return InContext.Blocks[InPosition.Y][InPosition.X].Value;
	}

	TVec2 GetNextBlockPosition(const TBoardContext& InNextContext, TVec2 InPosition, TBlock InBlock, TVec2 InDirection)
	{
		TVec2 ResultPosition = InPosition;
		while (true)
		{
			ResultPosition = ResultPosition + InDirection;
			if (ResultPosition.X < 0 || ResultPosition.X >= N || ResultPosition.Y < 0 || ResultPosition.Y >= N)
			{
				ResultPosition = ResultPosition - InDirection;
				break;
			}
			if (InNextContext.Blocks[ResultPosition.Y][ResultPosition.X].Value != 0)
				break;
		}
		return ResultPosition;
	}
	size_t GetCollisionKey(TVec2 InPosition)
	{
		return InPosition.Y * N + InPosition.X;
	}
private:
	std::set<size_t> Collisions;

};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	TBoardContext FirstContext;
	std::cin >> N;
	for (int32_t i = 0; i < N; ++i)
		for (int32_t j = 0; j < N; ++j)
			std::cin >> FirstContext.Blocks[i][j].Value;

	std::queue<TBoardContext> BoardContexts;
	BoardContexts.push(FirstContext);

	CBoardController BoardController;
	size_t MaxValue = 0;
	TVec2 Offsets[4] = { TVec2{ -1,0 } , TVec2{1,0 } ,TVec2{ 0,1 } ,TVec2{ 0,-1} };
	while (BoardContexts.empty() == false)
	{
		const TBoardContext& BoardContext = BoardContexts.front();

		for (size_t i = 0; i < 4; ++i)
		{
			TBoardContext New = BoardController.ProgressOneTilt(BoardContext, Offsets[i]);
			MaxValue = std::max<size_t>(MaxValue, New.MaxValue);
			New.Count += 1;
			if (New.Count < 5)
				BoardContexts.push(New);
		}

		BoardContexts.pop();
	}
	std::cout << MaxValue;
}