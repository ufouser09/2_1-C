#include <stdio.h>
#include <string.h>

//struct sinamafilmi diye bir struct olustururuz
struct sinamaFilmi{
	char ad[100];
	char yonetmen[50];
	int yapimYili;
};
//structtan sonra int main tan�mlan�r
int main(int argc,const char * argv[]){
	//struct sinamaFilmi'ne film ismi atan�r
	//film isimli struct degiskeni olustural�m
	struct sinamaFilmi film;
	//film degiskenin uyelerine deger at�yal�m
	//film.ad degiskenine String atan�r
	strcpy(film.ad,"batman beg�ns");
	//film.yonetmen degiskenine String ifadesi atan�r
	strcpy(film.yonetmen,"christopher nolan");
	//film.yapimYili degiskenine 2005 sayisi atan�r
	film.yapimYili=2005;
	//film adresini filmPtr'a kopyala
	//film isimli struct�m�z�n adresi filmPtr pointer�na atan�r
	struct sinamaFilmi *filmPtr=&film;
	
	//atad�g�m�z degerleri yazd�ral�m
	printf("film adi:%s\n",(*filmPtr).ad);
	printf("yonetmen:%s\n",filmPtr->yonetmen);
	printf("Yapim yili:%d\n",filmPtr->yapimYili);
	
	return 0;
}
//output:
film adi:batman beg�ns
yonetmen:christopher nolan
Yapim yili:2005
----------------------------------------------------------------

	
	//YAPILARA DEKLARASYON SIRASINDA �LK DEGER ATAMA
	yukar�daki structOrnek isimli ornegimizde film1 degiskenimizi �nce olusturduk.daha sonra bu degiskene strcpy vb. fonksiyonlar arac�l�g�yla deger atad�k.b�yle bir kullan�ma,kullan�c�dan deger okundugu durumlarda 
	ihtiyac duyulsa da bas�t kullan�mlar i�in yap�lara deklarasyon s�ras�nda da deger atamam�z m�mk�nd�r.
	�rnegin:yukar�daki �rnekte bulunan sinamaFilmi yap�s�na tan�mlama esnas�nda ilk deger atamak(initialize)i�in asag�daki gibi bir ifadeden faydalanabiliriz.
	
	struct sinamaFilmi film2={"seven","david fincher",1995};
	
	bu ifade yap�n�n her bir uyesine s�ras�yla deger atanmas�n� saglar
	yukar�daki ifadeden sonra film2 yap�sn�n ad �yesi seven degerine sahip olur.benzer sekilde yonetmen uyesinin degeri "david fincher" olur.yapimYili uyesinin degeri de 1995 olur.
	
	//YAPILARIN �SARETCILER ARACILIGI �LE KULLANIMI(STRUCT PO�NTERS)
	structlar arac�l�g� ile kendi olusturdugumuz veri tipleri i�in de isaretci tan�ml�yabilir.bu isaretciler arac�l�g� ile dinamik bellek y�netimi yapabilir ve kendi veri tiplerimizi manipule edebiliriz.
	bu k�s�mda �rnek bir struct �zerinde  isaretci kullan�m�n� ve dinamik bellek ay�rma y�ntemlerinin strcut'lar �zerinde uygulanams�n� inceleyecegiz.
	
	hat�rlarsan�z bir int isaretcisi su sekilde tan�mlan�yordu.
	
	int *sayi;
	
	benzer sekilde bir �nceki �rnegimizde verilen sinamaFilmi yap�s� i�in isaret eden bir isaretci degisken asagidaki gibi tan�mlanabilir.
	
	struct sinamaFilmi *filmPtr;
	
	bu ifadeyle struct sinamaFilmi tipinde tan�mlanm�s degiskenlere isaret eden film ptr isimli bir isaretci degisken tan�mlanmaktad�r.bu isaretci degiskeni tan�mlad�ktan sonra,herhangi bir sinamaFilmi struct�n�n bellek adresini bu isaretci degiskene asag�daki gibi kopyal�yabiliyoruz.
	
	filmPtr=&film1;
	
	asag�daki kod parcas�nda bir �nceki �rnekten farkl� olarak sinamaFilmi yaps�na degisken ad�yla degil isaretci arac�l�g� ile erismek istiyoruz.bunu yapabilmek i�in normal isaretciler i�in kulland�g�m�z erisim operatoru * ile birlikte nokta notasyonunu kullanmam�z gerekmektedir.
	�rnegin filmPtr isaretci degiskenimiz arac�l�g� ile bellek alan�ndaki uye degisken degerlerine ulasabilmek i�in asag�daki ifadelere ihtiyac duyulur
	
	(*filmPtr).ad;
	(filmPtr).yonetmen;
	(*filmPtr).yapimYili;
	
	yukar�daki ilk ifade bize sunu s�yler filmPtr isimli degiskende depolanan bellek adresine git ve bu adresteki ad uye degiskenini bize getir.
	diger ifadeler de benzer sekilde diger uye degiskenlere erisirler.Parantez,y�ld�z ve noktadan olusan bu notasyonu kullanmak uygulama gelistiricilere zor geldigi i�in sonradan c programlama diline yukar�daki ifadelerle ayn� i�i yapan bir baska notasyon eklenmistir.	
	
	filmPtr->ad;
	filmPtr->yonetmen;
	filmPtr->yapimYili;
	
	bir baska deyisle asag�daki iki ifade birbirinin ayn�s�d�r.
	(*filmPtr).ad;
	filmPtr->ad;
	
	yazd�g�n�z programlarda,struct isaretcilerinin referans g�sterdikleri bellek alan�nda,uye degiskenlere erisim saglamak i�in her iki notasyonu da kullanabilirsiniz.
	hemen bu kullan�m� g�steren bir �rnek verelim.
	
	-YUKARIDAK� KOD
	
	
	program i�erisinde filmPtr isimli bir isaretci olusturulmus ve bu isaretciye film isimli bir struct degiskeninin adresi kopyalanm�st�r.bu noktadan sonra film degiskeninin i�erigine filmPtr isaretcisi ve erisim operatorunu kullanarak dolayl� yoldan erisebiliriz.
	bu erisimin �rneklerini yukar�daki printf ifadeleri i�erisinde g�rebilmektesiniz.
	
	PROGRAM CIKTISI
	F�LM AD�:BATMAN begins
	yonetmen:christopher nolan
	yap�m yili:2005
	

