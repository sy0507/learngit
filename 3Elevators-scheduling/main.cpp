#include"normal.h"
#include"even.h"
#include"odd.h"
#include<fstream>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct   cus {
	int requesttime;
	int waitFloor;
	int toFloor;
}cus[1000];
int main()
{
	even    evenelevator;
	odd     oddelevator;
	normal   normalelevator;
	int even_currentFloor = 1;
	int normal_currentFloor = 1;
	int odd_currentFloor = 1;
	ifstream infile(".input.txt");
	int n,i;
	infile >> n;
	for (i = 0; i < n; i++)
	{
		infile >> cus[i].requesttime;
		infile >> cus[i].waitFloor;
		infile >> cus[i].toFloor;

	}
	infile.close();
	//����Ҫ�ѵ�һλ���������������ѡʲô���ݣ���Ȼ��õľ��ǰ���Ҫ�����ĵ���ѡ��
	int sumtime = cus[0].requesttime;
	if (cus[0].toFloor % 2 == 0)//ż
	{
		even_currentFloor = evenelevator.goToFloor(even_currentFloor, cus[0].waitFloor, sumtime);//��߾������ڳ�ʼ��һ��������Ȼûʲô�õ��ǵ������á�
		even_currentFloor = evenelevator.goToFloor(even_currentFloor, cus[0].toFloor, sumtime);
	}
	else//�� 
	{
		odd_currentFloor = oddelevator.goToFloor(odd_currentFloor, cus[0].waitFloor, sumtime);
		odd_currentFloor = oddelevator.goToFloor(odd_currentFloor, cus[0].toFloor, sumtime);

	}
	for (i = 1; i < n; i++)
	{
		if (sumtime < cus[i].requesttime)//�����ݵȲ��ȿ��ˣ��ȵĻ�
			sumtime = cus[i].requesttime;
		if (sumtime >= evenelevator.sumtime&&cus[i].waitFloor % 2 == 0 && cus[i].toFloor % 2 == 0)//ż����
		{
			even_currentFloor = evenelevator.goToFloor(even_currentFloor, cus[i].waitFloor, sumtime);
			even_currentFloor = evenelevator.goToFloor(even_currentFloor, cus[i].toFloor, sumtime);
		}
		else if (sumtime >= oddelevator.sumtime&&cus[i].waitFloor % 2 == 1 && cus[i].toFloor % 2 == 1)//��
		{
			odd_currentFloor = oddelevator.goToFloor(odd_currentFloor, cus[i].waitFloor, sumtime);
			odd_currentFloor = oddelevator.goToFloor(odd_currentFloor, cus[i].toFloor, sumtime);
		}
		else if (sumtime >= normalelevator.sumtime)//ɶ�����㲻�˾�ֻ����ͨ��
		{
			normal_currentFloor = normalelevator.goToFloor(normal_currentFloor, cus[i].waitFloor, sumtime);
			normal_currentFloor = normalelevator.goToFloor(normal_currentFloor, cus[i].toFloor, sumtime);
		}
		return 0;
	}

	
}