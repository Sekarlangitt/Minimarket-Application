#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3
#define GENERATE_BUTTON 11


LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void AddMenus(HWND);
void AddControls(HWND);
void loadImages1();
void loadImages2();
void loadImages3();
void loadImages4();
void loadImages5();
void loadImages6();
void loadLogo();
void Menus();

char texts[256];
int price = 0;
int itemPrice [100];
int itemQuantity [100];
int num = 0 ;

HWND hInput, hInput1, hAge, hOut, hOut1, hOut2, hOut3, hmyImg, hLogos, hMainWindow, hGenerate;
HMENU hMenu;
HBITMAP hImg1, hImg2, hImg3, hImg4, hImg5, hImg6, hLogo;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args,int ncmdshow)
{
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW ;
    wc.hCursor = LoadCursor (NULL,IDC_ARROW) ;
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"myWindowClass", L"MON'S BEAUTY", WS_OVERLAPPEDWINDOW |WS_VISIBLE, 20, 20, 1500, 800,
                  NULL, NULL, NULL, NULL);
    MSG msg = {0};
    while(GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

int powInt (int x, int y)
{
    for(int i = 0; i < y; i++)
    {
        x *= 10;
    }
    return x;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){

    int val;
    switch(msg)
    {
    case WM_COMMAND:
        switch(wp){

            case FILE_MENU_EXIT:
                DestroyWindow(hWnd);
                break;
            case 11:

                string totalPrice ;
                int quantity;
                char*t = &texts[0];
                char text2[10];

                char out[10];

                GetWindowText(hInput,&texts[0],256);
                GetWindowText(hInput1,text2,100);
                stringstream temp1;
                temp1 << text2;
                temp1 >> quantity;

            if (*t == '1') {
                SendMessage(hOut, WM_SETTEXT, 0, (LPARAM)"Scarlett Body Lotion (All Varian)");
                SendMessage(hOut1, WM_SETTEXT, 0, (LPARAM)"Price : Rp. 75.000");
                SendMessage(hOut2, WM_SETTEXT, 0, (LPARAM)"Scarlett Body Lotion (All Varian)");

                itemPrice [num] = 75000;
                itemQuantity[num] = quantity;
                loadImages1();
                price += 75000*quantity;
                //SendMessage(hOut1, WM_SETTEXT,0,(LPARAM)
            }else if(*t == '2') {
                SendMessage(hOut, WM_SETTEXT, 0, (LPARAM)"Scarlett Body Soap (All Varian)");
                SendMessage(hOut1, WM_SETTEXT, 0, (LPARAM)"Price : Rp. 70.000");
                SendMessage(hOut2, WM_SETTEXT, 0, (LPARAM)"Scarlett Body Soap (All Varian)");

                itemPrice [num] = 70000;
                itemQuantity[num] = quantity;
                loadImages2();
                price += 70000*quantity;
            }else if(*t == '3') {
                SendMessage(hOut, WM_SETTEXT, 0, (LPARAM)"Scarlett Brightening Facial Wash");
                SendMessage(hOut1, WM_SETTEXT, 0, (LPARAM)"Price : Rp. 60.000");
                SendMessage(hOut2, WM_SETTEXT, 0, (LPARAM)"Scarlett Brightening Facial Wash");

                itemPrice [num] = 60000;
                itemQuantity[num] = quantity;
                loadImages3();
                price += 60000*quantity;
            }else if(*t == '4') {
                SendMessage(hOut, WM_SETTEXT, 0, (LPARAM)"Scarlett Acne Serum");
                SendMessage(hOut1, WM_SETTEXT, 0, (LPARAM)"Price : Rp. 55.000");
                SendMessage(hOut2, WM_SETTEXT, 0, (LPARAM)"Scarlett Acne Serum");

                itemPrice [num] = 55000;
                itemQuantity[num] = quantity;
                loadImages4();
                price += 55000*quantity;
            }else if(*t == '5') {
                SendMessage(hOut, WM_SETTEXT, 0, (LPARAM)"Scarlett Brightly Ever After Serum");
                SendMessage(hOut1, WM_SETTEXT, 0, (LPARAM)"Price : Rp. 50.000");
                SendMessage(hOut2, WM_SETTEXT, 0, (LPARAM)"Scarlett Brightly Ever After Serum");

                itemPrice [num] = 50000;
                itemQuantity[num] = quantity;
                loadImages5();
                price += 50000*quantity;
            }else {
                SendMessage(hOut, WM_SETTEXT, 0, (LPARAM)"Not Available");
                SendMessage(hOut1, WM_SETTEXT, 0, (LPARAM)"Price : -");
                MessageBeep(MB_OKCANCEL);
            }
            char arrPrice[totalPrice.length()+1];
                char quantityDisplay[2];
                static char rp [10];
                stringstream temp;
                temp << price;
                temp >> totalPrice;

                strcpy(arrPrice, totalPrice.c_str());
                strcpy(rp,"Rp.");
                strcat(rp,arrPrice);

                stringstream temp3;
                temp3 << quantity;
                temp3 >> quantityDisplay;
                SendMessage(hOut2, WM_SETTEXT, 0, (LPARAM)rp);
                SendMessage(hOut3, WM_SETTEXT, 0, (LPARAM)quantityDisplay);

                static char itemList [1000];
                static char space [2];
                static char char_total[20];
                static char eol[2];

                strcpy(itemList,"");
                strcpy(space," ");
                strcpy(eol,"\r\n");
                strcpy(char_total,"Total = ");


                for (int i=0; i <= num ; i++){
                    char convPrice[10];
                    sprintf(convPrice, "%d", itemPrice[i]);
                    char convQuantity[10];
                    sprintf(convQuantity, "%d", itemQuantity[i]);

                    int total = itemPrice[i] * itemQuantity[i];
                    char convTotal[1000];
                    sprintf(convTotal, "%d", total);
                    char number[2];
                    sprintf(number, "%d",i+1);
                    strcat(itemList, number);
                    strcat(itemList, space);

                    strcat(itemList, convPrice);
                    strcat(itemList, space);

                    strcat(itemList, convQuantity);
                    strcat(itemList, space);

                    strcat(itemList, char_total);
                    strcat(itemList, convTotal);
                    strcat(itemList, eol);

                    SetWindowText(hOut3,itemList);
                }


                num++;

            break;

        }
        break;
    case WM_CREATE:
        AddMenus(hWnd);
        AddControls(hWnd);
        loadLogo();
        loadImages6();
        break;
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd,msg,wp,lp);
    }

}

void AddMenus(HWND hWnd){
    hMenu = CreateMenu();
    HMENU hFileMenu = CreateMenu();

    AppendMenu(hFileMenu,MF_STRING,FILE_MENU_EXIT,"Exit");

    AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hFileMenu,"File");

    SetMenu(hWnd,hMenu);
}

void AddControls(HWND hWnd){

    CreateWindowW(L"Static", L"WELCOME TO MON'S BEAUTY \nShop of Skincare and Bodycare", WS_VISIBLE | WS_CHILD | SS_CENTER, 500, 50, 500, 50, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"Skincare and Bodycare : \n1. Scarlett Body Lotion (All Varian) \n2. Scarlett Body Soap (All Varian) \n3. Scarlett Brightening Facial Wash \n4. Scarlett Acne Serum\n5. Scarlett Brightly Ever After Serum",
                  WS_VISIBLE | WS_CHILD, 50, 200, 400, 200, hWnd, NULL, NULL, NULL);

    hOut = CreateWindowW(L"Edit", L"Input the Code", WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | SS_CENTER | WS_BORDER, 350, 460, 145, 50, hWnd, NULL, NULL, NULL);
    hOut1 = CreateWindowW(L"Edit",L"Price: -", WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | SS_CENTER | WS_BORDER, 505, 460, 145, 50, hWnd, NULL, NULL, NULL);
    hmyImg = CreateWindowW(L"Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP | WS_BORDER, 350, 150, 300, 300, hWnd, NULL, NULL, NULL);
    hLogos = CreateWindowW(L"Static", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP , 100, 10, 130, 120, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Static", L"INPUT THE ORDER HERE", WS_VISIBLE | WS_CHILD | SS_CENTER, 900, 150, 400, 50, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"Code of Items", WS_VISIBLE | WS_CHILD | SS_LEFT, 800, 180, 200, 50, hWnd, NULL, NULL, NULL);
    hInput = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 900, 180, 80, 30, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"Quantity", WS_VISIBLE | WS_CHILD | SS_LEFT,800, 220, 200, 50, hWnd, NULL, NULL, NULL);
    hInput1 = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER, 900, 220, 80, 30, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Static", L"List of The Order", WS_VISIBLE | WS_CHILD | SS_CENTER, 900, 300, 400, 50, hWnd, NULL, NULL, NULL);
    CreateWindowW(L"Button", L"INPUT", WS_VISIBLE | WS_CHILD |WS_BORDER, 900, 260, 80, 30, hWnd, (HMENU)GENERATE_BUTTON, NULL, NULL);
    hOut3 = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL |WS_BORDER, 800, 330, 600, 260, hWnd, NULL, NULL, NULL);

    CreateWindowW(L"Static", L"Total", WS_VISIBLE | WS_CHILD | SS_LEFT, 800, 600, 200, 50, hWnd, NULL, NULL, NULL);
    hOut2 = CreateWindowW(L"Edit",L"-", WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | SS_CENTER | WS_BORDER, 900, 600, 145, 30, hWnd, NULL, NULL, NULL);

    hGenerate = CreateWindowW(L"Static",NULL,WS_VISIBLE | WS_CHILD | SS_BITMAP,170,370,80,30,hWnd,NULL,NULL,NULL);
}

void loadImages1(){
    hImg1 = (HBITMAP)LoadImageW(NULL, L"lotion.bmp", IMAGE_BITMAP, 300, 300, LR_LOADFROMFILE);
    SendMessageW(hmyImg, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hImg1);
}
void loadImages2(){
    hImg2 = (HBITMAP)LoadImageW(NULL, L"soap.bmp", IMAGE_BITMAP, 300, 300, LR_LOADFROMFILE);
    SendMessageW(hmyImg, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hImg2);
}
void loadImages3(){
    hImg3 = (HBITMAP)LoadImageW(NULL, L"fwash.bmp", IMAGE_BITMAP, 300, 300, LR_LOADFROMFILE);
    SendMessageW(hmyImg, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hImg3);
}
void loadImages4(){
    hImg4 = (HBITMAP)LoadImageW(NULL, L"serum.bmp", IMAGE_BITMAP, 300, 300, LR_LOADFROMFILE);
    SendMessageW(hmyImg, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hImg4);
}
void loadImages5(){
    hImg5 = (HBITMAP)LoadImageW(NULL, L"bserum.bmp", IMAGE_BITMAP, 300, 300, LR_LOADFROMFILE);
    SendMessageW(hmyImg, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hImg5);
}
void loadImages6(){
    hImg6 = (HBITMAP)LoadImageW(NULL, L"logo.bmp", IMAGE_BITMAP, 300,300, LR_LOADFROMFILE);
    SendMessageW(hmyImg, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hImg6);
}
void loadLogo(){
    hLogo = (HBITMAP)LoadImageW(NULL,L"logo.bmp",IMAGE_BITMAP,130,120,LR_LOADFROMFILE);
    SendMessageW(hLogos,STM_SETIMAGE,(WPARAM)IMAGE_BITMAP,(LPARAM)hLogo);
}
