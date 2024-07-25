#include <stdio.h>
int main(){
	//dizi adl� bir dizi tan�mlan�r
	int dizi[5]={1,2,3,4,5};
	//ptr pointer�na NUll degeri at�l�r
	int *ptr=NULL;
	//sayi degiskeni tan�mlan�r
	int sayi;
	//dizinin bas�ndaki eleman ptr pointer�n�n adresini g�sterir
	ptr=dizi;
	//ptr pointer�ndaki deger 1 artt�r�l�r ve sayi degiskenine at�l�r
	//burda ilk once ptr pointer�ndaki degeri sayi degiskenine ata sonra ptr pointer�n�n degerini bir artt�r demek
	sayi=*ptr++;
	printf("---------\n");
	printf("*ptr dizisinin komutu sonrasi\n");
	
	printf("-----------\n");
	
	//sayi degerini ekrana yazd�r�r o da 1 olarak c�kar
	printf("sayi=%d\n",sayi);
	//ptr pointer�ndaki degeri ekrana yazd�r�r o da 2 olarak ��kar
	printf("ptr:%d\n",*ptr);
	//dizinin bas�ndaki eleman ptr adresine at�l�r
	ptr=dizi;
	//burda ilk �nce ptr pointer�n�n degerini 1 artt�r sonra sayi degiskenine ata demek
	sayi=*++ptr;
	
	printf("------------\n");
	printf("++ptr komutu sonrasi\n");
	
	printf("-------------\n");
	//sayi degsikenini ekrana 2 olarak yazd�r�r
	printf("sayi=%d\n",sayi);
	//*ptr pointer�n�n degerini ekrana 2 olarak yazd�r�r
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
