#include <stdio.h>
int main(){
	//sayi deger1 deger2 ve deger3 degiskenlerini tanımla
	int sayi,deger1,deger2,deger3;
	//ptr pointırına NUll degerini ata
	int *ptr=NULL;
	//**ptrtoPtr diye pointırı gösteren pointer tanımla
	int **ptrToPtr=NULL;
	
	//sayi degiskenine 5 degerini ata
	sayi=5;
	//sayi degiskeninin adresi ptr 'ye atılır
	ptr=&sayi;
	//ptr pointırının adresi ptrtoPtr ye kopyalanır
	ptrToPtr=&ptr;
	//sayi degiskenin degerini deger1 degiskenine ata 
	deger1=sayi;
	//ptr pointırındaki degeri deger2 degiskenine ata
	deger2=*ptr;
	//ptrtoPtr deki degeri deger3 degiskenine ata
	deger3=**ptrToPtr;
	
	//deger1 deki degeri ekrana yazdırırız
	printf("deger1=%d\n",deger1);
	//deger2 deki degeri ekrana yazdırırız
	printf("deger2=%d\n",deger2);
	//deger3 deki degeri ekrana yazdırırız
	printf("deger3=%d\n",deger3);
	
	return 0;
}
//sayfa 441
/*
deger1=5
deger2=5
deger3=5
*/
