#include <stdio.h>
#include <stdlib.h>
//fonksiyonu ilk �nce algoritmaya tan�t�r�z
void degistir(int *,int *);

int main(){
	//sayi 1 degiskenini tan�mlar ve ona 10 degerini atar�z
	int sayi1=10;
	//sayi 2 degiskenini tan�mlar ve ona 15 degerini atar�z
	int sayi2=15;
	
	//sayi 1 ve sayi 2 degerlerini yazd�r�r�z
	printf("sayi1=%d,sayi2=%d\n",sayi1,sayi2);
	//sayi 1 ve sayi 2 degiskenlerinin adreslerini degistir fonksiyonuna atar�z
	degistir(&sayi1,&sayi2);
	//sayi 1 ve sayi 2 degiskenlerini yazd�r�r�z
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
