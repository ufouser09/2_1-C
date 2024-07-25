#include <stdio.h>
#include <stdlib.h>

void diziYazdir(int * dizi,int elemanSayisi);
int main(){
	//sayiDizisi pointerý olustur
	int *sayiDizisi1;
	//sayi degiskeni tanýmla
	int sayi;
	//kullanýcýdan eleman sayisini alýnýz
	printf("eleman sayisini giriniz\n");
	scanf("%d",&sayi);
	
	//sayidizisi1 pointerý için bellekte yer aç
	sayiDizisi1=(int *)calloc(sayi,sizeof(int));
	
	printf("\n------------------\n");
	printf("calloc sonucu olusan dizinin elemanlari\n");
	printf("---------------\n");
	//sayiDizisi1 pointerýný ve sayi degiskenini fonksiyona gönder
	diziYazdir(sayiDizisi1,sayi);
	
	printf("\n-------------\n");
	printf("dizi elemanlarina 5 degerini atýyalim\n");
	printf("------------------\n");
	//i degiskenini tanýmla
	int i;
	//sayidizisinin her elemanýna 5 degerini ata
	for(i=0;i<sayi;i++){
		sayiDizisi1[i]=5;
	}
	//diziYazdir fonksiyonuna sayiDizisi1 pointerýný ve sayi degiskenini ata
	diziYazdir(sayiDizisi1,sayi);
	//sayi degiskenine 10 degerini ata
	sayi=10;
	//bellek boyutunu degistirmek için reaolloc kullanýrýz
	sayiDizisi1=realloc(sayiDizisi1,sayi * sizeof (int));
	printf("\n---------------\n");
	printf("realloc sonucu olusan dizinin elemanlari\n");
	printf("----------------------------\n");
	//diziYazdir fonksiyonuna sayiDizisi1 pointerýný ve sayi degiskenini ata
	diziYazdir(sayiDizisi1,sayi);
	return 0;
}

void diziYazdir(int * dizi,int elemanSayisi){
	//i degiskenini tanýmla
	int i;
	
		//elemanlarý ekrana yazdýrýrýz
		for(i=0;i<elemanSayisi;i++){
			printf("dizi[%d]=%d\n",i,dizi[i]);
		}
	
}
//sayfa 449
/*
eleman sayisini giriniz
3

------------------
calloc sonucu olusan dizinin elemanlari
---------------
dizi[0]=0
dizi[1]=0
dizi[2]=0

-------------
dizi elemanlarina 5 degerini at²yalim
------------------
dizi[0]=5
dizi[1]=5
dizi[2]=5

---------------
realloc sonucu olusan dizinin elemanlari
----------------------------
dizi[0]=5
dizi[1]=5
dizi[2]=5
dizi[3]=0
dizi[4]=0
dizi[5]=0
dizi[6]=184549387
dizi[7]=62473
dizi[8]=7410784
dizi[9]=0
*/
/*
eleman sayisini giriniz
5

------------------
calloc sonucu olusan dizinin elemanlari
---------------
dizi[0]=0
dizi[1]=0
dizi[2]=0
dizi[3]=0
dizi[4]=0

-------------
dizi elemanlarina 5 degerini at²yalim
------------------
dizi[0]=5
dizi[1]=5
dizi[2]=5
dizi[3]=5
dizi[4]=5

---------------
realloc sonucu olusan dizinin elemanlari
----------------------------
dizi[0]=5
dizi[1]=5
dizi[2]=5
dizi[3]=5
dizi[4]=5
dizi[5]=0
dizi[6]=184549387
dizi[7]=50341
dizi[8]=11932768
dizi[9]=0
*/

