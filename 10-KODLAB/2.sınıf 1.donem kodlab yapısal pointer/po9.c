#include <stdio.h>
//burda fonksiyonu �nceden tan�mlar�z
void sifirla(int);

int main(){
	//sayi degiskenini tan�mlar ve 10 sayisini ona atar�z
	int sayi=10;
	//sifirla fonksiyonuna gider
	sifirla(sayi);
	//sayi degiskenini ekrana yazd�r�r
	printf("sayi=%d",sayi);
	
}
//sayi bu fonksiyona gelir
void sifirla(int arg){
	arg=0;
}
//sayfa 396
//normalde bu program kendisine g�denrilen sayiyi sifirlamayi ama�lamaktadir fakat istenileni yapmaz
/*
sayi=10
*/
