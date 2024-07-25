#include <stdio.h>
int main(){
	//2 tane char dizisi olustururuz
	char dizi1[20]="merhaba";
	char dizi2[20]="ahmet";
	
	//dizi2'deki 5 harfi dizi1'e atarsýn
	strncat(dizi1,dizi2,5);
	//dizi1'i ekrana yazdiririz
	printf("%s",dizi1);
	
}
//sayfa 343
/*
merhabaahmet
*/
