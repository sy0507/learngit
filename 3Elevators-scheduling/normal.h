#pragma once
class normal//��ͨ
{
public:
	int currentFloor;//��ǰλ��
	int waitFloor;
	int sumtime;
	int state;//�����ڲ��ڶ�����Ϊ1����Ϊ0
	int goToFloor(int waitFloor, int toFloor, int time);//����Ҫȥ��¥��
	int stop(int time);//����ͣ
	void show(int time, int currentFloor);//�����н���������ʾ���
	normal();
	~normal();
};

