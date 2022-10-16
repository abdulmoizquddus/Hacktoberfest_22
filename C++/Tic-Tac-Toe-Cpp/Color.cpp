#include "Color.h"
#include <iostream>
#include <windows.h>
HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
Color::Color()
{
}
void Color::color(int y)
{
    SetConsoleTextAttribute(out, y);
}
