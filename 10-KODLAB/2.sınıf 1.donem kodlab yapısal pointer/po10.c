#include <stdio.h>
//en basta fonksiyonu algoritmaya tanýtýrýz
void sifirla(int *);

int main(){
	//sayi diye bir degisken olusturur ve ona 10 sayisini atarýz
	int sayi=10;
	//sayi degiskenin adresini fonksiyona göndeririz
	sifirla(&sayi);
	//sayi degiskenini yazdýrýrýz
	printf("sayi=%d",sayi);
}
//sayi degiskenin adresi fonksiyona gelir
void sifirla(int *arg){
	//burda gelen sayýmýzý 0 larýz
	*arg=0;
}
//sayfa 397
