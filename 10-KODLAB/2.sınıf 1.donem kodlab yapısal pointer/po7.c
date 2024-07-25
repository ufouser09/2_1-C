#include <stdio.h>
int main(){
	//dizi adlý bir dizi tanýmlanýr
	int dizi[5]={1,2,3,4,5};
	//ptr pointerýna NUll degeri atýlýr
	int *ptr=NULL;
	//sayi degiskeni tanýmlanýr
	int sayi;
	//dizinin basýndaki eleman ptr pointerýnýn adresini gösterir
	ptr=dizi;
	//ptr pointerýndaki deger 1 arttýrýlýr ve sayi degiskenine atýlýr
	//burda ilk once ptr pointerýndaki degeri sayi degiskenine ata sonra ptr pointerýnýn degerini bir arttýr demek
	sayi=*ptr++;
	printf("---------\n");
	printf("*ptr dizisinin komutu sonrasi\n");
	
	printf("-----------\n");
	
	//sayi degerini ekrana yazdýrýr o da 1 olarak cýkar
	printf("sayi=%d\n",sayi);
	//ptr pointerýndaki degeri ekrana yazdýrýr o da 2 olarak çýkar
	printf("ptr:%d\n",*ptr);
	//dizinin basýndaki eleman ptr adresine atýlýr
	ptr=dizi;
	//burda ilk önce ptr pointerýnýn degerini 1 arttýr sonra sayi degiskenine ata demek
	sayi=*++ptr;
	
	printf("------------\n");
	printf("++ptr komutu sonrasi\n");
	
	printf("-------------\n");
	//sayi degsikenini ekrana 2 olarak yazdýrýr
	printf("sayi=%d\n",sayi);
	//*ptr pointerýnýn degerini ekrana 2 olarak yazdýrýr
	printf("*ptr=%d\n",*ptr);
	
	return 0;
}
//sayfa 393
/*
---------
*ptr dizisinin komutu sonrasi
-----------
sayi=1
ptr:2
------------
++ptr komutu sonrasi
-------------
sayi=2
*ptr=2
*/
