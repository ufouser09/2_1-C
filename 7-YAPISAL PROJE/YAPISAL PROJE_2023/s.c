#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define USERNAME_LEN 50
#define PASSWORD_LEN 50
#define NAME_LEN 50

typedef struct {
    char firstName[NAME_LEN];
    char lastName[NAME_LEN];
    char username[USERNAME_LEN];
    char password[PASSWORD_LEN];
} User;

User* users[MAX_USERS];
int userCount = 0;

int createUser(char *firstName, char *lastName, char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i]->username, username) == 0) {
            return 0; // Kullanýcý adý zaten var
        }
    }

    User *newUser = (User *)malloc(sizeof(User));
    if (newUser == NULL) {
        return -1; // Bellek tahsis hatasý
    }

    strcpy(newUser->firstName, firstName);
    strcpy(newUser->lastName, lastName);
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);

    users[userCount++] = newUser;
    return 1; // Kullanýcý baþarýyla oluþturuldu
}

int checkLogin(char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i]->username, username) == 0 && strcmp(users[i]->password, password) == 0) {
            return 1; // Giriþ baþarýlý
        }
    }
    return 0; // Giriþ baþarýsýz
}

void saveUsersToFile() {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        perror("Dosya açýlamadý");
        return;
    }

    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s %s %s %s\n", users[i]->firstName, users[i]->lastName, users[i]->username, users[i]->password);
    }

    fclose(file);
}

void loadUsersFromFile() {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        return; // Dosya yoksa yeni oluþtur
    }

    char firstName[NAME_LEN], lastName[NAME_LEN], username[USERNAME_LEN], password[PASSWORD_LEN];
    while (fscanf(file, "%s %s %s %s\n", firstName, lastName, username, password) != EOF) {
        createUser(firstName, lastName, username, password);
    }

    fclose(file);
}

int main() {
    // Oyun baþlangýcý
    loadUsersFromFile(); // Kullanýcýlarý dosyadan yükle

    // Kullanýcý hesap oluþturma ve giriþ yapma iþlemleri
    // ...

    // Oyun döngüsü
    // ...

    // Oyunun sonlanmasý ve kullanýcý bilgilerinin kaydedilmesi
    saveUsersToFile();

    // Belleði temizle
    for (int i = 0; i < userCount; i++) {
        free(users[i]);
    }

    return 0;
}

