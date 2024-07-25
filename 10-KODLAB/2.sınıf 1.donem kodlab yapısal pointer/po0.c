#include <stdio.h>
int main(){
	//sayi degiskeni tanımla ve ona 10 sayisini ata
	int sayi=10;
	//*p diye bir pointer olustur
	int *p;
	//sayi degsikenin adresini işaretçiye kopyala
	p=&sayi;
	//sayi2 degiskenimizde *p pointerını göstersin
	int sayi2=*p;
	//sayi degiskenin degerini yazdır o da ilk 10 olarak tanımlamıstık
	printf("%d sayi\n",sayi);
	//p pointerı da sayi degiskenin adresini gösterdigi için o da 10 olarak cıkar
	printf("%d p sayimiz\n",*p);
	//*p pointerını da sayi2 degiskenine atarız *p pointer'ı da 10'u gösterdigi için sayi2 10 olur
	printf("sayi2=%d\n",sayi2);
}
//sayfa 370
/*
10 sayi
10 p sayimiz
sayi2=10
*/
