#include <stdio.h>
//uzunluk degiskenini 10 olarak tanýmla
#define uzunluk 10

int main(){
	//dizi diye bir dizi olustur
	int dizi[uzunluk]={1,2,3,4,5,6,7,8,9,10};
	//dizinin basýndaki elemaný ptr pointerýna atarýz
	int *ptr=&dizi[0];
	//dizinin sýnýrýný yaparýz burda
	int *bitis=ptr+uzunluk;
	//toplam diye bir degisken tutarýz
	int toplam=0;
	
	while(ptr<bitis){
		//dizideki tum elemanlarý toplarýz
		toplam+=*ptr;
		//adresi her seferinde 1 arttýrýrýz
		ptr++;
	}
	//toplam degiskenini ekrana yazdýrýrýz
	printf("dizideki elemanlarin toplami=%d\n",toplam);
	return 0;
	
}
//sayfa 394
/*
dizideki elemanlarin toplami=55
*/
