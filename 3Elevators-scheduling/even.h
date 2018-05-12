#pragma once
class even//偶数
{
public:
	int currentFloor;//当前位置
	int waitFloor;
	int sumtime;
	int state;//电梯在不在动，动为1不动为0
	int goToFloor(int waitFloor, int toFloor, int time);//电梯要去的楼层
	int stop(int time);//电梯停
	void show(int time, int currentFloor);//在类中建立方便显示输出
	even();
	~even();
};