/*
logýn yapýcaz sonra harýtalar menusune gidicez hangi haritayla oynamak istedigimizi giricez
 oradan oynama menusune gidicez oynayan kiþilerin skorlarýný bi yerde kaydedicez
 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>//oyunu tam ekranda açmamýz için gereken fonksiyon
#include <conio.h>//getch'i kullanmamýzý saðlayan fonksiyon
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




	
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);//Oyun tam ekranda açýlmasý için fonksiyon
	system("COLOR F0");//Ekran ve yazý rengi için fonksiyon
	
	menu();
	
	
}
void menu(){
	int secim;
	
	system("CLS");//ekraný temizle
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
			printf("GECERSIZ SECIM LUTFEN BÝR DAHA DENEYINIZ!!!\n");
			printf("\t\tANA MENUYE DONMEK ICIN HERHANGI BIR TUSA BASINIZ... ");
			getch(); //Menüye dönmek için bir tuþa basmak için fonksiyon
			menu();
		break;
	}
	
}
void hakkinda(){
	system("CLS");
	printf("\n\n\n\n\n\t\t***HAKKINDA***\n\n");
	printf("\t\tBU OYUN YILDIZ TEKNIK UNIVERSITESI BILGISAYAR MUHENDISLIGI OGRENCISI EFE GIRGIN TARAFINDAN"
	"\n\t\tYAPISAL PROGRAMLAMA PROJE ODEVI OLARAK HAZIRLANMISTIR.\n\t\t\t\t\t\t\t\t\t\t\t\t\t©2023-2024\n\n\n");
	printf("\t\tKEYIFLI OYUNLAR DILERIM!\n");
	printf("\t\tANA MENUYE DONMEK ICIN HERHANGI BIR TUSA BASINIZ... ");
	getch(); //Menüye dönmek için bir tuþa basmak için fonksiyon
	menu();
}
void rules(){
	system("CLS");
	printf ("\n\n\n\n\n\t\t\t\t*** KURALLAR ***\n\n");
	printf ("\t\t1. Karþýt hidrojen üretebilmek için labirentin çýkýþýnda elinizde sadece P- ve e+ parçacýklarý bulunmalýdýr. .\n");
	printf ("\t\t2. Her turda oyuncular ok tuslarýyla labirentte ilerler.\n");
	printf ("\t\t3. belirli bir oyun süresi içinde çýkýsý bulamazsanýz oyun kendini sonlandýrýr.\n");
	printf ("\t\t4. duvarlardan gecemezsýnýz.\n");
	printf ("\t\t5.Kullanýcý kontrolü modunda kullanýcýnýn oyunu kendi istediði dört yöne giderek oynamasý saðlanmalýdýr .\n");
	printf ("\t\t6.Labirentte gezinmek için ok tuþlarý kullanýlacaktýr .\n");
	printf ("\t\t7. Karadelikler üzerine gelinirse oyun sonlanýr. .\n");
	printf ("\t\t8.Kullanýcý oyunda x ile gösterilmelidir .\n");
	printf ("\t\t9.Kullanýcýnýn her hamlesinde ekran temizlenerek kullanýcýnýn güncel lokasyonu x ile iþaretlenmelidir \n");
	printf ("\t\t10. Duvarlara ve matris dýþýna hamle yapýldýðýnda kullanýcýnýn yeri deðiþmez .\n\n\n");
	printf ("\t\t11.Kullanýcýya istediði zaman esc tuþuna basarak oyundan çýkma hakký tanýnmalýdýr  .\n\n\n");
	printf ("\t\t11. Her hamle ile elde edilmiþ atom altý parçacýklar ve labirentten çýkýldýðýnda kaç karþýt madde üretildiði ekrana yazýlmalýdýr  .\n\n\n");


	printf("\t\tAna Menuye donmek icin herhangi bir tusa basiniz... ");
	getch(); //Menüye dönmek için bir tuþa basmak için fonksiyon
		menu();
	
}
/*
void playGame(){
	int secim=0;
	printf("lutfen oyunu nasýl oynamak istediginizi giriniz:\n");
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
        if (kbhit()) {  // Klavyeden bir tuþa basýlýp basýlmadýðýný kontrol eder
            key = getch();  // Tuþ girdisini alýr

            if (key == 27) {  // ESC tuþu
                printf("ESC\n");
            } else if (key == 0 || key == 224) {  // Ok tuþlarý için özel durum
                key = getch();  // Ok tuþlarý için ikinci bir getch() çaðýrýlýr
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

        	system("cls");  // Ekraný temizle
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
    printf("Þu anki konum: (%d, %d), Deðeri: %d\n", x, y, labirent[x][y]);
}
*/
void kayit(){
	int i;
    const char * dosya_yolu = "kullanicilar.b";
    USER* allUsers[MAX_USERS];  // KULLANICILARI TUTUCAK DÝZÝYÝ TANIMLADIK,BASLAGICTA NULL
    for (i = 0; i < MAX_USERS; i++) {
        allUsers[i] = NULL;  // HER USER ÝCÝN BELLEK AYÝR
    }
    //BUTUN KULLANICILARI BÝR SEFRDE MÝ KAYDEDÝYORUZ VE BUNLARI KAYDETTÝKTEN SONRA KAYIT ÝÇÝN 
    //TEKRAR MI BÝR FONSÝYON YAZDIK DO WHÝLE ÝÇÝNDEKÝ FONKSÝYONDA KAYIT ALIYOR
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
    // Not: BU KISIMDA, ALLUSERS ICINDEKI HER BÝR KULLANICI ÝCÝN FREE KULLANMALISINIZ.
    // ÖRNEK BÝR TEMÝZLEME ÝSLEMÝ ASAGIDA VERÝLMÝSTÝR:

    for (i = 0; i < MAX_USERS; i++) {
        USER* current = allUsers[i];
        while (current != NULL) {
            USER* next = current->nextUser;
            free(current);
            current = next;
        }
    }
    //BU ASAGIDAKI FONKSÝYONU NÝYE YAZDIK FREE ETTÝKTEN SONRA 
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
//KULLANICI ADI TXT DOSYASINDA BULUNUYORSA KULLANICIDAN BU Bï¿½LGï¿½Yï¿½ TEKRAR AL

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




