#pragma once
#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<atlimage.h>
#include<math.h> 
#include<stdlib.h>

class sprite
{
	public:
		sprite(int num, int be )//����ͼƬ������ ��ʼ��λ��
			{
				pic_num = num;
				begin = be;
			}
		sprite() {
		}
		~sprite() {
		}
		int pic_num;//ͼƬ����
		int begin;
		void show(int x, int y, int index,HDC hdc, CImage pic[])//index 0 ��ʼ
		{
			pic[index+begin].Draw(hdc, x, y);
		}
};