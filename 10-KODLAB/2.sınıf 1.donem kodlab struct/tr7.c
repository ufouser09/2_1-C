#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct sinama filmi diye bir struct olustururuz
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
};
//typedef anahtar kelimesi daha önceden tanýmladýgýmýz bir tipi yeniden adlandýrarak kullanmamýzý saglar.bu komut sayesinde int float gibi veri tiplerine bile takma isim vererek kullanabiliriz.bu kullanýmýn iki örnegi asagýdadýr.asagýdaki ilk satýrdaint anahtar kelimesine tamsayi takma adý veriliyor.böylece eskiden int kullandýgýmýz heryerde tamsayi ifadesini kullanabilir durumda oluruz benzer sekilde struct sinamaFilmi isimli yapýya da film takma ismi verildi.artýk struct sinamaFilmi yazmamýz gereken bir yere Film ifadesini koymamýz yeterlidir.

//artýk int yerine tamSayi ifadesini kullanabilirsin demek
typedef int tamSayi;
//artýk struct sinamafilmi structýný film olarak ifade edebilirsin demek
typedef struct sinamaFilmi Film;

int main(int argc,const char *argv[]){
	//x degiskenine 30 degerini atarýz
	//yukarýdaki typedef int tamsayi komutu sayesinde int yerine tamsayi kelimesini kullanabiliriz.
	tamSayi x=30;
	//30 degerini ekrana yazdýrýrýz
	printf("x sayisinin degeri %d\n",x);
	//film structýna *filmPtr pointerý olustururuz
	//yukarýdaki typedef struct sinamaFilmi Film,komutu sayesinde struct sinamaFilmi yerine film kelimesini kullanabiliriz.
	Film *filmPtr;
	
	filmPtr=(Film *)malloc(sizeof(Film));
	//filmPtr aracýlýgý ile bellek alanýna ulasýp deger atýyalým
	//filmPtr pointerý ile artýk structa erisebiliriz
	strcpy((*filmPtr).ad,"Runaway jury\n");
	//filmPtr pointerý ile structýn yönetmen degiskenine erisiriz
	strcpy(filmPtr->yonetmen,"Gary fleder\n");
	filmPtr->yapimYili=2003;
	//atadigimiz degerleri yazdiralým
	printf("film adi :%s\n",(*filmPtr).ad);
	printf("yonetmen :%s\n",filmPtr->yonetmen);
	printf("Yapim Yili:%d\n",(*filmPtr).yapimYili);
	free(filmPtr);
	
	return 0;
}
/*
x sayisinin degeri 30
film adi :Runaway jury

yonetmen :Gary fleder

Yapim Yili:2003

*/
--------------------------------------------------
//TYPEDEF ANAHTAR KELÝMESÝ
typedef anahtar kelimesi daha önceden tanýmladýgýmýz bir tipi yeniden adlandýrarak kullanmamýzý saglar.bu komut sayesinde int,float gibi veri tiplerine bile takma isim vererek kullanabiliriz.
örnegin asagýdaki komutu verdigimizi dusunelim

typedef int tamsayi;
 bu komut sonrasýnda programýmýzýn içerisinde int yerine tamsayi kelimesini kullanabilir ve int tipindeki degiskenlerimizi tamsayi kelimesiyle tanýmlayabiliriz.
 
 tamsayi x=30;
 printf("x sayisinin degeri %d",x);
 
 bu anahtar kelime genellikle struct ifadesiyle olusturulmus yapýlara takma isim vermek için kullanýlýr.bir önceki bolumde sýklýkla struct sinamaFilmi ifadesini kullanmýstýk.bu ifadeye typedef anahtar kelimesiyle Film takma ismini asagýdaki gibi verebiliriz.
 
 typedef struct sinamaFilmi Film;
 
 bir satýrdan sonra artýk struct sinamaFilmi yazdýgýmýz her yere Film ifadesini koyabiliriz.
 
 Film * filmPtr;
 filmPtr=(Film *)malloc(sizeof(Film));
 
 asagýda bu kullanýmý gösteren örnek bir program verilmistir.
 
 -
 -
 -
 -YUKARIDAKÝ KOD
 -
 -
 -
 PROGRAM CIKTISI
 x sayisinin degeri 30
 Film adi:RunAway jury
 yonetmen:gary fleder
 yapim Yili:2003
 
 
//TYPEDEF ANAHTAR KELÝMESÝNÝ YAPILAR HENÜZ TANIMLANIRKEN KULLANMAK

yukarýdaki programda ilk önce sinamaFilmi isimli yapýmýzý olusturduk.daha sonra da typedef anahtar kelimesi aracýlýyla bu yapýya Film takma adýný verdik.Bunu asagýda Yontem 1 olarak tekrar yazdýmÇ

//YONTEM 1
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
}; 
typedef struct sinamaFilmi Film;

Yontem 1'deki iki komutu tek bir satýrda birlestirebiliriz.asagýdaki verilen yöntemdeki deklarasyon derleyici Yontem 1'dekiyle ayný seyi soyler.

//YONTEM 2
typedef struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
}Film;

bu iki deklarasyondan herhangi birini yaptýktan sonra ilgili yapý için asagýdaki degisken deklarasyonlarýndann her ikisi de gecerlidir.

struct sinamaFilmi film;//dogru
Film film1;//dogru

hatta eger typedef aracýlýgýyla bir yapýya isim tanýmlýyorsanýz,o yapýya ayrýca isim vermenize de gerek yoktur.asagýda verilen yontem 3,ilk iki yönteme denktir.

//YONTEM 3
typedef struct {
	char ad[100];
	char yonetmen[50];
	int yapimYili;
}Film;

yontem 3'un yontem 1 ve 2'den tek farký,yontem 3'te tanýmlanan yapý tipinde bir degisken tanýmlarken asagýdaki ilk ifadenin gecersiz olmasýdýr.

struct sinamaFilmi film1;//Yanlýs (tanýmda sinamaFilmi diye bir þey yok)
Film film1;//dogru

bir baska deyisle bir yapýyý yukarýdaki yontem 3 ile tanýmlýyorsanýz sadece typedef ile verdigimiz isim aracýlýgýyla (Film) o yapýnýn tipine sahip bir degisken tanýmlýyabilirsiniz.
 
