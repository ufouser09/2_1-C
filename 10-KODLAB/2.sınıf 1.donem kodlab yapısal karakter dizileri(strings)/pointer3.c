#include <stdio.h>
int main(int argc,const char argv[]){
	//bir tane char dizisi olustur
	char dizi[100];
	//kullan�c�dan bir string al
	printf("lutfen isminizi giriniz\n");
	//stringi kullan�c�dan al�rken & bu adres isaretine gerek yok
	scanf("%s",dizi);
	//kullan�c�dan ald�g�n diziyi yazd�r
	printf("merhaba %s",dizi);
	
	return 0;
}
//ad�n�z� giriniz:mustafa
//merhaba mustafa
//sayfa 326
