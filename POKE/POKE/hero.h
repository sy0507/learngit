#pragma once
#include "sprite.h"
#include<string.h>
#include<cstdio>
#include<cstring>
#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<atlimage.h>
#include<math.h> 
#include<stdlib.h>
#define red 0
#define blue 1
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
class hero
{
public:
	hero(){}
	~hero() {}
	hero(long long  id,int color, int who_, sprite SPR[],int x_,int y_/*��ʼ��*/) {//����Ĭ��˳�� ����������
		ID = id;
		who = who_;//0����� 1���ܻ� 2ˮ����

		spr_up = SPR[0];//������
		spr_down = SPR[1];
		spr_left = SPR[2];
		spr_right = SPR[3];
		spr_face = SPR[4];
		sprite_index = spr_down;


		image_index = 0;
		x = x_;
		y = y_;
		wide = 48;
		hight = 48;
		R = 24;
		my_time = 0;
		move = 0;
		speed = 5;

		//�ȼ���������ֵ==	
		LV = 1;
		EXE = 0;
		//��ʼ�����ܵȵ�
		if ( who==0 )//�����
		{
			max_hp = 1000;
			hp = 1000;
			max_mp = 100;
			mp = 100;
			atk_num = 100;
			for (int i = 1; i <= 5; i++)
			{
				S_CD[i] = 0;
			}
			S_CDSUM[1] = 10;//����CD����
			S_CDSUM[2] = 10;
			S_CDSUM[3] = 10;
			S_CDSUM[4] = 10;
			S_CDSUM[5] = 10;

			S_cost[1] = 10;//��������
			S_cost[2] = 10;
			S_cost[3] = 10;
			S_cost[4] = 10;
			S_cost[5] = 10;
		}
		else if ( who==1 )
		{

		}
		else
		{

		}
		//������ʼ��
		if (color == red){
			key_down = 'S';
			key_up = 'W';
			key_left = 'A';
			key_right = 'D';
			key_s1 = 'J';
			key_s2 = 'K';
			key_s3 = 'L';
			key_s4 = 'U';
			key_s5 = 'I';
			}
		else{
			key_down = VK_DOWN;
			key_up = VK_UP;
			key_left = VK_LEFT;
			key_right = VK_RIGHT;
			key_s1 = 97;
			key_s2 = 98;
			key_s3 = 99;
			key_s4 = 100;
			key_s5 = 101;

			}
	}
	sprite spr_up, spr_down, spr_left, spr_right,sprite_index,spr_face;//
	void use_skill1()//ʹ�ü���
	{

	}
	void use_skill2()
	{

	}
	void use_skill3()
	{

	}
	void use_skill4()
	{

	}
	void use_skill5()
	{

	}



	int who;//�����ܶණ��
	int color;//redΪ���0��rightΪ�ұ�1
	int hp, max_hp,mp,max_mp;//����ֵ

	//�������
	int EXE, LV;//���� �ȼ�
	int S_CD[6], S_CDSUM[6];//CDSUMΪ������������CD����0�������ͷż���
	int S_cost[6];//��������
	int atk_num;//������



	//ͨ��
	long long ID;//��������ͨ��ID����������ͬ
	int image_index;
	int speed, fx, x, y;//�ٶ�//����0 90 180 270 λ��//�Ƿ����ƶ�
	int wide, hight, R;// //���峤�Ϳ���ײ�뾶
	bool move;
	long long my_time;//�ҵ�ʱ��
	//����
	char key_down, key_up, key_left, key_right, key_s1, key_s2, key_s3, key_s4, key_s5;//����

	void draw_myself(HDC hdc, CImage pic[])
	{
		sprite_index.show(x, y, image_index, hdc, pic);
	}
	bool place_meet(int x_,int y_)//�Ƿ��ܹ������λ��
		{
			if ( x_<0 || y_<224 || x_>1728 || y_>496 )
			{
				return false;//�߳���ͼ
			}
			return true;
		}
	void step() {//ͬ���¼���Ҫ������������
		move = 0;
		if ( KEY_DOWN(key_left) )
			{
				if (  place_meet(x-speed,y)  )
					x -= speed;
				fx = 180;
				sprite_index = spr_left;
				move = 1;
			}
		if ( KEY_DOWN(key_up) )
		{
			if (place_meet(x, y-speed))
				y -= speed;
			fx = 90;
			sprite_index = spr_up;
			move = 1;
		}
		if ( KEY_DOWN(key_down) )
		{
			if (place_meet(x, y + speed))
				y += speed;
			fx = 270;
			sprite_index = spr_down;
			move = 1;
		}
		if ( KEY_DOWN(key_right) )
		{
			if (place_meet(x+speed, y))
				x += speed;
			fx = 0;
			sprite_index = spr_right;
			move = 1;
		}
		if (my_time%2==0)
			if ( move )
				image_index++;//����

		image_index %= 3;
		my_time++;
	}
};