#include <stdio.h>
int main(int argc,const char argv[]){
	//bir tane char dizisi olustur
	char dizi[100];
	//kullanýcýdan bir string al
	printf("lutfen isminizi giriniz\n");
	//stringi kullanýcýdan alýrken & bu adres isaretine gerek yok
	scanf("%s",dizi);
	//kullanýcýdan aldýgýn diziyi yazdýr
	printf("merhaba %s",dizi);
	
	return 0;
}
//adýnýzý giriniz:mustafa
//merhaba mustafa
//sayfa 326
