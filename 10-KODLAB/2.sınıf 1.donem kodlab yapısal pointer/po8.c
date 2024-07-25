#include <stdio.h>
//uzunluk degiskenini 10 olarak tan�mla
#define uzunluk 10

int main(){
	//dizi diye bir dizi olustur
	int dizi[uzunluk]={1,2,3,4,5,6,7,8,9,10};
	//dizinin bas�ndaki eleman� ptr pointer�na atar�z
	int *ptr=&dizi[0];
	//dizinin s�n�r�n� yapar�z burda
	int *bitis=ptr+uzunluk;
	//toplam diye bir degisken tutar�z
	int toplam=0;
	
	while(ptr<bitis){
		//dizideki tum elemanlar� toplar�z
		toplam+=*ptr;
		//adresi her seferinde 1 artt�r�r�z
		ptr++;
	}
	//toplam degiskenini ekrana yazd�r�r�z
	printf("dizideki elemanlarin toplami=%d\n",toplam);
	return 0;
	
}
//sayfa 394
/*
dizideki elemanlarin toplami=55
*/
