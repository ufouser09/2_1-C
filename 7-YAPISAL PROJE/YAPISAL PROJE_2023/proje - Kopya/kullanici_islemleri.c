#include "kullanici_islemleri.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "hash.h"
#define SIFRE_DOGRU 1
#define SIFRE_YANLIS 0
void printAllUsers(USER* allUsers[], int maxUsers) {
	int i;
    for ( i = 0; i < maxUsers; i++) {
        USER* currentUser = allUsers[i];
        while (currentUser != NULL) {
            printf("Kullanici %d:\n", i + 1);
            printf("  Adi: %s\n", currentUser->userName);
            printf("  Soyadi: %s\n", currentUser->userSurname);
            printf("  Kullanici adý: %s\n", currentUser->userNickName);
            // ÞÝFREYÝ YAZDIRMAK GUVENLIK AÇISINDAN UYUGUN OLMAYABÝLÝR
            // printf("  sifre: %s\n", currentUser->userPassword);
            currentUser = currentUser->nextUser;
        }
    }
}
void kullaniciEkle(USER** allUsers, USER* user, int hashDegeri) {
//	printf("kullanýcý ekleye girildi %s %s %s %s",loginName, loginSurname, loginPassword, loginNickName);
    // YENÝ KULLANICI ÝÇÝN HAFIZA AYIR

    if (allUsers[hashDegeri] == NULL) {
        // HASH DEGERÝNDE HÝÇ KULLANICI YOKSA, DOGRUDAN YENÝ KULLANICIYI EKLE 
        allUsers[hashDegeri] = user;
        user->nextUser = NULL;  // SONRAKÝ KULLANICI YOK
    } else {
        // EGER HASH DEGERÝNDE ZAten BÝR KULLANICI VARSA, YENÝ KULLANICIYI LÝSTENÝN BASINA EKLE
        user->nextUser = allUsers[hashDegeri];  // Yeni kullanï¿½cï¿½nï¿½n nextUser'ï¿½nï¿½ eski ilk kullanï¿½cï¿½ya baï¿½la
        allUsers[hashDegeri] = user;  // HASH TABLOSUNDAKÝ ÝLK KULLANICIYI YENÝ KULLANICI YAP
    }
}

bool kullaniciAdiMevcutMu(USER * allUsers[], char loginNickName[]){
	int hashDegeri = hash(loginNickName, MAX_USERS);
	bool isFind = false;
	// BULMAYA ÇALIÞICAZ
	if (allUsers[hashDegeri] != NULL){
		USER * tmpUser = allUsers[hashDegeri];
		while(tmpUser == NULL || !isFind){
			if(strcmp(tmpUser->userNickName,loginNickName) == 0)
				isFind = true;
			tmpUser = tmpUser->nextUser;
		}
	}
	return isFind;
}

bool kullaniciBilgileriKontrol(USER * allUsers[], char loginNickName[], char password[]){
	printf("-----: %s",loginNickName);
	int hashDegeri = hash(loginNickName, strlen(loginNickName));
	int isFind = 0;

	// BULMAYA ÇALIÞICAZ
	printf("HASH:%d",hashDegeri);
	if (allUsers[hashDegeri] != NULL){
		USER * tmpUser = allUsers[hashDegeri];
		while(tmpUser == NULL || isFind == 0){
			if(strcmp(tmpUser->userNickName,loginNickName) == 0){
				// þifre kontrolü
				if(strcmp(tmpUser->userPassword,password)){
					isFind = SIFRE_DOGRU;
				}else{
					isFind = SIFRE_YANLIS;
				}
			}
			tmpUser = tmpUser->nextUser;
		}
	}
	return isFind==SIFRE_DOGRU;
}

bool registerCourse(USER* allUsers[],char loginName[],char loginSurname[],char loginPassword[], char loginNickName[]){
	printf("-----: %s",loginNickName);
	int hashDegeri = hash(loginNickName, strlen(loginNickName));
	USER* newUser=(USER*)malloc(sizeof(USER*));
	strcpy(newUser->userName,loginName);
	strcpy(newUser->userSurname,loginSurname);
	strcpy(newUser->userNickName,loginNickName);
	strcpy(newUser->userPassword,loginPassword);
	
	kullaniciEkle(allUsers, newUser, hashDegeri);	
	return true;
}
