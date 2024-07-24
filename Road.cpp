#include "Road.h"

Road::Road(int numRoad)
{
	bridges = new BridgeList;
	//heapItem = new RoadHeapItem(numRoad);
	heapIndex = numRoad - 1;
	this->numRoad= numRoad;

}
Road::~Road()
{
	delete bridges;
	//delete heapItem;
}

void Road::insertBridge(float h)
{
	/*if (heapItem->getMin() > h)
		heapItem->setMin(h);*/
	bridges->insertDataToStart(h);
}

void Road::resetRoad()
{
	delete bridges;
	bridges = new BridgeList;
	/*heapItem->setMin(NO_BRIDGES);*/
}
