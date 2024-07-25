#include <stdio.h>
#include "kullanici_islemleri.h"
void writeAllUsersToFile(USER* allUsers[], int userCount, const char* filePath) {
	int i;
	USER *user;
    FILE* file = fopen(filePath, "w");  // DOSYAYI YAZMA MODUNDA AÇ
    if (file == NULL) {
        perror("Dosya acilamadi");
        return;
    }

    for ( i = 0; i < userCount; i++) {
        if (allUsers[i] != NULL) {
        	user = allUsers[i];
            fprintf(file,"%s %s %s %s\n", user->userName, user->userSurname, user->userNickName, user->userPassword);
			//fwrite(allUsers[i], sizeof(USER), 1, file);  // USER NESNESÝNÝ DOSYAYA YAZ
        }
        else {
            USER emptyUser = {0};  // BOÞ BÝR USER OLUSTUR
            fwrite(&emptyUser, sizeof(USER), 1, file);  // BOS BÝR USER'I DOSYAYA YAZ
        }
    }

    fclose(file);  // DOSYAYI KAPAT
}
void readUsersFromFile(const char* filePath, USER* allUsers[]) {
    FILE* file = fopen(filePath, "r");  // DOSYAYI OKUMA MODUNDA AÇ
    if (file == NULL) {
        perror("Dosya acilamadi\n");
        return;
    }

    char loginName[LENGTH], loginSurname[LENGTH], loginNickName[LENGTH], loginPassword[LENGTH];

    // DOSYADAN HER BÝR KULLANICIYI OKU
    while (fscanf(file, "%s %s %s %s\n", loginName, loginSurname, loginNickName, loginPassword) == 4) {
        // OKUNAN BÝLGÝLERÝ KULLANARAK YENÝ KULLANICIYI KAYDET
        printf("okunan: %s %s",loginName,loginPassword);
        if (!registerCourse(allUsers, loginName, loginSurname, loginNickName, loginPassword)) {
            fprintf(stderr, "Kullanici kaydedilemedi: %s\n", loginNickName);
        }
        printf("\n!\n");
    }

    fclose(file);  // DOSYAYI KAPAT
}
