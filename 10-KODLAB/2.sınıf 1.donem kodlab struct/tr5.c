#include <stdio.h>
#include <string.h>
//Struct sinamaFilmi diye bir struct olustururuz
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
};
//structtan sonra int main gelir
int main(int argc,const char * argv[]){
	//film1 isimli struct degiskeni olusturalým
	//struct sinamaFilmi structýna film1 ismini veririz
	struct sinamaFilmi film1;
	
	//film1 degiskenin uyelerine deger atýyalým
	//film1.ad degiskenine String ifadesini atarýz
	strcpy(film1.ad,"burn After reading");
	//film1.yonetmen degiskenine String ifadesini atarýz
	strcpy(film1.yonetmen,"ethan&john cohen");
	//film1.yapimYili degiskenine 2008 degerini atarýz
	film1.yapimYili=2008;
	
	//yeni bir struct olusturup film1'i film2'e atýyalým
	//Struct sinamafilmi structýna film2 ismini veririz
	struct sinamaFilmi film2;
	//film1 structýný film2 structýna atarýz
	film2=film1;
	
	//atadýgýmýz degerleri yazdýralým
	//structismi.degisken diyip degere ulasabiliriz
	printf("film adi:%s\n",film2.ad);
	printf("yonetmen :%s\n",film2.yonetmen);
	printf("yapim yili :%d\n",film2.yapimYili);
	return 0;
}
/*
film adi:burn After reading
yonetmen :ethan&john cohen
yapim yili :2008
*/
--------------------------------------------
//YAPILAR UZERÝNDE GECERLÝ OPERATORLER
yapýlar uzerinde uygulanabilecek iki operator vardýr.

1-sizeof operatoru
2-atama(=) operatoru

sizeof operatorunun kullanýmýný biraz önce görmüstuk.yapýnýn bellekte kapladýgý alaný bize veriyordu.atama operatoru ise bir yapýnýn degerini bir digerine kopyalamak için kullanýlabilir.

örnegin elimizde asagýdaki sekilde olusturulmus film1 isimli bir sinamaFilmi structý olsun

struct sinamFilmi film1;

//film degiskenin uyelerine deger atýyalým

strcpy(film1.ad,"burn after readýng");
strcpy(film1.yonetmen,"ethan&john cohen");
film1.yapimYili=2008;

bu struct'ý baska bir structa asagidaki gibi kopyalýyabiliriz.

struct sinamaFilmi film2;
film2=film1;

yukarýdaki iki kod calýstýrýldýgýnda film2'de degiskeninde film1'in bir kopyasý olusmus olur.


**c derleyicileri iki yapýnýn birbirine atandýgý bir durumla karsýlastýklarýnda arka tarafta bir memcpy komutu calýstýrýrlar.film1'in  154 bayt yer kapladýgýný söylemistik.derleyici film1 için ayrýlan 154 bayt'ýn içerigini alýr ve film 2 için ayrýlan 154 bytelýk alana kopyalar.bunun sonucunda hem film1 hem de film2 ayrý bellek alanlarýnda birbirinin kopyasý olan içerige sahip olurlar.

bu durumu gösteren programý kitapla birlikte verilen medya içerisinde,bolum 16 altýnda structlarýnkopyalanmasý adlý netbeans proje dosyasý icerisinde bulabilirsiniz. 

-Yukarýdaki kod


