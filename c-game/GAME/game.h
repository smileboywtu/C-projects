#ifndef _H_GAME_H
#define _H_GAME_H


#include"function.h"

/*******************函数定义*******************/
//logo
int logo(void)
{
	// 获得窗口句柄
	HWND hWnd = GetHWnd();
	//	HCURSOR hcur = LoadCursor(NULL, "cur");												// 加载系统预置的鼠标样式
	HMODULE hmod = GetModuleHandle(NULL); // 获取当前进程的句柄
	HCURSOR hcur = LoadCursor(hmod, "cur"); // 加载资源中的鼠标样式图片
	SetClassLong(hWnd, GCL_HCURSOR, (long)hcur);										// 设置窗口类的鼠标样式，其中第二个参数是鼠标样式
	
	SetWindowText(hWnd, "Time for joying!                             BO and XuKeLei");	// 使用 API 函数修改窗口名称

	cleardevice();											//清空背景色
	setbkcolor(BLACK);
	settextcolor(WHITE);									//输出文字属性
	settextstyle(30,20,_T("宋体"));
	
	TCHAR swel[]  = _T("Welcome!");
	TCHAR sload[] = _T("loading···");
	TCHAR soper[] = _T("please hit any key to continue···");
	
	outtextxy(320,30,swel);
	outtextxy(260,500,sload);
	
	/***********************游戏LOGO********************/
	putimage(120,70,&logimg[0]);
	Sleep(300);
	putimage(120,70,&logimg[1]);
	Sleep(300);
	putimage(120,70,&logimg[2]);
	Sleep(300);
	putimage(120,70,&logimg[3]);
	Sleep(300);
	putimage(120,70,&logimg[4]);
	Sleep(300);

	settextstyle(13,8,_T("宋体"));
	outtextxy(250,550,soper);
	
	
	_getch();

	return 0;													
}
//菜单
int menu()
{
	
	
	
	//选择关卡
	TCHAR name[5][20] = {
		{_T("The First Pass")},
		{_T("The Second Pass")},
		{_T("The Third Pass")},
		{_T("The Fouth Pass")},
		{_T("The Fifth Pass")}
	};
	setbkcolor(WHITE);
	cleardevice();												//清空背景色,可以略去


	
	//	setbkcolor(WHITE);
	TCHAR stip[] = _T("please choose the pass:");
	settextstyle(25,20,_T("宋体"));
	settextcolor(RED);
	outtextxy(150,70,stip);
	settextstyle(30,20,_T("宋体"));
	for(int j = 0,x0 = 250,y0 = 200; j < 5; j++ ,y0 +=50)
	{
		settextcolor(RGB(int((j+1)*255/5),255-int((j+1)*255/5),0));
		outtextxy(x0,y0,name[j]);
		
	}
	
	IMAGE array;												//第一次输出箭头作为初始化
	loadimage(&array,"IMAGE","array");
	putimage(200,190,&array);
	
	fflush(stdin);
	
	int midend = 1;												//判断结束的条件；
	int p = 0;
	int x2 = 200,y2 = 190;
	
	
	while(midend != 0)
	{
		fflush(stdin);
		
		
		switch(getch())											//获取键盘
		{
		case 'w':
		case 'W': if(p == 0) break;if(p > 0 ){ movearray(x2,y2,-1);y2 +=(-1)*50; p--;} 	break;				//上移 
		case 's':
		case 'S': if(p == 4) break;if(p < 4){ movearray(x2,y2,1);y2 += 50;p++;}			break;				//下移 
		case 0x0d:	midend = 0;															break;			    //进入游戏 
		case  27:	exit(0);																				//结束游戏 
		case 0xE0:											//如果是方向键 
			switch(getch())										//再次获取键盘 
			{
			case 72: if(p == 0) break;if(p > 0 ){ movearray(x2,y2,-1);y2 +=(-1)*50; p--; } 	break;
			case 80: if(p == 4) break;if(p < 4){ movearray(x2,y2,1);y2 += 50; p++;}	 break;
			}
		}
	}
	
	
	
	int a[5][10][10]={									//定义三维地图数组（很巧妙的方法）
		{	{0},										//第一关
		{0, 0, 6, 6, 6},
		{0, 0, 6, 3, 6},
		{0, 0, 6, 0, 6, 6, 6, 6},
		{6, 6, 6, 2, 0, 2, 3, 6},
		{6, 3, 0, 2, 1, 6, 6, 6},
		{6, 6, 6, 6, 2, 6},
		{0, 0, 0, 6, 3, 6},
		{0, 0, 0, 6, 6, 6} },
		
		{	{6, 6, 6, 6, 6},							//第二关
		{6, 1, 0, 0, 6},
		{6, 0, 2, 2, 6, 0, 6, 6, 6},
		{6, 0, 2, 0, 6, 0, 6, 3, 6},
		{6, 6, 6, 0, 6, 6, 6, 3, 6},
		{0, 6, 6, 0, 0, 0, 0, 3, 6},
		{0, 6, 0, 0, 0, 6, 0, 0, 6},
		{0, 6, 0, 0, 0, 6, 6, 6, 6},
		{0, 6, 6, 6, 6, 6} },
		
		{	{0, 6, 6, 6, 6},							//第三关
		{0, 6, 1, 0, 6, 6, 6},
		{0, 6, 0, 2, 0, 0, 6},
		{6, 6, 6, 0, 6, 0, 6, 6},
		{6, 3, 6, 0, 6, 0, 0, 6},
		{6, 3, 2, 0, 0, 6, 0, 6},
		{6, 3, 0, 0, 0, 2, 0, 6},
		{6, 6, 6, 6, 6, 6, 6, 6} },
		
		{	{0, 6, 6, 6, 6, 6, 6, 6},					//第四关
		{0, 6, 0, 1, 3, 3, 3, 6},
		{0, 6, 0, 0, 0, 6, 6, 6, 6},
		{6, 6, 6, 2, 0, 0, 0, 0, 6},
		{6, 0, 0, 0, 6, 2, 6, 0, 6},
		{6, 0, 2, 0, 6, 0, 0, 0, 6},
		{6, 0, 0, 0, 6, 6, 6, 6, 6},
		{6, 6, 6, 6, 6} },
		
		{	{0, 6, 6, 6, 6, 6},							//第五关
		{0, 6, 0, 1, 0, 6, 6, 6},
		{6, 6, 0, 6, 2, 0, 0, 6},
		{6, 0, 5 ,3, 0, 3, 0, 6},
		{6, 0, 0, 2, 2, 0, 6, 6},
		{6, 6, 6, 0, 6, 3, 6},
		{0, 0, 6, 0, 0, 0, 6},
		{0, 0, 6, 6, 6, 6, 6} }
	};
	
	
	int b[10][10];										//设置当前地图数组 
	memset(b,0,sizeof(b));
	
	do
	{
		loop_=0;										//loop置为0
		for(int x1 = 0; x1 < 10; x1++)
			for(int y1 = 0; y1 < 10; y1++)
				b[x1][y1] = a[p][x1][y1];			//对当前地图数组分别赋值 
			play(b);
	}while(loop_);									//如果loop被置为1则重新开始
	

	return 0;
	
}

int movearray(int x,int y,int k)
{
	IMAGE cover;
	IMAGE array;
	getimage(&cover,0,0,40,40);					//获取覆盖小方块
	putimage(x,y,&cover);
	loadimage(&array,"IMAGE","array");
	putimage(x,y+k*50,&array);
	return 0;
}


//画空地
void blank(int x1, int y1)	
{
	putimage(y1, x1, &img[0]);					// 在坐标 (y1, x1) 位置显示 IMAGE 对象
}



//画皮character1
void Drawchara(int x1, int y1)	
{
	putimage(y1, x1, &img[1]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}




//画ball
void box(int x1, int y1)
{
	putimage(y1, x1, &img[2]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}

//画目的地
void dest(int x1, int y1)
{
	putimage(y1, x1, &img[3]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}




//画在目的character2
void man1(int x1, int y1)
{
	putimage(y1, x1, &img[4]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}




//画在目的地上的旗子
void box1(int x1, int y1)
{
	putimage(y1, x1, &img[5]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}




//画围墙
void wall(int x1, int y1)
{
	putimage(y1, x1, &img[6]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}




//画character3
void man2(int x1, int y1)
{
	putimage(y1, x1, &img[7]);         // 在坐标 (y1, x1) 位置显示 IMAGE 对象
}




//把数组里的全画出来
void print(int a[][10])
{
	for(int x1 = 0; x1 < 10; x1++)
		for(int y1 = 0; y1 < 10; y1++)
			putimage(H_HIGHT * y1, W_WIDE * x1, &img[a[x1][y1]]);				//地图使用整数来标号的，
}




//移动
void move(int a[][10], int x1, int y1)
{
	if(a[x_ + x1][y_ + y1] == 0 || a[x_ + x1][y_ + y1] == 3)
	{
		a[x_][y_]--;
		a[x_ + x1][y_ + y1]++;
		for(int i = 0; i < LOOP; i++)
		{
			blank(W_WIDE * x_ + i * x1, H_HIGHT* y_ + i * y1);				//擦掉
			Drawchara(W_WIDE * x_ + (i + 1) * x1, H_HIGHT * y_ + (i + 1) * y1);
			Sleep(1);												//为了降低CPU且保存流畅
		}
		if(a[x_][y_] == 3)
			dest(W_WIDE * x_, H_HIGHT * y_);
		x_ += x1;
		y_ += y1;
		if(a[x_][y_] == 4)
			man1(W_WIDE * x_, H_HIGHT * y_);
	}
	else if((a[x_ + x1][y_ + y1] == 2 || a[x_ + x1][y_ + y1] == 5) && (a[x_ + 2 * x1][y_ + 2 * y1] == 0 || a[x_ + 2 * x1][y_ + 2 * y1] == 3))
	{
		a[x_][y_]--;
		a[x_ + x1][y_ + y1]--;
		a[x_ + 2 * x1][y_ + 2 * y1] += 2;
		for(int i = 0; i < LOOP; i++)
		{
			blank(W_WIDE * (x_ + x1) + i * x1, H_HIGHT * (y_ + y1) + i * y1);	        //擦掉
			box(W_WIDE * (x_ + x1) + (i + 1) * x1, H_HIGHT * (y_ + y1) + (i + 1) * y1);
			blank(W_WIDE * x_ + i * x1, H_HIGHT * y_ + i * y1);						//擦掉
			Drawchara(W_WIDE * x_ + (i + 1) * x1, H_HIGHT * y_ + (i + 1) * y1);
			Sleep(1);														//为了降低CPU且保存流畅
		}
		if(a[x_][y_] == 3)
			dest(W_WIDE * x_, H_HIGHT * y_);
		x_ += x1;
		y_ += y1;
		if(a[x_][y_] == 4)
			man1(W_WIDE * x_, H_HIGHT * y_);
		if(a[x_+x1][y_+y1] == 5)
			box1(W_WIDE * (x_ + x1), H_HIGHT * (y_ + y1));
	}
}

//找人物坐标x，y 
void find(int a[][10])
{
	for(x_ = 0; x_ < 10; x_++)
		for(y_ = 0; y_ < 10; y_++)
			if(a[x_][y_] == 1) return;
}

//判断游戏是否结束
int win(int a[][10])
{
	for(int x1 = 0; x1 < 10; x1++)
		for(int y1 = 0; y1 < 10; y1++)
			if(a[x1][y1] == 2) 
				return 0;					//如果还有球返回假
			return 1;												//如果没有球返回真
}


/************************游戏过程**********************/
//游戏过程
int play(int a[10][10])
{
	//背景音乐
	mciSendString("play m repeat", NULL, 0, NULL);
	loop_ = 0;
	print(a);
	find(a);												//通过find函数寻找人物的x, y坐标
	do
	{
		switch(getch())										//获取键盘
		{
		case 'w':
		case 'W':move(a, -1, 0);	break;				//上移 
		case 'a':
		case 'A':move(a, 0, -1);	break;				//左移 
		case 'd':
		case 'D':move(a, 0, 1);		break;				//右移 
		case 's':
		case 'S':move(a, 1, 0);		break;				//下移 
		case 'r':
		case 'R':
		case ' ':loop_ = 1;		return 0;				//重新开始当前关 
		case  27:exit(0);		break;					//结束游戏 
		case 0:
		case 0xE0:										//如果是方向键 
			switch(getch())								//再次获取键盘 
			{
			case 72:move(a, -1, 0);	break;
			case 75:move(a, 0, -1);	break;
			case 77:move(a, 0, 1); 	break;
			case 80:move(a, 1 , 0); break;
			}
		}
	}while(!win(a));										//通过win函数判断是否通过
	
	man2(W_WIDE * x_, H_HIGHT * y_);									//画一个开心的CHARACTER
	TCHAR schos[] = _T("Put enter key to continue,for ESC to stop···");

	
	
	cleardevice();
	setbkcolor(WHITE);
	settextstyle(15,15,_T("宋体"));
	outtextxy(40,250,schos);
	
	if(getch() == 0x0d)
		menu(); 
	else if(getch() == 27)
		exit(0);
	return	0;
}

//游戏关卡

#endif
