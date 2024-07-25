#include <stdio.h>
int main(){
	//tam sayi degiskeni tanýmlanýr 15 degeri atanýr
	int tamSayi=15;
	//ondalikli sayi diye bir degisken tanýmlanýr ve ona 20.2 degeri atanýr
	double ondalikliSayi=20.2;
	//karakter degiskenine C karakteri atýlýr
	char karakter='C';
	
	//*intPtr diye bir pointer tanýmlanýr
	int *intPtr;
	//doublePtr diye bir pointer tanýmlanýr
	double *doublePtr;
	//charPtr diye bir pointer tanýmlanýr
	char *charPtr;
	
	//tamsayinin degiskenin adresi intPtr pointer'ýna atanýr
	intPtr=&tamSayi;
	//ondaliklisayi degiskenin adresi doublePtr pointerýna atanýr
	doublePtr=&ondalikliSayi;
	//karakter degiskenin adresi charPtr pointerýna atanýr
	charPtr=&karakter;
	
	//intPtr pointerýnýn adresi yazdýrýlýr
	printf("int isaretcisinin degeri=%p\n",intPtr);
	//doublePtr pointerýnýn adresi yazdýrýlýr
	printf("double isaretcisinin degeri=%p\n",doublePtr);
	//charPtr pointerýnýn adresi yazdýrýlýr
	printf("char isaretcisinin degeri=%p\n",charPtr);
	
	//pointerlarý 1 arttýrýrýz
	intPtr++;
	doublePtr++;
	charPtr++;
	//intPtr pointerýnýn adresi yazdýrýlýr
	printf("\nint isaretcisinin degeri=%p\n",intPtr);
	//doublePtr pointerýnýn adresi yazdýrýlýr
	printf("double isaretcisinin degeri=%p\n",doublePtr);
	//charPtr pointerýnýn adresi yazdýrýlýr
	printf("char isaretcisinin degeri=%p\n",charPtr);
	
	//int degiskenler 4 byte double 8 byte char 1 byte yer kapladýgý için bellekte hepsi kapladýgý alan kadar ilerledi adres olarak
	
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

