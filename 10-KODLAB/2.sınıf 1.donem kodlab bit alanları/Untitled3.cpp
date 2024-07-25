//BÝTFÝELDSORNEK2-main.c
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
Yukarýdaki örnekte DordeKadar takma adý verilmiþ bir struct tanýmlanmýþtýr.
Bu struct'in içindeki sayi deðiþkeni 2 bit kaplayacak þekilde tasarlanmýþtýr.
Dolayýsýyla sayi deðiþkeni sadece 0, 1, 2 ve 3 deðerlerini alabilir. Çünkü
2 bit'de maksimum bu deðerler tanýmlanabilir. Bir döngü içerisinde sayi
deðiþkenine o'dan s'e kadar deðer atandýðýnda atanan deðer 4'ten küçük
olduðu sürece sorun yaþanmaz. Fakat deðer 4 veya 4'ten büyükse her bir deðer
alan geniþliðine uygun oluncaya kadar o deðerden alan geniþliði çýkarýlacaktýr.
Yukarýdaki programýn çýktýsý aþaðýdaki gibi olur:
	
	PROGRAM CIKTISI
	0
	1
	2
	3
	0
	1
	2
	3
	
	BITFIELD KULLANIMINDAKÝ KISITLAMALAR
. Kisit 1: Bitler kullanýlarak oluþturulan bir alanýnýn herhangi bir üyesi üzerinde
çalýþýr. Bu sebeple bit uzunluðunu elde edemezsiniz.
sizeof operatörünü kullanmayýnýz. Bu operatör sadece bayt'lar üzerinde
. Kisit 2: Bitfield içerisindeki bir deðiþken üzerinde, adres operatörü
kullanamazsýnýz. Ýþletim sistemleri bayt bazýnda adresleme yapar. Bit bazýnda
adresleme yapýlamadýðý için belli bir bit'in bellekte hangi adrese karþýlýk
geldiðini adres (&) operatörüyle elde edemezsiniz.


Kisit 3: Ikinci kisit sebebiyle bir bitfield'in deðerini scant içerisinde
okuyamazsýnýz. scanf fonksiyonu adres operatörünün kullanýmýný gerektin
Dolayýsýyla bitfield için kullanýcýdan deðer okuyacaðýnýzda ilk önce bu
deðeri normal bir deðiþkene okumanýz daha sonrasýnda ilgili bitfield alanina
kopyalamanýz gerekmektedir.
to
//NUMARALANDIRMA (ENUMERATION) KAVRAMI
Programlama dillerinin çok büyük bir kýsmýnda bulunan enumeration
(numaralandýrma) kavrami programlama esnasýnda kendi belirlediðimiz bazý
deðerleri daha okunabilir kilmak için sýklýkla kullanýlan bir yöntemdir.

Örneðin; birçok sayýda kullanýcýya hitap eden bir uygulama yazdýðýnýzý
düþünelim.

 Her bir kullanýcýnýn da çeþitli yetki seviyeleri olsun. Bu yetki
seviyelerinin de tam sayý karþýlýklar olsun. On binlerce satýrdan oluþan kod
içerisinde uygulamanýzýn bazý bölümlerine sadece admin yetki seviyesindeki
kullanýcýlarýn eriþebileceði diðer kullanýcýlarýn ise eriþemeyeceðini varsayalým.
Örneðin; admin kullanýcýsýnýn yetki seviyesinin tam sayý karþýlýðý da 4
olsun. Uygulama büyüdükçe ve yetki seviyeleri çeþitlendikçe bu yetki
seviyelerinin tam sayý deðerlerini hatýrlamak zorlaþacaktýr
. Hele uygulama
geliþtirmeyi tamamladýktan sonra sizden sonra kodu okuyan birisi 4 deðeriyle
karþýlaþtýðýnda, bu deðer ona hiçbir anlam ifade etmeyecektir.
iþte enumeration yapýsý bu noktada bize oldukça güzel bir çözüm
sunmaktadýr. Program içinde sýklýkla kullandýðýmýz ve karþýlýk gelen deðerleri
kendimiz belirlediðimiz özel veri tiplerini enum'lar aracýlýðýyla tanýmlayabiliriz.
Her bir deðere anlaþýlýr isimler verebilir ve program içerisinde sayýsal deðerler
üzerinden deðil de ismini kendimizin belirlediði anlaþýlabilir isimler aracýlýðýyla
iþlemlerimizi gerçekleþtirebiliriz.
C programlama dilindeki enum yapýsýnýn amacý da budur. Enum yapýsýna örnek
olarak aþaðýdaki programý verebiliriz. Bu programda Kullanýcý Seviyeleri
isimli özel bir enum yapýsý kullanýlmýþtýr. Bu enum yapýsýnda her bir kullanýcý
seviyesine akýlda kalýr bir isim verilmiþtir. Enum tanýmlamasýný yaptýktan sonra
menum KullaniciSeviyeleri kelime grubunu artýk yeni bir veri tipiymiþ gibi
düþünebiliriz.


Program içinde bu tipe sahip seviye isimli bir deðiþken tanýmlayarak, bu
deðiþkenin deðerinin kullanýcý tarafýndan girilmesini saðladýk. Daha sonra
girilen bu deðerin neye karþýlýk geldiðini bir switch ifadesi içerisinde bulmaya
çalýþtýk. switch ifadesi içinde tam sayý deðerler yerine enum tanýmýnda
belirlediðimiz kolay anlaþýlabilir isimleri kullandýk.
nina
MI
ion
azi
Bu program küçük bir uygulama olduðu için tanýmladýðýnýz enum tipinin ne
gibi bir kolaylýk saðladýðýný kolayca göremiyor olabilirsiniz. Fakat yazdýðýnýz
uygulamada satýr sayýsý arttýðýnda ve yazdýðýnýz kodu tekrardan gözden
geçirmek istediðinizde sayýsal deðerler yerine anlamlý ifadelerle karþýlaþmanýn
size oldukça zaman kazandýracaðýndan emin olabilirsiniz. Aþaðýda enum
yapýsýyla ilgili programýn tamamýný bulabilirsiniz:
	
#include <stdio.h>
int main(int argc,const char * argv[]){
	enum KullaniciSeviyeleri{
		misafir=1,
		ogrenci=2,
		akademisyen=3,
		admin=4,
	};
	enum KullaniciSeviyeleri seviye;
	printf("kullanýcýnýn yetki seviyesini 1,4 arasinda giriniz:");
	scanf("%d",&seviye);
	
	switch(seviye){
		case misafir:
			printf("yetki seviyesi misafir\n");
			break;
			case ogrenci:
				printf("yetki seviyesi ögrenci\n");
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
kullanýcýnýn yetki seviyesini 1,4 arasinda giriniz:15
girdiginiz deger gecersiz
kullanýcýnýn yetki seviyesini 1,4 arasinda giriniz:3
yetki seviyesi akademisyen


tum enum degiskenler sayisal(tam sayi)degerler alýrlar.eger enum degiskenlere deger vermezseniz bu degerler derleyici tarafýndan sýfýrdan baslayarak artacak sekilde verilir.yani yukarýdaki örnekteki veri tipimiz

enum KullaniciSeviyeleri{
	misafir,
	ogrenci,
	akademisyen,
	admin
};	
seklinde tanýmlanmýs olsaydýk misafir degerine derleyici tarafýndan otomatik olarak 0 degeri verilecekti.ayný sekilde ogrenci degerinin karsýlýgý 1,akademisyen degerinin karsýlýgý 2 ve admin degerinin karsýlýgý 3 olacaktý.
 
	
	
