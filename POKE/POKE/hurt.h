#pragma once
#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<atlimage.h>
#include<math.h> 
#include<stdlib.h>
#include<list>
class hurt//���캯����������
{
public:
	hurt(){}
	~hurt(){}
	hurt(int x_,int y_,int who,int atk_,long long aim_ID_) {//����λ�ã����ԣ���������Ŀ�� ��һ������

	}
	void step(){};//
	int kind;//����
	int x, y, speed,atk;//λ�� ���� �ٶ�
	double find_chan_x(int x_, int y_, int ax, int ay) {//����Ŀ��
		double xx = ax - x_;
		double len = (xx*xx) + (ay - y_)*(ay - y_);
		return xx / sqrt(len);
	}//�������
	double find_chan_y(int x_, int y_, int ax, int ay) {
		double yy = ay - y_;
		double len = (yy*yy) + (ay - y_)*(ay - y_);
		return yy / sqrt(len);
	}//�������
	long long aim_ID;int aim_x, aim_y;//Ŀ���ID ��λ��
	double chan_x, chan_y;//�ƶ�����
};

