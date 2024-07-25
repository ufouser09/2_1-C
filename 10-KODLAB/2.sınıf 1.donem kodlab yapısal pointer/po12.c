#include <stdio.h>
#define notsayisi 10

//ilk once fonksiyonu algoritmaya tan�t�r�z
void kullanicidanNotlariOKu(int *,int);
double ortalamaBul(int *,int);

int main(){
	//notlar diye bir dizi tan�mlar�z
	int notlar[notsayisi];
	//notlar dizisinin bas�ndaki eleman p pointer�na at�l�r//int *p=&notlar[0]; bu sekilde de yapabilirsin
	int *p=notlar;
	
	//fonksiyona p pointer�n� ve dizinin boyutunu atar�z
	kullanicidanNotlariOku(p,notsayisi);
	//fonksiyona p pointerini ve dizinin boyutunu atar�z
	double ortalama=ortalamaBul(p,notsayisi);
	
	//bulunan ortalamay� ekrana yazd�r�r�z
	printf("girdiginiz degerlerin ortlamasi=%.2f\n",ortalama);
	
	return 0;
}
//fonksiyona p pointerini ve dizinin boyutunu atar�z burda dikkat edilmesi gereken nokta parametre verirken p diye verdik al�rken int *p diye al�yoruz pointerda
void kullanicidanNotlariOku(int *p,int sayi){
	//i degiskenini tan�mlar�z
	int i;
	//kullan�c�dan diziyi al�r�z diziyi al�rken p+i diye al�yoruz ��nk� pointer larda *p degeri p ise adresi g�sterir
	for(i=0;i<sayi;i++){
		printf("%2d.sayiyi giriniz",i+1);
		scanf("%d",p+i);
	}
}
//ortalama bul fonksiyonuna p pointer� ve dizinin boyutu at�l�r
double ortalamaBul(int *p,int sayi){
	//i degiskeni tan�mlan�r
	int i;
	//toplam degiskeni tan�mlan�r ve 0 degeri at�l�r
	double toplam=0;
	
	//girdigimiz dizideki elemanlar� s�ras�yla toplar dizinin degerlerine erismek i�in *(p+i)'yi kulland�k
	for(i=0;i<sayi;i++){
		toplam+=*(p+i);
		
	}
	//bu ise dizideki tum elemanlar�n toplam�n� dizinin boyutuna b�lerek ortalamay� bulur ve onu d�nd�r�r
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
