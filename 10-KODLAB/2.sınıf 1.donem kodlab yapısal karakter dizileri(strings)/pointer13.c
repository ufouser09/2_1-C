#include <stdio.h>
#include <string.h>

int main(){
	//bir tane char dizisi olustur
	char dogruCevap[]="Ankara";
	//bir tane char dizisi olustur
	char cevap[20];
	//kullan�c�dan bir cevap al
	printf("t�rkiyenin baskenti hangi ilimizdir\n");
	scanf("%s",cevap);
	
	//cevap ve dogru cevab� kars�last�r
	if(strcmp(cevap,dogruCevap)==0){
		printf("cevab�n�z dogrudur\n");
		
	}
	else{
		printf("cevab�n�z yanl��t�r\n");
	}
	return 0;
	
}
//sayfa 336
/*
t�rkiyenin baskenti hangi ilimizdir
efe
cevab�n�z yanl��t�r
*/
/*
t�rkiyenin baskenti hangi ilimizdir
Ankara
cevab�n�z dogrudur
*/
