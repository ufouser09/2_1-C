#include <stdio.h>
int main(int argc,const char *argv[]){
	//bir tane char dizisi olustur
	char kelime[20];
	
	//puts fonksiyonu printf'e benzer
	puts("bir kelime giriniz");
	
	//kullan�c�dan kelime oku ve kelime isimli diziye kopyala
	gets(kelime);
	
	//puts ile asag�daki ifadeyi yazd�r�r�z
	puts("asagidaki kelimeyi girdiniz");
	//kelime isimli karakter dizisinin degerini ekrana bas
	puts(kelime);
	
	return 0;	
}
//bir kelime giriniz
//merhaba
//asag�daki kelimeyi girdiniz:
//merhaba
//sayfa 327
