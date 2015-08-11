//////////////////////////////////////////
// 程序名称: 迷宫游戏（简版）
// 程序语言: C
// 版本号  : 1.0
// 作者	   : SmithBob
// 创作时间: 2013-12-27
//////////////////////////////////////////

#include"stdio.h"
#include"stdlib.h"
#include"graphics.h"
#include"conio.h"
#include"math.h"

#define BLOCKWIDEN 50
#define BLOCKHIGHT 50
#define WINWIDEN   16*BLOCKWIDEN
#define WINHIGHT   16*BLOCKHIGHT

/*----------------------stack used in this exe-----------------------*/
struct maze{
	//Row
	int row;
	//Line
	int line;
	//Position
	int pos;
};

struct stackNode{
	//Save data in stack
	maze data;
	//Next stackNode
	stackNode* next;
};

struct stack{
	//The head of the stack
	stackNode* top;
};

//initStack
void initStack(stack &s){
	s.top = NULL;
}
//push
void push(stack &s,maze data_){
	//new a space 
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	//save the data
	temp->data.line = data_.line;
	temp->data.row  = data_.row ;
	temp->data.pos	= data_.pos ;
	//add to the stack
	temp->next = s.top;
	s.top = temp ;

}
//pop
void pop(stack &s){

	if(s.top){
		//record the current node
		stackNode* temp = s.top;
		//move the pointer
		s.top = s.top->next;
		//delet the node
		free(temp);
	}
	
}
//top
maze top(stack s){

		maze data_;
		data_.line = s.top->data.line;
		data_.row  = s.top->data.row ;
		data_.pos  = s.top->data.pos ;

		return data_;
}
//empty
bool empty(stack s){
	if(s.top)
		return false;

	return true;
}
//size
int size(stack s){

	int i=0;
	while(s.top){
		i++;
		s.top = s.top->next;
	}

	return i;
}
//destroy
void destory(stack &s){
	stackNode* temp;
	while(s.top){
		temp = s.top;
		s.top = s.top->next;
		free(temp);
	}
	
}

/*----------------------End the block-----------------------*/

/*--------------Used for the game--------------*/

const int map[16][16] = {

  //1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6
  	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,    //row one 
	0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,	
	0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,0,	
	0,1,0,1,1,1,1,1,1,1,1,0,0,0,1,0,	
	0,1,0,1,0,0,0,0,0,0,0,0,1,1,1,0,	//row five
	0,1,0,1,0,1,1,1,1,0,1,1,1,0,0,0,	//'3' reference to stop
	0,1,0,1,0,6,0,0,1,0,1,0,1,1,1,0,
	0,1,0,1,0,0,0,1,1,0,1,0,1,0,1,0,
	0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,0,
	0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,	//row ten
	0,0,0,0,1,1,1,1,1,1,1,0,1,0,1,0,
	0,0,1,1,1,1,0,0,0,0,1,0,1,0,1,0,
	0,0,0,1,0,0,0,1,1,1,1,0,1,0,1,0,
	0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,0,
	0,0,0,1,1,2,0,1,1,1,1,1,1,1,1,0,	//row fifteen   //'2' reference to start 
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

};

//Give the first Location of the character
//Start Stop,row,line
int mapInfo[2][2] = {14,5,6,5};
stack key;

IMAGE grass,wall,shade,start,stop;
IMAGE up,down,left,right;

void drawMap(){
	//line
	for(int i=0; i<WINWIDEN/BLOCKWIDEN; i++)
		//row
		for(int j=0; j<WINHIGHT/BLOCKHIGHT; j++){

			if(map[j][i] == 0)
				putimage(i*BLOCKWIDEN,j*BLOCKHIGHT,&wall );
			else if(map[j][i] == 1)
				putimage(i*BLOCKWIDEN,j*BLOCKHIGHT,&grass);
			else if(map[j][i] == 2)
				putimage(i*BLOCKWIDEN,j*BLOCKHIGHT,&start);
			else
				putimage(i*BLOCKWIDEN,j*BLOCKHIGHT,&stop );

		}
}

void updateMap(maze &location,int position){
//////////////Instruction /////////	
//'0' up
//'1' left
//'2' down
//'3' right

	//clear pre character
	//draw enter
	if(location.row == mapInfo[0][0] && location.line == mapInfo[0][1])
		putimage(location.line*BLOCKWIDEN,location.row*BLOCKHIGHT,&start);
	else
		putimage(location.line*BLOCKWIDEN,location.row*BLOCKHIGHT,&grass);
		
	//draw new one 
	switch(position){
	//update de location
	case 0: putimage(location.line*BLOCKWIDEN,(location.row-1)*BLOCKHIGHT,&up   );location.row -= 1;break;
	case 1: putimage((location.line-1)*BLOCKWIDEN,location.row*BLOCKHIGHT,&left );location.line-= 1;break;
	case 2: putimage(location.line*BLOCKWIDEN,(location.row+1)*BLOCKHIGHT,&down );location.row += 1;break;
	case 3: putimage((location.line+1)*BLOCKWIDEN,location.row*BLOCKHIGHT,&right);location.line+= 1;break;
	default:exit(0);

	}
		
}

bool find(maze data,maze stop){
	//row 6, line 7 is the WinLocation
	if(data.row == stop.row && data.line == stop.line)
		return true;
	return false;
}

bool winGame(maze data,int mapInfo[][2]){
	if(data.row == mapInfo[1][0] && data.line == mapInfo[1][1] )
		return true;
	return false;
}

void winLog(){
	//cleardevice
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(52, 30, _T("Impact"));
	settextcolor(RGB(255, 17, 102));
	outtextxy(270, 230, _T("GAME WIN"));
	settextcolor(RGB(215, 193, 238));
	outtextxy(273, 238, _T("GAME WIN"));

}

//search keyRoad
void keyRoad(int mapInfo[][2]){
	
	//record the info
	maze start,stop,temp; 
	start.row  = mapInfo[0][0];
	start.line = mapInfo[0][1];
	start.pos  = -1;
	stop.row   = mapInfo[1][0];
	stop.line  = mapInfo[1][1];
	stop.pos   = -1;
	
	
	//for another game
	destory(key);
	initStack(key);
	push(key,start);
	
	int prestep = 10;
	
	while(!empty(key)){
		//Do not win
		if( !find(top(key),stop) ){
			//no way to go
			if(top(key).pos == 3 )
				pop(key);
			else{
				//in this circle you can't go back
				//we use prestep to record 
				switch(top(key).pos++){

				case 0 :
						// up is available
					if(map[top(key).row-1][top(key).line] && abs(prestep-top(key).pos) != 2 ) {
						top(key).pos = 0;
						temp.pos = -1;
						temp.row = top(key).row-1;
						temp.line= top(key).line;
						prestep  = top(key).pos;
						push(key,temp);
					};break;
				case 1 :
					// left is available
					if(map[top(key).row][top(key).line-1] && abs(prestep-top(key).pos) != 2 ) {
						top(key).pos = 1;
						temp.pos = -1;
						temp.row = top(key).row;
						temp.line= top(key).line-1;
						prestep  = top(key).pos;
						push(key,temp);
					};break;
				case 2 :
					// down is available
					if(map[top(key).row+1][top(key).line] && abs(prestep-top(key).pos) != 2 ) {
						top(key).pos = 2;
						temp.pos = -1;
						temp.row = top(key).row+1;
						temp.line= top(key).line;
						prestep  = top(key).pos;
						push(key,temp);
					};break;
				case 3 :
					// right is available
					if(map[top(key).row][top(key).line+1] && abs(prestep-top(key).pos) != 2 ) {
						top(key).pos = 3;
						temp.pos = -1;
						temp.row = top(key).row;
						temp.line= top(key).line+1;
						prestep  = top(key).pos;
						push(key,temp);
					};break;
				default: exit(1);
				}

			}//end else	
		}

		else
			break;
	}//end while

}

void play(int mapInfo[][2]){

	//initcharacter
	putimage(mapInfo[0][1]*BLOCKWIDEN,mapInfo[0][0]*BLOCKHIGHT,&up);
	//save the user input
	char action = 0;
	maze currentloc;

	currentloc.row = mapInfo[0][0];
	currentloc.line= mapInfo[0][1];

	while( action != 27 && !winGame(currentloc,mapInfo) ){ // 'ESC' = 27
		//receive the user input
		action = getch();
		switch(action){
			
			//up is available
		case 'w':
			if ( map[currentloc.row-1][currentloc.line] )
				updateMap(currentloc,0);
			;break;
			//down is available
		case 's':
			if ( map[currentloc.row+1][currentloc.line] )
				updateMap(currentloc,2);
			;break;
			//left is available
		case 'a':
			if ( map[currentloc.row][currentloc.line-1] )
				updateMap(currentloc,1);
			;break;
			//right is available
		case 'd':
			if ( map[currentloc.row][currentloc.line+1] )
				updateMap(currentloc,3);
			;break;
		}//end switch
		
	}//end while

	//The WinLog
	winLog();
}


/*-------------------End the block-----------------*/

//Now let's enjoy!
int main(){

	initgraph(WINWIDEN,WINWIDEN);

	//log
	HWND hwnd = GetHWnd();
	SetWindowText(hwnd,"Maze");

	//load map part
	loadimage(&wall, "IMAGE","WALL" );
	loadimage(&grass,"IMAGE","GRASS");
	loadimage(&shade,"IMAGE","SHADE");
	loadimage(&start,"IMAGE","START");
	loadimage(&stop, "IMAGE", "STOP");
	loadimage(&up,   "IMAGE", "UP"  );
	loadimage(&down, "IMAGE","DOWN" );
	loadimage(&right,"IMAGE","RIGHT");
	loadimage(&left, "IMAGE","LEFT" );
	
	drawMap();
	play(mapInfo);

	_getch();
	closegraph();

	return 1;
}