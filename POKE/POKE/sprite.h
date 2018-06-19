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
		sprite(int num, int be )//精灵图片的数量 开始的位置
			{
				pic_num = num;
				begin = be;
			}
		sprite() {
		}
		~sprite() {
		}
		int pic_num;//图片数量
		int begin;
		void show(int x, int y, int index,HDC hdc, CImage pic[])//index 0 开始
		{
			pic[index+begin].Draw(hdc, x, y);
		}
};