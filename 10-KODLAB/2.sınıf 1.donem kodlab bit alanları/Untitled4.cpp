//ORTAKLIKLAR(UNÝONS)
hatýrlarsanýz yapýlar(structs)farklý tipteki belli degiskenleri gruplayarak bir paket haline getiriyorlardý.paket içerisindeki her bir degiskenin kendine has bir bellek alaný oluyordu.

ortaklýklar ise tanýmlama itibariyle yapýlara cok benzeseler de cok onemli bir farklarý vardýr.

union deyimiyle tanýmlanan paketlerde her degisken ortak bellek alanýný kullanýr.(adý da buradan gelmektedir.)

asagida Sayi takma adlý bir (typedef) bir ortaklýk tanýmlanmýstýr.

typedef union{
	int intSayi;
	float FloatSayi;
}Sayi;

bu ortaklýgý asagýdaki sekilde kullanabiliriz.

Sayi sayi;
sayi.intSayi=0;

printf("sayi.intSayi=%d\n",sayi.intSayi);

bir ortaklýkta bir uye degiskene deger atadýgýnýzda diger uye degiskenlerin degeri bozulur.Cünkü hepsi ortak bellek alanlarýný kullanmaktadýrlar.
Bu sebeple belli bir uye degiskene deger atadýktan sonra diger degiskenlere erismekten kacýnýnýz.

asagýdaki bu durumu gösteren örnek bir program verilmistir.

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

yukarýdaki programda sayi tipinde sayi isimli bir ortaklýk tanýmlanmýstýr.bu ortaklýgýn iki üyesi vardýr.ilk üyesi intSayi isimli tam sayýdýr.ikinci uyesi de floatSayi isimli bir noktalý sayýdýr.
program içerisinde önce sayi isimli ortaklýk degiskeninin intSayi degiskenine deger atanmýstýr.daha sonra da floatSayi degiskenin deger atanmýstýr.

her iki deger atama islemi sonrasýnda da her iki üye degiskenin degeri printf aracýlýgýyla yazdýrýlmýstýr.

deger atama islemleri sonrasýnda diger uye degiskene deger atanmamasýna ragmen bu degiskenin de degerinin de degistigini görebilirsiniz.

Program Cýktýsý

sayi.intSayi=0
sayi.floatSayi=0.000000
sayi.intSayi=1078523331
sayi.floatSayi=3.140000

*bir ortaklýgýn genisligi o ortaklýktaki en fazla alan kaplayan üye degiskenin genisligi kadardýr.örnegin bir ortaklýkta içerisinde bir adet char ve bir adet double degisken olsaydý ortaklýgýmýzýn genisligi double degiskenin bellekte kapladýgý yer kadar(8 bayt)olacaktý.

ortaklýklarýn kullaným alanlarý oldukca kýsýtlýdýr.ayný bellek alanýnda farklý tipten degiskenler tanýmlamak için kullanmak en yaygýn kullanýmlarýndan biridir.

bu sayede elemanlarý farklý tipte degiskenlerden olusan diziler olusturup kullanmak mümkündür.
bu kullanýmlardan bir tanesi bolum sonu sorularýnca incelenmistir.
bolum sonu sorularýnda verilen UnionOrnek2 isimli uygulamayý incelemenizi öneririm.
