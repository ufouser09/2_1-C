#include <stdio.h>
#include <stdlib.h>

int main(){
	//sayi degiskenini tan�mlar�z
	int sayi;
	//toplam degiskenini tan�mlar ve 0 degerini atar�z
	int toplam=0;
	//kullan�c�dan kac adet sayi gircegini al�n�z
	printf("kac adet sayi giriceksiniz\n");
	scanf("%d",&sayi);
	
	//kullanicinin girdigi sayi kadar int tutacak bellek alan� olustural�m
	int *sayiDizisi=(int *)malloc(sizeof(int)*sayi);
	
	//i degiskenini tan�mlar�z
	int i;
	//sayidizisi+i yaparak kullan�c�dan degerleri al�r�z
	for(i=0;i<sayi;i++){
		printf("%2d.elemani giriniz\n",i+1);
		scanf("%d",sayiDizisi+i);
		//scanf("%d",sayiDizisi[i]);
	}
	//sayi dizisinin ortalamasini bulmak i�in bu sefer dizi notasyonunu kullanalim
	for(i=0;i<sayi;i++){
		toplam+=sayiDizisi[i];
	}
	//ortalamayi hesaplayal�m ve yazd�ral�m
	float ortalama=(float)toplam/(float)sayi;
	printf("girdiginiz dizinin ortalamasi=%2f\n",ortalama);
	
	//program� tamamlamadan �nce olusturdugumuz bellek alanini bosaltal�m
	free(sayiDizisi);
	return 0;
}
//sayfa 438
/*
kac adet sayi giriceksiniz
5
 1.elemani giriniz
1
 2.elemani giriniz
2
 3.elemani giriniz
3
 4.elemani giriniz
4
 5.elemani giriniz
5
girdiginiz dizinin ortalamasi=3.000000
*/
