#define _CRT_SECURE_NO_WARNINGS

//#ifdef WIN32
#include < windows.h >
#include <stdio.h>

/**
 * 화면 출력 함수
 */
void print_screen(char fname[])
{
    FILE *fp;
    char line[100];

    if ((fp = fopen(fname, "r")) == NULL)
    {
        printf("file open error\n");
        getch();
        exit(-1);
    }
    while (1)
    {
        if (fgets(line, 99, fp) == NULL)
        {
            break;
        }
        printf("%s", line);
    }

    fclose(fp);
}

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