#include <stdio.h>
#include <string.h>
int main(){
	//bir kelime dizisi tan�mlay�n�z
	char kelime[50];
	//kullan�c�dan bir kelime al�n�z
	printf("bir metin giriniz\n");
	gets(kelime);
	//kelime nin boyutunu strlen sayesinde al�n�z
	int uzunluk=strlen(kelime);
	//ekrana uzunlu�u giriniz
	printf("girdiginiz metindeki karakter sayisi=%d\n",uzunluk);
	
	//kelime degiskenine string ifadeyi kopyalay�n�z
	strcpy(kelime,"kodlab yay�nevi");
	//kelime degiskenini ekrana yazd�rcaz
	puts(kelime);
	
	//girdiginiz kelimenin boyutunu ekrana yazd�r�r
	printf("girdiginiz metindeki karakter sayisi=%d\n",strlen(kelime));
	
	//strcat sayesinde kelime degiskenine String ifadeyi ekleriz
	strcat(kelime,"her yonuyle c");
	//kelime degiskenini ekrana yazd�rcaz
	puts(kelime);
	//kelimenin boyutunu ekrana yazd�r�r
	printf("girdiginiz metindeki karakter sayisi=%d\n",strlen(kelime));
	//bir tane char dizisi olustur
	char dizi1[]="kitap";
	char dizi2[]="defter";
	char dizi3[]="kitap";
	
	//dizi1 ve dizi2'yi kars�last�r
	if(strcmp(dizi1,dizi2)==0){
	
	printf("%s ve %s ayni\n",dizi1,dizi2);
}
	else{
	
	printf("%s ve %s farkli\n",dizi1,dizi2);
}
	
	//Dizi1 ve dizi3 � kars�last�r
	if(strcmp(dizi1,dizi3)==0){
		printf("%s ve %s ayni\n",dizi1,dizi3);
		}
	else{
		printf("%s ve %s farkli\n",dizi1,dizi3);
	}
	//Dizi1 ve dizi3'� kars�last�r
	if(strcmp(dizi1,dizi3)==0){
		printf("%s ve %s ayni\n",dizi1,dizi3);
	}
	else{
		printf("%s ve %s farkli\n",dizi1,dizi3);
	}
	
	
}



//sayfa 339
