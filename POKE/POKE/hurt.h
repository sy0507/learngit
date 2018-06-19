#pragma once
#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<atlimage.h>
#include<math.h> 
#include<stdlib.h>
#include<list>
class hurt//构造函数七种重载
{
public:
	hurt(){}
	~hurt(){}
	hurt(int x_,int y_,int who,int atk_,long long aim_ID_) {//创建位置，属性，攻击力，目标 第一种重载

	}
	void step(){};//
	int kind;//种类
	int x, y, speed,atk;//位置 方向 速度
	double find_chan_x(int x_, int y_, int ax, int ay) {//锁定目标
		double xx = ax - x_;
		double len = (xx*xx) + (ay - y_)*(ay - y_);
		return xx / sqrt(len);
	}//算出方向
	double find_chan_y(int x_, int y_, int ax, int ay) {
		double yy = ay - y_;
		double len = (yy*yy) + (ay - y_)*(ay - y_);
		return yy / sqrt(len);
	}//算出方向
	long long aim_ID;int aim_x, aim_y;//目标的ID 和位置
	double chan_x, chan_y;//移动分量
};

