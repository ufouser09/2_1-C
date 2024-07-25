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
void hakkýnda();
int loginCourse();
void registerCourse();
void rules();
int main(){
	
	ShowWindow(GetConsoleWindow(), 3);//Oyun tam ekranda açýlmasý için fonksiyon
	system("COLOR F0");//Ekran ve yazý rengi için fonksiyon
	
	menu();
	
	
}

void userKopyala(USER *kaynakUser, USER *hedefUser) {
    // String alanlarý kopyala
    strcpy(hedefUser->userName, kaynakUser->userName);
    strcpy(hedefUser->userSurname, kaynakUser->userSurname);
    strcpy(hedefUser->userNickName, kaynakUser->userNickName);
    strcpy(hedefUser->userPassword, kaynakUser->userPassword);

    // Göstericiyi kopyala
    hedefUser->nextUser = kaynakUser->nextUser;
}

void kullaniciEkle(USER* allUsers, USER user, int hashDegeri) {
    // Yeni kullanýcý için hafýza ayýr
    USER* yeniUser = (USER*)malloc(sizeof(USER));
    if (yeniUser == NULL) {
        // Hafýza ayýrma baþarýsýz oldu
        return;
    }
    userKopyala(&user, yeniUser);  // Yeni kullanýcýya verileri kopyala

    if (allUsers[hashDegeri] == NULL) {
        // Hash deðerinde hiç kullanýcý yoksa, doðrudan yeni kullanýcýyý ekle
        allUsers[hashDegeri] = yeniUser;
        yeniUser->nextUser = NULL;  // Sonraki kullanýcý yok
    } else {
        // Eðer hash deðerinde zaten bir kullanýcý varsa, yeni kullanýcýyý listenin baþýna ekle
        yeniUser->nextUser = allUsers[hashDegeri];  // Yeni kullanýcýnýn nextUser'ýný eski ilk kullanýcýya baðla
        allUsers[hashDegeri] = yeniUser;  // Hash tablosundaki ilk kullanýcýyý yeni kullanýcý yap
    }
}


bool registerCourse(USER* allUsers){
	char loginName[50];
	char logýnSurname[50];
	char LoginPassword[50];
	char loginNickName[50];
	USER* users[MAX_USERS];
	FILE *fp;
	fp=fopen("users.txt","rb");
	
	
	printf("\nLUTFEN KAYDOLMAK ICIN ASAGIDAKI YERLERI DOLDURUNUZ\n");

//*****************************************************************************
//KULLANICI ADI TXT DOSYASINDA BULUNUYORSA KULLANICIDAN BU BÝLGÝYÝ TEKRAR AL

	
	
	printf("LUTFEN KULLANICI ADINI GIRINIZ:\n");
	scanf("%s",loginNickName);
	int hashDegeri = hash(loginNickName);
	// bulmaya çalýþcaz
	if (allUsers[hashDegeri] != NULL){
		USER * tmpUser = allUsers[hashDegeri];
		bool isFind = false;
		while(tmpUser == NULL or !isFind){
			if(strcmp(tmpUser->userNickName,loginNickName) == 0)
				isFind = true
			tmpUser = tmpUser->nextUser;
		}
		// bulundu mu kontrolü
		if(isFind){
			retrun false;
		}
	}

//*****************************************************************************
	printf("LUTFEN ADINIZI GIRINIZ\n");
	scanf("%s",logýnName);
	printf("LUTFEN SOYADINIZI GIRINIZ\n");
	scanf("%s",logýnSurname);
	printf("LUTFEN SIFRENIZI GIRINIZ:\n");
	scanf("%s",logýnPassword);


	USER newUser=(User)malloc(sizeof(User));
	strcpy(newUser.userName,logýnName);
	strcpy(newUser.userSurame,logýnSurname);
	strcpy(newUser.userName,logýnNýckName);
	strcpy(newUser.userPassword,logýnPassword);
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
		
		case 4:hakkýnda();
		break;
		
		case 5:
			exit(0);
		
		
		default:
			printf("GECERSIZ SECIM LUTFEN BÝR DAHA DENEYINIZ!!!\n");
			printf("\t\tANA MENUYE DONMEK ICIN HERHANGI BIR TUSA BASINIZ... ");
			getch(); //Menüye dönmek için bir tuþa basmak için fonksiyon
			menu();
	}
	
}
void hakkýnda(){
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


