#include <stdio.h>
#include <stdlib.h>

int main(){
	//ptr1 ve ptr2 pointer� olarak iki tane pointer tan�mlar�z
	int *ptr1,*ptr2;
	//ptr1 pointer� i�in bellekter int boyutunda bir yer ay�r�r�z
	ptr1=(int *)malloc(sizeof(int));
	
	//ptr1 in adresi ekrana yazd�r�l�r
	printf("ptr1 de tutulan adres->%p\n",ptr1);
	//ptr2 nin adresi ekrana yazd�r�l�r
	printf("ptr2 de tutulan adres->%p\n",ptr2);
	//ptr1 pointer�n adresi ptr2 adresine kopyalan�r 
	ptr2=ptr1;
	
	//ptr1 pointer�n�n adresi yazd�r�l�r
	printf("ptr1 de tutulan adres->%p\n",ptr1);
	//ptr2 pointer�n�n adresi yazd�r�l�r
	printf("ptr2 de tutulan adres->%p\n",ptr2);
	//ptr1 pointer�na 10 degeri at�l�r
	*ptr1=10;
	
	//ptr2 pointer�n�n degeri ekrana yazd�r�l�r ptr1 ve ptr2 bellekte ayn� yeri g�sterdigi i�in ptr1'i 10 yapmam�z ptr2'yi de 10 yapmam�z� saglar
	printf("ayrilan bellek alanin degeri=%d\n",*ptr2);
	//ptr2 pointer�n� 20 degeri at�l�r
	*ptr2=20;
	//ptr1 pointer�n� ekrana yazd�r�r�z
	printf("ayrilan bellek alanin degeri=%d\n",*ptr1);
	//en son ptr1 i�in yer ay�rd�g�m�z yeri bosalt�r�z
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
