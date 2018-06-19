 
#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#include<conio.h>
#include<atlimage.h>
#include<math.h> 
#include<stdlib.h>
#include<vector>
#include <iostream>
#include "sprite.h"//精灵
#include "hero.h"//英雄
#include"Army.h"//小兵类
#include"hurt.h"//伤害动画
#include"tower.h"//塔头文件
#include<list>
#include<queue>
using namespace std;
#define red 0
#define blue 1
HDC hdc;
HWND  hwnd;
long long clear_time = 0;//计算游戏运行多少次

long long object_ID = 0;//物体ID
SYSTEMTIME now, last;
hero player_red,player_blue;//两个玩家

list<tower> Solid;//固体 即所有防御塔 
list<Army> Army_Slime;//双方小兵
list<hurt> Magic;//双方的特效


int dr_time;//绘制时间
//精灵们
sprite Spr_Charizard[6], Spr_Blastoise[6], Spr_Venusaur[6], Spr_Slime_red, Spr_Slime_blue, Spr_magic_array_red, Spr_magic_array_blue, Spr_tower_red, Spr_tower_blue, Spr_home_red, Spr_home_blue, Spr_skills, Spr_number, Spr_bullet_blue, Spr_bullet_red;
sprite Spr_bullet_green, Spr_fire, Spr_Million_tons, Spr_powder, Spr_Iron_wall, Spr_BIG, Spr_Sun_Flame, Spr_knife;//绿色子弹
CImage temp_pic[200];//存取图片的容器
CImage bac, wall, strip_hp_big, strip_hp_sma, strip_mp;//精灵们

int find_time(SYSTEMTIME last, SYSTEMTIME now)
{
	int w = 0;
	//w += (last.wDay - now.wDay) * 24 * 3600 * 1000;
	w += (last.wHour - now.wHour) * 3600 * 1000;
	w += (last.wMinute - now.wMinute) * 60 * 1000;
	w += (last.wSecond - now.wSecond) * 1000;
	w += (last.wMilliseconds - now.wMilliseconds);
	return w;
}
void Draw_num(int x,int y,int val /*x, y, 为右上角，绘制值为val的数字*/)
{
	int d;
	int i=0;
	if ( val==0 )
	{
		Spr_number.show(x, y, 0, hdc, temp_pic);
		return;
	}
	while (val > 0)
	{
		d = val % 10;
		val /= 10;
		Spr_number.show(x-i*32, y, d, hdc, temp_pic);
		i++;
	}
}
void ALL_draw(/*绘制函数*/)
{
	bac.Draw(hdc, 0, 0);//草
	wall.Draw(hdc, 0, 192);//城墙
	wall.Draw(hdc, 0, 544);//城墙 背景层次最低

						//此处绘制防御塔

	Draw_num(500, 50, dr_time);//临时计算帧率的代码

	player_red.draw_myself(hdc, temp_pic);//
	player_blue.draw_myself(hdc, temp_pic);//

								//此处绘制小兵
								
								//此处绘制特效
}
void LOADING(/*读取图片*/)
{

	bac.Load("sys\\bac.png");//地图
	wall.Load("sys\\wall.png");
	strip_hp_big.Load("sys\\strip_hp_big.png");//血条
	strip_hp_sma.Load("sys\\strip_hp_sma.png");
	strip_mp.Load("sys\\strip_mp_big.png");
	int cnt = 0, last = 0;
	if (1)
	{
		temp_pic[cnt++].Load("player\\Charizard_down_1.png");
		temp_pic[cnt++].Load("player\\Charizard_down_2.png");
		temp_pic[cnt++].Load("player\\Charizard_down_3.png");

		Spr_Charizard[1] = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("player\\Charizard_left_1.png");
		temp_pic[cnt++].Load("player\\Charizard_left_2.png");
		temp_pic[cnt++].Load("player\\Charizard_left_3.png");

		Spr_Charizard[2] = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("player\\Charizard_right_1.png");
		temp_pic[cnt++].Load("player\\Charizard_right_2.png");
		temp_pic[cnt++].Load("player\\Charizard_right_3.png");

		Spr_Charizard[3] = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("player\\Charizard_up_1.png");
		temp_pic[cnt++].Load("player\\Charizard_up_2.png");
		temp_pic[cnt++].Load("player\\Charizard_up_3.png");

		Spr_Charizard[0] = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("player\\Charizard.png");
		Spr_Charizard[4] = sprite(1, last);
		last++;//喷火龙读取结束


		temp_pic[cnt++].Load("player\\Blastoise_up_1.png");
		temp_pic[cnt++].Load("player\\Blastoise_up_2.png");
		temp_pic[cnt++].Load("player\\Blastoise_up_3.png");

		Spr_Blastoise[0] = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("player\\Blastoise_down_1.png");
		temp_pic[cnt++].Load("player\\Blastoise_down_2.png");
		temp_pic[cnt++].Load("player\\Blastoise_down_3.png");

		Spr_Blastoise[1] = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("player\\Blastoise_left_1.png");
		temp_pic[cnt++].Load("player\\Blastoise_left_2.png");
		temp_pic[cnt++].Load("player\\Blastoise_left_3.png");

		Spr_Blastoise[2] = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("player\\Blastoise_right_1.png");
		temp_pic[cnt++].Load("player\\Blastoise_right_2.png");
		temp_pic[cnt++].Load("player\\Blastoise_right_3.png");

		Spr_Blastoise[3] = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("player\\Blastoise.png");
		Spr_Blastoise[4] = sprite(1, last);
		last++;//水箭龟读取结束


		temp_pic[cnt++].Load("player\\Venusaur_up_1.png");
		temp_pic[cnt++].Load("player\\Venusaur_up_2.png");
		temp_pic[cnt++].Load("player\\Venusaur_up_3.png");

		Spr_Venusaur[0] = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("player\\Venusaur_down_1.png");
		temp_pic[cnt++].Load("player\\Venusaur_down_2.png");
		temp_pic[cnt++].Load("player\\Venusaur_down_3.png");

		Spr_Venusaur[1] = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("player\\Venusaur_left_1.png");
		temp_pic[cnt++].Load("player\\Venusaur_left_2.png");
		temp_pic[cnt++].Load("player\\Venusaur_left_3.png");

		Spr_Venusaur[2] = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("player\\Venusaur_right_1.png");
		temp_pic[cnt++].Load("player\\Venusaur_right_2.png");
		temp_pic[cnt++].Load("player\\Venusaur_right_3.png");

		Spr_Venusaur[3] = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("player\\Venusaur.png");
		Spr_Venusaur[4] = sprite(1, last);
		last++;//妙蛙花

		temp_pic[cnt++].Load("sys\\red_magic_array_1.png");
		temp_pic[cnt++].Load("sys\\red_magic_array_2.png");
		temp_pic[cnt++].Load("sys\\red_magic_array_3.png");

		Spr_home_red = sprite(3, last);
		last += 3;//红泉水

		temp_pic[cnt++].Load("sys\\blue_magic_array_1.png");
		temp_pic[cnt++].Load("sys\\blue_magic_array_2.png");
		temp_pic[cnt++].Load("sys\\blue_magic_array_3.png");

		Spr_home_blue = sprite(3, last);
		last += 3;//蓝泉水


		temp_pic[cnt++].Load("player\\Soldier_run_1.png");
		temp_pic[cnt++].Load("player\\Soldier_run_2.png");
		temp_pic[cnt++].Load("player\\Soldier_run_3.png");

		Spr_Slime_red = sprite(3, last);//红史莱姆
		last += 3;
		
		temp_pic[cnt++].Load("player\\blue_Soldier_run_1.png");
		temp_pic[cnt++].Load("player\\blue_Soldier_run_2.png");
		temp_pic[cnt++].Load("player\\blue_Soldier_run_3.png");

		Spr_Slime_blue = sprite(3, last);//蓝史莱姆
		last += 3;
	}
	if (1)
	{
		temp_pic[cnt++].Load("sys\\red_tower.png");
		Spr_tower_red = sprite(1, last);//红塔
		last++;

		temp_pic[cnt++].Load("sys\\blue_tower.png");
		Spr_tower_blue = sprite(1, last);//红塔
		last++;

		temp_pic[cnt++].Load("sys\\red_home.png");
		Spr_home_red = sprite(1, last);//红水晶
		last++;

		temp_pic[cnt++].Load("sys\\blue_home.png");
		Spr_home_blue = sprite(1, last);//红水晶
		last++;

		temp_pic[cnt++].Load("sys\\face_skill1.png");//
		temp_pic[cnt++].Load("sys\\face_skill2.png");
		temp_pic[cnt++].Load("sys\\face_skill3.png");
		temp_pic[cnt++].Load("sys\\face_skill4.png");
		temp_pic[cnt++].Load("sys\\face_skill5.png");
		temp_pic[cnt++].Load("sys\\face_skill6.png");
		temp_pic[cnt++].Load("sys\\face_skill7.png");
		temp_pic[cnt++].Load("sys\\face_skill8.png");
		temp_pic[cnt++].Load("sys\\face_skill9.png");
		temp_pic[cnt++].Load("sys\\face_skill10.png");
		temp_pic[cnt++].Load("sys\\face_skill11.png");
		temp_pic[cnt++].Load("sys\\face_skill12.png");
		temp_pic[cnt++].Load("sys\\face_skill13.png");
		temp_pic[cnt++].Load("sys\\face_skill14.png");
		Spr_skills = sprite(14, last);
		last += 14;


		temp_pic[cnt++].Load("sys\\num0.png");
		temp_pic[cnt++].Load("sys\\num1.png");
		temp_pic[cnt++].Load("sys\\num2.png");
		temp_pic[cnt++].Load("sys\\num3.png");
		temp_pic[cnt++].Load("sys\\num4.png");
		temp_pic[cnt++].Load("sys\\num5.png");
		temp_pic[cnt++].Load("sys\\num6.png");
		temp_pic[cnt++].Load("sys\\num7.png");
		temp_pic[cnt++].Load("sys\\num8.png");
		temp_pic[cnt++].Load("sys\\num9.png");
		Spr_number = sprite(10, last);
		last += 10;//数字

		temp_pic[cnt++].Load("hurt\\bullet_blue1.png");
		temp_pic[cnt++].Load("hurt\\bullet_blue2.png");
		temp_pic[cnt++].Load("hurt\\bullet_blue3.png");
		Spr_bullet_blue = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("hurt\\bullet_red1.png");
		temp_pic[cnt++].Load("hurt\\bullet_red2.png");
		temp_pic[cnt++].Load("hurt\\bullet_red3.png");
		Spr_bullet_red = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("hurt\\seed1.png");
		temp_pic[cnt++].Load("hurt\\seed2.png");
		temp_pic[cnt++].Load("hurt\\seed3.png");
		Spr_bullet_green = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("hurt\\fire1.png");
		temp_pic[cnt++].Load("hurt\\fire2.png");
		temp_pic[cnt++].Load("hurt\\fire3.png");
		Spr_fire = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("hurt\\Million_tons1.png");
		temp_pic[cnt++].Load("hurt\\Million_tons2.png");
		temp_pic[cnt++].Load("hurt\\Million_tons3.png");
		temp_pic[cnt++].Load("hurt\\Million_tons4.png");
		Spr_Million_tons = sprite(4, last);
		last += 4;

		temp_pic[cnt++].Load("hurt\\powder1.png");
		temp_pic[cnt++].Load("hurt\\powder2.png");
		temp_pic[cnt++].Load("hurt\\powder3.png");
		Spr_powder = sprite(3, last);
		last += 3;

		temp_pic[cnt++].Load("hurt\\knife_fx0.png");
		temp_pic[cnt++].Load("hurt\\knife_fx45.png");
		temp_pic[cnt++].Load("hurt\\knife_fx90.png");
		temp_pic[cnt++].Load("hurt\\knife_fx135.png");
		temp_pic[cnt++].Load("hurt\\knife_fx180.png");
		temp_pic[cnt++].Load("hurt\\knife_fx225.png");
		temp_pic[cnt++].Load("hurt\\knife_fx270.png");
		temp_pic[cnt++].Load("hurt\\knife_fx315.png");
		Spr_knife = sprite(8, last);
		last += 8;

		temp_pic[cnt++].Load("hurt\\Iron_wall.png");
		Spr_Iron_wall = sprite(1, last);
		last++;

		temp_pic[cnt++].Load("hurt\\BIG.png");
		Spr_BIG = sprite(1, last);
		last++;

		temp_pic[cnt++].Load("hurt\\Sun_Flame.png");
		Spr_Sun_Flame = sprite(1, last);
		last++;
	}
	
}
void ALL_ini()//初始化地图
{
	





}

void ALL_play()//游戏在此运行
{
	player_red.step();
	player_blue.step();




	clear_time++;//计算运行次数
}
int main()
{
	hwnd=initgraph(1728, 768);//创建窗口
	hdc= GetDC(hwnd);//获得窗口hdc
	LOADING();//读取图片
	player_red = hero(object_ID++, red, 0, Spr_Venusaur, 100, 300);//创建玩家
	player_blue= hero(object_ID++, blue, 0, Spr_Blastoise, 200, 300);//创建
	ALL_ini();//初始化游戏
	while (1)//死循环
	{
		GetLocalTime(&now);//开始执行代码的时间 
		//游戏此处执行
		ALL_draw();//绘制窗口
		ALL_play();//游戏运行
		Sleep(80);//休息一段时间
	   //		
		/*if ( clear_time>1000 )
		{
			cleardevice();
			clear_time = 0;
		}*/
		GetLocalTime(&last); //执行完代码的时间 
		dr_time=find_time(last, now);
	}
	closegraph();//关闭窗口
	return 0;
}