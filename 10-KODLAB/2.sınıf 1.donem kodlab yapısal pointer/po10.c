#include <stdio.h>
//en basta fonksiyonu algoritmaya tan�t�r�z
void sifirla(int *);

int main(){
	//sayi diye bir degisken olusturur ve ona 10 sayisini atar�z
	int sayi=10;
	//sayi degiskenin adresini fonksiyona g�ndeririz
	sifirla(&sayi);
	//sayi degiskenini yazd�r�r�z
	printf("sayi=%d",sayi);
}
//sayi degiskenin adresi fonksiyona gelir
void sifirla(int *arg){
	//burda gelen say�m�z� 0 lar�z
	*arg=0;
}
//sayfa 397
