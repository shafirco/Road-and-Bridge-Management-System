#include <iostream>
#include "RoadAndBridgesStructure.h"
using namespace std;


RoadAndBridgesStructure::RoadAndBridgesStructure(int numOfRoads):heap(numOfRoads)
{
	roads = new Road*[numOfRoads];
	for (int i = 0; i < numOfRoads; i++)
		roads[i] = new Road(i + 1);
	
	this->numOfRoads = numOfRoads;
}
RoadAndBridgesStructure::~RoadAndBridgesStructure()
{
	for (int i = 0; i < numOfRoads; i++)
		delete roads[i];
	delete[] roads;
}
void RoadAndBridgesStructure::init()
{
	for (int i = 0; i < numOfRoads; i++)
	{
		roads[i]->resetRoad();
		heap.heapArr[i]->setNumRoad(i + 1);
		heap.heapArr[i]->setMin(NO_BRIDGES);
	}
}
void RoadAndBridgesStructure::AddBridge(float h, int r)
{
	roads[r - 1]->bridges->insertDataToStart(h);

	int heapIndex = roads[r - 1]->heapIndex;
	if (heap.heapArr[heapIndex]->getMin() > h || heap.heapArr[heapIndex]->getMin() == NO_BRIDGES)
	{
		heap.heapArr[heapIndex]->setMin(h);
		moveItemToPlace(heapIndex);
	}
}

void RoadAndBridgesStructure::moveItemToPlace(int heapIndex)
{
	int maxChildIndex;
	bool flag = true;
	while (flag)
	{
		maxChildIndex = getMaxChildIndex(heapIndex);
		if (maxChildIndex < 0)
			flag = false;
		else if((heap.heapArr[maxChildIndex]->getMin() < heap.heapArr[heapIndex]->getMin())&& heap.heapArr[maxChildIndex]->getMin()!=NO_BRIDGES)
			flag = false;
		else
		{
			swapHeapItems(maxChildIndex, heapIndex);
			swap(&roads[(heap.heapArr[maxChildIndex]->getNumRoad()) - 1]->numRoad, &roads[(heap.heapArr[heapIndex]->getNumRoad()) - 1]->numRoad);
			heapIndex = maxChildIndex;
		}
	}
}


int RoadAndBridgesStructure::getMaxChildIndex(int indexParent)
{
	if (numOfRoads / 2 <= indexParent)
		return -1;
	
	int leftChild = indexParent * 2 + 1;
	int	rightChild = indexParent * 2 + 2;
	if (rightChild >= numOfRoads)
		return leftChild;

	int minRightChild= heap.heapArr[rightChild]->getMin();
	int minLeftChild= heap.heapArr[leftChild]->getMin();
	if (minRightChild == NO_BRIDGES)
		return rightChild;
	else if (minLeftChild == NO_BRIDGES)
		return leftChild;
	else
		return minRightChild > minLeftChild ? rightChild : leftChild;

}
void RoadAndBridgesStructure::swapHeapItems(int index1, int index2)
{
	RoadHeapItem* temp;
	temp = heap.heapArr[index1];
	heap.heapArr[index1] = heap.heapArr[index2];
	heap.heapArr[index2] = temp;
}

void RoadAndBridgesStructure::swap(int* index1, int* index2)
{
	int tmp = *index2;
	*index2 = *index1;
	*index1 = tmp;
}

void RoadAndBridgesStructure::WhichRoad(float height) const
{
	if (height < heap.heapArr[0]->getMin() || heap.heapArr[0]->getMin() == NO_BRIDGES)
		cout << heap.heapArr[0]->getNumRoad() << endl;
	else
		cout << 0;
}
void RoadAndBridgesStructure::Print(int r) const
{
	roads[r - 1]->bridges->printList();
}
