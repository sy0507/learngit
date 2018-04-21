#pragma once
class Elevactor
{
public:
	int currentFloor = 0;
	int waitFloor;
	int requestFloor;
	int requestTime;
	Elevactor();
	~Elevactor();

	int goToFloor(int waitFloor, int requestFloor, int requestTime, int time, int currentFloor);
	int stop(int requestFloor, int time);
	int updateDestination(int request, int ren);
};

