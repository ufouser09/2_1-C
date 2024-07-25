/*
log�n yap�caz sonra har�talar menusune gidicez hangi haritayla oynamak istedigimizi giricez
 oradan oynama menusune gidicez oynayan ki�ilerin skorlar�n� bi yerde kaydedicez
 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>//oyunu tam ekranda a�mam�z i�in gereken fonksiyon
#include <conio.h>//getch'i kullanmam�z� sa�layan fonksiyon
#include "kullanici_islemleri.h"
#include "dosya_islemleri.h"


void menu();
void rules();
void hakkinda();
//void playGame();
//void self_control();
//void oto_control();
bool kullanicidanBilgileriAl(USER * allUsers[]);
void kayit();


int main(){




	
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);//Oyun tam ekranda a��lmas� i�in fonksiyon
	system("COLOR F0");//Ekran ve yaz� rengi i�in fonksiyon
	
	menu();
	
	
}
void menu(){
	int secim;
	
	system("CLS");//ekran� temizle
	printf("1)-KAYIT OLUN\n");
	printf("2)-GIRIS YAP\n");
	printf("3)-KURALLAR\n");
	printf("4)-HAKKINDA\n");
	printf("5)-TOP PLAYERS' SCORES\n");
	//printf("6-)HARITALAR\n");
	//printf("7-)PLAY GAME");
	printf("8)-CIKIS\n");
	printf("lutfen seciminizi yapiniz(<1-5>)\n");
	scanf("%d",&secim);
	
	
	
	
	switch(secim){
		case 1:
			kayit();
			break;
		case 2:
		
		break;	
		
		case 3:rules();
		break;
		
		case 4:hakkinda();
		break;
		
		case 5:
			exit(0);
		break;
		
		case 6:
			break;
		case 7:
			//playGame();
		break;	
		case 8:
			exit(0);
			break;
		
		default:
			printf("GECERSIZ SECIM LUTFEN B�R DAHA DENEYINIZ!!!\n");
			printf("\t\tANA MENUYE DONMEK ICIN HERHANGI BIR TUSA BASINIZ... ");
			getch(); //Men�ye d�nmek i�in bir tu�a basmak i�in fonksiyon
			menu();
		break;
	}
	
}
void hakkinda(){
	system("CLS");
	printf("\n\n\n\n\n\t\t***HAKKINDA***\n\n");
	printf("\t\tBU OYUN YILDIZ TEKNIK UNIVERSITESI BILGISAYAR MUHENDISLIGI OGRENCISI EFE GIRGIN TARAFINDAN"
	"\n\t\tYAPISAL PROGRAMLAMA PROJE ODEVI OLARAK HAZIRLANMISTIR.\n\t\t\t\t\t\t\t\t\t\t\t\t\t�2023-2024\n\n\n");
	printf("\t\tKEYIFLI OYUNLAR DILERIM!\n");
	printf("\t\tANA MENUYE DONMEK ICIN HERHANGI BIR TUSA BASINIZ... ");
	getch(); //Men�ye d�nmek i�in bir tu�a basmak i�in fonksiyon
	menu();
}
void rules(){
	system("CLS");
	printf ("\n\n\n\n\n\t\t\t\t*** KURALLAR ***\n\n");
	printf ("\t\t1. Kar��t hidrojen �retebilmek i�in labirentin ��k���nda elinizde sadece P- ve e+ par�ac�klar� bulunmal�d�r. .\n");
	printf ("\t\t2. Her turda oyuncular ok tuslar�yla labirentte ilerler.\n");
	printf ("\t\t3. belirli bir oyun s�resi i�inde ��k�s� bulamazsan�z oyun kendini sonland�r�r.\n");
	printf ("\t\t4. duvarlardan gecemezs�n�z.\n");
	printf ("\t\t5.Kullan�c� kontrol� modunda kullan�c�n�n oyunu kendi istedi�i d�rt y�ne giderek oynamas� sa�lanmal�d�r .\n");
	printf ("\t\t6.Labirentte gezinmek i�in ok tu�lar� kullan�lacakt�r .\n");
	printf ("\t\t7. Karadelikler �zerine gelinirse oyun sonlan�r. .\n");
	printf ("\t\t8.Kullan�c� oyunda x ile g�sterilmelidir .\n");
	printf ("\t\t9.Kullan�c�n�n her hamlesinde ekran temizlenerek kullan�c�n�n g�ncel lokasyonu x ile i�aretlenmelidir \n");
	printf ("\t\t10. Duvarlara ve matris d���na hamle yap�ld���nda kullan�c�n�n yeri de�i�mez .\n\n\n");
	printf ("\t\t11.Kullan�c�ya istedi�i zaman esc tu�una basarak oyundan ��kma hakk� tan�nmal�d�r  .\n\n\n");
	printf ("\t\t11. Her hamle ile elde edilmi� atom alt� par�ac�klar ve labirentten ��k�ld���nda ka� kar��t madde �retildi�i ekrana yaz�lmal�d�r  .\n\n\n");


	printf("\t\tAna Menuye donmek icin herhangi bir tusa basiniz... ");
	getch(); //Men�ye d�nmek i�in bir tu�a basmak i�in fonksiyon
		menu();
	
}
/*
void playGame(){
	int secim=0;
	printf("lutfen oyunu nas�l oynamak istediginizi giriniz:\n");
	printf("1-)Oyunu kendim oynamak istiyorum\n");
	printf("2-)Oyunu bilgisayara oynatmak istiyorum\n");
	printf("lutfen seciminizi yapiniz<0-2>\n");
	scanf("%d",&secim);
	
	switch(secim){
		case 1:
			self_control();
			break;
			case 2:
				oto_control();
				break;
				default:
					printf("gecersiz secim yaptiniz lutfen bir daha giriniz\n");
					getch();
					playGame();
					break;
					
	}
	
    
	
}
/*
void self_control(){
	int x,y;
	printf("lutfen guncel konumu giriniz(X,Y)\n");
	scanf("%d %d",&x,&y);
	
	//printLabirent(x,y);
	int key;

    while (1) {
        if (kbhit()) {  // Klavyeden bir tu�a bas�l�p bas�lmad���n� kontrol eder
            key = getch();  // Tu� girdisini al�r

            if (key == 27) {  // ESC tu�u
                printf("ESC\n");
            } else if (key == 0 || key == 224) {  // Ok tu�lar� i�in �zel durum
                key = getch();  // Ok tu�lar� i�in ikinci bir getch() �a��r�l�r
                switch (key) {
                	
                    case 72: 
					printf("Up\n");
					if (x > 0){
						x--;
					} 
                        
                    break;
                    
					case 80: 
					printf("Down\n");
					if (x < ROW - 1){
						x++;
					} 
					break;
                    
					case 75: 
					printf("Left\n"); 
					if (y > 0){
						y--;
					} 

					break;
                    
					case 77: 
					printf("Right\n");
					if (y < COL - 1){
						y++;
					} 

					break;
                }
            }

        	system("cls");  // Ekran� temizle
        	printLabirent(x,y);
        }
    }

	
}
/*
void oto_control(){
	
}
/*
void printLabirent(){
	for ( i = 0; i < ROW; i++) {
        for ( j = 0; j < COL; j++) {
            if (i == x && j == y) {
                printf("______________");
				printf("|             |");
				printf("|    X  X     |");
				printf("|     XX      |",A[i][j]);
				printf("|    X  X     |");
				printf("|             |");
				printf("|_____________|");
            } else {
                printf("______________");
				printf("|             |");
				printf("|             |");
				printf("|     %c      |",A[i][j]);
				printf("|             |");
				printf("|             |");
				printf("|_____________|");
            }
        }
        printf("\n");
    }
    printf("�u anki konum: (%d, %d), De�eri: %d\n", x, y, labirent[x][y]);
}
*/
void kayit(){
	int i;
    const char * dosya_yolu = "kullanicilar.b";
    USER* allUsers[MAX_USERS];  // KULLANICILARI TUTUCAK D�Z�Y� TANIMLADIK,BASLAGICTA NULL
    for (i = 0; i < MAX_USERS; i++) {
        allUsers[i] = NULL;  // HER USER �C�N BELLEK AY�R
    }
    //BUTUN KULLANICILARI B�R SEFRDE M� KAYDED�YORUZ VE BUNLARI KAYDETT�KTEN SONRA KAYIT ���N 
    //TEKRAR MI B�R FONS�YON YAZDIK DO WH�LE ���NDEK� FONKS�YONDA KAYIT ALIYOR
    readUsersFromFile(dosya_yolu, allUsers);
    printAllUsers(allUsers, MAX_USERS);
    
        bool success = kullanicidanBilgileriAl(allUsers);
            if (success) {
            printf("Kullanici basariyla kaydedildi!\n");
            } else {
                printf("Kullanici kaydi basarisiz.\n");
            }
            printAllUsers(allUsers, MAX_USERS);
    

    // BELLEGIN ICINI TEMIZLE VE KAYNAKLARI SERBEST BIRAK
    // Not: BU KISIMDA, ALLUSERS ICINDEKI HER B�R KULLANICI �C�N FREE KULLANMALISINIZ.
    // �RNEK B�R TEM�ZLEME �SLEM� ASAGIDA VER�LM�ST�R:

    for (i = 0; i < MAX_USERS; i++) {
        USER* current = allUsers[i];
        while (current != NULL) {
            USER* next = current->nextUser;
            free(current);
            current = next;
        }
    }
    //BU ASAGIDAKI FONKS�YONU N�YE YAZDIK FREE ETT�KTEN SONRA 
    writeAllUsersToFile(allUsers, MAX_USERS, dosya_yolu);

   
}
bool kullanicidanBilgileriAl(USER * allUsers[]){
    char loginName[50];
	char loginSurname[50];
	char loginPassword[50];
	char loginNickName[50];
	
    printf("LUTFEN KULLANICI ADINI GIRINIZ:\n");
	scanf("%49s",loginNickName);
	
    if(kullaniciAdiMevcutMu(allUsers, loginNickName))
        return false;
    
	printf("\nLUTFEN KAYDOLMAK ICIN ASAGIDAKI YERLERI DOLDURUNUZ\n");

//*****************************************************************************
//KULLANICI ADI TXT DOSYASINDA BULUNUYORSA KULLANICIDAN BU B�LG�Y� TEKRAR AL

//*****************************************************************************
	printf("LUTFEN ADINIZI GIRINIZ\n");
	scanf("%s",loginName);
	printf("LUTFEN SOYADINIZI GIRINIZ\n");
	scanf("%s",loginSurname);
	printf("LUTFEN SIFRENIZI GIRINIZ:\n");
	scanf("%s",loginPassword);
    registerCourse(allUsers, loginName, loginSurname, loginPassword, loginNickName);
    return true;
}




