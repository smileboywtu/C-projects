#ifndef _H_GAME_H
#define _H_GAME_H


#include"function.h"

/*******************��������*******************/
//logo
int logo(void)
{
	// ��ô��ھ��
	HWND hWnd = GetHWnd();
	//	HCURSOR hcur = LoadCursor(NULL, "cur");												// ����ϵͳԤ�õ������ʽ
	HMODULE hmod = GetModuleHandle(NULL); // ��ȡ��ǰ���̵ľ��
	HCURSOR hcur = LoadCursor(hmod, "cur"); // ������Դ�е������ʽͼƬ
	SetClassLong(hWnd, GCL_HCURSOR, (long)hcur);										// ���ô�����������ʽ�����еڶ��������������ʽ
	
	SetWindowText(hWnd, "Time for joying!                             BO and XuKeLei");	// ʹ�� API �����޸Ĵ�������

	cleardevice();											//��ձ���ɫ
	setbkcolor(BLACK);
	settextcolor(WHITE);									//�����������
	settextstyle(30,20,_T("����"));
	
	TCHAR swel[]  = _T("Welcome!");
	TCHAR sload[] = _T("loading������");
	TCHAR soper[] = _T("please hit any key to continue������");
	
	outtextxy(320,30,swel);
	outtextxy(260,500,sload);
	
	/***********************��ϷLOGO********************/
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

	settextstyle(13,8,_T("����"));
	outtextxy(250,550,soper);
	
	
	_getch();

	return 0;													
}
//�˵�
int menu()
{
	
	
	
	//ѡ��ؿ�
	TCHAR name[5][20] = {
		{_T("The First Pass")},
		{_T("The Second Pass")},
		{_T("The Third Pass")},
		{_T("The Fouth Pass")},
		{_T("The Fifth Pass")}
	};
	setbkcolor(WHITE);
	cleardevice();												//��ձ���ɫ,������ȥ


	
	//	setbkcolor(WHITE);
	TCHAR stip[] = _T("please choose the pass:");
	settextstyle(25,20,_T("����"));
	settextcolor(RED);
	outtextxy(150,70,stip);
	settextstyle(30,20,_T("����"));
	for(int j = 0,x0 = 250,y0 = 200; j < 5; j++ ,y0 +=50)
	{
		settextcolor(RGB(int((j+1)*255/5),255-int((j+1)*255/5),0));
		outtextxy(x0,y0,name[j]);
		
	}
	
	IMAGE array;												//��һ�������ͷ��Ϊ��ʼ��
	loadimage(&array,"IMAGE","array");
	putimage(200,190,&array);
	
	fflush(stdin);
	
	int midend = 1;												//�жϽ�����������
	int p = 0;
	int x2 = 200,y2 = 190;
	
	
	while(midend != 0)
	{
		fflush(stdin);
		
		
		switch(getch())											//��ȡ����
		{
		case 'w':
		case 'W': if(p == 0) break;if(p > 0 ){ movearray(x2,y2,-1);y2 +=(-1)*50; p--;} 	break;				//���� 
		case 's':
		case 'S': if(p == 4) break;if(p < 4){ movearray(x2,y2,1);y2 += 50;p++;}			break;				//���� 
		case 0x0d:	midend = 0;															break;			    //������Ϸ 
		case  27:	exit(0);																				//������Ϸ 
		case 0xE0:											//����Ƿ���� 
			switch(getch())										//�ٴλ�ȡ���� 
			{
			case 72: if(p == 0) break;if(p > 0 ){ movearray(x2,y2,-1);y2 +=(-1)*50; p--; } 	break;
			case 80: if(p == 4) break;if(p < 4){ movearray(x2,y2,1);y2 += 50; p++;}	 break;
			}
		}
	}
	
	
	
	int a[5][10][10]={									//������ά��ͼ���飨������ķ�����
		{	{0},										//��һ��
		{0, 0, 6, 6, 6},
		{0, 0, 6, 3, 6},
		{0, 0, 6, 0, 6, 6, 6, 6},
		{6, 6, 6, 2, 0, 2, 3, 6},
		{6, 3, 0, 2, 1, 6, 6, 6},
		{6, 6, 6, 6, 2, 6},
		{0, 0, 0, 6, 3, 6},
		{0, 0, 0, 6, 6, 6} },
		
		{	{6, 6, 6, 6, 6},							//�ڶ���
		{6, 1, 0, 0, 6},
		{6, 0, 2, 2, 6, 0, 6, 6, 6},
		{6, 0, 2, 0, 6, 0, 6, 3, 6},
		{6, 6, 6, 0, 6, 6, 6, 3, 6},
		{0, 6, 6, 0, 0, 0, 0, 3, 6},
		{0, 6, 0, 0, 0, 6, 0, 0, 6},
		{0, 6, 0, 0, 0, 6, 6, 6, 6},
		{0, 6, 6, 6, 6, 6} },
		
		{	{0, 6, 6, 6, 6},							//������
		{0, 6, 1, 0, 6, 6, 6},
		{0, 6, 0, 2, 0, 0, 6},
		{6, 6, 6, 0, 6, 0, 6, 6},
		{6, 3, 6, 0, 6, 0, 0, 6},
		{6, 3, 2, 0, 0, 6, 0, 6},
		{6, 3, 0, 0, 0, 2, 0, 6},
		{6, 6, 6, 6, 6, 6, 6, 6} },
		
		{	{0, 6, 6, 6, 6, 6, 6, 6},					//���Ĺ�
		{0, 6, 0, 1, 3, 3, 3, 6},
		{0, 6, 0, 0, 0, 6, 6, 6, 6},
		{6, 6, 6, 2, 0, 0, 0, 0, 6},
		{6, 0, 0, 0, 6, 2, 6, 0, 6},
		{6, 0, 2, 0, 6, 0, 0, 0, 6},
		{6, 0, 0, 0, 6, 6, 6, 6, 6},
		{6, 6, 6, 6, 6} },
		
		{	{0, 6, 6, 6, 6, 6},							//�����
		{0, 6, 0, 1, 0, 6, 6, 6},
		{6, 6, 0, 6, 2, 0, 0, 6},
		{6, 0, 5 ,3, 0, 3, 0, 6},
		{6, 0, 0, 2, 2, 0, 6, 6},
		{6, 6, 6, 0, 6, 3, 6},
		{0, 0, 6, 0, 0, 0, 6},
		{0, 0, 6, 6, 6, 6, 6} }
	};
	
	
	int b[10][10];										//���õ�ǰ��ͼ���� 
	memset(b,0,sizeof(b));
	
	do
	{
		loop_=0;										//loop��Ϊ0
		for(int x1 = 0; x1 < 10; x1++)
			for(int y1 = 0; y1 < 10; y1++)
				b[x1][y1] = a[p][x1][y1];			//�Ե�ǰ��ͼ����ֱ�ֵ 
			play(b);
	}while(loop_);									//���loop����Ϊ1�����¿�ʼ
	

	return 0;
	
}

int movearray(int x,int y,int k)
{
	IMAGE cover;
	IMAGE array;
	getimage(&cover,0,0,40,40);					//��ȡ����С����
	putimage(x,y,&cover);
	loadimage(&array,"IMAGE","array");
	putimage(x,y+k*50,&array);
	return 0;
}


//���յ�
void blank(int x1, int y1)	
{
	putimage(y1, x1, &img[0]);					// ������ (y1, x1) λ����ʾ IMAGE ����
}



//��Ƥcharacter1
void Drawchara(int x1, int y1)	
{
	putimage(y1, x1, &img[1]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}




//��ball
void box(int x1, int y1)
{
	putimage(y1, x1, &img[2]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}

//��Ŀ�ĵ�
void dest(int x1, int y1)
{
	putimage(y1, x1, &img[3]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}




//����Ŀ��character2
void man1(int x1, int y1)
{
	putimage(y1, x1, &img[4]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}




//����Ŀ�ĵ��ϵ�����
void box1(int x1, int y1)
{
	putimage(y1, x1, &img[5]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}




//��Χǽ
void wall(int x1, int y1)
{
	putimage(y1, x1, &img[6]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}




//��character3
void man2(int x1, int y1)
{
	putimage(y1, x1, &img[7]);         // ������ (y1, x1) λ����ʾ IMAGE ����
}




//���������ȫ������
void print(int a[][10])
{
	for(int x1 = 0; x1 < 10; x1++)
		for(int y1 = 0; y1 < 10; y1++)
			putimage(H_HIGHT * y1, W_WIDE * x1, &img[a[x1][y1]]);				//��ͼʹ����������ŵģ�
}




//�ƶ�
void move(int a[][10], int x1, int y1)
{
	if(a[x_ + x1][y_ + y1] == 0 || a[x_ + x1][y_ + y1] == 3)
	{
		a[x_][y_]--;
		a[x_ + x1][y_ + y1]++;
		for(int i = 0; i < LOOP; i++)
		{
			blank(W_WIDE * x_ + i * x1, H_HIGHT* y_ + i * y1);				//����
			Drawchara(W_WIDE * x_ + (i + 1) * x1, H_HIGHT * y_ + (i + 1) * y1);
			Sleep(1);												//Ϊ�˽���CPU�ұ�������
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
			blank(W_WIDE * (x_ + x1) + i * x1, H_HIGHT * (y_ + y1) + i * y1);	        //����
			box(W_WIDE * (x_ + x1) + (i + 1) * x1, H_HIGHT * (y_ + y1) + (i + 1) * y1);
			blank(W_WIDE * x_ + i * x1, H_HIGHT * y_ + i * y1);						//����
			Drawchara(W_WIDE * x_ + (i + 1) * x1, H_HIGHT * y_ + (i + 1) * y1);
			Sleep(1);														//Ϊ�˽���CPU�ұ�������
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

//����������x��y 
void find(int a[][10])
{
	for(x_ = 0; x_ < 10; x_++)
		for(y_ = 0; y_ < 10; y_++)
			if(a[x_][y_] == 1) return;
}

//�ж���Ϸ�Ƿ����
int win(int a[][10])
{
	for(int x1 = 0; x1 < 10; x1++)
		for(int y1 = 0; y1 < 10; y1++)
			if(a[x1][y1] == 2) 
				return 0;					//��������򷵻ؼ�
			return 1;												//���û���򷵻���
}


/************************��Ϸ����**********************/
//��Ϸ����
int play(int a[10][10])
{
	//��������
	mciSendString("play m repeat", NULL, 0, NULL);
	loop_ = 0;
	print(a);
	find(a);												//ͨ��find����Ѱ�������x, y����
	do
	{
		switch(getch())										//��ȡ����
		{
		case 'w':
		case 'W':move(a, -1, 0);	break;				//���� 
		case 'a':
		case 'A':move(a, 0, -1);	break;				//���� 
		case 'd':
		case 'D':move(a, 0, 1);		break;				//���� 
		case 's':
		case 'S':move(a, 1, 0);		break;				//���� 
		case 'r':
		case 'R':
		case ' ':loop_ = 1;		return 0;				//���¿�ʼ��ǰ�� 
		case  27:exit(0);		break;					//������Ϸ 
		case 0:
		case 0xE0:										//����Ƿ���� 
			switch(getch())								//�ٴλ�ȡ���� 
			{
			case 72:move(a, -1, 0);	break;
			case 75:move(a, 0, -1);	break;
			case 77:move(a, 0, 1); 	break;
			case 80:move(a, 1 , 0); break;
			}
		}
	}while(!win(a));										//ͨ��win�����ж��Ƿ�ͨ��
	
	man2(W_WIDE * x_, H_HIGHT * y_);									//��һ�����ĵ�CHARACTER
	TCHAR schos[] = _T("Put enter key to continue,for ESC to stop������");

	
	
	cleardevice();
	setbkcolor(WHITE);
	settextstyle(15,15,_T("����"));
	outtextxy(40,250,schos);
	
	if(getch() == 0x0d)
		menu(); 
	else if(getch() == 27)
		exit(0);
	return	0;
}

//��Ϸ�ؿ�

#endif
