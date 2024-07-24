#ifndef BRIDGE_LIST
#define BRIDGE_LIST


class BridgeList;

class BridgeNode 
{
private: 
	float height;
	BridgeNode* next;
	friend class BridgeList;
	
public:
	BridgeNode(float height, BridgeNode* next);
};


class BridgeList
{
private:
	BridgeNode* head;
	BridgeNode* tail;
public:
	BridgeList();
	~BridgeList();
	void insertDataToStart(float h);
	void printList();
};

#endif // !BRIDGE_LIST