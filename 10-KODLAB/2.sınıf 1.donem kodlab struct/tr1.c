#include <stdio.h>
#include <string.h>
//struct sinama filmi diye bir struct olusturuyoruz
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
};
//structlardan sonra int main tan�ml�yoruz
int main(int argc,const char * argv[]){
	//struct sinamafilmi struct�na film1 ismini veriyoruz
	//film1 isimli struct degiskeni olustural�m
	struct sinamaFilmi film1;
	
	//film1 degiskenin uyelerine deger at�yal�m
	//film1.ad diyerek o struct�n degerine ulas�r�z
	strcpy(film1.ad,"Collateral");
	//film1.y�netmen ile structa ulasabiliriz
	strcpy(film1.yonetmen,"micheal mann");
	//film1.yapimYili degiskenine 2004 say�s�n� atar�z
	film1.yapimYili=2004;
	//atad�g�m�z degerleri yazd�ral�m
	//structtaki ad y�netmen ve yapim yili degiskenlerini yazdiririz
	printf("film adi:%s\n",film1.ad);
	printf("yonetmen:%s\n",film1.yonetmen);
	printf("yapim yili:%d\n",film1.yapimYili);
	
	return 0;
}
/*
film adi:Collateral
yonetmen:micheal mann
yapim yili:2004

*/
//YAPILAR (STRUCTS)
c programlama dili daha �nceden tan�mlanm�s veri tiplerini bir araya getirerek kendi veri tiplerimizi olusturmam�za izin verir.�rnegin bir film verisi modellediginizi dusunelim.
her bir filmin kendine ait bir ad�,yonetmeni ve yap�m y�l� bulunur.c programlama dili bu verileri gruplay�p tek bir noktadan erisebilmemizi saglayan struct isimli bir yap� icermektedir

�rnegin az once bahsettigimiz 3 adet degiskenden olusan bir s�nama filmini asag�daki gibi olusturabiliriz.

struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yap�mYili;
};
yukar�da tan�mda sinamaFilmi isimli bir yap� (struct)olusturuyoruz.bu yap�n�n 3 adet uye degiskeni bulunuyor.bu �ye degiskenlerden ilki olan ad dizisi sinama filminin ad�n� tutmak i�in tasarlanm�s ve en fazla 100 karaktere kadar bilgi i�erebilecek sekilde tasarlanm�st�r.
benzer sekilde yonetmen bilgisini tutabilmek i�in de 50 karaktere kadar veri i�eren yonetmen isimli bir karakter dizisi olusturulmustur.
yap�m�z son olarak filmin yap�m y�l�na yap�mYili isimli bir tam sayi degisken i�eriyor


**bir yap� i�erisinde bulunan butun degiskenlere uye degisken (member variable)ad� verilir.�rnegin yap�mYili degiskeni s�namaFilmi yap�s�n�n bir �yesidir.�ye ifadesini k�tabin ilerleyen bolumlerinde kullan�cag�m.
yukar�daki yap�y� program�m�z�n bas�nda tan�mlad�ktan sonra bu yap� art�k bizim i�in yeni bir veri tipidir.
bu veri tipini t�pk� int veya float gibi kullan�labilir ve yeni degiskenler olusturabiliriz.
yukar�daki yap�y� kullanarak kod i�erisinde film1 isimli bir degiskeni deklare eden kod sat�r� asag�daki gibi olabilir.

struct sinamaFilmi film1;

yukar�daki gibi bir deklarasyon sonras�nda struct SinamaFilmi i�in bellek alan� olusturulur.
boyle bir deklarasyon olmadan struct sinamaFilmi ifadesini int ve float gibi bir veri tipi olarak dusunebilirsiniz.
tek fark� bu ifadenin bu tipin kendi olusturdugumuz bir veri tipi olmas�d�r.



**yukar�daki deklarasyonda film1 isimli degiskenin tipi sinamaFilmi degildir.
degiskenin tipini struct sinamaFilmi olarak dusununuz.degiskeni tan�ml�yabilmek i�in her defas�nda struct anahtar kelimesini kullanmal�s�n�z.bu anahtar kelimeyi kullanmamak i�in typedef ifedesi arac�l�g� ile 
belli bir yap�ya takma ad verebilmemiz mumkundur.
bu yap�n�n kullan�m�n� bolum icersinde ilerleyen k�s�mlarda inceleyecegiz.


bu deklarasyon sonrasi film1 degiskenin i�inde ad,yonetmen ve yap�mYili bilgisi bizim i�in otomatik olarak olusturulmaktad�r.
bu bilgilere erismek i�in nokta notasyonunu(dot notation) kullanabiliriz

film1.ad
film1.yonetmen
film1.yap�mYili

yukar�da nokta notasyonunun kullan�m� g�r�lmektedir.
ilk kullan�m film1 degiskeninin ad uyesine erisir
ikinci kullan�m yonetmen,�c�nc� kullan�m ise yapimYili �yesine erisir.
asag�daki programda sinamaFilmi yap�s�n�n bir kullan�m� incelenmistir.


///yukar�daki kodumuz var burda

yukar�daki program kodunu inceledigimizde film1 isimli 1 adet yap� olusturdugumuzu ve bu yap�n�n uye degiskenlerine nokta notasyonu kullanarak deger atad�g�m�z� g�rebilirsiniz.
sinamaFilmi yap�s�n�n ad ve yonetmen uye degiskenleri karakter dizisi oldugu i�in bu elemanlar deger atama islemini karakter dizileri bolumde inceledigimiz strcpy fonksiyonunu kullanarak gerceklestirdik.
�rnegin asagidaki ifade:
	strcpy(film1.ad,"collateral");
	
**film1 yap�s�n�n ad degiskenine collateral degerini kopyalamktad�r.
**benzer sekilde y�netmen bilgisine de yonetmen uye degiskeni kullan�larak deger atan�r.

	
	srtcpy(film1.yonetmen,"micheal jordan");
	//en son olarak 
	film1.yapimYili=2004;
	
	ifadesiyle film1 yap�s�n�n yapimYili uye degiskenine 2004 degeri atan�r.
	daha sonra bu degerler printf fonksiyonu arac�l�g� ile konsola yazd�r�l�r.
	program ��kt�s� asag�daki gibidir.
	
	//PROGRAM CIKTISI
	
	Film adi:Collateral
	yonetmen :micheal mann
	yapim Yili:2004
	
	structlar� kendi veri yap�lar�m�z� olusturmak i�in kullan�r�z.�niversitelerde g�sterilen veri yap�lar� ve algoritmalar dersinin c programlama dili �zerindeki uygulamalar� yogun bir sekilde struct kullan�m� i�erir.
	Stack(y�g�n),Queue(kuyruk),Tree(agac),L�nked list(baglant�l� liste) gibi veri yap�lar�n�n tamam�nda struct benzeri yap�lar kullan�l�r.kitab�n ilerleyen bolumlerinde bu veri yap�lar�n�n baz� uygulamalar�n� g�recegiz.
	
