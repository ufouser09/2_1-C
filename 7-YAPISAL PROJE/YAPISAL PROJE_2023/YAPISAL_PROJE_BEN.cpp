#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "hash.h"
#define MAX 50
#define LENGTH 50
#define MAX_USERS 101
typedef struct user{
	char userName[LENGTH];
	char userSurname[LENGTH];
	char userNickName[LENGTH];
	char userPassword[LENGTH];
	user* nextUser = NULL;
}USER;

void menu();
void hakk�nda();
int loginCourse();
void registerCourse();
void rules();
int main(){
	
	ShowWindow(GetConsoleWindow(), 3);//Oyun tam ekranda a��lmas� i�in fonksiyon
	system("COLOR F0");//Ekran ve yaz� rengi i�in fonksiyon
	
	menu();
	
	
}

void userKopyala(USER *kaynakUser, USER *hedefUser) {
    // String alanlar� kopyala
    strcpy(hedefUser->userName, kaynakUser->userName);
    strcpy(hedefUser->userSurname, kaynakUser->userSurname);
    strcpy(hedefUser->userNickName, kaynakUser->userNickName);
    strcpy(hedefUser->userPassword, kaynakUser->userPassword);

    // G�stericiyi kopyala
    hedefUser->nextUser = kaynakUser->nextUser;
}

void kullaniciEkle(USER* allUsers, USER user, int hashDegeri) {
    // Yeni kullan�c� i�in haf�za ay�r
    USER* yeniUser = (USER*)malloc(sizeof(USER));
    if (yeniUser == NULL) {
        // Haf�za ay�rma ba�ar�s�z oldu
        return;
    }
    userKopyala(&user, yeniUser);  // Yeni kullan�c�ya verileri kopyala

    if (allUsers[hashDegeri] == NULL) {
        // Hash de�erinde hi� kullan�c� yoksa, do�rudan yeni kullan�c�y� ekle
        allUsers[hashDegeri] = yeniUser;
        yeniUser->nextUser = NULL;  // Sonraki kullan�c� yok
    } else {
        // E�er hash de�erinde zaten bir kullan�c� varsa, yeni kullan�c�y� listenin ba��na ekle
        yeniUser->nextUser = allUsers[hashDegeri];  // Yeni kullan�c�n�n nextUser'�n� eski ilk kullan�c�ya ba�la
        allUsers[hashDegeri] = yeniUser;  // Hash tablosundaki ilk kullan�c�y� yeni kullan�c� yap
    }
}


bool registerCourse(USER* allUsers){
	char loginName[50];
	char log�nSurname[50];
	char LoginPassword[50];
	char loginNickName[50];
	USER* users[MAX_USERS];
	FILE *fp;
	fp=fopen("users.txt","rb");
	
	
	printf("\nLUTFEN KAYDOLMAK ICIN ASAGIDAKI YERLERI DOLDURUNUZ\n");

//*****************************************************************************
//KULLANICI ADI TXT DOSYASINDA BULUNUYORSA KULLANICIDAN BU B�LG�Y� TEKRAR AL

	
	
	printf("LUTFEN KULLANICI ADINI GIRINIZ:\n");
	scanf("%s",loginNickName);
	int hashDegeri = hash(loginNickName);
	// bulmaya �al��caz
	if (allUsers[hashDegeri] != NULL){
		USER * tmpUser = allUsers[hashDegeri];
		bool isFind = false;
		while(tmpUser == NULL or !isFind){
			if(strcmp(tmpUser->userNickName,loginNickName) == 0)
				isFind = true
			tmpUser = tmpUser->nextUser;
		}
		// bulundu mu kontrol�
		if(isFind){
			retrun false;
		}
	}

//*****************************************************************************
	printf("LUTFEN ADINIZI GIRINIZ\n");
	scanf("%s",log�nName);
	printf("LUTFEN SOYADINIZI GIRINIZ\n");
	scanf("%s",log�nSurname);
	printf("LUTFEN SIFRENIZI GIRINIZ:\n");
	scanf("%s",log�nPassword);


	USER newUser=(User)malloc(sizeof(User));
	strcpy(newUser.userName,log�nName);
	strcpy(newUser.userSurame,log�nSurname);
	strcpy(newUser.userName,log�nN�ckName);
	strcpy(newUser.userPassword,log�nPassword);
	kullaniciEkle(allUsers, newUser, hashDegeri);	
	
}
int LoginCourse(){
	FILE *fp;
	int found1=0;
	int found2=0;
	char loginNickName[50];
	char loginPassword[50];
	
	fp=fopen("user.txt",rb);
	if(fp==NULL){
		printf("DOSYA ACILIRKEN HATA OLUSTU!!!\n");
		return -1;
	}
	
	
	printf("LUTFEN KULLANICI ADINI GIRINIZ\n");
	scanf("%s",loginNickName);
	printf("LUTFEN SIFRENIZI GIRINIZ\n");
	scanf("%s",loginPassword);
	
	
	
		fread(&users,sizeof(USER),1,fp);
		
		while(!(feof)&&((!found1)||(!found2))){
			if(strcmp(users[i].userNickName,loginNickName)==0){
				found1=1;
				
				if(strcmp(users[i].userPassword,loginPassword)==0){
					found2=1;
				}
			}
		}
		if(found1==1 && found2==1){
			printf("KULLANICI ADI VE SIFRE DOGRU\n");
			printf("SIMDI OYUNA BASLAYABILIRSINIZ\n");
			oyunaBasla(userNickName,userPassword);
		}
		else{
			printf("")
		}
	
	
	
	fclose(fp);
}

vodi menu(){
	int secim;
	
	printf("1)-KAYIT OLUN\n");
	printf("2)-GIRIS YAP\n");
	printf("3)-KURALLAR\n");
	printf("4)-HAKKINDA\n");
	printf("5)-TOP SCORES");
	printf("6)-CIKIS\n");
	printf("lutfen seciminizi yapiniz(<1-5>)\n");
	scanf("%d",&secim);
	
	
	
	
	switch(secim){
		case 1:
			registerUser();
			break;
		case 2:
		if(loginUser()){
			printf("GIRIS BASARILI.\n");
			
		}else{
			printf("GIRIS BASARISIZ.KULLANICI ADI VEYA SIFRE YANLIS\n");
		}
		break;	
		
		case 3:rules();
		break;
		
		case 4:hakk�nda();
		break;
		
		case 5:
			exit(0);
		
		
		default:
			printf("GECERSIZ SECIM LUTFEN B�R DAHA DENEYINIZ!!!\n");
			printf("\t\tANA MENUYE DONMEK ICIN HERHANGI BIR TUSA BASINIZ... ");
			getch(); //Men�ye d�nmek i�in bir tu�a basmak i�in fonksiyon
			menu();
	}
	
}
void hakk�nda(){
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


