#include <stdio.h>
int main(){
	//tam sayi degiskeni tan�mlan�r 15 degeri atan�r
	int tamSayi=15;
	//ondalikli sayi diye bir degisken tan�mlan�r ve ona 20.2 degeri atan�r
	double ondalikliSayi=20.2;
	//karakter degiskenine C karakteri at�l�r
	char karakter='C';
	
	//*intPtr diye bir pointer tan�mlan�r
	int *intPtr;
	//doublePtr diye bir pointer tan�mlan�r
	double *doublePtr;
	//charPtr diye bir pointer tan�mlan�r
	char *charPtr;
	
	//tamsayinin degiskenin adresi intPtr pointer'�na atan�r
	intPtr=&tamSayi;
	//ondaliklisayi degiskenin adresi doublePtr pointer�na atan�r
	doublePtr=&ondalikliSayi;
	//karakter degiskenin adresi charPtr pointer�na atan�r
	charPtr=&karakter;
	
	//intPtr pointer�n�n adresi yazd�r�l�r
	printf("int isaretcisinin degeri=%p\n",intPtr);
	//doublePtr pointer�n�n adresi yazd�r�l�r
	printf("double isaretcisinin degeri=%p\n",doublePtr);
	//charPtr pointer�n�n adresi yazd�r�l�r
	printf("char isaretcisinin degeri=%p\n",charPtr);
	
	//pointerlar� 1 artt�r�r�z
	intPtr++;
	doublePtr++;
	charPtr++;
	//intPtr pointer�n�n adresi yazd�r�l�r
	printf("\nint isaretcisinin degeri=%p\n",intPtr);
	//doublePtr pointer�n�n adresi yazd�r�l�r
	printf("double isaretcisinin degeri=%p\n",doublePtr);
	//charPtr pointer�n�n adresi yazd�r�l�r
	printf("char isaretcisinin degeri=%p\n",charPtr);
	
	//int degiskenler 4 byte double 8 byte char 1 byte yer kaplad�g� i�in bellekte hepsi kaplad�g� alan kadar ilerledi adres olarak
	
}

//sayfa 384
/*
int isaretcisinin degeri=000000000062FE04
double isaretcisinin degeri=000000000062FDF8
char isaretcisinin degeri=000000000062FDF7

int isaretcisinin degeri=000000000062FE08
double isaretcisinin degeri=000000000062FE00
char isaretcisinin degeri=000000000062FDF8
*/

