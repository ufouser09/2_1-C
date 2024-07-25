#include <stdio.h>
#include <stddef.h>  // NULL icin
#include <stdlib.h>  // NULL ve diger standart fonksiyonlar icin
#include "kullanici_islemleri.h"
#include "dosya_islemleri.h"
bool kullanicidanBilgileriAl(USER * allUsers[]);
int main() {
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
    do{
        bool success = kullanicidanBilgileriAl(allUsers);
            if (success) {
            printf("Kullanici basariyla kaydedildi!\n");
            } else {
                printf("Kullanici kaydi basarisiz.\n");
            }
            printAllUsers(allUsers, MAX_USERS);
    }while(true);

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
