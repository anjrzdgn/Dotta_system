//
// Created by Ali on 2024-03-28.
//
#include "universal_header.h"
#include "UI_UX_header.h"

std::string RED()
{
    return "\033[1;31m";
}

std::string GREEN()
{
    return "\033[1;32m";
}

std::string CYAN()
{
    return "\033[1;36m";
}

std::string PURPLE()
{
    return "\033[1;35m";
}

std::string BLUE()
{
    return "\033[1;34m";
}

std::string YELLOW()
{
    return "\033[1;33m";
}

std::string WHITE()
{
    return "\033[1;0m";
}

void cursor_on()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void cursor_off()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}

std::string GetCurrentDateTimeString()
{
    SYSTEMTIME systemTime;
    GetLocalTime(&systemTime);

    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << systemTime.wYear
        << std::setw(2) << std::setfill('0') << systemTime.wMonth
        << std::setw(2) << std::setfill('0') << systemTime.wDay
        << "_"
        << std::setw(2) << std::setfill('0') << systemTime.wHour
        << std::setw(2) << std::setfill('0') << systemTime.wMinute
        << std::setw(2) << std::setfill('0') << systemTime.wSecond;

    return oss.str();
}