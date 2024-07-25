#include <stdio.h>
#include <string.h>

//struct sinamafilmi diye bir struct olustururuz
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
};
//structtan sonra int main tanýmlanýr
int main(int argc,const char * argv[]){
	//struct sinamaFilmi'ne film ismi atanýr
	//film isimli struct degiskeni olusturalým
	struct sinamaFilmi film;
	//film degiskenin uyelerine deger atýyalým
	//film.ad degiskenine String atanýr
	strcpy(film.ad,"batman begýns");
	//film.yonetmen degiskenine String ifadesi atanýr
	strcpy(film.yonetmen,"christopher nolan");
	//film.yapimYili degiskenine 2005 sayisi atanýr
	film.yapimYili=2005;
	//film adresini filmPtr'a kopyala
	//film isimli structýmýzýn adresi filmPtr pointerýna atanýr
	struct sinamaFilmi *filmPtr=&film;
	
	//atadýgýmýz degerleri yazdýralým
	printf("film adi:%s\n",(*filmPtr).ad);
	printf("yonetmen:%s\n",filmPtr->yonetmen);
	printf("Yapim yili:%d\n",filmPtr->yapimYili);
	
	return 0;
}
//output:
film adi:batman beg²ns
yonetmen:christopher nolan
Yapim yili:2005
----------------------------------------------------------------

	
	//YAPILARA DEKLARASYON SIRASINDA ÝLK DEGER ATAMA
	yukarýdaki structOrnek isimli ornegimizde film1 degiskenimizi önce olusturduk.daha sonra bu degiskene strcpy vb. fonksiyonlar aracýlýgýyla deger atadýk.böyle bir kullanýma,kullanýcýdan deger okundugu durumlarda 
	ihtiyac duyulsa da basýt kullanýmlar için yapýlara deklarasyon sýrasýnda da deger atamamýz mümkündür.
	örnegin:yukarýdaki örnekte bulunan sinamaFilmi yapýsýna tanýmlama esnasýnda ilk deger atamak(initialize)için asagýdaki gibi bir ifadeden faydalanabiliriz.
	
	struct sinamaFilmi film2={"seven","david fincher",1995};
	
	bu ifade yapýnýn her bir uyesine sýrasýyla deger atanmasýný saglar
	yukarýdaki ifadeden sonra film2 yapýsnýn ad üyesi seven degerine sahip olur.benzer sekilde yonetmen uyesinin degeri "david fincher" olur.yapimYili uyesinin degeri de 1995 olur.
	
	//YAPILARIN ÝSARETCILER ARACILIGI ÝLE KULLANIMI(STRUCT POÝNTERS)
	structlar aracýlýgý ile kendi olusturdugumuz veri tipleri için de isaretci tanýmlýyabilir.bu isaretciler aracýlýgý ile dinamik bellek yönetimi yapabilir ve kendi veri tiplerimizi manipule edebiliriz.
	bu kýsýmda örnek bir struct üzerinde  isaretci kullanýmýný ve dinamik bellek ayýrma yöntemlerinin strcut'lar üzerinde uygulanamsýný inceleyecegiz.
	
	hatýrlarsanýz bir int isaretcisi su sekilde tanýmlanýyordu.
	
	int *sayi;
	
	benzer sekilde bir önceki örnegimizde verilen sinamaFilmi yapýsý için isaret eden bir isaretci degisken asagidaki gibi tanýmlanabilir.
	
	struct sinamaFilmi *filmPtr;
	
	bu ifadeyle struct sinamaFilmi tipinde tanýmlanmýs degiskenlere isaret eden film ptr isimli bir isaretci degisken tanýmlanmaktadýr.bu isaretci degiskeni tanýmladýktan sonra,herhangi bir sinamaFilmi structýnýn bellek adresini bu isaretci degiskene asagýdaki gibi kopyalýyabiliyoruz.
	
	filmPtr=&film1;
	
	asagýdaki kod parcasýnda bir önceki örnekten farklý olarak sinamaFilmi yapsýna degisken adýyla degil isaretci aracýlýgý ile erismek istiyoruz.bunu yapabilmek için normal isaretciler için kullandýgýmýz erisim operatoru * ile birlikte nokta notasyonunu kullanmamýz gerekmektedir.
	örnegin filmPtr isaretci degiskenimiz aracýlýgý ile bellek alanýndaki uye degisken degerlerine ulasabilmek için asagýdaki ifadelere ihtiyac duyulur
	
	(*filmPtr).ad;
	(filmPtr).yonetmen;
	(*filmPtr).yapimYili;
	
	yukarýdaki ilk ifade bize sunu söyler filmPtr isimli degiskende depolanan bellek adresine git ve bu adresteki ad uye degiskenini bize getir.
	diger ifadeler de benzer sekilde diger uye degiskenlere erisirler.Parantez,yýldýz ve noktadan olusan bu notasyonu kullanmak uygulama gelistiricilere zor geldigi için sonradan c programlama diline yukarýdaki ifadelerle ayný iþi yapan bir baska notasyon eklenmistir.	
	
	filmPtr->ad;
	filmPtr->yonetmen;
	filmPtr->yapimYili;
	
	bir baska deyisle asagýdaki iki ifade birbirinin aynýsýdýr.
	(*filmPtr).ad;
	filmPtr->ad;
	
	yazdýgýnýz programlarda,struct isaretcilerinin referans gösterdikleri bellek alanýnda,uye degiskenlere erisim saglamak için her iki notasyonu da kullanabilirsiniz.
	hemen bu kullanýmý gösteren bir örnek verelim.
	
	-YUKARIDAKÝ KOD
	
	
	program içerisinde filmPtr isimli bir isaretci olusturulmus ve bu isaretciye film isimli bir struct degiskeninin adresi kopyalanmýstýr.bu noktadan sonra film degiskeninin içerigine filmPtr isaretcisi ve erisim operatorunu kullanarak dolaylý yoldan erisebiliriz.
	bu erisimin örneklerini yukarýdaki printf ifadeleri içerisinde görebilmektesiniz.
	
	PROGRAM CIKTISI
	FÝLM ADÝ:BATMAN begins
	yonetmen:christopher nolan
	yapým yili:2005
	

