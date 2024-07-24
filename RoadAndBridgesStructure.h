#ifndef ROAD_AND_BRIDGES_STRUCTURE
#define ROAD_AND_BRIDGES_STRUCTURE



#include "Heap.h"
#include "Road.h"

class RoadAndBridgesStructure
{
private:
	Heap heap;
	Road** roads;
	int numOfRoads;
public:
	RoadAndBridgesStructure(int numOfRoads);
	~RoadAndBridgesStructure();
	void init();
	void AddBridge(float h, int r);
	void moveItemToPlace(int heapIndex);
	int getMaxChildIndex(int indexParent);
	void swapHeapItems(int index1, int index2);
	void swap(int* index1, int* index2);
	void WhichRoad(float height) const;
	void Print(int r) const;

};


#endif // !ROAD_AND_BRIDGES_STRUCTURE