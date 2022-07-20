#pragma once


// #define WINVER 0x0500

#define WHITE   "\033[37m"


using std::cin;
using std::cout;
using std::endl;
using std::string;

int Menu();
void Clicker();
void inputTime(unsigned short* n);
void PowerOff(unsigned short timer);