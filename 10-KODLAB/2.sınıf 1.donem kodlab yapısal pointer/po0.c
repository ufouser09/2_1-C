#include <stdio.h>
int main(){
	//sayi degiskeni tan�mla ve ona 10 sayisini ata
	int sayi=10;
	//*p diye bir pointer olustur
	int *p;
	//sayi degsikenin adresini i�aret�iye kopyala
	p=&sayi;
	//sayi2 degiskenimizde *p pointer�n� g�stersin
	int sayi2=*p;
	//sayi degiskenin degerini yazd�r o da ilk 10 olarak tan�mlam�st�k
	printf("%d sayi\n",sayi);
	//p pointer� da sayi degiskenin adresini g�sterdigi i�in o da 10 olarak c�kar
	printf("%d p sayimiz\n",*p);
	//*p pointer�n� da sayi2 degiskenine atar�z *p pointer'� da 10'u g�sterdigi i�in sayi2 10 olur
	printf("sayi2=%d\n",sayi2);
}
//sayfa 370
/*
10 sayi
10 p sayimiz
sayi2=10
*/
