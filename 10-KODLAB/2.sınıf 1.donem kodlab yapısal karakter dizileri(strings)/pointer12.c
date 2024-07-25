#include <stdio.h>
#include <string.h>
int main(){
	//i degiskenini tanýmla
	int i;
	//bir tane char dizisi olustur
	char dizi1[]="merhaba";
	//bir tane char dizisi olustur
	char dizi2[]="ahmet";
	//dizi1 in boyutunu al ve onu uzunluk1 degiskenine ata
	int uzunluk1=strlen(dizi1);
	//dizi2'nin boyutunu al ve onu uzunluk2 degiskenine ata
	int uzunluk2=strlen(dizi2);
	//
	for(i=0;i<uzunluk2;i++){
		 dizi1[uzunluk1+i]=dizi2[i];
		
		
	}
	dizi1[uzunluk1+i]='\0';
	printf("dizi1=%s\n",dizi1);
	printf("dizi2=%s\n",dizi2);
}
//sayfa 335
/*
dizi1=merhabaahmet
dizi2=ahmet
*/
