#include "normal.h"
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;


int normal::goToFloor(int waitFloor, int toFloor, int time)
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

int normal::stop(int time)
{
	time++;
	return time;
}

void normal::show(int time, int currentFloor)
{
	ofstream outfile2("./output2.txt", ios::app);
	outfile2 << time << " " << currentFloor << endl;
	outfile2.close();
}

normal::normal()
{
}


normal::~normal()
{
}
