#include <stdio.h>
#include <string.h>
int main(int argc,const char *argv){
	//bir tane char dizisi olustur
	char dizi1[20]="mehmet";
	//bir tane char dizisi olustur
	char dizi2[20];
	//i ve len degiskenlerini tanýmla
	int i,len;
	//dizi1 in boyutunu strlen ile al ve o degeri len degiskenine ata
	len=strlen(dizi1);
	//<=len ifadesinin nedeni dizinin sonundaki null karakterini almak için yaptýk onu
	for(i=0;i<=len;i++){
		dizi2[i]=dizi1[i];
	}
	//dizi2 yi ekrana yazdýr
	printf("%s",dizi2);
return 0;

}
//sayfa 334
/*
mehmet
*/
