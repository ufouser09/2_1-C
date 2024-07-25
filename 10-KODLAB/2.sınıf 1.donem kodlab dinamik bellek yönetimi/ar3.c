#include <stdio.h>
#include <stdlib.h>

int main(){
	//ptr1 ve ptr2 pointerlar�n� tan�mlar�z
	int *ptr1,*ptr2;
	//ptr1 i�in int boyutunda bir yer ay�r�r�z
	ptr1=(int *)malloc(sizeof(int));
	
	//ptr1 adresi ekrana yazd�r�l�r
	printf("ptr1 de tutulan adres->%p\n",ptr1);
	//ptr2 nin adresi ekrana yazd�r�l�r
	printf("ptr2 de tutulan adres->%p\n",ptr2);
	
	//ptr2 i�in bellekte int boyutunda yer ay�r�r�z
	ptr2=(int *)malloc(sizeof(int));
	//ptr1 'in adresi ekrana yazd�r�l�r
	printf("ptr1 de tutulan adres->%p\n",ptr1);
	//ptr2 n�n adresi ekrana yazd�r�l�r
	printf("ptr2 de tutulan adres->%p\n",ptr2);
	//ptr1 pointer�na 24 degeri at�l�r
	*ptr1=24;
	//ptr pointer�n degeri ekrana yazd�r�l�r
	printf("ptr1 icin ayrilan bellek alanin degeri=%d\n",*ptr1);
	//ptr2 pointer�na 325 degeri at�l�r
	*ptr2=325;
	//ptr2 pointer�n�n degeri ekrana yazd�r�l�r
	printf("ptr1 icin ayrilan bellek alanin degeri=%d\n",*ptr2);
	//ptr2 pointer�n�n degerini ptr1 pointer�na atar�z
	*ptr1=*ptr2;
	printf("----------------------\n");
	//ptr1 pointer�n�n degerini ekrana yazd�r�r�z
	printf("ptr1 icin ayrilan bellek alanin degeri=%d\n",*ptr1);
	//ptr2 pointer�n�n degerini ekrana yazd�r�r�z
	printf("ptr2 icin ayrilan bellek alanin degeri=%d\n",*ptr2);
	
	//ptr1 ve ptr2 i�in bellekte ay�rd�g�m�z yeri bosalt�r�z
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
