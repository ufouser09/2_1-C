#include <stdio.h>
#define MAX(x,y) (x)<(y) ? (y) : (x)

int main(int argc,char** argv){
	int sayi1=0,sayi2=0;
	printf("birinci sayiyi giriniz:\n");
	scanf("%d",&sayi1);
	printf("ikinci sayiyi giriniz\n");
	scanf("%d",&sayi2);
	
	int buyukSayi=MAX(sayi1,sayi2);
	printf("girdiginiz sayilardan buyuk olani:%d\n",buyukSayi);
	
	return 0;
}

