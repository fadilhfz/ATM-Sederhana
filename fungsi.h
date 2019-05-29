#ifndef FUNGSI_H_INCLUDED
#define FUNGSI_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int menu(), cekSaldo();
void konfirmasi(), errorInput(), welcomeError(), welcome(), keluar(), inputRekening();
void akun(char *user[], char *name[]);
void verifikasi(int p, int *inputPin);
void saldoATM(unsigned long long int *saldoAkun, unsigned long long int saldoSisa);
void noRekening(unsigned long long int *noRek, unsigned long long int rekeningSaldo);
void temp(unsigned long long int *tmp, unsigned long long int temp);

char *akunATM, akunA[50][100]={"Dimas Radhitya","Fadhil Hafizh"};
int pin, pinA[50]={111000,222000};
unsigned long long int saldo = 0, saldoA[50]={500000,500000};
unsigned long long int rek = 0, rekA[50]={1806199972,1806148763}, tmp=0;

void saldoATM(unsigned long long int *saldoAkun, unsigned long long int saldoSisa)
{
	*saldoAkun = saldoSisa;
}

void noRekening(unsigned long long int *noRek, unsigned long long rekeningAkun)
{
	*noRek = rekeningAkun;
}

void temp(unsigned long long int *tmp, unsigned long long int temp)
{
    *tmp = temp;
}

void errorInput()
{
    system("cls");
    printf("\n\n\n                   Maaf Pilihan Tidak Tersedia\n\n");
}

void verifikasi(int p, int *inputPin)
{
    char **akunAktif;
    int n=0;
    for (n=0;n<50;n++)
    {
        if(p == pinA[n])
        {
            *inputPin = p;
            akunAktif = &akunATM;
            *akunAktif = (char*) malloc(100 * sizeof(char));
            strcpy(*akunAktif, akunA[n]);
            saldoATM(&saldo,saldoA[n]);
            noRekening (&rek,rekA[n]);
            printf("\n\nNama akun\t: %s\n", akunATM);
            printf("\nSaldo akun\t: Rp %llu\n", saldo);
            printf("\nRekening Akun\t: %llu\n", rek);
            sleep(2);
            menu();
        }
	}
	welcomeError();
}

int cekSaldo()
{
	char input;
	printf("\n\n                  SISA SALDO ANDA\n\n");
	printf("                 "); printf("Rp %llu",saldo);
	printf("\n\n\n  APAKAH ANDA INGIN MELAKUKAN TRANSAKSI LAIN?\n\n");
	printf("          1. YA\n\n          2. TIDAK\n\n");
	printf("Pilihan : ");
	scanf("%c", &input);
	fflush (stdin);
	system("cls");
	switch (input) 
	{
	case '1':
        menu(); 
        break;
    case '2':
    	keluar(); 
    	break;
    default:
        errorInput();
        cekSaldo();
        break;
    }
}
void keluar(){
	int n;
	for (n=0;n<2;n++)
	{
	if(pin == pinA[n])
       saldoATM(&saldoA[n], saldo); //Mengupdate sisa saldo terbaru
	}
	welcome();
}

int penarikan()
{
    system("cls");
    unsigned long long int nominal;
    char input;
    printf("\n\n                   MASUKKAN NOMINAL KELIPATAN RP 50000\n\n");
    printf("                           Rp "); scanf("%llu", &nominal);
    printf("\n\n                  1. BENAR\n\n                  2. KELUAR\n\n                  3. KEMBALI KE MENU");
    printf("\n\n\tPILIHAN : "); 
	scanf("%c",&input);
	fflush (stdin);
    system("cls");
    switch (input)
    {
    case '1':
        if((nominal%50000 == 0) && saldo >= nominal)
        {
            saldo = saldo - nominal;
            cekSaldo();
        }
        else
        {
            printf("                  MAAF");
            cekSaldo();
        }
        break;
    case '2':
        keluar();
        break;
    default:
        menu();
        break;
    }
    return 0;
}

void transfer()
{
    system("cls");
    char input;
    unsigned long long int nominal;
    printf("\n\n                  MASUKKAN NOMINAL MINIMAL Rp 50.000\n\n");
    printf("                             Rp "); scanf("%llu",&nominal);
    fflush(stdin);
    printf("\n\n                  1. BENAR\n\n                  2.KELUAR\n\n                  3.KEMBALI KE MENU");
    printf("\n\n\tPILIHAN : "); scanf("%c",&input);
    fflush(stdin);
    system("cls");
    switch (input)
    {
    case '1':
        if((nominal%50000 >= 0) && saldo >= nominal)
        {
            temp(&tmp, nominal);
            inputRekening();
        }
        else
        {
            printf("                  MAAF");
            cekSaldo();
        }
        break;
    case '2':
        keluar();
        break;
    default:
        menu();
        break;
    }
}

void inputRekening()
{
    int n;
    char input;
    unsigned long long int rekening;
    system("cls");
    printf("\n\n                    MASUKKAN NOMOR REKENING\n\n");
    printf("                         "); scanf("%llu",&rekening);
    fflush(stdin);
    printf("\n\n                  1. BENAR\n\n                  2. KELUAR\n\n                  3. KEMBALI KE MENU");
    printf("\n\n\tPILIHAN : "); 
	scanf("%c",&input);
	fflush (stdin);
    system("cls");
    switch (input)
    {
    case '1':
        if(rekening != rek)
        {
        	for (n=0;n<2;n++)
			{
            	if(rekening == rekA[n])
				{
            	konfirmasi();
        		}
            else 
				{
				transfer();
				}
			}
        }
        else
        {
            printf("                  MAAF");
            cekSaldo();
        }
    case '2':
        keluar();
    	break;
    default:
        menu();
    }
}

void konfirmasi()
{
    system("cls");
    int n;
    char input;
    for (n=0;n<2;n++)
	{
    if(strcmp(akunATM, akunA[n]) == 0)
        {
            printf("\n\n\t\tTUJUAN TRANSFER\n\n");
            printf("\t\tNAMA      : %s\n\n", akunA[n+1]);
            printf("\t\tREKENING  : %llu\n\n", rekA[n+1]);
        }
    if(strcmp(akunATM, akunA[n+1]) == 0)
        {
            printf("\t\tTUJUAN TRANSFER\n\n");
            printf("\t\tNAMA      : %s\n\n", akunA[n]);
            printf("\t\tREKENING  : %llu\n\n", rekA[n]);
        }
    printf("\n\n                  1. BENAR\n\n                  2. KELUAR\n\n                  3. KEMBALI KE MENU");
    printf("\n\n\tPILIHAN : "); 
	scanf("%c",&input);
	fflush (stdin);
    system("cls");
    switch (input)
	{
	case '1':
        if(strcmp(akunATM, akunA[n]) == 0)
        {
            saldo = saldo - tmp;
            saldoA[n+1] = saldoA[n+1] + tmp;
        }
        if(strcmp(akunATM, akunA[n+1]) == 0)
        {
            saldo = saldo - tmp;
            saldoA[n] = saldoA[n] + tmp;
        }
        break;
    case '2':
        keluar();
        break;
    default:
        menu();
        break;
    }
    printf("                          TRANSAKSI BERHASIL!");
    cekSaldo();
	}
}

#endif
