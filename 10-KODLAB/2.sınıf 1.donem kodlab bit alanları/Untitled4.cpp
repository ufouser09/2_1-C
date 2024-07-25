//ORTAKLIKLAR(UN�ONS)
hat�rlarsan�z yap�lar(structs)farkl� tipteki belli degiskenleri gruplayarak bir paket haline getiriyorlard�.paket i�erisindeki her bir degiskenin kendine has bir bellek alan� oluyordu.

ortakl�klar ise tan�mlama itibariyle yap�lara cok benzeseler de cok onemli bir farklar� vard�r.

union deyimiyle tan�mlanan paketlerde her degisken ortak bellek alan�n� kullan�r.(ad� da buradan gelmektedir.)

asagida Sayi takma adl� bir (typedef) bir ortakl�k tan�mlanm�st�r.

typedef union{
	int intSayi;
	float FloatSayi;
}Sayi;

bu ortakl�g� asag�daki sekilde kullanabiliriz.

Sayi sayi;
sayi.intSayi=0;

printf("sayi.intSayi=%d\n",sayi.intSayi);

bir ortakl�kta bir uye degiskene deger atad�g�n�zda diger uye degiskenlerin degeri bozulur.C�nk� hepsi ortak bellek alanlar�n� kullanmaktad�rlar.
Bu sebeple belli bir uye degiskene deger atad�ktan sonra diger degiskenlere erismekten kac�n�n�z.

asag�daki bu durumu g�steren �rnek bir program verilmistir.

Unionornek-main.c
#include <stdio.h>
#include <string.h>

typedef union{
	int intSayi;
	float floatSayi;
}Sayi;

int main(int argc,const char * argv[]){
	Sayi sayi;
	sayi.intSayi =0;
	
	printf("sayi.intSayi=%d\n",sayi.intSayi);
	printf("sayi.floatSayi=%f\n",sayi.floatSayi);
	
	sayi.floatSayi=3.14;
	printf("sayi.intSayi=%d\n",sayi.intSayi);
	printf("sayi.floatSayi0=%f\n",sayi.floatSayi);
	
	return 0;
}

yukar�daki programda sayi tipinde sayi isimli bir ortakl�k tan�mlanm�st�r.bu ortakl�g�n iki �yesi vard�r.ilk �yesi intSayi isimli tam say�d�r.ikinci uyesi de floatSayi isimli bir noktal� say�d�r.
program i�erisinde �nce sayi isimli ortakl�k degiskeninin intSayi degiskenine deger atanm�st�r.daha sonra da floatSayi degiskenin deger atanm�st�r.

her iki deger atama islemi sonras�nda da her iki �ye degiskenin degeri printf arac�l�g�yla yazd�r�lm�st�r.

deger atama islemleri sonras�nda diger uye degiskene deger atanmamas�na ragmen bu degiskenin de degerinin de degistigini g�rebilirsiniz.

Program C�kt�s�

sayi.intSayi=0
sayi.floatSayi=0.000000
sayi.intSayi=1078523331
sayi.floatSayi=3.140000

*bir ortakl�g�n genisligi o ortakl�ktaki en fazla alan kaplayan �ye degiskenin genisligi kadard�r.�rnegin bir ortakl�kta i�erisinde bir adet char ve bir adet double degisken olsayd� ortakl�g�m�z�n genisligi double degiskenin bellekte kaplad�g� yer kadar(8 bayt)olacakt�.

ortakl�klar�n kullan�m alanlar� oldukca k�s�tl�d�r.ayn� bellek alan�nda farkl� tipten degiskenler tan�mlamak i�in kullanmak en yayg�n kullan�mlar�ndan biridir.

bu sayede elemanlar� farkl� tipte degiskenlerden olusan diziler olusturup kullanmak m�mk�nd�r.
bu kullan�mlardan bir tanesi bolum sonu sorular�nca incelenmistir.
bolum sonu sorular�nda verilen UnionOrnek2 isimli uygulamay� incelemenizi �neririm.
