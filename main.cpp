#include "RoadAndBridgesStructure.h"



int main()
{
	RoadAndBridgesStructure st(5);
	st.AddBridge(2.2, 1);
	//st.AddBridge(5, 1);
	//st.AddBridge(7.2, 1);
	st.AddBridge(9.2, 3);
	st.AddBridge(7.1, 2);
	st.AddBridge(2.2, 5);
	st.AddBridge(3.5, 4);
	//st.AddBridge(4.2, 5);
	st.WhichRoad(10);
	st.Print(1);
}