#include <stdio.h>
#include <string.h>
//struct sinamafilmi diye bir struct olustururuz
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
};
//structtan sonra int main gelir
int main(int argc,const char *argv[]){
	//filmler isimli bir struct dizisi olustural�m
	//struct sinamafilmi struct�na filmler diye isim verirsin 
	struct sinamaFilmi filmler[2]={{"seven","david fincher",1995},{"snatch","guy ritche",2000}
};
	
	
	printf("\n[FILM LISTESINDEK� ELEMANLAR]\n\n");
	printf("film adi:%s\n",filmler[0].ad);
	printf("yonetmen:%s\n",filmler[0].yonetmen);
	printf("yap�m y�l�:%d\n",filmler[0].yapimYili);
	
	printf("\n");
	
	printf("film Adi:%s\n",filmler[1].ad);
	printf("yonetmen:%s\n",filmler[1].yonetmen);
	printf("yapim yili:%d\n",filmler[1].yapimYili);
	
	return 0;
}
/*
[FILM LISTESINDEK� ELEMANLAR]

film adi:seven
yonetmen:david fincher
yap�m y�l�:1995

film Adi:snatch
yonetmen:guy ritche
yapim yili:2000
*/
--------------------------------------------------------------------------------
//YAPILARIN DiZ�LERLE B�RL�KTE KULLANIMI
bir yap�y� tan�mlad�ktan sonra o yap�n�n normal bir veri tipinden hicbir fark� yoktur.
fonksiyonlara parametre olarak g�nderebilir veya o icerigi o yap�n�n tipinde elemanlar olan diziler tan�ml�yabiliriz.
asag�da

struct sinamaFilmi isimli yap�dan iki elemanl� bir dizi olusturan,
bu dizinin elemanlar�na diziyi tan�mlama esnas�nda ilk deger atayan ve 
dizinin i�erigini konsola yazd�ran kucuk bir �rnek uygulama verilmistir.
-
-
-
-YUKARIDAK� KOD
-
-
-
uygulama i�erigini inceleyecek olursan�z 2 elemanl� bir dizinin olusturuldugunu g�rebilirsiniz.deger atama isleminin tan�mlama esnas�nda yap�ld�g�n�n g�rebilirsiniz.bir struct eleman�na ilk deger atamaya benzer
tek fark� dizideki her bir eleman i�in ilk degerin virguller ile ayr�lmas�d�r.

dizinin her bir eleman�n�n tipi struct sinamaFilmi tipindedir.
boyle bir deklarasyon yapt�g�n�zda dizideki ikinci eleman�n�n ad uyesine ulasabilmek i�in asag�daki gibi bir ifade kullanmal�s�n�z.

filmler[1].ad;

yukar�daki dizinin her iki eleman� i�in elemanlar�n ald�g� degerler printf fonksiyonlar� arac�l�g�yla konsola yazd�r�lm�st�r.
program�n c�kt�s� asag�da verilmistir.

//PROGRAM CIKTISI
[F�LM L�STES�NDEK� ELEMANLAR]
film adi:SEVEN
yonetmen:david fincher
yap�m yili:1995

film adi:snatch 
yonetmen :guy ritchie
Yapim Yili:2000



