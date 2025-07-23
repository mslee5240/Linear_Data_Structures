#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // _getch() 사용을 위해 필요

typedef enum MY_MENU {
    EXIT,
    NEW,
    SEARCH,
    PRINT,
    REMOVE
} MY_MENU;

MY_MENU printMenu(void);

int main(void) {
    MY_MENU menu = 0;

    while ((menu = printMenu()) != EXIT) {
        switch (menu) {
        case NEW:
            puts("=========================================================================");
            puts("> You selected [New]!");
            puts("> Press any key!");
            _getch();
            break;

        case SEARCH:
            puts("=========================================================================");
            puts("> You selected [Search]!");
            puts("> Press any key!");
            _getch();
            break;

        case PRINT:
            puts("=========================================================================");
            puts("> You selected [Print]!");
            puts("> Press any key!");
            _getch();
            break;

        case REMOVE:
            puts("=========================================================================");
            puts("> You selected [Remove]!");
            puts("> Press any key!");
            _getch();
            break;

        default:
            puts("=========================================================================");
            puts("> You selected [Wrong]!\n");
            puts("> Press any key\n");
            _getch();
            break;
        }
    }
    puts("> Closing soon.\n");

    return 0;
}

MY_MENU printMenu(void) {
    MY_MENU input = 0;

    // system() : OS의 명령어를 실행하는 C 표준 라이브러리 함수
    // cls = Clear Screen 
    system("cls");  // 화면을 지우는 Windows 명령 프롬프트 명령어
    printf("> [1] New\t[2] Search\t[3] Print\t[4] Remove\t[0] Exit\n");
    printf("> Enter: ");

    // 사용자가 문자열을 입력하면 scanf가 정수 변환에 실패하여 input 변수가 초기화되지 않아
    // 쓰레기 값 또는 0을 가져서 while 탈출하는 문제 발생 => 해결
    if (scanf_s("%d%*c", &input) != 1) {
        // 입력 실패 시 버퍼 비우기
        while (getchar() != '\n');

        return -1; // 또는 다시 입력 요청
    }

    return input;
}