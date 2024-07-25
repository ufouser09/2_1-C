#include <stdio.h>
int main(){
	//sayi degiskeni olusturup ona 10 degerini atadık
	int sayi=10;
	//sayi degiskenin adresini *pointerına atadık
	int *p=&sayi;
	//p pointerına 16 degerini atadık
	*p=16;
	//p pointerına 16 degerini atddık
	printf("sayi=%d\n",*p);
	//p pointerını degistirdigimiz için p pointerı da sayi degiskenin adresini gösterdigi için sayi degiskeninin degerini de degistirdi
	printf("sayi=%d\n",sayi);
	//isaretcıye NULL degerini atadık
	p=NULL;
	
	
	//asagidaki ifade p isaretcisinin tuttugu bellek adresinde bulunan degeri 20 olarak degistirmeye calısmaktadir.
	//null degeri atanmıs bir isaretci hicbir bellek adresi tutmucagı için asagıdaki ifade hatalidir.
	
	//*p=20;
}
//sayfa 373
/*
sayi=16
sayi=16
*/
