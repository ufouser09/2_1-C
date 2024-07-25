#include <stdio.h>
#include <string.h>
//struct sinamafilmi diye bir struct olustururuz
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
};
//structtan sonra int main gelir
int main(int argc,const char *argv[]){
	//filmler isimli bir struct dizisi olusturalým
	//struct sinamafilmi structýna filmler diye isim verirsin 
	struct sinamaFilmi filmler[2]={{"seven","david fincher",1995},{"snatch","guy ritche",2000}
};
	
	
	printf("\n[FILM LISTESINDEKÝ ELEMANLAR]\n\n");
	printf("film adi:%s\n",filmler[0].ad);
	printf("yonetmen:%s\n",filmler[0].yonetmen);
	printf("yapým yýlý:%d\n",filmler[0].yapimYili);
	
	printf("\n");
	
	printf("film Adi:%s\n",filmler[1].ad);
	printf("yonetmen:%s\n",filmler[1].yonetmen);
	printf("yapim yili:%d\n",filmler[1].yapimYili);
	
	return 0;
}
/*
[FILM LISTESINDEK¦ ELEMANLAR]

film adi:seven
yonetmen:david fincher
yap²m y²l²:1995

film Adi:snatch
yonetmen:guy ritche
yapim yili:2000
*/
--------------------------------------------------------------------------------
//YAPILARIN DiZÝLERLE BÝRLÝKTE KULLANIMI
bir yapýyý tanýmladýktan sonra o yapýnýn normal bir veri tipinden hicbir farký yoktur.
fonksiyonlara parametre olarak gönderebilir veya o icerigi o yapýnýn tipinde elemanlar olan diziler tanýmlýyabiliriz.
asagýda

struct sinamaFilmi isimli yapýdan iki elemanlý bir dizi olusturan,
bu dizinin elemanlarýna diziyi tanýmlama esnasýnda ilk deger atayan ve 
dizinin içerigini konsola yazdýran kucuk bir örnek uygulama verilmistir.
-
-
-
-YUKARIDAKÝ KOD
-
-
-
uygulama içerigini inceleyecek olursanýz 2 elemanlý bir dizinin olusturuldugunu görebilirsiniz.deger atama isleminin tanýmlama esnasýnda yapýldýgýnýn görebilirsiniz.bir struct elemanýna ilk deger atamaya benzer
tek farký dizideki her bir eleman için ilk degerin virguller ile ayrýlmasýdýr.

dizinin her bir elemanýnýn tipi struct sinamaFilmi tipindedir.
boyle bir deklarasyon yaptýgýnýzda dizideki ikinci elemanýnýn ad uyesine ulasabilmek için asagýdaki gibi bir ifade kullanmalýsýnýz.

filmler[1].ad;

yukarýdaki dizinin her iki elemaný için elemanlarýn aldýgý degerler printf fonksiyonlarý aracýlýgýyla konsola yazdýrýlmýstýr.
programýn cýktýsý asagýda verilmistir.

//PROGRAM CIKTISI
[FÝLM LÝSTESÝNDEKÝ ELEMANLAR]
film adi:SEVEN
yonetmen:david fincher
yapým yili:1995

film adi:snatch 
yonetmen :guy ritchie
Yapim Yili:2000



