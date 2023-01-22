#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include <locale.h>
#include <time.h>
#include <process.h>
#include <mysql.h>
#include <string.h>
#pragma comment(lib,"libmySQL.lib")
MYSQL Conn;
MYSQL* ConnPtr = NULL;
MYSQL_ROW alwaysRow;
MYSQL_ROW newsRow;
char newss[150][3][255];
char weathers[24][3][255];
MYSQL_ROW weatherRow;
MYSQL_RES* alwaysResult;
MYSQL_RES* nResult;
MYSQL_RES* wResult;
CONSOLE_SCREEN_BUFFER_INFO presentCur;
DWORD dwNOER;
HANDLE CIN = 0;
CRITICAL_SECTION cs;
int onclick;
int shutoff;
char color[300];
char my[40][140];
int cc[16] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
int up=0;
int down=1;
void setcolor(unsigned short text, unsigned short back);
void screen(int up, int down);
int gotoxy(int x, int y);
void sender();
void shad(int x, int y);
void scroll(char right,int page);
int maincolor=1;
int flag;
int Stat;
int turnon;
int nowworking;
enum colour {
	black = 0,
	dblue,
	dgreen,
	dsky,
	dred,
	dpurple,
	dyellow,
	gray,
	dgray,
	blue,
	green,
	sky,
	red,
	purple,
	yellow,
	white
};
void scroll(char right,int page) {
    if (right == 'n') {
        gotoxy(0, page+1 );
        printf("%d\n",page);
        printf("■");
    }
    else if (right == 'w') {
        gotoxy(0, 3 * page - 1);
        printf("▲");
        gotoxy(0, 3 * page);
        printf("■");
        gotoxy(0, 3 * page + 1);
        printf("▼");
    }
}
void setcolor(unsigned short text, unsigned short back){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}
int gotoxy(int x, int y)
{
    COORD pos = { x, y };
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void connect() {
    mysql_init(&Conn);
    ConnPtr = mysql_real_connect(&Conn, "127.0.0.1", "root", "1234", "news", 3306, (char*)NULL, 0);
    if (ConnPtr == NULL) {
        Beep(260, 500);
        printf("MYSQL-!C  please try again : %s", mysql_error(&Conn));
        return;
    }
}
void turnoff() {
    mysql_close(ConnPtr);
}
void always() {
    char Query[100] = "SELECT * FROM `ytn`";
    Stat = mysql_query(ConnPtr, Query);
    if (Stat != 0) {
        Beep(260, 500);
        gotoxy(50, 30);
        printf("SQL -! C please try again : %s", mysql_error(&Conn));
        return;
    }
    alwaysResult = mysql_store_result(ConnPtr);
    while ((alwaysRow = mysql_fetch_row(alwaysResult)) != NULL) {
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
        nowworking = 1;
        if (shutoff==1) {
            nowworking = 0;
            gotoxy(0, 0);
            setcolor(white, maincolor);
            printf("                                                                                                                                            ");
            gotoxy(0, 1);
            printf("                                                                                                                                            ");
            gotoxy(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);
            return;
        }
        //EnterCriticalSection(&cs);
        gotoxy(0, 0);
        setcolor(black, gray);
        printf("                                                                                                                                            ");
        gotoxy(0, 1);
        printf("____________________________________________________________ALWAYS NEWS_____________________________________________________________________");
        setcolor(black, gray);
        gotoxy(0, 0);
        printf("%s. ", alwaysRow[0]);
        printf("%s ", alwaysRow[1]);
        printf("%s ", alwaysRow[2]);
        setcolor(white, maincolor);
        gotoxy(presentCur.dwCursorPosition.X, presentCur.dwCursorPosition.Y);
        //LeaveCriticalSection(&cs);
        Sleep(5000);
    }
    printf("This news is provided by naver news.");
    TerminateThread(always, 0);
}
void print(char right) {
    if (right == 'n') {
        for (int i = 0; i < 22;) {
            WaitForSingleObject(always, INFINITE);
            gotoxy(0, 2);
            for (int k = 0; k < 37 * 140; k++) {
                setcolor(white, maincolor);
                printf(" ");
            }
            if (i != 21) {
                scroll('n', i + 1);
                for (int j = 0; j < 7; j++) {
                    Sleep(10);
                    gotoxy(2, 4 * (j + 1) - 2);
                    printf("__________________________________________________________________________________________________________________________________________");
                    gotoxy(2, 4 * (j + 1) - 1);
                    printf("Serial number : %s", newss[i * 7 + j][0]);
                    gotoxy(2, 4 * (j + 1));
                    printf("Head Line : %s", newss[i * 7 + j][1]);
                    gotoxy(2, 4 * (j + 1) + 1);
                    printf("Link : https://n.news.naver.com/mnews/article/052/%s ", newss[i * 7 + j][2]);
                }
            }
            else {
                scroll('n', i + 1);
                for (int j = 0; j < 3; j++) {
                    gotoxy(2, 4 * (j + 1) - 2);
                    printf("__________________________________________________________________________________________________________________________________________");
                    gotoxy(2, 4 * (j + 1) - 1);
                    printf("Serial number : %s", newss[i * 7 + j][0]);
                    gotoxy(2, 4 * (j + 1));
                    printf("Head Line : %s", newss[i * 7 + j][1]);
                    gotoxy(2, 4 * (j + 1) + 1);
                    printf("Link : https://n.news.naver.com/mnews/article/052/%s ", newss[i * 7 + j][2]);
                }
            }
                char check;
                pagere:
                gotoxy(2, 36);
                if (i == 0) {
                    printf("t : turn off , > : go next page");
                    gotoxy(2, 37);
                    scanf("%c", &check);
                    if (check == '>') {
                        i++;
                    }
                    else if (check == '<') {
                        gotoxy(2, 38);
                        printf("This is a first page");
                        Sleep(1000);
                        gotoxy(2, 37);
                        printf("                    ");
                        goto pagere;
                    }
                    else if (check == 't') {
                        system("cls");
                        screen(1, 1);
                        sender();
                        return;
                    }
                    else {
                        gotoxy(2, 37);
                        printf("                    ");
                        goto pagere;
                    }
                }
                else if (i == 21) {
                    printf("t : turn off , < : go previous page");
                    gotoxy(2, 37);
                    scanf("%c", &check);
                    if (check == '>') {
                        gotoxy(2, 38);
                        printf("This is a last page");
                        Sleep(1000);
                        gotoxy(2, 37);
                        printf("                    ");
                    }
                    else if (check == '<') {
                        i--;
                    }
                    else if (check == 't') {
                        system("cls");
                        sender();
                        return;
                    }
                    else {
                        gotoxy(2, 37);
                        printf("                    ");
                        goto pagere;
                    }
                }
                else {
                    printf("t : turn off , < : go previous page , > : go next page");
                    gotoxy(2, 37);
                    scanf("%c", &check);
                    if (check == '>') {
                        i++;
                    }
                    else if (check == '<') {
                        i--;
                    }
                    else if (check == 't') {
                        system("cls");
                        sender();
                        return;
                    }
                    else {
                        gotoxy(2, 37);
                        printf("                    ");
                        goto pagere;
                    }
                }
        }
    }
    else if (right == 'w') {
        for (int i = 0; i < 8;) {
            gotoxy(0, 2);
            for (int k = 0; k < 37 * 140; k++) {
                setcolor(white, maincolor);
                printf(" ");
            }
            for (int j = 0; j < 3; j++) {
                scroll('w', i + 1);
                gotoxy(2, j*9+2);
                printf("__________________________________________________________________________________________________________________________________________");
                gotoxy(2, j*9+3);
                printf("%s ", weathers[i*3+j][0]);
                gotoxy(2, j*9+4);
                printf("%s \n", weathers[i * 3 + j][1]);
                if (strcmp("cloudy", weathers[i * 3 + j][2]) == 0) {
                    gotoxy(2, j * 9 + 5);
                    printf("        ________________");
                    gotoxy(2, j * 9 + 6);
                    printf("        |               |");
                    gotoxy(2, j * 9 + 7);
                    printf("    _________________");
                    gotoxy(2, j * 9 + 8);
                    printf("   /                 \\");
                    gotoxy(2, j * 9 + 9);
                    printf("__/       Cloudy      \\____");
                    gotoxy(2, j * 9 + 10);
                    printf("_____________________________");
                }
                else if (strcmp("blur", weathers[i * 3 + j][2]) == 0) {
                    gotoxy(2, j * 9 + 5);
                    printf("    _________________");
                    gotoxy(2, j * 9 + 6);
                    printf("   /                 \\");
                    gotoxy(2, j * 9 + 7);
                    printf("__/     Blur          \\____");
                    gotoxy(2, j * 9 + 8);
                    printf("_____________________________");
                }
                else if (strcmp("Sunny", weathers[i * 3 + j][2]) == 0) {
                    gotoxy(2, j * 9 + 5);
                    printf("_____________________");
                    gotoxy(2, j * 9 + 6);
                    printf("|                    |");
                    gotoxy(2, j * 9 + 7);
                    printf("|                    |");
                    gotoxy(2, j * 9 + 8);
                    printf("|     Sunny          |");
                    gotoxy(2, j * 9 + 9);
                    printf("|                    |");
                    gotoxy(2, j * 9 + 10);
                    printf("_____________________");
                }
                else if (strcmp("rain", weathers[i * 3 + j][2]) == 0) {
                    gotoxy(2, j * 9 + 5);
                    printf("|          |          |");
                    gotoxy(2, j * 9 + 6);
                    printf("|     |       |        |");
                    gotoxy(2, j * 9 + 7);
                    printf("|     |      |       |  |");
                    gotoxy(2, j * 9 + 8);
                    printf("| |    rain          |");
                    gotoxy(2, j * 9 + 9);
                    printf("|      |     |         |");
                    gotoxy(2, j * 9 + 10);
                    printf("|   |       |     |     |");
                }
                else {
                    gotoxy(2, j * 9 + 5);
                    printf("|      __________     |");
                    gotoxy(2, j * 9 + 6);
                    printf("|     |          |    |");
                    gotoxy(2, j * 9 + 7);
                    printf("|                |    |");
                    gotoxy(2, j * 9 + 8);
                    printf("|   unkown  _____     |");
                    gotoxy(2, j * 9 + 9);
                    printf("|          |          |");
                    gotoxy(2, j * 9 + 10);
                    printf("|          ㅁ         |");
                }
            }
            char check;
            pagere2:
            gotoxy(2, 36);
            if (i == 0) {
                printf("t : turn off , > : go next page");
                gotoxy(2, 37);
                scanf("%c", &check);
                if (check == '>') {
                    i++;
                }
                else if (check == '<') {
                    gotoxy(2, 38);
                    printf("This is a first page");
                    Sleep(1000);
                    gotoxy(2, 37);
                    printf("                    ");
                    goto pagere2;
                }
                else if (check == 't') {
                    system("cls");
                    screen(1, 1);
                    sender();
                    return;
                }
                else {
                    gotoxy(2, 37);
                    printf("                    ");
                    goto pagere2;
                }
            }
            else if (i == 7) {
                printf("t : turn off , < : go previous page");
                gotoxy(2, 37);
                scanf("%c", &check);
                if (check == '>') {
                    gotoxy(2, 38);
                    printf("This is a last page");
                    Sleep(1000);
                    gotoxy(2, 37);
                    printf("                    ");
                }
                else if (check == '<') {
                    i--;
                }
                else if (check == 't') {
                    system("cls");
                    screen(1, 1);
                    sender();
                    return;
                }
                else {
                    gotoxy(2, 37);
                    printf("                    ");
                    goto pagere2;
                }
            }
            else {
                printf("t : turn off , < : go previous page , > : go next page");
                gotoxy(2, 37);
                scanf("%c", &check);
                if (check == '>') {
                    i++;
                }
                else if (check == '<') {
                    i--;
                }
                else if (check == 't') {
                    system("cls");
                    screen(1, 1);
                    sender();
                    return;
                }
                else {
                    gotoxy(2, 37);
                    printf("                    ");
                    goto pagere2;
                }
            }
        }
    }
} 
void news() {
    char Query[100] = "SELECT * FROM `ytn`";
    Stat = mysql_query(ConnPtr, Query);
    if (Stat != 0) {
        printf("SQL -! C please try again : %s", mysql_error(&Conn));
        return;
    }
    nResult = mysql_store_result(ConnPtr);
    int i = 0;
    while( newsRow = mysql_fetch_row(nResult)){
        strcpy(newss[i][0], newsRow[0]);
        strcpy(newss[i][1], newsRow[1]);
        strcpy(newss[i][2], newsRow[2]);
        i++;
    }
    mysql_free_result(nResult);
    return;
}
void weather() {
    char Query[100] = "SELECT * FROM `weather`";
    Stat = mysql_query(ConnPtr, Query);
    if (Stat != 0) {
        printf("SQL -! C please try again : %s", mysql_error(&Conn));
        return;
    }
    wResult = mysql_store_result(ConnPtr);
    int k = 0;
    while (weatherRow = mysql_fetch_row(wResult)) {
        strcpy(weathers[k][0],weatherRow[0]);
        strcpy(weathers[k][1],weatherRow[1]);
        strcpy( weathers[k][2],weatherRow[2]);
        k++;
    }
    mysql_free_result(wResult);
    return;
}
void sender() {
    //_beginthreadex(NULL, 0, (_beginthreadex_proc_type)send, NULL, 0, NULL);
    char Query[100] = "";
    shutoff = 0;
    screen(1, 1);
    Sleep(1000);
home:
    gotoxy(50, 20);
    
    printf("What will you do? ");
    gotoxy(50, 21);
    scanf("%s", Query);
    if (strcmp(Query, "help") == 0) {
        gotoxy(50, 22);
        printf("news : print the news");
        gotoxy(50, 23);
        printf("Weather : print the weather");
        gotoxy(50, 22);
        Sleep(7000);
        printf("                           ");
        gotoxy(50, 23);
        printf("                           ");
        gotoxy(50, 20);
        goto home;
    }
    else if (strcmp(Query, "news") == 0) {
        system("cls");
        gotoxy(0,0);
        setcolor(black, gray);
        printf("Todays News                                                                              NAVER                                              ");
        shutoff = 1;
        screen(0, 1);
        print('n');
    }
    else if (strcmp(Query, "weather") == 0) {
        system("cls");
        gotoxy(0, 0);
        setcolor(black, gray);
        printf("Todays Weather                                                                              NAVER                                           ");
        shutoff = 1;
        screen(0, 1);
        print('w');
    }
    else if (strcmp(Query, "turn off") == 0) {
        turnoff();
        return;
    }
    else {
        goto home;
    }
}
void screen(int up, int down) {
    for (int i = 0; i < 40 * 140; i++) {
        printf(" ");
    }
    /*if (up) {
        setcolor(black, gray);
        gotoxy(0, 0);
        printf("                                                                                                                                            ");
        gotoxy(0, 0);
        if (alwaysRow != NULL) {
        Sleep(100);
        printf("%s. ", alwaysRow[0]);
        printf("%s ", alwaysRow[1]);
        printf("%s ", alwaysRow[2]);
        }
        gotoxy(0, 1);
        printf("____________________________________________________________ALWAYS NEWS_____________________________________________________________________");
        setcolor(white, maincolor);
    }*/
    if (down) {
        gotoxy(0, 39);
        setcolor(black, gray);
        printf(">>               h:Help                          w:Weather                             n:News                          c:Color           <<");
        gotoxy(0, 0);
        setcolor(white, maincolor);
    }
    if (up==1 && nowworking ==0) {
       // InitializeCriticalSection(&cs);
        _beginthreadex(NULL, 0, (_beginthreadex_proc_type)always, NULL, 0, NULL);
    }
    /*if (up == 0) {
        if (flag == 1) {
            TerminateThread((_beginthreadex_proc_type)always, 0);
        }
        
    }*/
}
void loading() {
    gotoxy(50, 10);
    printf("ISSUE PROGRAM en POWERED BY naver");
    gotoxy(50, 13);
    printf("SQL Connect....");
    gotoxy(50, 15);
    for (int i = 0; i < 20; i++) {
        printf("■");
        Sleep(100);
        if (i == 10) {
            connect();
            Sleep(1000);
            news();
            Sleep(1000);
        }
        else if (i == 15) {
            weather();
            Sleep(1000);
        }
    }
    gotoxy(50, 17);
    printf("Connection Complete");
    Beep(420, 500);
    system("cls");
    Sleep(100);
    sender();
}
int main()
{   
    setlocale(0, "");
    system("cls");
    setcolor(white, dblue);
    SetConsoleTitle(TEXT("ISSUE PROGRAM en POWERED BY naver"));
    system("mode con:cols=140 lines=40");
    for (int i = 0; i < 40 * 140; i++) {
        printf(" ");
    }
    system("cls");
    screen(0, 1);
    gotoxy(50, 20);
    setcolor(white, dblue);
    printf("Please set a color");

    for (int i = 0; i < 15; i++) {
        gotoxy(50 + 2 * i, 21);
        setcolor(white, cc[i]);
        printf("  ");
    }
    gotoxy(50, 22);
    rec :
    setcolor(white, dblue);
    
    scanf("%s", color);
    if (strcmp(color, "black") == 0) {
        maincolor = black;
        setcolor(white, black);
    }
    else if (strcmp(color, "dblue") == 0) {
        maincolor = dblue;
        setcolor(white, dblue);
    }
    else if (strcmp(color, "dgreen") == 0) {
        maincolor = dgreen;
        setcolor(white, dgreen);
    }
    else if (strcmp(color, "dred") == 0) {
        maincolor = dred;
        setcolor(white, dred);
    }
    else if (strcmp(color, "dpurple") == 0) {
        maincolor = dpurple;
        setcolor(white, dpurple);
    }
    else if (strcmp(color, "dyellow") == 0) {
        maincolor = dyellow;
        setcolor(white, dyellow);
    }
    else if (strcmp(color, "gray") == 0) {
        maincolor = gray;
        setcolor(white, gray);
    }
    else if (strcmp(color, "dgray") == 0) {
        maincolor = dgray;
        setcolor(white, dgray);
    }
    else if (strcmp(color, "blue") == 0) {
        maincolor = blue;
        setcolor(white, blue);
    }
    else if (strcmp(color, "green") == 0) {
        maincolor = green;
        setcolor(white, green);
    }
    else if (strcmp(color, "sky") == 0) {
        maincolor = sky;
        setcolor(white, sky);
    }
    else if (strcmp(color, "red") == 0) {
        maincolor = red;
        setcolor(white, red);
    }
    else if (strcmp(color, "purple") == 0) {
        maincolor = purple;
        setcolor(white, purple);
    }
    else if (strcmp(color, "yellow") == 0) {
        maincolor = yellow;
        setcolor(white, yellow);
    }
    else {
        gotoxy(50, 23);
        if (strcmp(color, "white") == 0) {
            printf("We don't provide white");
        }
        else {
            printf("There is no color please retry");
        }
        
        gotoxy(50, 23);
        for (int i = 0; i < 30; i++) {
            printf(" ");
            Sleep(100);
        }
        gotoxy(50, 22);
        for (int i = 0; i < 30; i++) {
            printf(" ");
            Sleep(100);
        }
        gotoxy(50, 22);
        goto rec;
    }
    system("cls");
    screen(0, 1);
    loading();
}