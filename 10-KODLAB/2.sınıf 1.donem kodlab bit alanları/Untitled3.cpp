//B�TF�ELDSORNEK2-main.c
#include <stdio.h>
#include <string.h>

typedef struct{
	unsigned int sayi:2;
}DordeKadar;
int main(int argc,const char * argv[]){
	int tarihiGun,tarihiAy,tarihiYil;
	
	DordeKadar temp;
	int i;
	for(i=0;i<8;i++){
		temp.sayi=i;
		printf("%d\n",temp.sayi);
	}
	return 0;
}
Yukar�daki �rnekte DordeKadar takma ad� verilmi� bir struct tan�mlanm��t�r.
Bu struct'in i�indeki sayi de�i�keni 2 bit kaplayacak �ekilde tasarlanm��t�r.
Dolay�s�yla sayi de�i�keni sadece 0, 1, 2 ve 3 de�erlerini alabilir. ��nk�
2 bit'de maksimum bu de�erler tan�mlanabilir. Bir d�ng� i�erisinde sayi
de�i�kenine o'dan s'e kadar de�er atand���nda atanan de�er 4'ten k���k
oldu�u s�rece sorun ya�anmaz. Fakat de�er 4 veya 4'ten b�y�kse her bir de�er
alan geni�li�ine uygun oluncaya kadar o de�erden alan geni�li�i ��kar�lacakt�r.
Yukar�daki program�n ��kt�s� a�a��daki gibi olur:
	
	PROGRAM CIKTISI
	0
	1
	2
	3
	0
	1
	2
	3
	
	BITFIELD KULLANIMINDAK� KISITLAMALAR
. Kisit 1: Bitler kullan�larak olu�turulan bir alan�n�n herhangi bir �yesi �zerinde
�al���r. Bu sebeple bit uzunlu�unu elde edemezsiniz.
sizeof operat�r�n� kullanmay�n�z. Bu operat�r sadece bayt'lar �zerinde
. Kisit 2: Bitfield i�erisindeki bir de�i�ken �zerinde, adres operat�r�
kullanamazs�n�z. ��letim sistemleri bayt baz�nda adresleme yapar. Bit baz�nda
adresleme yap�lamad��� i�in belli bir bit'in bellekte hangi adrese kar��l�k
geldi�ini adres (&) operat�r�yle elde edemezsiniz.


Kisit 3: Ikinci kisit sebebiyle bir bitfield'in de�erini scant i�erisinde
okuyamazs�n�z. scanf fonksiyonu adres operat�r�n�n kullan�m�n� gerektin
Dolay�s�yla bitfield i�in kullan�c�dan de�er okuyaca��n�zda ilk �nce bu
de�eri normal bir de�i�kene okuman�z daha sonras�nda ilgili bitfield alanina
kopyalaman�z gerekmektedir.
to
//NUMARALANDIRMA (ENUMERATION) KAVRAMI
Programlama dillerinin �ok b�y�k bir k�sm�nda bulunan enumeration
(numaraland�rma) kavrami programlama esnas�nda kendi belirledi�imiz baz�
de�erleri daha okunabilir kilmak i�in s�kl�kla kullan�lan bir y�ntemdir.

�rne�in; bir�ok say�da kullan�c�ya hitap eden bir uygulama yazd���n�z�
d���nelim.

 Her bir kullan�c�n�n da �e�itli yetki seviyeleri olsun. Bu yetki
seviyelerinin de tam say� kar��l�klar olsun. On binlerce sat�rdan olu�an kod
i�erisinde uygulaman�z�n baz� b�l�mlerine sadece admin yetki seviyesindeki
kullan�c�lar�n eri�ebilece�i di�er kullan�c�lar�n ise eri�emeyece�ini varsayal�m.
�rne�in; admin kullan�c�s�n�n yetki seviyesinin tam say� kar��l��� da 4
olsun. Uygulama b�y�d�k�e ve yetki seviyeleri �e�itlendik�e bu yetki
seviyelerinin tam say� de�erlerini hat�rlamak zorla�acakt�r
. Hele uygulama
geli�tirmeyi tamamlad�ktan sonra sizden sonra kodu okuyan birisi 4 de�eriyle
kar��la�t���nda, bu de�er ona hi�bir anlam ifade etmeyecektir.
i�te enumeration yap�s� bu noktada bize olduk�a g�zel bir ��z�m
sunmaktad�r. Program i�inde s�kl�kla kulland���m�z ve kar��l�k gelen de�erleri
kendimiz belirledi�imiz �zel veri tiplerini enum'lar arac�l���yla tan�mlayabiliriz.
Her bir de�ere anla��l�r isimler verebilir ve program i�erisinde say�sal de�erler
�zerinden de�il de ismini kendimizin belirledi�i anla��labilir isimler arac�l���yla
i�lemlerimizi ger�ekle�tirebiliriz.
C programlama dilindeki enum yap�s�n�n amac� da budur. Enum yap�s�na �rnek
olarak a�a��daki program� verebiliriz. Bu programda Kullan�c� Seviyeleri
isimli �zel bir enum yap�s� kullan�lm��t�r. Bu enum yap�s�nda her bir kullan�c�
seviyesine ak�lda kal�r bir isim verilmi�tir. Enum tan�mlamas�n� yapt�ktan sonra
menum KullaniciSeviyeleri kelime grubunu art�k yeni bir veri tipiymi� gibi
d���nebiliriz.


Program i�inde bu tipe sahip seviye isimli bir de�i�ken tan�mlayarak, bu
de�i�kenin de�erinin kullan�c� taraf�ndan girilmesini sa�lad�k. Daha sonra
girilen bu de�erin neye kar��l�k geldi�ini bir switch ifadesi i�erisinde bulmaya
�al��t�k. switch ifadesi i�inde tam say� de�erler yerine enum tan�m�nda
belirledi�imiz kolay anla��labilir isimleri kulland�k.
nina
MI
ion
azi
Bu program k���k bir uygulama oldu�u i�in tan�mlad���n�z enum tipinin ne
gibi bir kolayl�k sa�lad���n� kolayca g�remiyor olabilirsiniz. Fakat yazd���n�z
uygulamada sat�r say�s� artt���nda ve yazd���n�z kodu tekrardan g�zden
ge�irmek istedi�inizde say�sal de�erler yerine anlaml� ifadelerle kar��la�man�n
size olduk�a zaman kazand�raca��ndan emin olabilirsiniz. A�a��da enum
yap�s�yla ilgili program�n tamam�n� bulabilirsiniz:
	
#include <stdio.h>
int main(int argc,const char * argv[]){
	enum KullaniciSeviyeleri{
		misafir=1,
		ogrenci=2,
		akademisyen=3,
		admin=4,
	};
	enum KullaniciSeviyeleri seviye;
	printf("kullan�c�n�n yetki seviyesini 1,4 arasinda giriniz:");
	scanf("%d",&seviye);
	
	switch(seviye){
		case misafir:
			printf("yetki seviyesi misafir\n");
			break;
			case ogrenci:
				printf("yetki seviyesi �grenci\n");
				break;
				case akademisyen:
					printf("yetki seviyesi akademisyen\n");
					break;
					case admin:
						printf("yetki seviyesi admin\n");
						break;
						default:
							printf("girdiginiz deger gecersiz\n");
							break;
						}
						return 0;
	}
PROGRAM CIKTISI
kullan�c�n�n yetki seviyesini 1,4 arasinda giriniz:15
girdiginiz deger gecersiz
kullan�c�n�n yetki seviyesini 1,4 arasinda giriniz:3
yetki seviyesi akademisyen


tum enum degiskenler sayisal(tam sayi)degerler al�rlar.eger enum degiskenlere deger vermezseniz bu degerler derleyici taraf�ndan s�f�rdan baslayarak artacak sekilde verilir.yani yukar�daki �rnekteki veri tipimiz

enum KullaniciSeviyeleri{
	misafir,
	ogrenci,
	akademisyen,
	admin
};	
seklinde tan�mlanm�s olsayd�k misafir degerine derleyici taraf�ndan otomatik olarak 0 degeri verilecekti.ayn� sekilde ogrenci degerinin kars�l�g� 1,akademisyen degerinin kars�l�g� 2 ve admin degerinin kars�l�g� 3 olacakt�.
 
	
	
