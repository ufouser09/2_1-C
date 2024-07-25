#include <stdio.h>
#include <stdlib.h>

int main(){
	//sayi degiskenini tanýmlarýz
	int sayi;
	//toplam degiskenini tanýmlar ve 0 degerini atarýz
	int toplam=0;
	//kullanýcýdan kac adet sayi gircegini alýnýz
	printf("kac adet sayi giriceksiniz\n");
	scanf("%d",&sayi);
	
	//kullanicinin girdigi sayi kadar int tutacak bellek alaný olusturalým
	int *sayiDizisi=(int *)malloc(sizeof(int)*sayi);
	
	//i degiskenini tanýmlarýz
	int i;
	//sayidizisi+i yaparak kullanýcýdan degerleri alýrýz
	for(i=0;i<sayi;i++){
		printf("%2d.elemani giriniz\n",i+1);
		scanf("%d",sayiDizisi+i);
		//scanf("%d",sayiDizisi[i]);
	}
	//sayi dizisinin ortalamasini bulmak için bu sefer dizi notasyonunu kullanalim
	for(i=0;i<sayi;i++){
		toplam+=sayiDizisi[i];
	}
	//ortalamayi hesaplayalým ve yazdýralým
	float ortalama=(float)toplam/(float)sayi;
	printf("girdiginiz dizinin ortalamasi=%2f\n",ortalama);
	
	//programý tamamlamadan önce olusturdugumuz bellek alanini bosaltalým
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
