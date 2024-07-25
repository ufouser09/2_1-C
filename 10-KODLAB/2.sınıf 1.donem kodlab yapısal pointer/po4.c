#include <stdio.h>
int main(){
	//sayi degiskeni tan�mlan�r ona 100 degeri at�l�r
	int sayi=100;
	//referans diye bir pointer olusturulur
	int *referans;
	//sayi degiskenin adresi referans pointerina atan�r
	referans=&sayi;
	//referans pointer�n�n g�sterdigi deger sayi degiskenin adresinde bulunan degerdir o da 100 dur.burda yani 100 sayisi sayi2 degiskenine atan�r
	int sayi2=*referans;
	//daha sonra 150 sayisi referans pointer�na atan�r
	*referans=150;
	//sayi degiskenimiz referans pointer�na 150 sayisi atand�g� i�in art�k sayi degiskeni 150 olarak ��kar
	printf("sayi degiskenin degeri=%d\n",sayi);
	//sayi2 degiskeni 100 degerini al�r
	printf("sayi2 degiskenin degeri=%d\n",sayi2);
	
	return 0;
}
//sayfa 378
/*
sayi degiskenin degeri=150
sayi2 degiskenin degeri=100
*/
