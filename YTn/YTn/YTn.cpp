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
MYSQL_ROW Row;
MYSQL_RES* alwaysResult;
MYSQL_RES* Result;
CONSOLE_SCREEN_BUFFER_INFO presentCur;
int Stat;
void sender();
int gotoxy(int x, int y)
{
    COORD pos = { x, y };
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void connect() {
    mysql_init(&Conn);
    ConnPtr = mysql_real_connect(&Conn,"127.0.0.1","root","1234","news",3306,(char*)NULL,0);
    if (ConnPtr == NULL) {
        Beep(260, 500);
        printf("MYSQL-!C  please try again : %s",mysql_error(&Conn));
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
        printf("SQL -! C please try again : %s", mysql_error(&Conn));
        return;
    }
    alwaysResult = mysql_store_result(ConnPtr);
    re :
    while ((alwaysRow = mysql_fetch_row(alwaysResult)) != NULL) {
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);
        gotoxy(0, 0);
        for (int i = 0; i < 140; i++) {
            printf(" ");
        }
        gotoxy(0, 1);
        for (int i = 0; i < 140; i++) {
            printf(" ");
        }
        gotoxy(0, 1);
        printf("----------------------------------Always News--------------------------------");
        gotoxy(0, 0);
        printf("%s. ", alwaysRow[0]);
        printf("%s ", alwaysRow[1]);
        printf("%s ", alwaysRow[2]);
        gotoxy(presentCur.dwCursorPosition.X,presentCur.dwCursorPosition.Y );
        Sleep(5000);
        
    }
    int check=0;
    printf("This news is provided by naver news. Will you seem more? ");
    scanf("%d", check);
    if (check !=1) {
       mysql_free_result(alwaysResult);
       turnoff();
    }
    goto re;
    
}void news() {
    char Query[100] = "SELECT * FROM `ytn`";
    Stat = mysql_query(ConnPtr, Query);
    if (Stat != 0) {
        Beep(260, 500);
        printf("SQL -! C please try again : %s", mysql_error(&Conn));
        return;
    }
    Result = mysql_store_result(ConnPtr);
    while ((Row = mysql_fetch_row(Result)) != NULL) {
        Beep(420, 500);
        Beep(340, 500);
        printf("_________________________________________________________________________________________________\n");
        printf("Serial number : %s\n", Row[0]);
        printf("Head Line : %s\n", Row[1]);
        printf("Link : %s\n", Row[2]);
        Sleep(100);
    }
    printf("News data is all printed");
    mysql_free_result(Result);
    system("cls");
    sender();

}void weather() {
    char Query[100] = "SELECT * FROM `weather`";
    Stat = mysql_query(ConnPtr, Query);
    if (Stat != 0) {
        Beep(260, 500);
        printf("SQL -! C please try again : %s", mysql_error(&Conn));
        return;
    }
    Result = mysql_store_result(ConnPtr);
    while ((Row = mysql_fetch_row(Result)) != NULL) {
        Beep(420, 500);
        Beep(340, 500);
        printf("_________________________________________________________________________________________________\n");
        printf("%s ", Row[0]);
        printf("%s ", Row[1]);
        printf("Weather : %s\n", Row[2]);
        Sleep(100);
    }
    printf("Todays Weather\n");
    mysql_free_result(Result);
    system("cls");
    sender();
}
void sender() {
    //_beginthreadex(NULL, 0, (_beginthreadex_proc_type)send, NULL, 0, NULL);
    char Query[100] = "SELECT * FROM `ytn`";
home :
    gotoxy(0, 3);
    printf("What will you do?");
    scanf("%s", Query);
    if (strcmp(Query,"help")==0) {
        printf("news : print the news");
        printf("Weather : print the weather");
        goto home;
    }
    else if (strcmp(Query, "news") == 0) {
        news();
    }
    else if (strcmp(Query, "weather") == 0) {
        weather();
    }
    else{
        turnoff();
    }
    
    Stat = mysql_query(ConnPtr, Query);
    if (Stat != 0) {
        Beep(260, 500);
        printf("SQL -! C please try again : %s", mysql_error(&Conn));
        return;
    }
    Result = mysql_store_result(ConnPtr);
    while ((Row = mysql_fetch_row(Result)) != NULL ) {
        Beep(420, 500);
        Beep(340, 500);
        printf("_________________________________________________________________________________________________\n");
        printf("Serial number : %s\n", Row[0]);
        printf("Head Line : %s\n",Row[1]);
        printf("Link : %s\n", Row[2]);
        Sleep(10000);
    }
    printf("News data is all printed");
    mysql_free_result(Result);
    turnoff();
}



void loading() {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        gotoxy(30,0); 
        printf("ISSUE PROGRAM en");
        gotoxy(0, 1);
        printf("SQL Connect....\n");
        printf("MYSQL");
        for (int i = 0; i < 20; i++) {
            printf("->");
            Sleep(100);
            if (i==10) {
                connect();
                Sleep(1000);
            }
        }
        printf("C\n");
        printf("Connection Complete");
        Beep(420, 500);
        printf("\n\n");
        system("cls");
        _beginthreadex(NULL, 0, (_beginthreadex_proc_type)always, NULL, 0, NULL);
        sender();
}


int main()
{
   system("cls");
   SetConsoleTitle("ISSUE Loading Program"); 
   system("mode con:cols=140 lines=40");
   loading();
}