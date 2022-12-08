#define _CRT_SECURE_NO_WARNINGS

#include "../screenHandler/screenHandler.h"
#include "./point/point.h"

void mainmenu_main(char *userid){
    clrscr();
    print_screen("screen/mainmenu_screen.txt");
    
    gotoxy(15,28);
    printf("%s", userid);

    gotoxy(29, 13);

    char input = getch();

    if (input == '1') // 상품 조회 메뉴
    { 
        
    }
    else if (input == '2') // 상품 구매 내역 조회 메뉴
    { 
        
    }
    else if(input == '3') // 포인트 조회 메뉴
    {
        pointmenu_main(userid);   
    }
    else if(input == '4') // 로그아웃 메뉴
    {

    }
}