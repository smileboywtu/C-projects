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


int x_, y_;							//��������
int loop_;							//�����Ƿ����¿�ʼ
IMAGE img[8];                     	//����IMAGE����������
IMAGE logimg[5];					//�����洢��������




/*******************��������*******************/
void blank(int x1, int y1);	                //���յ�
void Drawchara  (int x1, int y1);           //��CHARACTER
void box  (int x1, int y1);	                //��BALL
void dest (int x1, int y1);					//��Ŀ�ĵ�
void man1 (int x1, int y1);	                //����Ŀ�ĵ��ϵ�CHARACTER
void box1 (int x1, int y1);					//����Ŀ�ĵ��ϵ�AIM
void wall (int x1, int y1);	                //��Χǽ
void man1 (int x1, int y1);					//����ʤ����CHARACTER
void print(int a[10][10]);	                //���������ȫ������
void move (int a[10][10], int x1, int y1);	//�ƶ�
void find (int a[10][10]);	                //����������
int  win  (int a[10][10]);					//�ж���Ϸ�Ƿ����
int  play (int a[10][10]);	                //��Ϸ����



int logo(void);								//logo
int menu(void);								//����
int movearray(int x,int y,int k);


#endif