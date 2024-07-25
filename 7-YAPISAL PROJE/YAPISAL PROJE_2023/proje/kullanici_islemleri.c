#include "kullanici_islemleri.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "hash.h"
void printAllUsers(USER* allUsers[], int maxUsers) {
    for (int i = 0; i < maxUsers; i++) {
        USER* currentUser = allUsers[i];
        while (currentUser != NULL) {
            printf("Kullanıcı %d:\n", i + 1);
            printf("  Adı: %s\n", currentUser->userName);
            printf("  Soyadı: %s\n", currentUser->userSurname);
            printf("  Kullanıcı Adı: %s\n", currentUser->userNickName);
            // Şifreyi yazdırmak güvenlik açısından uygun olmayabilir
            // printf("  Şifre: %s\n", currentUser->userPassword);
            currentUser = currentUser->nextUser;
        }
    }
}
void kullaniciEkle(USER** allUsers, USER* user, int hashDegeri) {
    // Yeni kullan�c� i�in haf�za ay�r
    USER* yeniUser = (USER*)malloc(sizeof(USER));
    if (yeniUser == NULL) {
        // Haf�za ay�rma ba�ar�s�z oldu
        return;
    }

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

bool kullaniciAdiMevcutMu(USER * allUsers[], char loginNickName[]){
	int hashDegeri = hash(loginNickName, MAX_USERS);
	bool isFind = false;
	// bulmaya �al��caz
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

bool registerCourse(USER* allUsers[],char loginName[],char loginSurname[],char loginPassword[], char loginNickName[]){
	int hashDegeri = hash(loginNickName, MAX_USERS);
	USER* newUser=(USER*)malloc(sizeof(USER*));
	strcpy(newUser->userName,loginName);
	strcpy(newUser->userSurname,loginSurname);
	strcpy(newUser->userName,loginNickName);
	strcpy(newUser->userPassword,loginPassword);
	kullaniciEkle(allUsers, newUser, hashDegeri);	
	return true;
}
