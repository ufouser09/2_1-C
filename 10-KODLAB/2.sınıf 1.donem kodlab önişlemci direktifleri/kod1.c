#include <stdio.h>
#include <stdlib.h>

void yazdir();
int main(int argc,char** argv){
	const int SABIT_SAYI1=10;
	#define SABIT_SAYI2 15
	
	printf("Sabýt_sayý1=%d\n",SABIT_SAYI1);
	printf("sabit _sayi2=%d\n",SABIT_SAYI2);
	
	yazdir();
	
	return 0;
	
}
void yazdir(){
	printf("SABIT_SAYI1=%d\n",SABIT_SAYI1);
	printf("SABIT_SAYI2=%d\n",SABIT_SAYI2);
	
	
}
