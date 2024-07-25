#include <stdio.h>
#include <stdlib.h>
#define MAX 20

//bu tarz i�lemlerde dosya okurken eger yap�m�z dosyam�z yap�land�r�lm�s bir �ey ise 
//bunu struct �zerinden okumak kod yazarken cok avantaj saglar �zellikle her degisken i�in 


typedef struct ogr{
	char ad[MAX];
	int no;
	int puan;
}OGR;


int main(){
	//�imdi burda bir dosya a��caz 
	char dosya[20];
	
	//FILE uzerinden pointer olustural�m 
	FILE *fp;
	
	int no;
	
	//ve okudugumuz bu dosyay� da bir OGR turunde bir degiskende tutucaz.(odevde de biz boyle yap�caz.)
	OGR ogr;
	
	//hi�bir projede hi�bir �eyde kod i�erisinden d�sar�dan girilecek bir veri girilmez.
	//bunu kullan�c�dan al�caks�n�z ona uygun tasarlaman�z laz�m.
	printf("DOSYA adi giriniz\n");
	scanf("%s",dosya);
	
	//oncelikle dosyan�n i�indeki �eyleri ekrana yazd�racak bir fonksiyon yazal�m.
	printf_file(dosya);
	//dosyay� ac�p i�erisinde bir kay�t ar�yal�m.
	
	//ben burda dosyay� tekrar ac�y�m okumay� da burda yapal�m 
	//yani aranan bir ogrencilere ait bilgileri veya aranan ogrenci bilgisini kullan�c�dan alal�m.
	
	//bir file pointer acal�m 
	//burdaki dosya ismiyle bunu binary olarak okuycaz 
	fp=fopen(dosya,"rb");     
	
	//eger file pointer'�m�z null dan farkl� ise 
	if(fp!=NULL){
		//burda kullan�c�dan bir ogrenci numaras� alal�m 
		printf("Ogrenci No");
		scanf("%d",&no);
	}
	//burda aranan ogrencinin bilgileri var m� yok mu diye
	//�imdi dosyay� act�k bir kay�t okuycam s�md� 
	//bu kay�t eger benim arad�g�m bir kay�tsa dogrudan buluruz.
	//veya dosyan�n sonuna kadar arama yapmam gerekecek.burda bir fread yapal�m ilk once cunku ilk defade bulabilme imkan�m�z var.
	//dosyan�n format� bu arada binary format.bunu acarken once bi tane okumam gerekiyor.
	//muhtemelen burda numaralar da s�ral�yd� okuyunca daha rahat anlas�l�r.
	//burdan bir kay�t okuycam once.
	//Nas�l okuycaz ----------->nas�l yaz�ld�ysa oyle.
	
	//gidicez ogrenci struct�n�n i�erisine ,sizeof(OGR)kadar bir kay�t oku,bunu bir defa oku,file pointer'�n gosterdigi yerden oku.
	fread(&ogr,sizeof(OGR),1,fp);
	
	//�imdi bunu okuduktan sonra bu benim ogrenci i�erisinde ogrenci no degiskenimin alt�nda bir �ey var art�k bir degisken var 
	//bir de bunu while dongusu ile butun kay�tlar� gezicem arad�g�m kayd� bulmak i�in bunu da soyle ogrenci numaras�na gore 
	//s�ral� bir format var burda ogrenci no'nun nosu kucukse no'dan diyelim bir de diger sart olarak dosyan�n sonuna gelene kadar 
	//feof(fp)diyince nap�yoduk dosyan�n sonuna gelip gelmedigimizi kontrol ediyoduk.yani boyle yapt�g�m�zda dosyan�n sonuna kadar ar�caz.
	while((ogr.no<no)&&(!feof(fp))){
		
		//�imdi yine ayn� sekilde burda bir kay�t ara diyoruz bu �art sa�lanana kadar yani while'a hi� girmeyebilir 
		//eger girersede sartlar sa�lanana kadar bir �ey gelicek.
		fread(&ogr,sizeof(OGR),1,fp);
	}
	
	//�imdi buraya geldigimizde arad�g�m�z kay�t bulundu mu bulunmad� m�
	//bu bahsettigimiz kay�t numara degil de puan olsayd� ve birden fazla gelme durumu vard� aran�lan durumda birden fazla ogrenci olabilirdi o zaman napmak gerekirdi. dosyadan okuyoruz ama okudugumuz kay�t her defas�nda birden fazla kay�t var.o zaman nas�l bir cozum uretirdiniz.bu veri taban� ve oop nin konusudur.her bir sorgulama yap�ld�g�nda ister veri taban�nda ister dosyada nerde yap�l�rsa yap�ls�n eger kullan�cag�n�z kay�tlar yani cekeceginiz veriler size bi yerde gosterilsin istiyorsan�z,o zaman tek bir degisken degil dinamik olarak bir degisken yani OGR ogr dedigimiz seyi bir struct'�r dizisinden saklamam�z gerekiyor.bu struct'�r neyse art�k hangi turse ve her bir okudugumuz sey� napmam�z laz�m o struct�r dizisine eklememiz laz�m.tabi dosya oldugu i�in dosyada napcak deep copy methodu ile burdaki struct�ra bellek i�erisinde bir yere bunlar kopyalancak cunku onlar�n dogrudan adresi yok.biz sadece bir ogrenci buldugumuzda onun bilgisini yazmas� o zaman burda birden fazla sat�r olucaksa OGR ogr 'yi nas�l tan�ml�cam.malloc ile tan�ml�cam.once bir tanelik yer ay�r�rs�n�z kay�t buldukca onu geni�letirsiniz veya ��yle bir strateji olabilir.ozellikle oop lerde array listler vard�r array list'in mant�g� �udur.d�nam�k bir dizi her turde tan�mlanabiliyor.orneg�n once 1000 tane ac�l�yor.siz i�erisinde 500 kay�t kulland�ysan�z.500 luk k�sm� bellege geri iade ediyor.1000 i doldurdunuz.1.5 kat� kadar kendi otomatik boyut artt�r�yor.arkada olan olaylar yine malloc realloc falan var.boyle bir dinam�k sey olmak zounda.dosyadan okudugumuz bu veriyi ��rencinin i'sine kopyalad�k tamam s�md� burdan ald�g�m�z� baska bir fonksiyona g�ndercez orda i�licez baska bir dosyaya gondercez o zaman ne laz�m.dinamik bellek yonetimini olusturmak daha onemli oluyor.yan� normal bir dizi bizi cok s�k�nt�ya sokar  
	if(ogr.no==no ){
		printf("bulunan bilgiler");
		
		//ister text format� olsun ister binary formatta olsun.
		//dosya �zerinde arama yaparken bi �ekilde s�ral� i�leme tak�lmak zorunday�z.ayn� dizide arar gibi.
		printf("\n%s %d %d\n",ogr.ad,ogr.no,ogr.puan);
	
	}
	
	else{	
		printf("kay�t bulunamad�.");
	}
	return 0;
}

//Dosya yazd�rma fonksiyonu
//buraya ne gelicek bir dosya ad� gelicek 

void print_file(char ad[20]){
	int N,i;
	OGR e;
	FILE *fp=fopen(ad,"wb");//ad ile a�,binary bir dosya oldugu i�in bunu binary modda ac�cam 
	//kac tane ogrenci olduguna bakmak istiyorum.bunu okuyunca   
	printf("ogrenci sayisi giriniz\n");
	scanf("%d",&N);
	
	printf("Bilgiler\n Ad -No - Puan\n");
	//formatl� bir okuma burda yap�cam yani formatl� bir �ekilde dosyaya yazmak istiyorum 
	for(i=0;i<N;i++){
		
		//fscanf'i klavyeden almak i�in kullan�cam 
		//nerden al�yorum stdin ile ald�g�m i�in bunu kullan�c�dan al�yorum klavyeden al�yorum yani 
		fscanf(stdin,"%s %d %d",e.ad,&e.no,&e.puan);
		
		//sonra struct'� tek bir seferde tek bir blok halinde yaz�yorum 
		//fwrite oncelikle burda bir pointer istiyor.su e'nin pointer�n� adresini yaz,sizeof(OGR)kadar yaz ,1 defa yaz,nereye yaz file pointer'�n gosterdigi yere yaz.
		fwrite(&e,sizeof(OGR),1,fp);
		
		//kac defa giriceksek N defa kay�t giriceksek N defa bu kay�t girdik 	
		
		
	}
	//file pointer'� kapatt�k.
	fclose(fp);
}
