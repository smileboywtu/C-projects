/////////////////////////////////////////////////////////
// �������ƣ�������
// ���뻷����Visual C++ 6.0 / 2012��EasyX 2013˪����
// �������ԣ�C
// ��    �ߣ�SmithBob
// ����޸ģ�2013-12-25
//

#include"Function.h"

void main(){

	initgraph(W,H); 
	//log
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd,"Mini Calculator");

	loadimage(NULL,"IMAGE","wholeView");
	setcolor(WHITE);
	fillcircle(30,75,5);

	
	char buffer[64] = {'\0'};
	getimage(&img,45,27,70,15);

	while(true){

		Touch(buffer);

	//This's used as a test 
	//Assidant(hwnd);
  
	//now calculate and out put the data
		OutPut(Expression(buffer));
	}

	getch();
	closegraph();

}