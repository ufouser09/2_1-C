#include <stdio.h>
#include <string.h>
//struct sinama filmi diye bir struct olusturuyoruz
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
};
//structlardan sonra int main tanýmlýyoruz
int main(int argc,const char * argv[]){
	//struct sinamafilmi structýna film1 ismini veriyoruz
	//film1 isimli struct degiskeni olusturalým
	struct sinamaFilmi film1;
	
	//film1 degiskenin uyelerine deger atýyalým
	//film1.ad diyerek o structýn degerine ulasýrýz
	strcpy(film1.ad,"Collateral");
	//film1.yönetmen ile structa ulasabiliriz
	strcpy(film1.yonetmen,"micheal mann");
	//film1.yapimYili degiskenine 2004 sayýsýný atarýz
	film1.yapimYili=2004;
	//atadýgýmýz degerleri yazdýralým
	//structtaki ad yönetmen ve yapim yili degiskenlerini yazdiririz
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
c programlama dili daha önceden tanýmlanmýs veri tiplerini bir araya getirerek kendi veri tiplerimizi olusturmamýza izin verir.örnegin bir film verisi modellediginizi dusunelim.
her bir filmin kendine ait bir adý,yonetmeni ve yapým yýlý bulunur.c programlama dili bu verileri gruplayýp tek bir noktadan erisebilmemizi saglayan struct isimli bir yapý icermektedir

örnegin az once bahsettigimiz 3 adet degiskenden olusan bir sýnama filmini asagýdaki gibi olusturabiliriz.

struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapýmYili;
};
yukarýda tanýmda sinamaFilmi isimli bir yapý (struct)olusturuyoruz.bu yapýnýn 3 adet uye degiskeni bulunuyor.bu üye degiskenlerden ilki olan ad dizisi sinama filminin adýný tutmak için tasarlanmýs ve en fazla 100 karaktere kadar bilgi içerebilecek sekilde tasarlanmýstýr.
benzer sekilde yonetmen bilgisini tutabilmek için de 50 karaktere kadar veri içeren yonetmen isimli bir karakter dizisi olusturulmustur.
yapýmýz son olarak filmin yapým yýlýna yapýmYili isimli bir tam sayi degisken içeriyor


**bir yapý içerisinde bulunan butun degiskenlere uye degisken (member variable)adý verilir.örnegin yapýmYili degiskeni sýnamaFilmi yapýsýnýn bir üyesidir.üye ifadesini kýtabin ilerleyen bolumlerinde kullanýcagým.
yukarýdaki yapýyý programýmýzýn basýnda tanýmladýktan sonra bu yapý artýk bizim için yeni bir veri tipidir.
bu veri tipini týpký int veya float gibi kullanýlabilir ve yeni degiskenler olusturabiliriz.
yukarýdaki yapýyý kullanarak kod içerisinde film1 isimli bir degiskeni deklare eden kod satýrý asagýdaki gibi olabilir.

struct sinamaFilmi film1;

yukarýdaki gibi bir deklarasyon sonrasýnda struct SinamaFilmi için bellek alaný olusturulur.
boyle bir deklarasyon olmadan struct sinamaFilmi ifadesini int ve float gibi bir veri tipi olarak dusunebilirsiniz.
tek farký bu ifadenin bu tipin kendi olusturdugumuz bir veri tipi olmasýdýr.



**yukarýdaki deklarasyonda film1 isimli degiskenin tipi sinamaFilmi degildir.
degiskenin tipini struct sinamaFilmi olarak dusununuz.degiskeni tanýmlýyabilmek için her defasýnda struct anahtar kelimesini kullanmalýsýnýz.bu anahtar kelimeyi kullanmamak için typedef ifedesi aracýlýgý ile 
belli bir yapýya takma ad verebilmemiz mumkundur.
bu yapýnýn kullanýmýný bolum icersinde ilerleyen kýsýmlarda inceleyecegiz.


bu deklarasyon sonrasi film1 degiskenin içinde ad,yonetmen ve yapýmYili bilgisi bizim için otomatik olarak olusturulmaktadýr.
bu bilgilere erismek için nokta notasyonunu(dot notation) kullanabiliriz

film1.ad
film1.yonetmen
film1.yapýmYili

yukarýda nokta notasyonunun kullanýmý görülmektedir.
ilk kullaným film1 degiskeninin ad uyesine erisir
ikinci kullaným yonetmen,ücüncü kullaným ise yapimYili üyesine erisir.
asagýdaki programda sinamaFilmi yapýsýnýn bir kullanýmý incelenmistir.


///yukarýdaki kodumuz var burda

yukarýdaki program kodunu inceledigimizde film1 isimli 1 adet yapý olusturdugumuzu ve bu yapýnýn uye degiskenlerine nokta notasyonu kullanarak deger atadýgýmýzý görebilirsiniz.
sinamaFilmi yapýsýnýn ad ve yonetmen uye degiskenleri karakter dizisi oldugu için bu elemanlar deger atama islemini karakter dizileri bolumde inceledigimiz strcpy fonksiyonunu kullanarak gerceklestirdik.
örnegin asagidaki ifade:
	strcpy(film1.ad,"collateral");
	
**film1 yapýsýnýn ad degiskenine collateral degerini kopyalamktadýr.
**benzer sekilde yönetmen bilgisine de yonetmen uye degiskeni kullanýlarak deger atanýr.

	
	srtcpy(film1.yonetmen,"micheal jordan");
	//en son olarak 
	film1.yapimYili=2004;
	
	ifadesiyle film1 yapýsýnýn yapimYili uye degiskenine 2004 degeri atanýr.
	daha sonra bu degerler printf fonksiyonu aracýlýgý ile konsola yazdýrýlýr.
	program çýktýsý asagýdaki gibidir.
	
	//PROGRAM CIKTISI
	
	Film adi:Collateral
	yonetmen :micheal mann
	yapim Yili:2004
	
	structlarý kendi veri yapýlarýmýzý olusturmak için kullanýrýz.üniversitelerde gösterilen veri yapýlarý ve algoritmalar dersinin c programlama dili üzerindeki uygulamalarý yogun bir sekilde struct kullanýmý içerir.
	Stack(yýgýn),Queue(kuyruk),Tree(agac),Lýnked list(baglantýlý liste) gibi veri yapýlarýnýn tamamýnda struct benzeri yapýlar kullanýlýr.kitabýn ilerleyen bolumlerinde bu veri yapýlarýnýn bazý uygulamalarýný görecegiz.
	
