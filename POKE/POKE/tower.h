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
	int x, y;//λ��
	int wide, hight,R,atk,atk_R,hp,max_hp;//��͸ߣ���ײ�뾶 �������������뾶 ����ֵ���������ֵ ���������������
	int color;//��Ӫ
	int who;//Ȫˮ ˮ�� ��
	sprite sprite_index;
};