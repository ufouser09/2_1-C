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
	//struct sinamafilmi structýna *filmptr diye bir isim verilir
	//struct sinamaFilmi için filmPtr isimli bir isaretci olusturalým
	struct sinamaFilmi *filmPtr;
	//isaretci için bellekten yer ayýralým
	//filmPtr pointeri için bellekte yer ayýrýrýz
	filmPtr=(struct sinamaFilmi *)malloc(sizeof(struct sinamaFilmi));
	//(*filmPtr).ad diye ulasabiliriz)
	//filmPtr aracýlýgý ile bellek alanýna ulasýp deger atýyalým
	strcpy((*filmPtr).ad,"departed");
	//ya da (filmPtr->yonetmen diyip erisebiliriz
	strcpy(filmPtr->yonetmen,"martin scorsese");
	//FilmPtr->yapimYili diyip 2006 degerini degiskene atarýz
	filmPtr->yapimYili=2006;
	//atadýgýmýz degerleri yazdýralým
	//(*filmPtr).ad degerini yazdýrýrýz
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
//YAPILAR VE DÝNAMÝK BELLEK FONKSÝYONLARI
yapýlarla birlikte dinamik bellek ayýrma fonksiyonlarýný da kullanbiliriz.
asagýdaki örnekte ise;filmPtr isaretcisinin isaret edecegi struct sinamaFilmi yapýsý için bellekten dinamik olarak yer ayrýlmýstýr.
bu islemi gerceklestiren satýr asagýda verilmistir.

struct sinamaFilmi *filmPtr;
filmPtr=(struct sinamaFilmi *)malloc(sizeof(struct sinamaFilmi));

yukarýdaki yapýnýn int tipinden isaretciler için bellek ayýrma islemine ne kadar benzedigini görebilirsiniz.
tek fark bu örnekte int için degil struct sinamaFilmi için bellekten yer ayrýlmasýdýr.

sizeof(struct sinamaFilmi)ifadesi sinamaFilmi yapýsýnýn bellekten ne kadar alan kapladýgýný dondurur.
eger elle bir hesap yaparsak 100 karakterlik ad üye degisken için 100 bayt,50 karakterlik yonetmen üye degiskeni için 50 bayt ve int tipindeki yapimYili degiskeni için 4 bayt olmak üzere bellekten toplamda 154 baytlýk yer ayrýlmaktadýr.
sinamaFilmi yapýsnýn bellekteki görüntüsü asagýdaki resýmdeki gibidir.

-REsim

bir yapýyý olusturduktan sonra onun bellekte kapladýgý alan sabittir.bu alaný degistiremezsiniz.yukarýdaki struct her zaman 154 byte yer kaplayacaktýr.eger struct uyelerini degisken uzunluklarda tanýmlamak istiyorsanýz(örnegin:her yonetmen dizisinin uzunlugu yonetmenin adýnýn uzunlugu kadar olsun diyorsanýz)yapý uyelerini isaretci olarak tanýmlayýnýz.bu kullanýmý veri yapýlarý bolumunde görecegiz.

bu ayrýlan alanýn baslangýc adresi filmPtr isimli isaretci degiskenimize kopyalanmýstýr.
asagýda struct isaretcilerinin kullanýmýný ve dýnamýk bellek ayýrma islemini gösteren uygulama kodumuzun tamamý listelenmistir.
program içerisinde printf ve strcpy fonksiyonlarýnda biraz önce inceledigimiz notasyonlarýn ikisi de kullanýlmýstýr.


-YUKARIDAKÝ KOD

//PROGRAM CIKTISI
film adi:departed
yonetmen:martýn scorsese
Yapim Yili:2006

bu program bir onceki programla temelde ayný seyi yapar.tek farký bu programda isaretci yonteminin kullanýlmasýdýr.
dolayýsýyla programýn cýktýsý bir oncekiyle ayný olacaktýr.
programýn en sonunda free fonksiyonunu kullanarak filmPtr isaretcisinin isaret ettigi bellek alanýný hafizaya iade edilmistir.



