//#ifdef WIN32
#include < windows.h >

/*---------------  화면 커서 제어 함수 --------------------*/
#define STD_HANDLE GetStdHandle(STD_OUTPUT_HANDLE)

void gotoxy(int x, int y)
{
    COORD Cur = { (SHORT)x, (SHORT)y };

    SetConsoleCursorPosition(STD_HANDLE, Cur);
}

void getxy(int* x, int* y)
{
    CONSOLE_SCREEN_BUFFER_INFO Buf;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Buf);
    *x = (int)Buf.dwCursorPosition.X;
    *y = (int)Buf.dwCursorPosition.Y;

}

void clrscr(void)
{
    COORD Cur = { 0, 0 };
    unsigned long dwLen;

    FillConsoleOutputCharacter(STD_HANDLE, ' ', 80 * 25, Cur, &dwLen);
}

/*---------------------------------------------------------*/