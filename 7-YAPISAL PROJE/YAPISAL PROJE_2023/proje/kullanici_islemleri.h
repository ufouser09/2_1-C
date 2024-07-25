#ifndef KULLANICI_ISLEMLERI_H
#define KULLANICI_ISLEMLERI_H
#include <stddef.h>  // NULL i�in
#include <stdlib.h>  // NULL ve di�er standart fonksiyonlar i�in
#include <stdbool.h>
#define MAX 50
#define LENGTH 50
#define MAX_USERS 101
typedef struct user USER;  // USER tipini �nceden bildir
void printAllUsers(USER* allUsers[], int maxUsers);
struct user {
    char userName[LENGTH];
    char userSurname[LENGTH];
    char userNickName[LENGTH];
    char userPassword[LENGTH];
    USER* nextUser;  // Varsay�lan de�er atayamazs�n�z, bunu yap�n�n bir �rne�ini olu�tururken yapmal�s�n�z
};
bool kullaniciAdiMevcutMu(USER * allUsers[], char loginNickName[]);
bool registerCourse(USER* allUsers[],char loginName[],char loginSurname[],char loginPassword[], char loginNickName[]);
#endif
