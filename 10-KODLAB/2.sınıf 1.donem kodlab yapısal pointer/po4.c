#include <stdio.h>
int main(){
	//sayi degiskeni tanımlanır ona 100 degeri atılır
	int sayi=100;
	//referans diye bir pointer olusturulur
	int *referans;
	//sayi degiskenin adresi referans pointerina atanır
	referans=&sayi;
	//referans pointerının gösterdigi deger sayi degiskenin adresinde bulunan degerdir o da 100 dur.burda yani 100 sayisi sayi2 degiskenine atanır
	int sayi2=*referans;
	//daha sonra 150 sayisi referans pointerına atanır
	*referans=150;
	//sayi degiskenimiz referans pointerına 150 sayisi atandıgı için artık sayi degiskeni 150 olarak çıkar
	printf("sayi degiskenin degeri=%d\n",sayi);
	//sayi2 degiskeni 100 degerini alır
	printf("sayi2 degiskenin degeri=%d\n",sayi2);
	
	return 0;
}
//sayfa 378
/*
sayi degiskenin degeri=150
sayi2 degiskenin degeri=100
*/
