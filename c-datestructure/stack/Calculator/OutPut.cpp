#include"Function.h"

void OutPut(double a){
	TCHAR s[10];
	sprintf(s, _T("%lf"), a);
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	putimage(45,27,&img);
	outtextxy(45, 27, s);
}