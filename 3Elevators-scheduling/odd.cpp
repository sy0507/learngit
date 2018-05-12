#include "odd.h"
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;



int odd::goToFloor(int waitFloor, int toFloor, int time)
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

int odd::stop(int time)
{
	time++;
	return time;
}

void odd::show(int time, int currentFloor)
{
	ofstream outfile1("./output1.txt", ios::app);
	outfile1 << time << " " << currentFloor << endl;
	outfile1.close();
}


odd::odd()
{
}


odd::~odd()
{
}
