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
//fonksiyonu basta tanýmlarýz
void daire_bilgisi_yazdir(Daire d);

int main(int argc,const char * argv[]){
	//daire structýna daire ismini veririz
	Daire daire;
	//kullanýcýdan dairenin merkez x koordinatlarýný alýrýz
	printf("dairenin merkezinin x koordinatlarini giriniz\n");
	scanf("%f",&daire.merkez.x);
	//kullanýcýdan dairenin merkez y koordinatlarýný alýrýz
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
//YAPILARIN FONKSÝYONLARA PARAMETRE OLARAK GÖNDERÝLMESÝ

Bir yapay bir fonksiyona parametre olarak göndermenin bir tam
sayiyi bir
fonksiyona parametre olarak göndermekten hiçbir farký yoktur. Yapýlar
fonksiyonlara gönderildiklerinde tipki tam sayi deðiþkenler gibi deðerleri
fonksiyon parametresine kopyalanýr (call by value). Bir baþka deyiþle biraz
önce gördüðümüz atama ifadesi çalýþýr. Parametre olarak gönderilen struct,
fonksiyon içerisindeki deðiþiklikten etkilenmez. (call by value'yu hatýrlayalým.)
Bunu daha iyi anlayabilmek için yukarýdaki film örneklerimizdeki yazdýrma
iþlemlerini gerçekleþtirebilecek ayrý bir fonksiyon tanýmlayalým. Bu fonksiyon
kendisine parametre olarak gelen yapýyý alsýn ve deðerini konsola yazdirsin.

void filmYazdirDegerYontemiyle(struct sinamaFilmi arg){
	printf("-------------------------------------\n");
	printf("deger yontemi:\n");
	printf("----------------------------------\n");
	printf("Film adi:%s\n",arg.ad);
	printf("yonetmen:%s\n",arg.yonetmen);
	printf("yapim Yili:%d\n\n",arg.yapimYili);
	
	
	
}
yukarýdaki fonksiyon,bir adet sinamFilmi yapýsýný arguman alacak sekilde tasarlanmýstýr.bu fonksiyonu asagidaki sekilde cagýrdýgýmýzý dusunelim.


struct sinamaFilmi film1;
srtcpy(film1.ad,"burn after readýng");
strcpy(film1.yonetmen,"ethan6john cohen");
film1.yapimYili=2008;

filmYazdirDegerYontemiyle(film1);


yukarýdaki fonksiyon cagýrýsýnda,fonksiyona gönderilen film1 karakteri arg degiskene kopyalanýr.fonksiyon içerisinde arg degiskenine kopyalanýr.fonksiyon içerisinde arg degiskeni uzerinde yapýlan degisikliklerden film degiskeni etkilenmez.fonksiyon içerisinde film bilgisinin yazdýrýldýgýný görmektesiniz.
týpký diger degiskenlerde oldugu gibi yapýlarý parametre alan fonksiyonlarý o yapýnýn bellek adresini parametre alacak sekilde de tasarlýyabiliriz.bu durumda yazacagýmýz fonksiyon yapýnýn bellek adresini tutacak bir isaretci degisken kabul etmelidir.
ornegin asagýdaki fonksiyon bu sekilde yazýlmýstýr.


void filmYazdirReferansYöntemiyle(struct sinamaFilmi*arg){
	
		printf("---------------------\n");
		printf("referans yontemi:\n");
		printf("------------------------\n");
		printf("film adi:%s\n",arg->ad);
		printf("yonetmen:%s\n",arg->yonetmen);
		printf("yapim Yili:%d\n\n",arg->yapiYili);
	}
	
bu sekilde calýsan fonksiyonlara yaptýgýmýz cagrýlara referans yontemiyle cagrý adý verilir.bu fonksiyona film yapýsýnýn kendisini degil,adresini göndermeliyiz.
asagýdaki cagrýdaki adres operatoru kullanýmýna dikkat ediniz.

filmYazdirReferansYontemiyle(&film1);


//ÝÇ ÝÇE YAPILAR(NESTED STRUCTS)
bu yapý baska bir yapýnýn uye degiskeni olabilir.bu tip yapýlara iç içe yapýlar(nested structs)adý verilir.hemen basit bir örnek ile bu yapýlarý inceleyelim.iki boyutlu duzlemde bir noktayý x ve y koordinat degerleriyle belirleyebiliriz.
boyle bir noktayý asagýdaki gibi modelleyebiliriz.

typedef struct{
	int x;
	int y;
}Nokta;

bir daireyi veya cemberi ise;merkezin bulundugu nokta ve yarýcapýnýn uzunlugu ile bilebiliriz.böyle bir daireyi yapýlarý kullanarak asagýdaki sekilde modelleyebiliriz.

typedef struct{
	float yaricap;
	Nokta merkez;
}Daire;

bu durumda Daire isimli yapýnýn 2 uyesi vardýr.ilk uyesi yaricap isimli bir float degiskendir.
ikinci üyesi de merkez isimli ve Nokta tipinde bir yapýdýr.
bu noktada Daire yapýsý için iç içe yapý(nested struct)adlandýrýlmasý yapabiliriz.

Daire yapýsý tipinde Daire ismindeki bir degiskeni asagýdaki gibi tanýmlayabiliriz ve uyelerine de asagidaki gibi erisebiliriz.

Daire daireÝ
daire.yaricap=3.5;
daire.merkez.x=4.0;
daire.merkez.y=5.2;

yukarýda ilk önce daire isimli bir degisken olusturuyoruz.bu degiskenin yaricap isimli uyesinde nokta operatoruyle erisiyoruz.
dairenin diger uyesi olan merkez isimli uye degisken Nokta tipinde oldugu için ilk once daire.merkez ile dairenin merkez isimli uye degiskenine ulasýyoruz.
daha sonra bu üye degisken üzerinden daire.merkez.x ve daire.merkez.y ifadeleriyle Nokta tipindeki merkez isimli uye degiskeninin x ve y isimli üyelerine deger atamýs oluyoruz.

//YUKARIDAKÝ KOD

Yukarýdaki programda hem iç içe yapýlarýn bir kullanýmýný görmekteyiz hem
de yapýlarý parametre olarak alan fonksiyonlarýn bir kullanýmýný görmekteyiz
Programda ilk önce Daire tipinde bir deðiþken oluþturulmuþ ve daha sonra bu
deðiþkenin bilgileri kullanýcýdan okunmuþtur. Kullanýcý tüm bilgilerini girdikten
sonra daire_bilgisi yazdir isimli fonksiyona çaðrý yapýlmýþtýr. Bu fonksiyon
içerisinde dairenin ilk önce çevre ve alan bilgileri hesaplanmýþ daha sonra da
dairenin bilgileriyle birlikte çevresi ve alanýnýn bilgileri ekrana yazdýrýlmýþtýr.
Programýn çýktýsý aþaðýda verilmiþtir:
	
	PROGRAM CIKTISI
dairenin merkezinin x koordinatýný giriniz:5.2
dairenin merkezinin y koordýnatini giriniz:6.7
dairenin yaricap uzunlugunu giriniz:15

[DAÝRENÝN BÝLGÝLERÝ]
dairenin merkez koordýnatlarý(x,y):(5.20,6.70)
daire yaricapi:15.00
daire cevresi:94.20
daire alaný:706.50

	
