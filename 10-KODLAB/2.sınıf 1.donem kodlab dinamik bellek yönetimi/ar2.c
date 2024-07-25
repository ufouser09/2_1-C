#include <stdio.h>
#include <stdlib.h>

int main(){
	//ptr1 ve ptr2 pointerý olarak iki tane pointer tanýmlarýz
	int *ptr1,*ptr2;
	//ptr1 pointerý için bellekter int boyutunda bir yer ayýrýrýz
	ptr1=(int *)malloc(sizeof(int));
	
	//ptr1 in adresi ekrana yazdýrýlýr
	printf("ptr1 de tutulan adres->%p\n",ptr1);
	//ptr2 nin adresi ekrana yazdýrýlýr
	printf("ptr2 de tutulan adres->%p\n",ptr2);
	//ptr1 pointerýn adresi ptr2 adresine kopyalanýr 
	ptr2=ptr1;
	
	//ptr1 pointerýnýn adresi yazdýrýlýr
	printf("ptr1 de tutulan adres->%p\n",ptr1);
	//ptr2 pointerýnýn adresi yazdýrýlýr
	printf("ptr2 de tutulan adres->%p\n",ptr2);
	//ptr1 pointerýna 10 degeri atýlýr
	*ptr1=10;
	
	//ptr2 pointerýnýn degeri ekrana yazdýrýlýr ptr1 ve ptr2 bellekte ayný yeri gösterdigi için ptr1'i 10 yapmamýz ptr2'yi de 10 yapmamýzý saglar
	printf("ayrilan bellek alanin degeri=%d\n",*ptr2);
	//ptr2 pointerýný 20 degeri atýlýr
	*ptr2=20;
	//ptr1 pointerýný ekrana yazdýrýrýz
	printf("ayrilan bellek alanin degeri=%d\n",*ptr1);
	//en son ptr1 için yer ayýrdýgýmýz yeri bosaltýrýz
	free(ptr1);
	
	return 0;
}
//sayfa 432
/*
ptr1 de tutulan adres->0000000000C31460
ptr2 de tutulan adres->0000000000000000
ptr1 de tutulan adres->0000000000C31460
ptr2 de tutulan adres->0000000000C31460
ayrilan bellek alanin degeri=10
ayrilan bellek alanin degeri=20
*/
