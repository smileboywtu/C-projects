#include"Function.h"


void Assidant(HWND hwnd){	
	POINT point;
	TCHAR s[10];
	
	while(true)
	{
		GetCursorPos(&point);			// ��ȡ���ָ��λ�ã���Ļ���꣩
		ScreenToClient(hwnd, &point);	// �����ָ��λ��ת��Ϊ��������
		
		// ��ȡ��갴��״̬������ GetAsyncKeyState ���������ﲻ��������
		
		// ����������
		sprintf(s, _T("%05d"), point.x);
		outtextxy(0, 0, s);
		
		sprintf(s, _T("%05d"), point.y);
		outtextxy(0, 20, s);
		
		// �ʵ���ʱ
		Sleep(10);
	}
}