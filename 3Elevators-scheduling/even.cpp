#include "even.h"
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;



int even::goToFloor(int waitFloor, int toFloor, int time)
{
	state = 1;
	sumtime = time;
	sumtime += abs(waitFloor - toFloor);
	currentFloor = toFloor;
	show(sumtime, currentFloor);
	stop(sumtime);
	state = 0;//жуж╧

	return currentFloor;
	
}

int even::stop(int time)
{
	time++;
	return time;
}

void even::show(int time, int currentFloor)
{
	ofstream outfile3("./output3.txt", ios::app);
	outfile3 << time << " " << currentFloor << endl;
	outfile3.close();
}

even::even()
{
}


even::~even()
{
}
