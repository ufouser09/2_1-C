#include <stdio.h>
#include <string.h>

int main(){
	//2 tane char dizisi olustur
	char kelime1[20]="merhaba";
	
	char kelime2[20]="ahmet";
	
	//kelime2 deki 5 harfi kelime1'e kopyalarýz
	strncpy(kelime1,kelime2,5);
	
	//kelime1'i ekrana yazdýrýrýz
	printf("cikan kelimemiz=%s\n",kelime1);
	
	
}
//sayfa 342
