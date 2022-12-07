
#include "../../screenHandler/screenHandler.h"

void pointmenu_main(){
    clrscr();
    print_screen("screen/point_screen.txt");

    gotoxy(44, 16);

    char input = getch();

    if(input == '1') {  // 포인트 충전
        
    } else if(input == '2') { // 포인트 반환

    }
}