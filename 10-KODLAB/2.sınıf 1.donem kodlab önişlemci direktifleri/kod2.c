#include <stdio.h>
#define KAREBUL(sayi) sayi*sayi

int main(int argc,char** argv){
	int tamSayi=5;
	float ondalikliSayi=8.32;
	int kare1=KAREBUL(tamSayi);
	float kare2=KAREBUL(ondalikliSayi);
	printf("%d sayisinin karesi %d\n",tamSayi,kare1);
	printf("%.2f sayisinin karesi %.2f\n",ondalikliSayi,kare2);
	
	return 0;
}
