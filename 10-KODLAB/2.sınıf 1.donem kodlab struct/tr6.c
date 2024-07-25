#include <stdio.h>
#include <string.h>
#define PI 3.14
//struct nokta diye bir struct olustururuz
typedef struct{
	float x;
	float y;
	
}Nokta;
//Struct daire diye bir struct olustururuz
typedef struct{
	float yaricap;
	Nokta merkez;
}Daire;
//fonksiyonu basta tan�mlar�z
void daire_bilgisi_yazdir(Daire d);

int main(int argc,const char * argv[]){
	//daire struct�na daire ismini veririz
	Daire daire;
	//kullan�c�dan dairenin merkez x koordinatlar�n� al�r�z
	printf("dairenin merkezinin x koordinatlarini giriniz\n");
	scanf("%f",&daire.merkez.x);
	//kullan�c�dan dairenin merkez y koordinatlar�n� al�r�z
	printf("dairenin merkezinin y koordinatlarini giriniz\n");
	scanf("%f",&daire.merkez.y);
	
	printf("dairenin yaricap uzunlugunu giriniz:\n");
	scanf("%f",&daire.yaricap);
	
	daire_bilgisi_yazdir(daire);
	
	return 0;
	
}
void daire_bilgisi_yazdir(Daire d){
	float cevre=2*PI*d.yaricap;
	float alan=PI*d.yaricap*d.yaricap;
	
	
	printf("\n[DAIRENIN BILGELERI]\n");
	printf("\nDairenin merkez koordinatlari(x,y):(%.2f,%.2f) ",	d.merkez.x,d.merkez.y);

	printf("\ndairenin Yaricapi:%.2f",d.yaricap);
	printf("\ndairenin cevresi:%.2f",cevre);
	printf("\ndairenin Alani:%.2f",alan);
	printf("\n");
}
//output:
dairenin merkezinin x koordinatlarini giriniz
5.2
dairenin merkezinin y koordinatlarini giriniz
6.7
dairenin yaricap uzunlugunu giriniz:
15

[DAIRENIN BILGELERI]

Dairenin merkez koordinatlari(x,y):(5.20,6.70)
dairenin Yaricapi:15.00
dairenin cevresi:94.20
dairenin Alani:706.50
--------------------------------------------------------
//YAPILARIN FONKS�YONLARA PARAMETRE OLARAK G�NDER�LMES�

Bir yapay bir fonksiyona parametre olarak g�ndermenin bir tam
sayiyi bir
fonksiyona parametre olarak g�ndermekten hi�bir fark� yoktur. Yap�lar
fonksiyonlara g�nderildiklerinde tipki tam sayi de�i�kenler gibi de�erleri
fonksiyon parametresine kopyalan�r (call by value). Bir ba�ka deyi�le biraz
�nce g�rd���m�z atama ifadesi �al���r. Parametre olarak g�nderilen struct,
fonksiyon i�erisindeki de�i�iklikten etkilenmez. (call by value'yu hat�rlayal�m.)
Bunu daha iyi anlayabilmek i�in yukar�daki film �rneklerimizdeki yazd�rma
i�lemlerini ger�ekle�tirebilecek ayr� bir fonksiyon tan�mlayal�m. Bu fonksiyon
kendisine parametre olarak gelen yap�y� als�n ve de�erini konsola yazdirsin.

void filmYazdirDegerYontemiyle(struct sinamaFilmi arg){
	printf("-------------------------------------\n");
	printf("deger yontemi:\n");
	printf("----------------------------------\n");
	printf("Film adi:%s\n",arg.ad);
	printf("yonetmen:%s\n",arg.yonetmen);
	printf("yapim Yili:%d\n\n",arg.yapimYili);
	
	
	
}
yukar�daki fonksiyon,bir adet sinamFilmi yap�s�n� arguman alacak sekilde tasarlanm�st�r.bu fonksiyonu asagidaki sekilde cag�rd�g�m�z� dusunelim.


struct sinamaFilmi film1;
srtcpy(film1.ad,"burn after read�ng");
strcpy(film1.yonetmen,"ethan6john cohen");
film1.yapimYili=2008;

filmYazdirDegerYontemiyle(film1);


yukar�daki fonksiyon cag�r�s�nda,fonksiyona g�nderilen film1 karakteri arg degiskene kopyalan�r.fonksiyon i�erisinde arg degiskenine kopyalan�r.fonksiyon i�erisinde arg degiskeni uzerinde yap�lan degisikliklerden film degiskeni etkilenmez.fonksiyon i�erisinde film bilgisinin yazd�r�ld�g�n� g�rmektesiniz.
t�pk� diger degiskenlerde oldugu gibi yap�lar� parametre alan fonksiyonlar� o yap�n�n bellek adresini parametre alacak sekilde de tasarl�yabiliriz.bu durumda yazacag�m�z fonksiyon yap�n�n bellek adresini tutacak bir isaretci degisken kabul etmelidir.
ornegin asag�daki fonksiyon bu sekilde yaz�lm�st�r.


void filmYazdirReferansY�ntemiyle(struct sinamaFilmi*arg){
	
		printf("---------------------\n");
		printf("referans yontemi:\n");
		printf("------------------------\n");
		printf("film adi:%s\n",arg->ad);
		printf("yonetmen:%s\n",arg->yonetmen);
		printf("yapim Yili:%d\n\n",arg->yapiYili);
	}
	
bu sekilde cal�san fonksiyonlara yapt�g�m�z cagr�lara referans yontemiyle cagr� ad� verilir.bu fonksiyona film yap�s�n�n kendisini degil,adresini g�ndermeliyiz.
asag�daki cagr�daki adres operatoru kullan�m�na dikkat ediniz.

filmYazdirReferansYontemiyle(&film1);


//�� ��E YAPILAR(NESTED STRUCTS)
bu yap� baska bir yap�n�n uye degiskeni olabilir.bu tip yap�lara i� i�e yap�lar(nested structs)ad� verilir.hemen basit bir �rnek ile bu yap�lar� inceleyelim.iki boyutlu duzlemde bir noktay� x ve y koordinat degerleriyle belirleyebiliriz.
boyle bir noktay� asag�daki gibi modelleyebiliriz.

typedef struct{
	int x;
	int y;
}Nokta;

bir daireyi veya cemberi ise;merkezin bulundugu nokta ve yar�cap�n�n uzunlugu ile bilebiliriz.b�yle bir daireyi yap�lar� kullanarak asag�daki sekilde modelleyebiliriz.

typedef struct{
	float yaricap;
	Nokta merkez;
}Daire;

bu durumda Daire isimli yap�n�n 2 uyesi vard�r.ilk uyesi yaricap isimli bir float degiskendir.
ikinci �yesi de merkez isimli ve Nokta tipinde bir yap�d�r.
bu noktada Daire yap�s� i�in i� i�e yap�(nested struct)adland�r�lmas� yapabiliriz.

Daire yap�s� tipinde Daire ismindeki bir degiskeni asag�daki gibi tan�mlayabiliriz ve uyelerine de asagidaki gibi erisebiliriz.

Daire daire�
daire.yaricap=3.5;
daire.merkez.x=4.0;
daire.merkez.y=5.2;

yukar�da ilk �nce daire isimli bir degisken olusturuyoruz.bu degiskenin yaricap isimli uyesinde nokta operatoruyle erisiyoruz.
dairenin diger uyesi olan merkez isimli uye degisken Nokta tipinde oldugu i�in ilk once daire.merkez ile dairenin merkez isimli uye degiskenine ulas�yoruz.
daha sonra bu �ye degisken �zerinden daire.merkez.x ve daire.merkez.y ifadeleriyle Nokta tipindeki merkez isimli uye degiskeninin x ve y isimli �yelerine deger atam�s oluyoruz.

//YUKARIDAK� KOD

Yukar�daki programda hem i� i�e yap�lar�n bir kullan�m�n� g�rmekteyiz hem
de yap�lar� parametre olarak alan fonksiyonlar�n bir kullan�m�n� g�rmekteyiz
Programda ilk �nce Daire tipinde bir de�i�ken olu�turulmu� ve daha sonra bu
de�i�kenin bilgileri kullan�c�dan okunmu�tur. Kullan�c� t�m bilgilerini girdikten
sonra daire_bilgisi yazdir isimli fonksiyona �a�r� yap�lm��t�r. Bu fonksiyon
i�erisinde dairenin ilk �nce �evre ve alan bilgileri hesaplanm�� daha sonra da
dairenin bilgileriyle birlikte �evresi ve alan�n�n bilgileri ekrana yazd�r�lm��t�r.
Program�n ��kt�s� a�a��da verilmi�tir:
	
	PROGRAM CIKTISI
dairenin merkezinin x koordinat�n� giriniz:5.2
dairenin merkezinin y koord�natini giriniz:6.7
dairenin yaricap uzunlugunu giriniz:15

[DA�REN�N B�LG�LER�]
dairenin merkez koord�natlar�(x,y):(5.20,6.70)
daire yaricapi:15.00
daire cevresi:94.20
daire alan�:706.50

	
