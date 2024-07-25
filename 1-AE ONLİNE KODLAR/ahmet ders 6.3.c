/*
uygulama:sieve of erotoshenes algoritmas�n� kullan�larak kullan�c� taraf�ndan girilen tam sayinin alt�nda kalan butun asal say�lar� hesaplayan program asag�da belirtilen maddelere uyarak yaz�n�z.
1-alt�nda kalan butun asal say�lar�n hesaplanacag� tam sayi kullan�c� taraf�ndan girilecektir(n sayisi)
2-hesaplama sonucunda elde edilen asal say�lar yeni bir dizide tutulacakt�r(boyut 1xn)
3-program c�kt�s� asag�da g�sterildigi gibi olmal�d�r.

sieve of eratoshenes algoritmas� 
bu metot verilen bir tam sayinin alt�nda kalan butun asal say�lar� bulmak i�in kullan�l�r.
oncelikle verilen tam sayiya n denilir ise 2 den n ye kadar olan tum tam say�lar s�ras�yla bir listeye yaz�l�r ve o anda kontrol edilen asal say�ya a denilir ise a^2<n esitligi saglanana kadar a say�s�n�n katlar� bu listeden elenir.eleme i�lemine baslamadan once a sayisi listede kontrol edilmemis en kucuk sayidir ve eleme i�lemi tamamland�ktan sonra henuz kontrol edilmemis en kucuk sayi a sayisinin yeni degeri olur.baslang�cta tum sayilarin asal oldugu kabul edilir ve a degeri 2 ile baslar 

�RNEK 
10 a kadar olan tum asal say�lar� sieve of erotoshenes algoritmasini kullanarak bulunuz.
n=10;

2  3  4  5  6  7  8  9  10

baslang�cta tum sayilar asal sayi olarak kabul edildiginden listenin en kucuk asal sayisi 2^2<=10 esitligini saglad�g� i�in 2 olur ve 2 nin kat� olan tum sayilar l�steden elenir

n=10,a=2

2  3   4x  5  6x  7  8x   9  10x 


listede kontrol edilmemis en kucuk asal sayi 3^2<=10 esitligini saglad�g� i�in 3 olur ve 3 un kat� olan tum sayilar listeden elenir.

n=10,a=3;

2  3  4x  5  6x  7  8x  9x  10x

listede kontrol edilmemis en kucuk asal say� asl�nda 5 dir ancak 5^2<=10 olmad�g� i�in hesaplama bu ad�mda sonlan�r
10 a kadar olan tum asal say�lar 2 3 5 7 olarak bulunur.


*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
 
int main(int argc,char *argv[]){ 
	setLocale(LC_ALL,"Turk�sh");
	//konsoldan turkce karakter girebilmek i�in bunu yazd�k
	int n,i,j,prime_count,*primes;
	
	char *prime_states;
	printf("sieve of eratoshenes algoritmas�n�n kullanrak asal say�\nolusturmak i�in bir tamsayisi giriniz: ");
	scanf("%d",&n);
	n--;//1 zaten asal degil o yuzden
	prime_states=(char*)malloc(n*size(char));
	
	if(prime_states==NULL){
		printf("bellekte alan olusturulmad�.");
		exit(0);
	}
	 
	for(i=0;i<n;i++){
		prime_states[i]=1;//1 =asal sayi demektir  
	}
	
	for(i=0;(i+2)*(i+2)<=n+1;i++){
		if(prime_states[i]==1){
			for(j=(i+2)*(i+2);j<=n+1;j+=i+2){
				prime_states[j-2]=0;
				
				
			}
		}
	}
	prime_count=0;
	for(i=0;i<n;i++){
		if(prime_states[i]==1){
			prime_count++;
		}
		
		
	}
	primes=(int *)malloc(prime_count*sizeof(int));
	if(primes==NULL){
		printf("bellekte alan olusturalamad�.");
		exit(0);
	}
	j=0;
	for(i=0;i<n;i++){
		if(prime_states[i]==1){
				primes[j]=i+2;
				j++;
		}
	}
	 
	 printf("Program c�kt�s�-\n0-%d aras�ndaki asal sayilar:",n+1);
	 
	 for(i=0;i<prime_count;i++){
	 	if(i%10==0){
	 		printf("\n");
	 		if(i==prime_count-1){
	 			printf("%5d",primes[i]);
			 }
			 else{
			 	printf("%5d,",primes[i]);
			 }
		 }
	 }
	 free(prime_states);
	 free(primes);
	 
	 
	
	return 0;
}
