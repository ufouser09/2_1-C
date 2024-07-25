

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>//oyunu tam ekranda a�mam�z i�in gereken fonksiyon
#include <conio.h>//getch'i kullanmam�z� sa�layan fonksiyon

#include <stddef.h>  // NULL ICIN
#include <stdbool.h>
#define SIFRE_DOGRU 1
#define SIFRE_YANLIS 0
#define MAX 50
#define LENGTH 50
#define MAX_USERS 101
typedef struct user USER;
 struct user {
    char userName[LENGTH];
    char userSurname[LENGTH];
    char userNickName[LENGTH];
    char userPassword[LENGTH];
    USER* nextUser;  // Varsay�lan de�er atayamazs�n�z, bunu yap�n�n bir �rne�ini olu�tururken yapmal�s�n�z
};

void matrisiDosyayaKaydet(char* dosyaAdi, char*** matris, int satir, int sutun);
char*** kullaniciMatrisiOlustur(int *satir, int *sutun);
char*** matrisOkuVeDonustur(char* dosyaAdi, int *satir, int *sutun);
void sembollerinAnlamlariniGoster();
int sembolSayiDonustur(char* sembol);
char* sayiSembolDonustur(int sayi);
//void playGame();



void menu();
void rules();
void hakkinda();
void kayit();
bool kullanicidanBilgileriAl(USER * allUsers[]);
void login();
int haritalar();
void writeAllUsersToFile(USER* allUsers[], int userCount, const char* filePath);
void readUsersFromFile(const char* filePath, USER* allUsers[]);

int hash(char *str, int length);
void printAllUsers(USER* allUsers[], int maxUsers);
void kullaniciEkle(USER** allUsers, USER* user, int hashDegeri); 
bool kullaniciAdiMevcutMu(USER * allUsers[], char loginNickName[]);
bool kullaniciBilgileriKontrol(USER * allUsers[], char loginNickName[], char password[]);
bool registerCourse(USER* allUsers[],char loginName[],char loginSurname[],char loginPassword[], char loginNickName[]);
 


int main(){




	
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);//Oyun tam ekranda a��lmas� i�in fonksiyon
	system("COLOR F0");//Ekran ve yaz� rengi i�in fonksiyon
	
	menu();
	
	
}
void menu(){
	int secim;
	
	system("CLS");//ekran� temizle
	printf("1)-KAYIT OLUN\n");
	printf("2)-GIRIS YAP\n");
	printf("3)-KURALLAR\n");
	printf("4)-HAKKINDA\n");
	printf("5)-TOP PLAYERS' SCORES\n");
	printf("6-)HARITALAR\n");
	printf("7-)PLAY GAME");
	printf("8)-CIKIS\n");
	printf("lutfen seciminizi yapiniz(<1-5>)\n");
	scanf("%d",&secim);
	
	
	
	
	switch(secim){
		case 1:
			kayit();
			break;
		case 2:
		 login();
		break;	
		
		case 3:
		rules();
		break;
		
		case 4:
		hakkinda();
		break;
		
		case 5:
			
		break;
		
		case 6:
			haritalar();
			break;
		case 7:
		//	playGame();
		break;	
		
		case 8:
			exit(0);
			break;
		
		default:
			printf("GECERSIZ SECIM LUTFEN B�R DAHA DENEYINIZ!!!\n");
			printf("\t\tANA MENUYE DONMEK ICIN HERHANGI BIR TUSA BASINIZ... ");
			getch(); //Men�ye d�nmek i�in bir tu�a basmak i�in fonksiyon
			menu();
		break;
	}
	
}
void hakkinda(){
	system("CLS");
	printf("\n\n\n\n\n\t\t***HAKKINDA***\n\n");
	printf("\t\tBU OYUN YILDIZ TEKNIK UNIVERSITESI BILGISAYAR MUHENDISLIGI OGRENCISI EFE GIRGIN TARAFINDAN"
	"\n\t\tYAPISAL PROGRAMLAMA PROJE ODEVI OLARAK HAZIRLANMISTIR.\n\t\t\t\t\t\t\t\t\t\t\t\t\t�2023-2024\n\n\n");
	printf("\t\tKEYIFLI OYUNLAR DILERIM!\n");
	printf("\t\tANA MENUYE DONMEK ICIN HERHANGI BIR TUSA BASINIZ... ");
	getch(); //Men�ye d�nmek i�in bir tu�a basmak i�in fonksiyon
	menu();
}
void rules(){
	system("CLS");
	printf ("\n\n\n\n\n\t\t\t\t*** KURALLAR ***\n\n");
	printf ("\t\t1. Kar��t hidrojen �retebilmek i�in labirentin ��k���nda elinizde sadece P- ve e+ par�ac�klar� bulunmal�d�r. .\n");
	printf ("\t\t2. Her turda oyuncular ok tuslar�yla labirentte ilerler.\n");
	printf ("\t\t3. belirli bir oyun s�resi i�inde ��k�s� bulamazsan�z oyun kendini sonland�r�r.\n");
	printf ("\t\t4. duvarlardan gecemezs�n�z.\n");
	printf ("\t\t5.Kullan�c� kontrol� modunda kullan�c�n�n oyunu kendi istedi�i d�rt y�ne giderek oynamas� sa�lanmal�d�r .\n");
	printf ("\t\t6.Labirentte gezinmek i�in ok tu�lar� kullan�lacakt�r .\n");
	printf ("\t\t7. Karadelikler �zerine gelinirse oyun sonlan�r. .\n");
	printf ("\t\t8.Kullan�c� oyunda x ile g�sterilmelidir .\n");
	printf ("\t\t9.Kullan�c�n�n her hamlesinde ekran temizlenerek kullan�c�n�n g�ncel lokasyonu x ile i�aretlenmelidir \n");
	printf ("\t\t10. Duvarlara ve matris d���na hamle yap�ld���nda kullan�c�n�n yeri de�i�mez .\n\n\n");
	printf ("\t\t11.Kullan�c�ya istedi�i zaman esc tu�una basarak oyundan ��kma hakk� tan�nmal�d�r  .\n\n\n");
	printf ("\t\t11. Her hamle ile elde edilmi� atom alt� par�ac�klar ve labirentten ��k�ld���nda ka� kar��t madde �retildi�i ekrana yaz�lmal�d�r  .\n\n\n");


	printf("\t\tAna Menuye donmek icin herhangi bir tusa basiniz... ");
	getch(); //Men�ye d�nmek i�in bir tu�a basmak i�in fonksiyon
		menu();
	
}
void kayit(){
	int i;
    const char * dosya_yolu = "kullanicilar.txt";
    USER* allUsers[MAX_USERS];  // KULLANICILARI TUTUCAK D�Z�Y� TANIMLADIK,BASLAGICTA NULL
    for (i = 0; i < MAX_USERS; i++) {
        allUsers[i] = NULL;  // HER USER �C�N BELLEK AY�R
    }
    //BUTUN KULLANICILARI B�R SEFRDE M� KAYDED�YORUZ VE BUNLARI KAYDETT�KTEN SONRA KAYIT ���N 
    //TEKRAR MI B�R FONS�YON YAZDIK DO WH�LE ���NDEK� FONKS�YONDA KAYIT ALIYOR
    readUsersFromFile(dosya_yolu, allUsers);
    printf("readen");
    printAllUsers(allUsers, MAX_USERS);
    
        bool success = kullanicidanBilgileriAl(allUsers);
            if (success) {
            printf("Kullanici basariyla kaydedildi!\n");
            writeAllUsersToFile(allUsers, MAX_USERS, dosya_yolu);
            } else {
                printf("Kullanici kaydi basarisiz.\n");
            }
            printAllUsers(allUsers, MAX_USERS);
    

    // BELLEGIN ICINI TEMIZLE VE KAYNAKLARI SERBEST BIRAK
    // Not: BU KISIMDA, ALLUSERS ICINDEKI HER B�R KULLANICI �C�N FREE KULLANMALISINIZ.
    // �RNEK B�R TEM�ZLEME �SLEM� ASAGIDA VER�LM�ST�R:

    for (i = 0; i < MAX_USERS; i++) {
        USER* current = allUsers[i];
        while (current != NULL) {
            USER* next = current->nextUser;
            free(current);
            current = next;
        }
    }
    //BU ASAGIDAKI FONKS�YONU N�YE YAZDIK FREE ETT�KTEN SONRA 
    //writeAllUsersToFile(allUsers, MAX_USERS, dosya_yolu);

   
}
bool kullanicidanBilgileriAl(USER * allUsers[]){
    char loginName[50];
	char loginSurname[50];
	char loginPassword[50];
	char loginNickName[50];
	
    printf("LUTFEN KULLANICI ADINI GIRINIZ:\n");
	scanf("%s",loginNickName);
	
    if(kullaniciAdiMevcutMu(allUsers, loginNickName))
        return false;
    
	//printf("\nLUTFEN KAYDOLMAK ICIN ASAGIDAKI YERLERI DOLDURUNUZ\n");

//*****************************************************************************
//KULLANICI ADI TXT DOSYASINDA BULUNUYORSA KULLANICIDAN BU B�LG�Y� TEKRAR AL

//*****************************************************************************
	printf("LUTFEN ADINIZI GIRINIZ\n");
	scanf("%s",loginName);
	printf("LUTFEN SOYADINIZI GIRINIZ\n");
	scanf("%s",loginSurname);
	printf("LUTFEN SIFRENIZI GIRINIZ:\n");
	scanf("%s",loginPassword);
	
	printf("%s %s %s %s",loginName, loginSurname, loginPassword, loginNickName);
    registerCourse(allUsers, loginName, loginSurname, loginPassword, loginNickName);
    
    return true;
}
void login(){
	int i;
	char loginPassword[50];
	char loginNickName[50];
	
	printf("KULLANICI ADI :");
	scanf("%s",loginNickName);
	printf("\nSIFRE : ");
	scanf("%s",loginPassword);
	
	const char * dosya_yolu = "kullanicilar.txt";
    USER* allUsers[MAX_USERS];  // KULLANICILARI TUTUCAK D�Z�Y� TANIMLADIK,BASLAGICTA NULL
    for (i = 0; i < MAX_USERS; i++) {
        allUsers[i] = NULL;  // HER USER �C�N BELLEK AY�R
    }
	    readUsersFromFile(dosya_yolu, allUsers);

	if(kullaniciBilgileriKontrol(allUsers,loginNickName,loginPassword)==1){
		printf("BASARIYLA GIRIS YAPTINIZ!!\n");
	}
	else{
		printf("KULLANICI ADI VEYA SIFRE YANLIS\n");
	}
	
}
void writeAllUsersToFile(USER* allUsers[], int userCount, const char* filePath) {
	int i;
	USER *user;
    FILE* file = fopen(filePath, "w");  // DOSYAYI YAZMA MODUNDA A�
    if (file == NULL) {
        perror("Dosya acilamadi");
        return;
    }

    for ( i = 0; i < userCount; i++) {
        if (allUsers[i] != NULL) {
        	user = allUsers[i];
            fprintf(file,"%s %s %s %s", user->userName, user->userSurname, user->userNickName, user->userPassword);
			//fwrite(allUsers[i], sizeof(USER), 1, file);  // USER NESNES�N� DOSYAYA YAZ
        }
        else {
            USER emptyUser = {0};  // BO� B�R USER OLUSTUR
            fwrite(&emptyUser, sizeof(USER), 1, file);  // BOS B�R USER'I DOSYAYA YAZ
        }
    }

    fclose(file);  // DOSYAYI KAPAT
}

void readUsersFromFile(const char* filePath, USER* allUsers[]) {
    FILE* file = fopen(filePath, "r");  // DOSYAYI OKUMA MODUNDA A�
    if (file == NULL) {
        perror("Dosya acilamadi\n");
        return;
    }

    char loginName[LENGTH], loginSurname[LENGTH], loginNickName[LENGTH], loginPassword[LENGTH];

    // DOSYADAN HER B�R KULLANICIYI OKU
    while (fscanf(file, "%s %s %s %s", loginName, loginSurname, loginNickName, loginPassword) == 4) {
    	 printf("okunan: %s %s",loginName,loginPassword);
        // OKUNAN B�LG�LER� KULLANARAK YEN� KULLANICIYI KAYDET
        if (!registerCourse(allUsers, loginName, loginSurname, loginNickName, loginPassword)) {
            fprintf(stderr, "Kullanici kaydedilemedi: %s\n", loginNickName);
        }
        printf("\n!\n");
    }

    fclose(file);  // DOSYAYI KAPAT
}

int hash(char *str, int length) {
    int hash = 5381;
    printf("nick: %s",str);
    int c;

    while (c = *str++) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % length;
}
void printAllUsers(USER* allUsers[], int maxUsers) {
	int i;
    for ( i = 0; i < maxUsers; i++) {
        USER* currentUser = allUsers[i];
        while (currentUser != NULL) {
            printf("Kullanici %d:\n", i + 1);
            printf("  Adi: %s\n", currentUser->userName);
            printf("  Soyadi: %s\n", currentUser->userSurname);
            printf("  Kullanici ad�: %s\n", currentUser->userNickName);
            // ��FREY� YAZDIRMAK GUVENLIK A�ISINDAN UYUGUN OLMAYAB�L�R
            // printf("  sifre: %s\n", currentUser->userPassword);
            currentUser = currentUser->nextUser;
        }
    }
}
void kullaniciEkle(USER** allUsers, USER* user, int hashDegeri) {
//	printf("kullan�c� ekleye girildi %s %s %s %s",loginName, loginSurname, loginPassword, loginNickName);
    // YEN� KULLANICI ���N HAFIZA AYIR
	printf("\nkullaci ekle\n");
    if (allUsers[hashDegeri] == NULL) {
        // HASH DEGER�NDE H�� KULLANICI YOKSA, DOGRUDAN YEN� KULLANICIYI EKLE 
        allUsers[hashDegeri] = user;
        printf("%s",user->userName);
        user->nextUser = NULL;  // SONRAK� KULLANICI YOK
        printf("\nnull");
    } else {
        // EGER HASH DEGER�NDE ZAten B�R KULLANICI VARSA, YEN� KULLANICIYI L�STEN�N BASINA EKLE
        user->nextUser = allUsers[hashDegeri];  // Yeni kullan�c�n�n nextUser'�n� eski ilk kullan�c�ya ba�la
        allUsers[hashDegeri] = user;  // HASH TABLOSUNDAK� �LK KULLANICIYI YEN� KULLANICI YAP
    }
}

bool kullaniciAdiMevcutMu(USER * allUsers[], char loginNickName[]){
	int hashDegeri = hash(loginNickName, MAX_USERS);
	bool isFind = false;
	// BULMAYA �ALI�ICAZ
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

	// BULMAYA �ALI�ICAZ
	printf("HASH:%d",hashDegeri);
	if (allUsers[hashDegeri] != NULL){
		USER * tmpUser = allUsers[hashDegeri];
		while(tmpUser == NULL || isFind == 0){
			if(strcmp(tmpUser->userNickName,loginNickName) == 0){
				// �ifre kontrol�
				if(strcmp(tmpUser->userPassword,password)){
					isFind = SIFRE_DOGRU;
				}else{
					isFind = SIFRE_YANLIS;
				}
			}
			tmpUser = tmpUser->nextUser;
		}
	}
	return isFind;
}

bool registerCourse(USER* allUsers[],char loginName[],char loginSurname[],char loginNickName[], char loginPassword[]){
	printf("--reg--: %s",loginNickName);
	int hashDegeri = hash(loginNickName, strlen(loginNickName));
	USER* newUser=(USER*)malloc(sizeof(USER*));
	strcpy(newUser->userName,loginName);
	strcpy(newUser->userSurname,loginSurname);
	strcpy(newUser->userNickName,loginNickName);
	strcpy(newUser->userPassword,loginPassword);
	
	kullaniciEkle(allUsers, newUser, hashDegeri);	
	return true;
}

int haritalar(){
		int satir, sutun;
    char*** matris = kullaniciMatrisiOlustur(&satir, &sutun);

    if(matris == NULL) {
        fprintf(stderr, "Matris olu�turulamad�.\n");
        return 1;
    }

    // Olu�turulan matrisi dosyaya kaydet
    char* dosyaAdi = "matris.txt"; // Kaydedilecek dosya ad�
    matrisiDosyayaKaydet(dosyaAdi, matris, satir, sutun);
    printf("Matris '%s' dosyas�na kaydedildi.\n", dosyaAdi);
	
}
int sembolSayiDonustur(char* sembol){
    if(strcmp(sembol, "0") == 0)
        return 0;
    else if(strcmp(sembol, "1") == 0)
        return 1;
    else if(strcmp(sembol, "p-") == 0)
        return 2;
    else if(strcmp(sembol, "p+") == 0)
        return 3;
    else if(strcmp(sembol, "e-") == 0)
        return 4;
    else if(strcmp(sembol, "e+") == 0)
        return 5;
    else if(strcmp(sembol, "k") == 0)
        return 6;
    else
        return -1;  // E�le�me bulunamad�
}
char* sayiSembolDonustur(int sayi){
    // Statik bir dizi d�nd�rmek i�in tan�ml�yoruz ki dizi fonksiyon bitince kaybolmas�n.
    static char sembol[3];
    
    switch(sayi){
        case 0:
            strcpy(sembol, "0\0");
            break;
        case 1:
            strcpy(sembol, "1\0");
            break;
        case 2:
            strcpy(sembol, "p-\0");
            break;
        case 3:
            strcpy(sembol, "p+\0");
            break;
        case 4:
            strcpy(sembol, "e-\0");
            break;
        case 5:
            strcpy(sembol, "e+\0");
            break;
        case 6:
            strcpy(sembol, "k\0");
            break;
        default:
            strcpy(sembol, "??\0"); // Tan�ms�z bir say� girildi�inde
    }
    return sembol;
}
void matrisiDosyayaKaydet(char* dosyaAdi, char*** matris, int satir, int sutun) {
    FILE* file = fopen(dosyaAdi, "w"); // Dosyay� yazma modunda a�
    int i, j;
    if (file == NULL) {
        perror("Dosya a��lamad�");
        return;
    }

    fprintf(file, "%d %d\n", satir, sutun); // Sat�r ve s�tun say�s�n� dosyaya yaz

    // Matrisi dosyaya yaz
    for (i = 0; i < satir; i++) {
        for (j = 0; j < sutun; j++) {
            fprintf(file, "%d ", sembolSayiDonustur(matris[i][j])); // Her bir matris eleman�n� dosyaya yaz
        }
        fprintf(file, "\n"); // Her sat�rdan sonra bir yeni sat�r karakteri ekle
    }

    fclose(file); // Dosyay� kapat
}
void sembollerinAnlamlariniGoster() {
    printf("0 -> 0\n");
    printf("1 -> 1\n");
    printf("2 -> p-\n");
    printf("3 -> p+\n");
    printf("4 -> e-\n");
    printf("5 -> e+\n");
    printf("6 -> k\n");
}
char*** kullaniciMatrisiOlustur(int *satir, int *sutun) {
	int i,j;
    printf("Satir sayisini giriniz: ");
    scanf("%d", satir);
    printf("Sutun sayisini giriniz: ");
    scanf("%d", sutun);

    // Kullan�c�ya sembollerin anlamlar�n� g�ster
    sembollerinAnlamlariniGoster();

    // Matrisi olu�tur
    char*** matris = (char***)malloc(*satir * sizeof(char**));
    for(i = 0; i < *satir; i++) {
        matris[i] = (char**)malloc(*sutun * sizeof(char*));
        for(j = 0; j < *sutun; j++) {
            matris[i][j] = (char*)malloc(3 * sizeof(char)); // En fazla 2 karakter + null terminator
        }
    }

    // Kullan�c�dan matris elemanlar�n� al
    for(i = 0; i < *satir; i++) {
        for(j = 0; j < *sutun; j++) {
            printf("Matrisin %d. satir %d. sutun elemanini girin (0-6 aras�): ", i+1, j+1);
            int sayi;
            scanf("%d", &sayi); // Say�y� oku
            while(sayi < 0 || sayi > 6) {
                printf("Hatali giris! Lutfen 0-6 arasi bir sayi giriniz: ");
                scanf("%d", &sayi);
            }
            strcpy(matris[i][j], sayiSembolDonustur(sayi)); // Sembol d�n���m�n� uygula
        }
    }

    return matris; // Olu�turulan matrisi d�nd�r
}
char*** matrisOkuVeDonustur(char* dosyaAdi, int *satir, int *sutun) {
	int i,j;
    FILE* file = fopen(dosyaAdi, "r"); // Dosyay� okuma modunda a�
    if (file == NULL) {
        perror("Dosya a��lamad�");
        return NULL;
    }

    fscanf(file, "%d %d", satir, sutun); // Sat�r ve s�tun say�s�n� oku

    // Matrisi olu�tur
    char*** matris = (char***)malloc(*satir * sizeof(char**));
    for(i = 0; i < *satir; i++) {
        matris[i] = (char**)malloc(*sutun * sizeof(char*));
        for(j = 0; j < *sutun; j++) {
            matris[i][j] = (char*)malloc(3 * sizeof(char)); // En fazla 2 karakter + null terminator
        }
    }

    // Matris de�erlerini oku ve d�n��t�r
    for(i = 0; i < *satir; i++) {
        for(j = 0; j < *sutun; j++) {
            int sayi;
            fscanf(file, "%d", &sayi); // Say�y� oku
            strcpy(matris[i][j], sayiSembolDonustur(sayi)); // D�n��t�r ve matrise ata
        }
    }

    fclose(file); // Dosyay� kapat

    return matris;
}
/*
void playGame(){
	int secim=0;
	printf("lutfen oyunu nas�l oynamak istediginizi giriniz:\n");
	printf("1-)Oyunu kendim oynamak istiyorum\n");
	printf("2-)Oyunu bilgisayara oynatmak istiyorum\n");
	printf("lutfen seciminizi yapiniz<0-2>\n");
	scanf("%d",&secim);
	
	switch(secim){
		case 1:
			self_control();
			break;
			case 2:
				oto_control();
				break;
				default:
					printf("gecersiz secim yaptiniz lutfen bir daha giriniz\n");
					getch();
					playGame();
					break;
					
	}
	
    
	
}

/*
void self_control(){
	int x,y;
	printf("lutfen guncel konumu giriniz(X,Y)\n");
	scanf("%d %d",&x,&y);
	
	printLabirent(x,y);
	int key;

    while (1) {
        if (kbhit()) {  // Klavyeden bir tu�a bas�l�p bas�lmad���n� kontrol eder
            key = getch();  // Tu� girdisini al�r

            if (key == 27) {  // ESC tu�u
                printf("ESC\n");
            } else if (key == 0 || key == 224) {  // Ok tu�lar� i�in �zel durum
                key = getch();  // Ok tu�lar� i�in ikinci bir getch() �a��r�l�r
                switch (key) {
                	
                    case 72: 
					printf("Up\n");
					
						x--;
					 
                        
                    break;
                    
					case 80: 
					printf("Down\n");
					
						x++;
					 
					break;
                    
					case 75: 
					printf("Left\n"); 
				
						y--;
					 

					break;
                    
					case 77: 
					printf("Right\n");
					
						y++;
					 

					break;
                }
            }

        	system("cls");  // Ekran� temizle
        	printLabirent(x,y);
        }
    }

	
}

void oto_control(){
	
}

void printLabirent(int x,int y){
	int i,j;
	
	for ( i = 0; i < 5; i++) {
        for ( j = 0; j < 5; j++) {
            if (i == x && j == y) {
                printf("______________");
				printf("|             |");
				printf("|    X  X     |");
				printf("|     XX      |",A[i][j]);
				printf("|    X  X     |");
				printf("|             |");
				printf("|_____________|");
            } else {
                printf("______________");
				printf("|             |");
				printf("|             |");
				printf("|     %c      |",A[i][j]);
				printf("|             |");
				printf("|             |");
				printf("|_____________|");
            }
        }
        printf("\n");
    }
    printf("�u anki konum: (%d, %d), De�eri: %d\n", x, y, labirent[x][y]);
}
*/
