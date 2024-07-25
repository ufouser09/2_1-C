#include <stdio.h>
#include <string.h>
//Struct sinamaFilmi diye bir struct olustururuz
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
};
//structtan sonra int main gelir
int main(int argc,const char * argv[]){
	//film1 isimli struct degiskeni olustural�m
	//struct sinamaFilmi struct�na film1 ismini veririz
	struct sinamaFilmi film1;
	
	//film1 degiskenin uyelerine deger at�yal�m
	//film1.ad degiskenine String ifadesini atar�z
	strcpy(film1.ad,"burn After reading");
	//film1.yonetmen degiskenine String ifadesini atar�z
	strcpy(film1.yonetmen,"ethan&john cohen");
	//film1.yapimYili degiskenine 2008 degerini atar�z
	film1.yapimYili=2008;
	
	//yeni bir struct olusturup film1'i film2'e at�yal�m
	//Struct sinamafilmi struct�na film2 ismini veririz
	struct sinamaFilmi film2;
	//film1 struct�n� film2 struct�na atar�z
	film2=film1;
	
	//atad�g�m�z degerleri yazd�ral�m
	//structismi.degisken diyip degere ulasabiliriz
	printf("film adi:%s\n",film2.ad);
	printf("yonetmen :%s\n",film2.yonetmen);
	printf("yapim yili :%d\n",film2.yapimYili);
	return 0;
}
/*
film adi:burn After reading
yonetmen :ethan&john cohen
yapim yili :2008
*/
--------------------------------------------
//YAPILAR UZER�NDE GECERL� OPERATORLER
yap�lar uzerinde uygulanabilecek iki operator vard�r.

1-sizeof operatoru
2-atama(=) operatoru

sizeof operatorunun kullan�m�n� biraz �nce g�rm�stuk.yap�n�n bellekte kaplad�g� alan� bize veriyordu.atama operatoru ise bir yap�n�n degerini bir digerine kopyalamak i�in kullan�labilir.

�rnegin elimizde asag�daki sekilde olusturulmus film1 isimli bir sinamaFilmi struct� olsun

struct sinamFilmi film1;

//film degiskenin uyelerine deger at�yal�m

strcpy(film1.ad,"burn after read�ng");
strcpy(film1.yonetmen,"ethan&john cohen");
film1.yapimYili=2008;

bu struct'� baska bir structa asagidaki gibi kopyal�yabiliriz.

struct sinamaFilmi film2;
film2=film1;

yukar�daki iki kod cal�st�r�ld�g�nda film2'de degiskeninde film1'in bir kopyas� olusmus olur.


**c derleyicileri iki yap�n�n birbirine atand�g� bir durumla kars�last�klar�nda arka tarafta bir memcpy komutu cal�st�r�rlar.film1'in  154 bayt yer kaplad�g�n� s�ylemistik.derleyici film1 i�in ayr�lan 154 bayt'�n i�erigini al�r ve film 2 i�in ayr�lan 154 bytel�k alana kopyalar.bunun sonucunda hem film1 hem de film2 ayr� bellek alanlar�nda birbirinin kopyas� olan i�erige sahip olurlar.

bu durumu g�steren program� kitapla birlikte verilen medya i�erisinde,bolum 16 alt�nda structlar�nkopyalanmas� adl� netbeans proje dosyas� icerisinde bulabilirsiniz. 

-Yukar�daki kod


