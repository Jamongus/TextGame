#include "stdafx.h"
#include <string>
#include <iostream>
#include "UI.h"
#include <Windows.h>
using namespace std;

bool isUp;
bool isDown;
bool isLeft;
bool isRight;

bool keydown(int key)
{
	return (GetAsyncKeyState(key) & 0x8000) != 0;
}
void clearMovement() {
	isLeft = false;
	isRight = false;
	isUp = false;
	isDown = false;
}
void left() {
	isLeft = true;
}
void right() {
	isRight = true;
}
void up() {
	isUp = true;
}
void down() {
	isDown = true;
}
string movement() {
	string toReturn = "";
	if (isLeft) {
		toReturn += "LEFT ";
	}
	if (isRight) {
		toReturn += "RIGHT ";
	}
	if (isUp) {
		toReturn += "UP ";
	}
	if (isDown) {
		toReturn += "DOWN ";
	}
	return toReturn;
}
void checkForInput() {
	clearMovement();
	if (keydown(VK_ESCAPE)) {

	}
	if (keydown(VK_UP)) {
		up();
	}
	if (keydown(VK_DOWN)) {
		down();
	}
	if (keydown(VK_LEFT)) {
		left();
	}
	if (keydown(VK_RIGHT)) {
		right();
	}
}


int main()
{
	//UI ui;
	//ui.print("print this pls");
	while (!keydown(VK_ESCAPE))
	{
		checkForInput();
		cout << movement();
		Sleep(50);
		system("cls");

	}
	return 0;
}



