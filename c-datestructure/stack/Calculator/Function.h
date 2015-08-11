#pragma once
#pragma message("This is the result of compiling Function: ")

#include"graphics.h"
#include"conio.h"
#include"stdio.h"



#define W 250
#define H 400

IMAGE img; //use to save img
 
void Touch(char buffer[]);
void Assidant(HWND hwnd);
void OutPut(double a);
double calculate(double a,char o,double b);
double Expression(char buffer[]);


#pragma message("Successful")