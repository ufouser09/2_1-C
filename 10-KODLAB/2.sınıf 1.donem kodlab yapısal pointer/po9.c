#include <stdio.h>
//burda fonksiyonu önceden tanýmlarýz
void sifirla(int);

int main(){
	//sayi degiskenini tanýmlar ve 10 sayisini ona atarýz
	int sayi=10;
	//sifirla fonksiyonuna gider
	sifirla(sayi);
	//sayi degiskenini ekrana yazdýrýr
	printf("sayi=%d",sayi);
	
}
//sayi bu fonksiyona gelir
void sifirla(int arg){
	arg=0;
}
//sayfa 396
//normalde bu program kendisine gödenrilen sayiyi sifirlamayi amaçlamaktadir fakat istenileni yapmaz
/*
sayi=10
*/
