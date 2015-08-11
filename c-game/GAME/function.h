#ifndef  __TT
#define  __TT


#include <graphics.h>			
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#pragma comment(lib,"Winmm.lib")


//  pixel
#define W_WIDE	80	
#define H_HIGHT	80
#define LOOP    80


int x_, y_;							//人物坐标
int loop_;							//控制是否重新开始
IMAGE img[8];                     	//定义IMAGE对象数组来
IMAGE logimg[5];					//用来存储开场动画




/*******************函数声明*******************/
void blank(int x1, int y1);	                //画空地
void Drawchara  (int x1, int y1);           //画CHARACTER
void box  (int x1, int y1);	                //画BALL
void dest (int x1, int y1);					//画目的地
void man1 (int x1, int y1);	                //画在目的地上的CHARACTER
void box1 (int x1, int y1);					//画在目的地上的AIM
void wall (int x1, int y1);	                //画围墙
void man1 (int x1, int y1);					//画在胜利的CHARACTER
void print(int a[10][10]);	                //把数组里的全画出来
void move (int a[10][10], int x1, int y1);	//移动
void find (int a[10][10]);	                //找人物坐标
int  win  (int a[10][10]);					//判断游戏是否结束
int  play (int a[10][10]);	                //游戏过程



int logo(void);								//logo
int menu(void);								//界面
int movearray(int x,int y,int k);


#endif