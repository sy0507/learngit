#include<iostream>
#include<queue>
#include<fstream>
#include"Elevactor.h"
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
int time=0;
int currentFloor = 0;
int waitFloor;
int requestFloor;
int requestTime;
struct custom
{
	int requestTime;
	int waitFloor;//�ȴ���¥��
	int requestFloor;//ȥ��¥��
	int flag;
}cus[1000];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ofstream outFile;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cus[i].requestFloor;
		cin >> cus[i].requestTime;
		cin >> cus[i].waitFloor;
	}
	for (int i = 0; i < n-1; i++)
	{
		if (cus[i].requestFloor == cus[i + 1].requestFloor&&cus[i + 1].requestTime - cus[i].requestTime < 2 && cus[i + 1].waitFloor - cus[i].waitFloor == 1)
			cus[i].requestFloor--;//��¥��ʱ���������������������0 0 2   1 1 2
		if (cus[i].requestFloor == cus[i + 1].requestFloor&&cus[i + 1].requestTime - cus[i].requestTime < 2 && cus[i].waitFloor - cus[i + 1].waitFloor == 1)
			cus[i].waitFloor--;//��¥ʱ����������������� 020     120
	}
	for (int i = 0; i < n; i++)
	{
		waitFloor = cus[i].waitFloor;
		requestFloor = cus[i].requestFloor;
		requestTime = cus[i].requestTime;
		int goToFloor(int waitFloor, int requestFloor, int requestTime, int time, int currentFloor);
		int stop(int requestFloor, int time);
		cout << time << ' ' << currentFloor << endl;
       
	}
	
}
 