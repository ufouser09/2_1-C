#include <stdio.h>
#include <string.h>

int main(){
	//bir tane char dizisi olustur
	char dogruCevap[]="Ankara";
	//bir tane char dizisi olustur
	char cevap[20];
	//kullanýcýdan bir cevap al
	printf("türkiyenin baskenti hangi ilimizdir\n");
	scanf("%s",cevap);
	
	//cevap ve dogru cevabý karsýlastýr
	if(strcmp(cevap,dogruCevap)==0){
		printf("cevabýnýz dogrudur\n");
		
	}
	else{
		printf("cevabýnýz yanlýþtýr\n");
	}
	return 0;
	
}
//sayfa 336
/*
t³rkiyenin baskenti hangi ilimizdir
efe
cevab²n²z yanl²¦t²r
*/
/*
t³rkiyenin baskenti hangi ilimizdir
Ankara
cevab²n²z dogrudur
*/
