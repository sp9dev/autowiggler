// autowiggler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <stdio.h>
#define WINVER 0x0500
#include <Windows.h>
#include <iostream>
#include <windows.h>
#include <WinUser.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

int main()
{
	cout << "_________________________" << endl;
	cout << "Welcome to AutoWiggler," << endl;
	cout << "a simple script, that enables you to... auto wiggle!" << endl;
	cout << "To activate wiggle, press numpad slash, a key next to numpad star" << endl;
	cout << "By Piotr Slawecki & Tomasz Gajda, AGH University of Science and Technology" << endl;
	cout << "_________________________" << endl;

	srand(time(NULL));

	bool isOn = false;
	bool executed = false;

	while (true)
	{
		INPUT input1;
		INPUT input2;
		int tmp_sleep;

		if (GetKeyState(0x6F) < 0) 
		{
			isOn = !isOn;
			Sleep(400);
		}
		
		if (isOn)
		{
			input1.type = INPUT_KEYBOARD;
			input1.ki.wScan = 'a'; 
			input1.ki.time = 0;
			input1.ki.dwExtraInfo = 0;
			input1.ki.wVk = 0x41; 
			
			input2.type = INPUT_KEYBOARD;
			input2.ki.wScan = 'd';
			input2.ki.time = 0;
			input2.ki.dwExtraInfo = 0;
			input2.ki.wVk = 0x44;
			


			input1.ki.dwFlags = 0;
			SendInput(1, &input1, sizeof(INPUT));

			tmp_sleep = rand() % 10 + 30;
			Sleep(tmp_sleep);

			input1.ki.dwFlags = KEYEVENTF_KEYUP; 
			SendInput(1, &input1, sizeof(INPUT));

			tmp_sleep = rand() % 10 + 30;
			Sleep(tmp_sleep);

			input2.ki.dwFlags = 0;
			SendInput(1, &input2, sizeof(INPUT));

			tmp_sleep = rand() % 10 + 30;
			Sleep(tmp_sleep);

			input2.ki.dwFlags = KEYEVENTF_KEYUP; 
			SendInput(1, &input2, sizeof(INPUT));

			tmp_sleep = rand() % 10;
			Sleep(tmp_sleep);
		}
	}
}
