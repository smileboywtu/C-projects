//////////////////////////////////////////////////
// Project : PutBox
// Auther : SmithBob
// Language : Peer C
// Time : 2013
//////////////////////////////////////////////////

#include"game.h"



int main()
{
	
	
	initgraph(800,800);	
	cleardevice();
	/***********************游戏画面********************/
	loadimage(&img[0],"IMAGE","a");
	loadimage(&img[1],"IMAGE","b");
	loadimage(&img[2],"IMAGE","c");
	loadimage(&img[3],"IMAGE","d");
	loadimage(&img[4],"IMAGE","e");
	loadimage(&img[5],"IMAGE","f");
	loadimage(&img[6],"IMAGE","g");
	loadimage(&img[7],"IMAGE","h");
	/***********************游戏LOGO********************/
	loadimage(&logimg[0],"IMAGE","l1");

	loadimage(&logimg[1],"IMAGE","l2");

	loadimage(&logimg[2],"IMAGE","l3");

	loadimage(&logimg[3],"IMAGE","l4");

	loadimage(&logimg[4],"IMAGE","l5");
	
	mciSendString("open music.mp3 alias m", NULL, 0, NULL);
	
	logo();
	
	
	menu();
	
	//关闭音乐
	mciSendString("close m", NULL, 0, NULL);
	closegraph();
	
	
	return 0;
}

