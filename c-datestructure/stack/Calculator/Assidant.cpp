#include"Function.h"


void Assidant(HWND hwnd){	
	POINT point;
	TCHAR s[10];
	
	while(true)
	{
		GetCursorPos(&point);			// 获取鼠标指针位置（屏幕坐标）
		ScreenToClient(hwnd, &point);	// 将鼠标指针位置转换为窗口坐标
		
		// 获取鼠标按键状态可以用 GetAsyncKeyState 函数，这里不再详述。
		
		// 输出鼠标坐标
		sprintf(s, _T("%05d"), point.x);
		outtextxy(0, 0, s);
		
		sprintf(s, _T("%05d"), point.y);
		outtextxy(0, 20, s);
		
		// 适当延时
		Sleep(10);
	}
}