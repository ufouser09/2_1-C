#include <stdio.h>
int main(){
	//sayi deger1 deger2 ve deger3 degiskenlerini tan�mla
	int sayi,deger1,deger2,deger3;
	//ptr point�r�na NUll degerini ata
	int *ptr=NULL;
	//**ptrtoPtr diye point�r� g�steren pointer tan�mla
	int **ptrToPtr=NULL;
	
	//sayi degiskenine 5 degerini ata
	sayi=5;
	//sayi degiskeninin adresi ptr 'ye at�l�r
	ptr=&sayi;
	//ptr point�r�n�n adresi ptrtoPtr ye kopyalan�r
	ptrToPtr=&ptr;
	//sayi degiskenin degerini deger1 degiskenine ata 
	deger1=sayi;
	//ptr point�r�ndaki degeri deger2 degiskenine ata
	deger2=*ptr;
	//ptrtoPtr deki degeri deger3 degiskenine ata
	deger3=**ptrToPtr;
	
	//deger1 deki degeri ekrana yazd�r�r�z
	printf("deger1=%d\n",deger1);
	//deger2 deki degeri ekrana yazd�r�r�z
	printf("deger2=%d\n",deger2);
	//deger3 deki degeri ekrana yazd�r�r�z
	printf("deger3=%d\n",deger3);
	
	return 0;
}
//sayfa 441
/*
deger1=5
deger2=5
deger3=5
*/
