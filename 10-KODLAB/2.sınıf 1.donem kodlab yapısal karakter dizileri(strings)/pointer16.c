#include <stdio.h>
#include <string.h>
int main(){
	//bir kelime dizisi tanýmlayýnýz
	char kelime[50];
	//kullanýcýdan bir kelime alýnýz
	printf("bir metin giriniz\n");
	gets(kelime);
	//kelime nin boyutunu strlen sayesinde alýnýz
	int uzunluk=strlen(kelime);
	//ekrana uzunluðu giriniz
	printf("girdiginiz metindeki karakter sayisi=%d\n",uzunluk);
	
	//kelime degiskenine string ifadeyi kopyalayýnýz
	strcpy(kelime,"kodlab yayýnevi");
	//kelime degiskenini ekrana yazdýrcaz
	puts(kelime);
	
	//girdiginiz kelimenin boyutunu ekrana yazdýrýr
	printf("girdiginiz metindeki karakter sayisi=%d\n",strlen(kelime));
	
	//strcat sayesinde kelime degiskenine String ifadeyi ekleriz
	strcat(kelime,"her yonuyle c");
	//kelime degiskenini ekrana yazdýrcaz
	puts(kelime);
	//kelimenin boyutunu ekrana yazdýrýr
	printf("girdiginiz metindeki karakter sayisi=%d\n",strlen(kelime));
	//bir tane char dizisi olustur
	char dizi1[]="kitap";
	char dizi2[]="defter";
	char dizi3[]="kitap";
	
	//dizi1 ve dizi2'yi karsýlastýr
	if(strcmp(dizi1,dizi2)==0){
	
	printf("%s ve %s ayni\n",dizi1,dizi2);
}
	else{
	
	printf("%s ve %s farkli\n",dizi1,dizi2);
}
	
	//Dizi1 ve dizi3 ü karsýlastýr
	if(strcmp(dizi1,dizi3)==0){
		printf("%s ve %s ayni\n",dizi1,dizi3);
		}
	else{
		printf("%s ve %s farkli\n",dizi1,dizi3);
	}
	//Dizi1 ve dizi3'ü karsýlastýr
	if(strcmp(dizi1,dizi3)==0){
		printf("%s ve %s ayni\n",dizi1,dizi3);
	}
	else{
		printf("%s ve %s farkli\n",dizi1,dizi3);
	}
	
	
}



//sayfa 339
