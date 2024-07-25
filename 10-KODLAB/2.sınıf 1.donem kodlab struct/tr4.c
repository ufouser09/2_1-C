#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//struct sinamaFilmi diye bir struct olustururuz
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
};

int main(int argc,const char * argv[]){
	//struct sinamafilmi struct�na *filmptr diye bir isim verilir
	//struct sinamaFilmi i�in filmPtr isimli bir isaretci olustural�m
	struct sinamaFilmi *filmPtr;
	//isaretci i�in bellekten yer ay�ral�m
	//filmPtr pointeri i�in bellekte yer ay�r�r�z
	filmPtr=(struct sinamaFilmi *)malloc(sizeof(struct sinamaFilmi));
	//(*filmPtr).ad diye ulasabiliriz)
	//filmPtr arac�l�g� ile bellek alan�na ulas�p deger at�yal�m
	strcpy((*filmPtr).ad,"departed");
	//ya da (filmPtr->yonetmen diyip erisebiliriz
	strcpy(filmPtr->yonetmen,"martin scorsese");
	//FilmPtr->yapimYili diyip 2006 degerini degiskene atar�z
	filmPtr->yapimYili=2006;
	//atad�g�m�z degerleri yazd�ral�m
	//(*filmPtr).ad degerini yazd�r�r�z
	printf("film adi:%s\n",(*filmPtr).ad);
	printf("yonetmen :%s\n",filmPtr->yonetmen);
	printf("yapim Yili:%d\n",(*filmPtr).yapimYili);
	free(filmPtr);
	
	
}
/*
film adi:departed
yonetmen :martin scorsese
yapim Yili:2006
*/
--------------------------------------------------------------------------------------
//YAPILAR VE D�NAM�K BELLEK FONKS�YONLARI
yap�larla birlikte dinamik bellek ay�rma fonksiyonlar�n� da kullanbiliriz.
asag�daki �rnekte ise;filmPtr isaretcisinin isaret edecegi struct sinamaFilmi yap�s� i�in bellekten dinamik olarak yer ayr�lm�st�r.
bu islemi gerceklestiren sat�r asag�da verilmistir.

struct sinamaFilmi *filmPtr;
filmPtr=(struct sinamaFilmi *)malloc(sizeof(struct sinamaFilmi));

yukar�daki yap�n�n int tipinden isaretciler i�in bellek ay�rma islemine ne kadar benzedigini g�rebilirsiniz.
tek fark bu �rnekte int i�in degil struct sinamaFilmi i�in bellekten yer ayr�lmas�d�r.

sizeof(struct sinamaFilmi)ifadesi sinamaFilmi yap�s�n�n bellekten ne kadar alan kaplad�g�n� dondurur.
eger elle bir hesap yaparsak 100 karakterlik ad �ye degisken i�in 100 bayt,50 karakterlik yonetmen �ye degiskeni i�in 50 bayt ve int tipindeki yapimYili degiskeni i�in 4 bayt olmak �zere bellekten toplamda 154 baytl�k yer ayr�lmaktad�r.
sinamaFilmi yap�sn�n bellekteki g�r�nt�s� asag�daki res�mdeki gibidir.

-REsim

bir yap�y� olusturduktan sonra onun bellekte kaplad�g� alan sabittir.bu alan� degistiremezsiniz.yukar�daki struct her zaman 154 byte yer kaplayacakt�r.eger struct uyelerini degisken uzunluklarda tan�mlamak istiyorsan�z(�rnegin:her yonetmen dizisinin uzunlugu yonetmenin ad�n�n uzunlugu kadar olsun diyorsan�z)yap� uyelerini isaretci olarak tan�mlay�n�z.bu kullan�m� veri yap�lar� bolumunde g�recegiz.

bu ayr�lan alan�n baslang�c adresi filmPtr isimli isaretci degiskenimize kopyalanm�st�r.
asag�da struct isaretcilerinin kullan�m�n� ve d�nam�k bellek ay�rma islemini g�steren uygulama kodumuzun tamam� listelenmistir.
program i�erisinde printf ve strcpy fonksiyonlar�nda biraz �nce inceledigimiz notasyonlar�n ikisi de kullan�lm�st�r.


-YUKARIDAK� KOD

//PROGRAM CIKTISI
film adi:departed
yonetmen:mart�n scorsese
Yapim Yili:2006

bu program bir onceki programla temelde ayn� seyi yapar.tek fark� bu programda isaretci yonteminin kullan�lmas�d�r.
dolay�s�yla program�n c�kt�s� bir oncekiyle ayn� olacakt�r.
program�n en sonunda free fonksiyonunu kullanarak filmPtr isaretcisinin isaret ettigi bellek alan�n� hafizaya iade edilmistir.



