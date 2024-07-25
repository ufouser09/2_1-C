#include <stdio.h>
#include "kullanici_islemleri.h"
void writeAllUsersToFile(USER* allUsers[], int userCount, const char* filePath) {
    FILE* file = fopen(filePath, "wb");  // Dosyayı yazma modunda aç
    if (file == NULL) {
        perror("Dosya açılamadı");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        if (allUsers[i] != NULL) {
            fwrite(allUsers[i], sizeof(USER), 1, file);  // USER nesnesini dosyaya yaz
        }
        else {
            USER emptyUser = {0};  // Boş bir USER oluştur
            fwrite(&emptyUser, sizeof(USER), 1, file);  // Boş USER'ı dosyaya yaz
        }
    }

    fclose(file);  // Dosyayı kapat
}
void readUsersFromFile(const char* filePath, USER* allUsers[]) {
    FILE* file = fopen(filePath, "rb");  // Dosyayı okuma modunda aç
    if (file == NULL) {
        perror("Dosya açılamadı");
        return;
    }

    char loginName[LENGTH], loginSurname[LENGTH], loginNickName[LENGTH], loginPassword[LENGTH];

    // Dosyadan her bir kullanıcıyı oku
    while (fscanf(file, "%49s %49s %49s %49s", loginName, loginSurname, loginNickName, loginPassword) == 4) {
        // Okunan bilgileri kullanarak yeni kullanıcıyı kaydet
        if (!registerCourse(allUsers, loginName, loginSurname, loginNickName, loginPassword)) {
            fprintf(stderr, "Kullanıcı kaydedilemedi: %s\n", loginNickName);
        }
    }

    fclose(file);  // Dosyayı kapat
}