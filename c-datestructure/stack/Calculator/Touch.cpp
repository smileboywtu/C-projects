#include"Function.h"

const char recognition[5][4] = {
	{'+', '-', '*', '/'},
	{'7', '8', '9', '^'},
	{'4', '5', '6', '%'},
	{'1', '2', '3', '$'},
	{'0', '.', ' ', '='}
};

void stringlink(char buffer[], char temp){
	for(int i=0; buffer[i]!='\0'; i++);
	buffer[i] = temp;
}

void LED(){
	setcolor(RED);
	fillcircle(30,75,5);
	Sleep(100);
	fillcircle(30,75,5);
}

void Touch(char buffer[]){
	MOUSEMSG m;
	while(1){
		m = GetMouseMsg();
		if(m.uMsg == WM_LBUTTONDOWN){
			setwritemode(R2_XORPEN);
			float L = 0.5f;
			for(int r=1; r<=13; r++){
				setcolor(HSLtoRGB(230,1,L));
				circle(m.x,m.y,r);
				L += 0.041f; 
			}
			Sleep(230);
			L = 0.5f;
			for(r=1; r<=13; r++){
				setcolor(HSLtoRGB(230,1,L));
				circle(m.x,m.y,r);
				L += 0.041f; 
			}
			
			//This used to recognize the touch
			if(getpixel(m.x,m.y) == WHITE || getpixel(m.x,m.y) == getpixel(31,101) ){
				//This to show the LED
				LED();
				char temp = recognition[int((m.y-93)/55)][int((m.x-25)/53)] ;
				if(temp == ' '){
					memset(buffer,'\0',sizeof(buffer));
					OutPut(0);
				}
				else if(temp == '=')
					break;
				else
					stringlink(buffer,temp);
			}

			Sleep(1);
			FlushMouseMsgBuffer();
		}
	}//end while
}