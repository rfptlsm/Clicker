#include <Windows.h>
#include <iostream>
#include <thread>
#include <string>
#include "Clicker.h"


int main(int argc, char const* argv[])
{
    int timer = Menu();
    cout << timer << endl;
    PowerOff(timer);
    Clicker();

    system("pause");
    return 0;
}

void PowerOff(int timer)
{
    if (timer == 0)
        return;
    else if (timer <= -1)
    {
        cout << WHITE << "\nInterrupt system shutdown\n";
        system("c:\\windows\\system32\\shutdown /a");
    }
    else
    {
        timer *= 60;
        string shutdown_str = "c:\\windows\\system32\\shutdown /s /t ";
        string command = shutdown_str + std::to_string(timer);
        const char* command_char = command.c_str();
        //cout << command_char << endl;
        system(command_char);
    }
}

int Menu()
{
    system("Color A");
    std::cout << "\t****************************" << std::endl;
    std::cout << "\t*                          *" << std::endl;
    std::cout << "\t* Enter timer or wait...   *" << std::endl;
    std::cout << "\t*                          *" << std::endl;
    std::cout << "\t****************************" << std::endl;

    int time = 0;
    std::thread t1(inputTime, &time);

    std::this_thread::sleep_for(std::chrono::seconds(10));

    t1.detach();
    system("cls");
    if (time > 0)
    {
        system("Color A");
        cout << "Your computer will be turned off after " << time << " min" << endl;
    }
        
    else
    {
        system("Color C");
        cout << "The program will run until it is closed" << endl;
    }
 
    return time;
}

void inputTime(int* n)
{
    cout << WHITE << "\nEnter timer: ";
    cin >> *n;
    if (!cin.good())
        *n = 0;
}

void Clicker()
{
    const unsigned short TIME_SLEEP = 5;
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = VK_LCONTROL; //VK_CONTROL;
    input.ki.dwFlags = 0;

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::minutes(TIME_SLEEP));
        SendInput(1, &input, sizeof(INPUT));
    }
}
