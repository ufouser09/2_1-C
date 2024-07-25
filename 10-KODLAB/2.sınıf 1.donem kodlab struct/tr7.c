#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct sinama filmi diye bir struct olustururuz
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
};
//typedef anahtar kelimesi daha �nceden tan�mlad�g�m�z bir tipi yeniden adland�rarak kullanmam�z� saglar.bu komut sayesinde int float gibi veri tiplerine bile takma isim vererek kullanabiliriz.bu kullan�m�n iki �rnegi asag�dad�r.asag�daki ilk sat�rdaint anahtar kelimesine tamsayi takma ad� veriliyor.b�ylece eskiden int kulland�g�m�z heryerde tamsayi ifadesini kullanabilir durumda oluruz benzer sekilde struct sinamaFilmi isimli yap�ya da film takma ismi verildi.art�k struct sinamaFilmi yazmam�z gereken bir yere Film ifadesini koymam�z yeterlidir.

//art�k int yerine tamSayi ifadesini kullanabilirsin demek
typedef int tamSayi;
//art�k struct sinamafilmi struct�n� film olarak ifade edebilirsin demek
typedef struct sinamaFilmi Film;

int main(int argc,const char *argv[]){
	//x degiskenine 30 degerini atar�z
	//yukar�daki typedef int tamsayi komutu sayesinde int yerine tamsayi kelimesini kullanabiliriz.
	tamSayi x=30;
	//30 degerini ekrana yazd�r�r�z
	printf("x sayisinin degeri %d\n",x);
	//film struct�na *filmPtr pointer� olustururuz
	//yukar�daki typedef struct sinamaFilmi Film,komutu sayesinde struct sinamaFilmi yerine film kelimesini kullanabiliriz.
	Film *filmPtr;
	
	filmPtr=(Film *)malloc(sizeof(Film));
	//filmPtr arac�l�g� ile bellek alan�na ulas�p deger at�yal�m
	//filmPtr pointer� ile art�k structa erisebiliriz
	strcpy((*filmPtr).ad,"Runaway jury\n");
	//filmPtr pointer� ile struct�n y�netmen degiskenine erisiriz
	strcpy(filmPtr->yonetmen,"Gary fleder\n");
	filmPtr->yapimYili=2003;
	//atadigimiz degerleri yazdiral�m
	printf("film adi :%s\n",(*filmPtr).ad);
	printf("yonetmen :%s\n",filmPtr->yonetmen);
	printf("Yapim Yili:%d\n",(*filmPtr).yapimYili);
	free(filmPtr);
	
	return 0;
}
/*
x sayisinin degeri 30
film adi :Runaway jury

yonetmen :Gary fleder

Yapim Yili:2003

*/
--------------------------------------------------
//TYPEDEF ANAHTAR KEL�MES�
typedef anahtar kelimesi daha �nceden tan�mlad�g�m�z bir tipi yeniden adland�rarak kullanmam�z� saglar.bu komut sayesinde int,float gibi veri tiplerine bile takma isim vererek kullanabiliriz.
�rnegin asag�daki komutu verdigimizi dusunelim

typedef int tamsayi;
 bu komut sonras�nda program�m�z�n i�erisinde int yerine tamsayi kelimesini kullanabilir ve int tipindeki degiskenlerimizi tamsayi kelimesiyle tan�mlayabiliriz.
 
 tamsayi x=30;
 printf("x sayisinin degeri %d",x);
 
 bu anahtar kelime genellikle struct ifadesiyle olusturulmus yap�lara takma isim vermek i�in kullan�l�r.bir �nceki bolumde s�kl�kla struct sinamaFilmi ifadesini kullanm�st�k.bu ifadeye typedef anahtar kelimesiyle Film takma ismini asag�daki gibi verebiliriz.
 
 typedef struct sinamaFilmi Film;
 
 bir sat�rdan sonra art�k struct sinamaFilmi yazd�g�m�z her yere Film ifadesini koyabiliriz.
 
 Film * filmPtr;
 filmPtr=(Film *)malloc(sizeof(Film));
 
 asag�da bu kullan�m� g�steren �rnek bir program verilmistir.
 
 -
 -
 -
 -YUKARIDAK� KOD
 -
 -
 -
 PROGRAM CIKTISI
 x sayisinin degeri 30
 Film adi:RunAway jury
 yonetmen:gary fleder
 yapim Yili:2003
 
 
//TYPEDEF ANAHTAR KEL�MES�N� YAPILAR HEN�Z TANIMLANIRKEN KULLANMAK

yukar�daki programda ilk �nce sinamaFilmi isimli yap�m�z� olusturduk.daha sonra da typedef anahtar kelimesi arac�l�yla bu yap�ya Film takma ad�n� verdik.Bunu asag�da Yontem 1 olarak tekrar yazd�m�

//YONTEM 1
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
}; 
typedef struct sinamaFilmi Film;

Yontem 1'deki iki komutu tek bir sat�rda birlestirebiliriz.asag�daki verilen y�ntemdeki deklarasyon derleyici Yontem 1'dekiyle ayn� seyi soyler.

//YONTEM 2
typedef struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
}Film;

bu iki deklarasyondan herhangi birini yapt�ktan sonra ilgili yap� i�in asag�daki degisken deklarasyonlar�ndann her ikisi de gecerlidir.

struct sinamaFilmi film;//dogru
Film film1;//dogru

hatta eger typedef arac�l�g�yla bir yap�ya isim tan�ml�yorsan�z,o yap�ya ayr�ca isim vermenize de gerek yoktur.asag�da verilen yontem 3,ilk iki y�nteme denktir.

//YONTEM 3
typedef struct {
	char ad[100];
	char yonetmen[50];
	int yapimYili;
}Film;

yontem 3'un yontem 1 ve 2'den tek fark�,yontem 3'te tan�mlanan yap� tipinde bir degisken tan�mlarken asag�daki ilk ifadenin gecersiz olmas�d�r.

struct sinamaFilmi film1;//Yanl�s (tan�mda sinamaFilmi diye bir �ey yok)
Film film1;//dogru

bir baska deyisle bir yap�y� yukar�daki yontem 3 ile tan�ml�yorsan�z sadece typedef ile verdigimiz isim arac�l�g�yla (Film) o yap�n�n tipine sahip bir degisken tan�ml�yabilirsiniz.
 
