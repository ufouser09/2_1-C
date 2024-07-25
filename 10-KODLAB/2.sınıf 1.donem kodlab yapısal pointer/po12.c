#include <stdio.h>
#define notsayisi 10

//ilk once fonksiyonu algoritmaya tanýtýrýz
void kullanicidanNotlariOKu(int *,int);
double ortalamaBul(int *,int);

int main(){
	//notlar diye bir dizi tanýmlarýz
	int notlar[notsayisi];
	//notlar dizisinin basýndaki eleman p pointerýna atýlýr//int *p=&notlar[0]; bu sekilde de yapabilirsin
	int *p=notlar;
	
	//fonksiyona p pointerýný ve dizinin boyutunu atarýz
	kullanicidanNotlariOku(p,notsayisi);
	//fonksiyona p pointerini ve dizinin boyutunu atarýz
	double ortalama=ortalamaBul(p,notsayisi);
	
	//bulunan ortalamayý ekrana yazdýrýrýz
	printf("girdiginiz degerlerin ortlamasi=%.2f\n",ortalama);
	
	return 0;
}
//fonksiyona p pointerini ve dizinin boyutunu atarýz burda dikkat edilmesi gereken nokta parametre verirken p diye verdik alýrken int *p diye alýyoruz pointerda
void kullanicidanNotlariOku(int *p,int sayi){
	//i degiskenini tanýmlarýz
	int i;
	//kullanýcýdan diziyi alýrýz diziyi alýrken p+i diye alýyoruz çünkü pointer larda *p degeri p ise adresi gösterir
	for(i=0;i<sayi;i++){
		printf("%2d.sayiyi giriniz",i+1);
		scanf("%d",p+i);
	}
}
//ortalama bul fonksiyonuna p pointerý ve dizinin boyutu atýlýr
double ortalamaBul(int *p,int sayi){
	//i degiskeni tanýmlanýr
	int i;
	//toplam degiskeni tanýmlanýr ve 0 degeri atýlýr
	double toplam=0;
	
	//girdigimiz dizideki elemanlarý sýrasýyla toplar dizinin degerlerine erismek için *(p+i)'yi kullandýk
	for(i=0;i<sayi;i++){
		toplam+=*(p+i);
		
	}
	//bu ise dizideki tum elemanlarýn toplamýný dizinin boyutuna bölerek ortalamayý bulur ve onu döndürür
	return (double)toplam/(double)sayi;
}
//sayfa 400
/*
 1.sayiyi giriniz1
 2.sayiyi giriniz2
 3.sayiyi giriniz3
 4.sayiyi giriniz4
 5.sayiyi giriniz5
 6.sayiyi giriniz6
 7.sayiyi giriniz7
 8.sayiyi giriniz8
 9.sayiyi giriniz9
10.sayiyi giriniz10
girdiginiz degerlerin ortlamasi=5.50

*/
