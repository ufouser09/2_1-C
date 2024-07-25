#include <stdio.h>
#include <conio.h>  // Windows i�in klavye girdisi ve ekran kontrol fonksiyonlar�
#include <string.h>
#include <stdlib.h>

void matrisiDosyayaKaydet(char* dosyaAdi, char*** matris, int satir, int sutun);
char*** kullaniciMatrisiOlustur(int *satir, int *sutun);

int main() {
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
/*
void haritaYukle(){

int choice=0;

while(choice!=3){
	
	
	
	
	printf("lutfen haritay� nas�l yuklemek istediginizi giriniz\n");
	printf("1-)oyun tahtas�ndaki degerleri ben elle girmek istiyorum\n");
	printf("2-)oyun tahtas�ndaki degerleri disaridaki bir text dosyas�ndan yuklemek istiyorum\n");
	scanf("%d",choice);
	
	switch(choice){
		
		case 1:
			elleHaritaYukleme();
			break;
			
			case 2:
				dosyadanHaritaYukleme();
				break;
				
				default:
					printf("gecersiz secim yaptiniz\n");
					break;
					
				
			
	}
}


	
}
/*
int elleHaritaYukleme(){
	int N,M;
	int i,j;
	FILE *fp;
	printf("lutfen girmek istediginiz haritan�n satir ve sutun sayisini giriniz\n");
	scanf("%d %d",&N,&M);
	char A[N][M];

	printf("lutfen matrisinizi giriniz\n");
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf("A[%d][%d]=\n",i+1,j+1);
			scanf("%c",&A[i][j]);
		}
	}


	printf("MATR�S�N�Z BOYLE GOZUKUYOR:");
	
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
printf("______________");
printf("|             |");
printf("|             |");
printf("|     %c      |",A[i][j]);
printf("|             |");
printf("|             |");
printf("|_____________|");
			
		}
		printf("\n");
	}

	
	
	//KULLANICININ GIRDIGI DEGERLERI HARITALARIN YUKLU OLDUGU KLASORUME EKLIYORUM 
	fp=fopen(maps.txt,"a");
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			fprintf(fp,"%c",A[i][j]);
		}
		fprintf(file,"\n");
	}
	
	
	fclose(fp);
	
}*/
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
void haritaSec(){
	FILE *fp;
	char value[]="";
	fp=fopen(maps.txt,"r");
	if(fp==NULL){
		printf("dosya acilamadi\n");
		return -1;
	}
	while(fscanf(fp,"%s",value)!=EOF){
	

printf("______________");
printf("|             |");
printf("|             |");
printf("|     %c      |",fgetc(fp));
printf("|             |");
printf("|             |");
printf("|_____________|");
			
			if(fscanf(fp,"%d",&num)=="\n"){
				fscanf(fp,"\n");
				
				
			}
			
		}
		printf("\n");
	}

	
	
	
}
void playGame(){
	 int key;

    while (1) {
        if (kbhit()) {  // Klavyeden bir tu�a bas�l�p bas�lmad���n� kontrol eder
            key = getch();  // Tu� girdisini al�r

            if (key == 27) {  // ESC tu�u
                printf("ESC\n");
            } else if (key == 0 || key == 224) {  // Ok tu�lar� i�in �zel durum
                key = getch();  // Ok tu�lar� i�in ikinci bir getch() �a��r�l�r
                switch (key) {
                    case 72: printf("Up\n");
                    
					break;
                    case 80: printf("Down\n");
					break;
                    case 75: printf("Left\n"); 
					break;
                    case 77: printf("Right\n");
					break;
                }
            }

           // system("cls");  // Ekran� temizle
        }
    }

    return 0;
	
}
void guncelHarita(){
	
}
void toplananPuanlar(){
	
}
*/








