#include <stdio.h>
int main(int argc,const char *argv[]){
	//bir tane char dizisi olustur
	char kelime[20];
	
	//puts fonksiyonu printf'e benzer
	puts("bir kelime giriniz");
	
	//kullanıcıdan kelime oku ve kelime isimli diziye kopyala
	gets(kelime);
	
	//puts ile asagıdaki ifadeyi yazdırırız
	puts("asagidaki kelimeyi girdiniz");
	//kelime isimli karakter dizisinin degerini ekrana bas
	puts(kelime);
	
	return 0;	
}
//bir kelime giriniz
//merhaba
//asagıdaki kelimeyi girdiniz:
//merhaba
//sayfa 327
