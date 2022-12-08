#define _CRT_SECURE_NO_WARNINGS

#include "../screenHandler/screenHandler.h"
#include "./point/point.h"
#include "./productmenu/productmenu.h"

extern void startProcess();

void mainmenu_main(char *userid){
    clrscr();
    print_screen("screen/mainmenu_screen.txt");
    
    gotoxy(15,28);
    printf("%s", userid);

    gotoxy(29, 13);

    char input;
    while (input = getch())
    {
        if (input == '1') { // 상품 조회 메뉴
            productmenu_main();
            break;
        }
        else if (input == '2') { // 상품 구매 내역 조회 메뉴
        }
        else if (input == '3')  { // 포인트 조회 메뉴
            pointmenu_main(userid);
            break;
        }
        else if (input == '4') { // 로그아웃 메뉴
            startProcess();
            break;
        }
    }
}