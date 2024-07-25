#include <stdio.h>
#include <string.h>

int main(int argc,const char *argv[]){
	//bir tane char dizisi olustur
	char dizi1[20]="merhaba";
	//bir tane char dizisi olustur
	char dizi2[20];
	//kullanýcýdan lutfen bir kelime alýnýz
	printf("lutfen bir kelime giriniz\n");
	//String alýrken & adres isaretini kullanmamýza gerek yok
	scanf("%s", dizi2);
	
	//dizi2 yi dizi1'e ekle
	strcat(dizi1, dizi2);
	//dizi1'i yazdir
	printf("%s",dizi1);
	
	return 0;
}
//sayfa 335
