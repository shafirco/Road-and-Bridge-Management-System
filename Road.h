#ifndef ROAD
#define ROAD


#include "BridgeList.h"
#include "Heap.h"


class Road
{
private:
	BridgeList* bridges;
	//RoadHeapItem* heapItem;
	int heapIndex;
	int numRoad;
	friend class RoadAndBridgesStructure;
public:
	Road(int numRoad);
	~Road();
	void insertBridge(float h);
	void resetRoad();
};




#endif // !ROAD