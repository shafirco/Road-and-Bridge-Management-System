#include <iostream>
#include "BridgeList.h"

using namespace std;

BridgeNode::BridgeNode(float height, BridgeNode* next)
{
	this->height = height;
	this->next = next;
}

BridgeList::BridgeList()
{
	head = nullptr;
	tail = nullptr;
}

BridgeList::~BridgeList()
{
	BridgeNode* curr = head;
	BridgeNode* next;

	while (curr != nullptr)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
}

void BridgeList::insertDataToStart(float h)
{
	BridgeNode* newNode = new BridgeNode(h, head);
	if (head == nullptr)
		head = tail = newNode;
	else
		head = newNode;
}
void BridgeList::printList()
{
	BridgeNode* curr = head;
	while (curr != nullptr)
	{
		if(curr->height>0)
			cout << curr->height << endl;
		curr = curr->next;
	}
}
