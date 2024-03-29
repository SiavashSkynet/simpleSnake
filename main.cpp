#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY,score;

enum eDirection{STOP = 0, LEFT, RIGHT, DOWN, UP};
eDirection dir;

void setup()
{
	gameOver = false;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void draw()
{
	system("cls");//for linux ("clear");
	for (int i = 0; i < width+2; i++) {
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "0";
			else if (i == fruitY && j == fruitX)
			
				cout << "F";
		
			else
				cout << " ";
			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	
	}
		for (int j = 0; j < width+2; j++) {
			cout << "#" ;
		}
		cout << endl;
		cout << "Score : " << score << endl;
		
	}

void input()
{
	if (_kbhit) {
		switch (_getch()) {
		case 's':
			dir = DOWN;
			
			break;
			case 'a' :
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 50:
			gameOver = true;
			break;

		}}
	
	}

void logic()
{
	switch (dir) {
	case LEFT:	
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > width  || y > height || y<0 || x<0) {
		gameOver = true;
	}
	if (x == fruitX && y == fruitY) {
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}

int main()
{
	setup();
	while (!gameOver) {
		draw();
		input();
		logic();
		//sleep(10);
	}
	return 0; 
}
