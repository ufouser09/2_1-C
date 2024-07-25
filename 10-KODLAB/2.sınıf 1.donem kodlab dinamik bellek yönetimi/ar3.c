#include <stdio.h>
#include <stdlib.h>

int main(){
	//ptr1 ve ptr2 pointerlarýný tanýmlarýz
	int *ptr1,*ptr2;
	//ptr1 için int boyutunda bir yer ayýrýrýz
	ptr1=(int *)malloc(sizeof(int));
	
	//ptr1 adresi ekrana yazdýrýlýr
	printf("ptr1 de tutulan adres->%p\n",ptr1);
	//ptr2 nin adresi ekrana yazdýrýlýr
	printf("ptr2 de tutulan adres->%p\n",ptr2);
	
	//ptr2 için bellekte int boyutunda yer ayýrýrýz
	ptr2=(int *)malloc(sizeof(int));
	//ptr1 'in adresi ekrana yazdýrýlýr
	printf("ptr1 de tutulan adres->%p\n",ptr1);
	//ptr2 nýn adresi ekrana yazdýrýlýr
	printf("ptr2 de tutulan adres->%p\n",ptr2);
	//ptr1 pointerýna 24 degeri atýlýr
	*ptr1=24;
	//ptr pointerýn degeri ekrana yazdýrýlýr
	printf("ptr1 icin ayrilan bellek alanin degeri=%d\n",*ptr1);
	//ptr2 pointerýna 325 degeri atýlýr
	*ptr2=325;
	//ptr2 pointerýnýn degeri ekrana yazdýrýlýr
	printf("ptr1 icin ayrilan bellek alanin degeri=%d\n",*ptr2);
	//ptr2 pointerýnýn degerini ptr1 pointerýna atarýz
	*ptr1=*ptr2;
	printf("----------------------\n");
	//ptr1 pointerýnýn degerini ekrana yazdýrýrýz
	printf("ptr1 icin ayrilan bellek alanin degeri=%d\n",*ptr1);
	//ptr2 pointerýnýn degerini ekrana yazdýrýrýz
	printf("ptr2 icin ayrilan bellek alanin degeri=%d\n",*ptr2);
	
	//ptr1 ve ptr2 için bellekte ayýrdýgýmýz yeri bosaltýrýz
	free(ptr1);
	free(ptr2);
	
	return 0;
}
//sayfa 435
/*
ptr1 de tutulan adres->00000000001F1460
ptr2 de tutulan adres->0000000000000000
ptr1 de tutulan adres->00000000001F1460
ptr2 de tutulan adres->00000000001F6F00
ptr1 icin ayrilan bellek alanin degeri=24
ptr1 icin ayrilan bellek alanin degeri=325
----------------------
ptr1 icin ayrilan bellek alanin degeri=325
ptr2 icin ayrilan bellek alanin degeri=325
*/
