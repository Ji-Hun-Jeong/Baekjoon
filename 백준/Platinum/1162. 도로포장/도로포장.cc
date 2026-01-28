#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

enum { MaxVertex = 10001, MaxPave = 21 };
int32_t N, M, K;
struct TEdge
{
	int32_t Vertex;
	size_t Weight;
};
std::vector<TEdge> VertexEdges[MaxVertex];
size_t MinDist[MaxVertex][MaxPave];

bool operator < (const TEdge& InA, const TEdge& InB)
{
	return InA.Weight > InB.Weight;
}
std::vector<int32_t> RoadInfos[MaxVertex];

struct TQueueInfo : public TEdge
{
	int32_t Chance;
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M >> K;
	for (int32_t i = 0; i < M; ++i)
	{
		int32_t a, b, c;
		std::cin >> a >> b >> c;
		VertexEdges[a].emplace_back(b, c);
		VertexEdges[b].emplace_back(a, c);
	}
	for (int32_t i = 1; i <= N; ++i)
		std::fill(MinDist[i], MinDist[i] + K + 1, SIZE_MAX);
	std::fill(MinDist[1], MinDist[1] + K + 1, 0);

	std::priority_queue<TQueueInfo> QueueInfos;
	QueueInfos.emplace(TQueueInfo{ 1, 0 ,0 });

	while (QueueInfos.empty() == false)
	{
		TQueueInfo QueueInfo = QueueInfos.top();
		QueueInfos.pop();

		int32_t Vertex = QueueInfo.Vertex;
		size_t Weight = QueueInfo.Weight;
		int32_t Chance = QueueInfo.Chance;

		if (MinDist[Vertex][Chance] < Weight)
			continue;

		const std::vector<TEdge>& AdjEdges = VertexEdges[Vertex];
		for (TEdge AdjEdge : AdjEdges)
		{
			int32_t NextVertex = AdjEdge.Vertex;
			size_t NextWeight = AdjEdge.Weight;

			if (Chance + 1 <= K)
			{
				size_t PaveWeight = Weight + 0;
				if (PaveWeight < MinDist[NextVertex][Chance + 1])
				{
					MinDist[NextVertex][Chance + 1] = PaveWeight;
					QueueInfos.emplace(TQueueInfo{ NextVertex, PaveWeight, Chance + 1 });
				}
			}
			if (Chance <= K)
			{
				size_t DontPaveWeight = Weight + NextWeight;
				if (DontPaveWeight < MinDist[NextVertex][Chance])
				{
					MinDist[NextVertex][Chance] = DontPaveWeight;
					QueueInfos.emplace(TQueueInfo{ NextVertex, DontPaveWeight, Chance });
				}
			}
		}
	}

	size_t Min = SIZE_MAX;
	for (int32_t i = 0; i <= K; ++i)
	{
		if (MinDist[N][i] < Min)
			Min = MinDist[N][i];
	}
	std::cout << Min;
}