#include "Elevactor.h"
#include<math.h>



Elevactor::Elevactor()
{
}


Elevactor::~Elevactor()
{
}

int Elevactor::goToFloor(int waitFloor,int requestFloor,int requestTime,int time,int currentFloor )
{
	int temp;
	temp = time;
	time += (abs)(requestTime - temp);
	time += (abs)(currentFloor - requestFloor);
	currentFloor = requestFloor;

	return time;
}

int Elevactor::stop(int requestFloor,int time)
{
	if (requestFloor == currentFloor)
		time++;

	return time;
}

int Elevactor::updateDestination(int request, int ren)
{
	if (request == currentFloor)
		ren--;
	return 0;//感觉楼少的时候这个函数没啥用。
}
