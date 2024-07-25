#include "kullanici_islemleri.h"
#include <stddef.h>  // NULL i�in
#include <stdlib.h>  // NULL ve diziler standart fonksiyonlar i�in
#include <stdio.h>
#include "dosya_islemleri.h"
bool kullanicidanBilgileriAl(USER * allUsers[]);
int main() {
	int i;
    const char * dosya_yolu = "kullanicilar.b";
    USER* allUsers[MAX_USERS];  // Kullan�c�lar� tutacak dizi, ba�lang��ta NULL
    for (i = 0; i < MAX_USERS; i++) {
        allUsers[i] = NULL;  // USER için bellek ayır
    }
    readUsersFromFile(dosya_yolu, allUsers);
    printAllUsers(allUsers, MAX_USERS);
    do{
        bool success = kullanicidanBilgileriAl(allUsers);
            if (success) {
            printf("Kullanıcı başarıyla kaydedildi!\n");
            } else {
                printf("Kullanıcı kaydı başarısız.\n");
            }
            printAllUsers(allUsers, MAX_USERS);
    }while(true);

    // Belle�i temizle ve kaynaklar� serbest b�rak
    // Not: Bu k�s�mda, allUsers i�indeki her bir kullan�c� i�in free kullanmal�s�n�z.
    // �rnek bir temizleme i�lemi a�a��da verilmi�tir:

    for (i = 0; i < MAX_USERS; i++) {
        USER* current = allUsers[i];
        while (current != NULL) {
            USER* next = current->nextUser;
            free(current);
            current = next;
        }
    }
    writeAllUsersToFile(allUsers, MAX_USERS, dosya_yolu);

    return 0;
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
