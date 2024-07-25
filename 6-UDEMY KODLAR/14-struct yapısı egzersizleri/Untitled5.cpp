#include <stdio.h>
#include <stdlib.h>
//struct AdresDefteri diye bir struct olustururuz
struct AdresDefteri{
char Ad[100];
char Soyad[100];
char TelNo[10];
char Adres[200];
char PostaKodu[6];

};
//structlar tan�mland�ktan sonra 
int main()
{
    /*Adres defteri ad�nda bir yap� tan�mlay�n�z.Tutulacak bilgiler ad,soyad,tel,adres,posta kodu �eklindedir.
    Buna g�re N adet ki�inin bilgisini bir yap�da tutan C program�n� yaz�n�z.*/
    //N diye bir degisken tan�mlar�z
	int N;
	//i diye bir degisken tan�mlar�z
    int i;
    //satir diye bir degisken tan�mlar�z
    char satir;
    //kac adet kayit tutulac�n� kullan�c�dan al�r ve onu da N degiskenine aktar�r�z
    printf("Kac adet kayit tutulacak\n");
    scanf("%d",&N);
    scanf("%c",&satir);
	//struct adres defterine iletisim[N] ismini veririz
    struct AdresDefteri iletisim[N];

    for(i=0;i<N;i++)
    {
		//kullan�c�dan iletisim[i].Ad ile ad� al�r�z
        printf("Adi giriniz\n");
        gets(iletisim[i].Ad);
		//kullan�cdan iletisim[i].Soyad ile soyad al�r�z
        printf("Soyadi giriniz\n");
        gets(iletisim[i].Soyad);
		//kullan�c�dan iletisim[i].TelNo ile tel no al�r�z
        printf("Telno giriniz\n");
        gets(iletisim[i].TelNo);
		//kullan�c�dan iletisim[i].Adres ile adres al�r�z
        printf("Adres giriniz\n");
        gets(iletisim[i].Adres);
		//kullan�c�dan iletisim[i].PostaKodu ile posta kodunu al�r�z
        printf("Postakodu giriniz\n");
        gets(iletisim[i].PostaKodu);


    }

    printf("ADI\tSOYADI\tTELEFON\tADRES\t\POSTAKODU\n");
    printf("=============================================\n");
	//kullan�c�dan ald�klar�m�z� ekrana yazd�r�r�z
    for(i=0;i<N;i++)
    {
        printf("%s \t %s \t %s \t %s \t %s\n",iletisim[i].Ad,iletisim[i].Soyad,iletisim[i].TelNo,iletisim[i].PostaKodu,iletisim[i].Adres);
    }

    return 0;
}
/*
output:
Kac adet kayit tutulacak
2
Adi giriniz
e
Soyadi giriniz
f
Telno giriniz
g
Adres giriniz
3
Postakodu giriniz
4
Adi giriniz
r
Soyadi giriniz
e
Telno giriniz
e
Adres giriniz
a
Postakodu giriniz
s
ADI     SOYADI  TELEFON ADRES   POSTAKODU
=============================================
e        f       g       4       3
r        e       e       s       a
*/





