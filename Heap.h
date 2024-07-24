#ifndef HEAP
#define HEAP



const float NO_BRIDGES = -1;

class RoadHeapItem
{
private:
	float minHeight;
	
	int numRoad;
public:
	RoadHeapItem(int numRoad);
	void setMin(float min);
	float getMin();
	void setNumRoad(int num);
	int getNumRoad();
};

class Heap
{
private:
	RoadHeapItem** heapArr;
	int sizeHeap;

	friend class RoadAndBridgesStructure;
public:
	Heap(int m);
	~Heap();
	float getMin();
	//void fixHeap();
	//int find(float key);
	//void insert()

};

#endif // !HEAP