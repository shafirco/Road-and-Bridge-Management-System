#include "Heap.h"

RoadHeapItem::RoadHeapItem(int numRoad)
{
	minHeight = NO_BRIDGES;
	this->numRoad = numRoad;
}

void RoadHeapItem::setMin(float min)
{
	this->minHeight = min;
}

float RoadHeapItem::getMin()
{
	return minHeight;
}

void RoadHeapItem::setNumRoad(int num)
{
	numRoad = num;
}
int RoadHeapItem::getNumRoad()
{
	return numRoad;
}

Heap::Heap(int m)
{
	sizeHeap = m;
	heapArr = new RoadHeapItem * [m];
	for (int i = 0; i < m; i++)
	{
		RoadHeapItem* itemHeap = new RoadHeapItem(i + 1);
		heapArr[i] = itemHeap;
	}
}
Heap::~Heap()
{
	for (int i = 0; i < sizeHeap; i++)
		delete heapArr[i];
	delete heapArr;
}
//void fixHeap();
//int find(float key);
//void insert();