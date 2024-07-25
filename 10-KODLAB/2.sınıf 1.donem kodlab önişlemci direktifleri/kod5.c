#include <stdio.h>
#define LOGLAMA_AKTIF

int faktoriyelHesaplama(int sayi);

int main(int argc,char** argv){
	int sayi=0;
	printf("faktoriyel hesaplanacak sayiyi giriniz\n");
	scanf("%d",&sayi);
	
	printf("\nsonuc=%d\n",faktoriyelHesapla(sayi));
	
	return 0;
}
int faktoriyelHesapla(int sayi){
	if(sayi<=1)
	return 1;
	
	long i,sonuc=1;
	
	for(i=1;i<=sayi;i++){
		#ifdef LOGLAMA_AKTIF
		sonuc=sonuc*i;
		printf("%d!=%d\n",i,sonuc);
		#else
		sonuc=sonuc*i;
		#endif
	}
	return sonuc;
}
