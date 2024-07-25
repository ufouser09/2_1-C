#ifndef DOSYA_ISLEMLERI_H
#define DOSYA_ISLEMLERI_H
#include "kullanici_islemleri.h"
void readUsersFromFile(const char* filePath, USER* allUsers[]);
void writeAllUsersToFile(USER* allUsers[], int userCount, const char* filePath);
#endif