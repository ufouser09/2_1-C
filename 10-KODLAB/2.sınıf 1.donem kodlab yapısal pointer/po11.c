#include <stdio.h>
#include <stdlib.h>
//fonksiyonu ilk önce algoritmaya tanýtýrýz
void degistir(int *,int *);

int main(){
	//sayi 1 degiskenini tanýmlar ve ona 10 degerini atarýz
	int sayi1=10;
	//sayi 2 degiskenini tanýmlar ve ona 15 degerini atarýz
	int sayi2=15;
	
	//sayi 1 ve sayi 2 degerlerini yazdýrýrýz
	printf("sayi1=%d,sayi2=%d\n",sayi1,sayi2);
	//sayi 1 ve sayi 2 degiskenlerinin adreslerini degistir fonksiyonuna atarýz
	degistir(&sayi1,&sayi2);
	//sayi 1 ve sayi 2 degiskenlerini yazdýrýrýz
	printf("sayi1=%d,sayi2=%d\n",sayi1,sayi2);
	
	return 0;
	
}
//sayi 1 ve sayi 2 degiskenlerinin adresleri fonksiyona gelir
void degistir(int *arg1,int *arg2){
	//burda sayi 1 ve sayi 2 degerleri yer degistirir
	int gecici=*arg1;
	*arg1=*arg2;
	*arg2=gecici;
	
	
}
//sayfa 398
