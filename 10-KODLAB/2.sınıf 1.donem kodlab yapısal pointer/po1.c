#include <stdio.h>
int main(){
	//sayi degiskeni olusturup ona 10 degerini atad�k
	int sayi=10;
	//sayi degiskenin adresini *pointer�na atad�k
	int *p=&sayi;
	//p pointer�na 16 degerini atad�k
	*p=16;
	//p pointer�na 16 degerini atdd�k
	printf("sayi=%d\n",*p);
	//p pointer�n� degistirdigimiz i�in p pointer� da sayi degiskenin adresini g�sterdigi i�in sayi degiskeninin degerini de degistirdi
	printf("sayi=%d\n",sayi);
	//isaretc�ye NULL degerini atad�k
	p=NULL;
	
	
	//asagidaki ifade p isaretcisinin tuttugu bellek adresinde bulunan degeri 20 olarak degistirmeye cal�smaktadir.
	//null degeri atanm�s bir isaretci hicbir bellek adresi tutmucag� i�in asag�daki ifade hatalidir.
	
	//*p=20;
}
//sayfa 373
/*
sayi=16
sayi=16
*/
