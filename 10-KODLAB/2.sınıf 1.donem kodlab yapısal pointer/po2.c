#include <stdio.h>
int main(){
	//sayi degiskenin degerine 15 sayisini atarız
	int sayi=15;
	//sayi degiskenini ekrana yazdırırız
	printf("sayi degiskenin degeri=%d\n",sayi);
	//sayi degiskenin adresini yazdırırız
	printf("sayi degiskenin bellek adresi=%p\n",&sayi);
	//p isaretcisini tanımlarız ve ona null degerini atarız
	int *p=NULL;
	//p isaretcisinin adresini ekrana yazdırırız
	printf("p isaretcisinin tanımlama zamanındaki degeri=%p\n",p);
	//isaretciye sayi degiskenin bellek adresini kopyalıyalım
	p=&sayi;
	//p isaretcisi artık sayi degiskeninin adresini gösterir
	printf("p isaretcisinin yeni degeri=%p\n",p);
	//p isaretcisi artık sayi degiskenin adresini gösterdigi için p pointerımız 15 degerini alır
	printf("p degiskeninin tuttugu bellek adresindeki deger=%d\n",*p);
	//p pointerına 16 degerini atarız
	*p=16;
	//p pointer'ı artık 16 degerini gösterir
	printf("p isaretcisinin tuttugu bellek adresindeki yeni deger=%d\n",*p);
	//p pointerını degistirdigimiz için sayi degiskenin degeri de degisir ve o da 16 degerini gösterir
	printf("sayi degiskenin yeni degeri=%d\n",sayi);
	
	return 0;
}
//sayfa 374
/*
sayi degiskenin degeri=15
sayi degiskenin bellek adresi=000000000062FE14
p isaretcisinin tan²mlama zaman²ndaki degeri=0000000000000000
p isaretcisinin yeni degeri=000000000062FE14
p degiskeninin tuttugu bellek adresindeki deger=15
p isaretcisinin tuttugu bellek adresindeki yeni deger=16
sayi degiskenin yeni degeri=16
*/
