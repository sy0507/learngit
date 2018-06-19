#pragma once
#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<atlimage.h>
#include<math.h> 
#include<stdlib.h>
#include<list>
#define red 0
#define blue 1
class tower
{
public:
	tower(long long ID_,int color_,int x_,int y_,int kind,sprite SPR){
		ID = ID_;
		x = x_;
		y = y_;
		who = kind;
		sprite_index = SPR;
	}
	~tower(){}
	
	void step(){};
	long long ID;
	int x, y;//位置
	int wide, hight,R,atk,atk_R,hp,max_hp;//宽和高，碰撞半径 攻击力，攻击半径 生命值和最大生命值 都可以由种类决定
	int color;//阵营
	int who;//泉水 水晶 塔
	sprite sprite_index;
};