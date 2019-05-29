#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "fungsi.h"

char password[55];

int main()
{
	system("color 16");
//	fullscreen();
	welcome();
}

void fullscreen()
{
    CONSOLE_SCREEN_BUFFER_INFOEX info = {0};
    int width, height;
    HANDLE hConsole = NULL;

    // maximize window
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);

    // print width/height of this window in terms of columns and rows
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    info.cbSize = sizeof(info);
    GetConsoleScreenBufferInfoEx(hConsole, &info);
}

void welcome() //fungsi welcome
{
	int inputPin, p=0;
    printf("                          SELAMAT DATANG\n");
    printf("                                DI\n");
    printf("                            BANK KRUT\n\n");
    printf("                      SILAHKAN MASUKKAN PIN");
    printf("\n\n\t\t   Masukkan PIN anda : "); 
	do{ 
        password[p]=getch(); 
        if(password[p]!='\r'){ 
            printf("*"); 
        } 
        p++; 
    }while(password[p-1]!='\r'); 
    password[p-1]='\0';
    inputPin=atoi(password);
	system ("cls");
 	verifikasi(inputPin, &pin);
}

void welcomeError()
{
	int inputPin, p=0;
    system("cls");
    printf("                          SELAMAT DATANG\n");
    printf("                                DI\n");
    printf("                            BANK KRUT\n\n");
    printf("                            PIN SALAH\a\n\n");
    printf("                      SILAHKAN MASUKKAN PIN");
    printf("\n\n\t\t   Masukkan PIN anda : "); 
	do{ 
        password[p]=getch(); 
        if(password[p]!='\r'){ 
            printf("*"); 
        } 
        p++; 
    }while(password[p-1]!='\r'); 
    password[p-1]='\0';
    inputPin=atoi(password);
    system("cls");
    verifikasi(inputPin, &pin);

}

int menu(){
	system ("cls");
	char input;
	printf("                    MENU UTAMA\n");
	printf("              PECAHAN UANG RP 50.000\n");
	printf("          ===============================\n");
	printf("               TEKAN <0> UNTUK BATAL\n\n");
	printf("  1. 100.000                           5. 500.000\n\n\n");
	printf("  2. 300.000                           6. 1.000.000\n\n\n");
	printf("  3. PENARIKAN JUMLAH LAIN             7. TRANSFER\n\n\n");
	printf("  4. CEK SALDO");
	printf("\n\nPILIHAN : ");
	scanf ("%c", &input);
	fflush (stdin);
	system("cls");
	switch(input)
	{
		case '1' :
    if(saldo >= 100000) //Jika saldo lebih dari 100.000 maka
       {
         saldo = saldo - 100000; //Saldo berkurang 100.000
         cekSaldo();
       }
    else
        {
          printf("                  MAAF");
          cekSaldo();
    	}
       case '2' :
    if(saldo >= 300000) //Jika saldo lebih dari 100.000 maka
       {
         saldo = saldo - 300000; //Saldo berkurang 100.000
         cekSaldo();
       }
    else
        {
          printf("                  MAAF");
          cekSaldo();
    	}
       case '3' :
    		penarikan();
            break;
       case '4' :
    		cekSaldo();
            break;
       case '5' :
    if(saldo >= 500000) //Jika saldo lebih dari 100.000 maka
       {
         saldo = saldo - 500000; //Saldo berkurang 100.000
         cekSaldo();
       }
    else
        {
          printf("                  MAAF");
          cekSaldo();
    	}
       case '6' :
    if(saldo >= 1000000) //Jika saldo lebih dari 1.000.000 maka
       {
         saldo = saldo - 1000000; //Saldo berkurang 1.000.000
       }
    else
        {
          printf("                  MAAF");
          cekSaldo();
    	}
       case '7' :
       		transfer();
        	break;
       case '0' :
       		system ("cls");
       		keluar();
            break;
    	default:
            errorInput();
            menu();
	}
	return 0;
}
