#include <stdio.h>
int main(){
	//sayi degiskenin degerine 15 sayisini atar�z
	int sayi=15;
	//sayi degiskenini ekrana yazd�r�r�z
	printf("sayi degiskenin degeri=%d\n",sayi);
	//sayi degiskenin adresini yazd�r�r�z
	printf("sayi degiskenin bellek adresi=%p\n",&sayi);
	//p isaretcisini tan�mlar�z ve ona null degerini atar�z
	int *p=NULL;
	//p isaretcisinin adresini ekrana yazd�r�r�z
	printf("p isaretcisinin tan�mlama zaman�ndaki degeri=%p\n",p);
	//isaretciye sayi degiskenin bellek adresini kopyal�yal�m
	p=&sayi;
	//p isaretcisi art�k sayi degiskeninin adresini g�sterir
	printf("p isaretcisinin yeni degeri=%p\n",p);
	//p isaretcisi art�k sayi degiskenin adresini g�sterdigi i�in p pointer�m�z 15 degerini al�r
	printf("p degiskeninin tuttugu bellek adresindeki deger=%d\n",*p);
	//p pointer�na 16 degerini atar�z
	*p=16;
	//p pointer'� art�k 16 degerini g�sterir
	printf("p isaretcisinin tuttugu bellek adresindeki yeni deger=%d\n",*p);
	//p pointer�n� degistirdigimiz i�in sayi degiskenin degeri de degisir ve o da 16 degerini g�sterir
	printf("sayi degiskenin yeni degeri=%d\n",sayi);
	
	return 0;
}
//sayfa 374
/*
sayi degiskenin degeri=15
sayi degiskenin bellek adresi=000000000062FE14
p isaretcisinin tan�mlama zaman�ndaki degeri=0000000000000000
p isaretcisinin yeni degeri=000000000062FE14
p degiskeninin tuttugu bellek adresindeki deger=15
p isaretcisinin tuttugu bellek adresindeki yeni deger=16
sayi degiskenin yeni degeri=16
*/
