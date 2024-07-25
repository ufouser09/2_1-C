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
            return 0; // Kullan�c� ad� zaten var
        }
    }

    User *newUser = (User *)malloc(sizeof(User));
    if (newUser == NULL) {
        return -1; // Bellek tahsis hatas�
    }

    strcpy(newUser->firstName, firstName);
    strcpy(newUser->lastName, lastName);
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);

    users[userCount++] = newUser;
    return 1; // Kullan�c� ba�ar�yla olu�turuldu
}

int checkLogin(char *username, char *password) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i]->username, username) == 0 && strcmp(users[i]->password, password) == 0) {
            return 1; // Giri� ba�ar�l�
        }
    }
    return 0; // Giri� ba�ar�s�z
}

void saveUsersToFile() {
    FILE *file = fopen("users.txt", "w");
    if (file == NULL) {
        perror("Dosya a��lamad�");
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
        return; // Dosya yoksa yeni olu�tur
    }

    char firstName[NAME_LEN], lastName[NAME_LEN], username[USERNAME_LEN], password[PASSWORD_LEN];
    while (fscanf(file, "%s %s %s %s\n", firstName, lastName, username, password) != EOF) {
        createUser(firstName, lastName, username, password);
    }

    fclose(file);
}

int main() {
    // Oyun ba�lang�c�
    loadUsersFromFile(); // Kullan�c�lar� dosyadan y�kle

    // Kullan�c� hesap olu�turma ve giri� yapma i�lemleri
    // ...

    // Oyun d�ng�s�
    // ...

    // Oyunun sonlanmas� ve kullan�c� bilgilerinin kaydedilmesi
    saveUsersToFile();

    // Belle�i temizle
    for (int i = 0; i < userCount; i++) {
        free(users[i]);
    }

    return 0;
}

