#include <stdio.h>
int main(){
	//bir dizi degiskeni tan�mlar ve i�ine sayilar atar�z
	int dizi[10]={1,2,3,4,5,6,7,8,9,10};
	//dizi adl� dizinin en bas�ndaki eleman�n� ptr pointer�na atar�z
	int *ptr=&dizi[0];
	//bu islem yukar�dakiyle ayn�d�r
	int *ptr2=dizi;
	//i degiskenini tan�mlar�z
	int i;
	//dizi[0] *ptr ve *ptr2 ayn� degeri g�sterir yani dizinin bas�ndaki eleman olan 1'i
	printf("dizinin 1.eleman�=%d\n",dizi[0]);
	printf("dizinin 1.eleman�=%d\n",*ptr);
	printf("dizinin 1.eleman�=%d\n",*ptr2);
	
	
	printf("----------------------------\n");
	//dizinin 5.eleman�n� g�sterirler o da 5'tir
	printf("dizinin 4.eleman�=%d\n",dizi[4]);
	printf("dizinin 4.eleman�=%d\n",*(ptr+4));
	printf("dizinin 4.eleman�=%d\n",*(ptr2+4));
	
	//dizinin 8.eleman�n� g�sterirler
	printf("-----------------------------\n");
	printf("dizinin 8.eleman�=%d\n",dizi[8]);
	printf("dizinin 8.eleman�=%d\n",*(ptr+8));
	printf("dizinin 8.eleman�=%d\n",*(ptr2+8));
	
	//(ptr+i)dedigimiz zaman pointer�n adresini g�sterir *(ptr+i) dedigimiz zaman ise degeri g�sterir
	for(i=0;i<10;i++){
		printf("dizi[%d]->adresi=%p,degeri:%d\n",i,ptr+i,*(ptr+i));
	}
}
//sayfa 386
/*
dizinin 1.eleman�=1
dizinin 1.eleman�=1
dizinin 1.eleman�=1
----------------------------
dizinin 4.eleman�=5
dizinin 4.eleman�=5
dizinin 4.eleman�=5
-----------------------------
dizinin 8.eleman�=9
dizinin 8.eleman�=9
dizinin 8.eleman�=9
dizi[0]->adresi=000000000062FDE0,degeri:1
dizi[1]->adresi=000000000062FDE4,degeri:2
dizi[2]->adresi=000000000062FDE8,degeri:3
dizi[3]->adresi=000000000062FDEC,degeri:4
dizi[4]->adresi=000000000062FDF0,degeri:5
dizi[5]->adresi=000000000062FDF4,degeri:6
dizi[6]->adresi=000000000062FDF8,degeri:7
dizi[7]->adresi=000000000062FDFC,degeri:8
dizi[8]->adresi=000000000062FE00,degeri:9
dizi[9]->adresi=000000000062FE04,degeri:10
*/

