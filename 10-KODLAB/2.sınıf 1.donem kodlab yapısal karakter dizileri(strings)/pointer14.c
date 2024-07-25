#include <stdio.h>
#include <string.h>
int main(){
	//i degiskenini tanýmla
	int i;
	//bir tane char dizisi olustur
	char dizi1[20];
	//bir tane char dizisi olustur
	char dizi2[30];
	//kullanýcýdan dizi al
	printf("lutfen ilk diziyi giriniz\n");
	scanf("%s",dizi1);
	//kullanýcýdan 2.diziyi al
	printf("lutfen 2.diziyi giriniz\n");
	scanf("%s",dizi2);
	
	while(dizi1[i]!='\0'&&dizi2[i]!='\0'){
		
		if(dizi1[i]==dizi2[i]){
			i++;
		}
		
		
	}
	int uzunluk1=strlen(dizi1);
	int uzunluk2=strlen(dizi2);
	if(i==uzunluk1&&uzunluk1==uzunluk2){
	
	printf("dizilerimiz aynýdýr\n");
}
else{
	printf("dizilerimiz ayný degildir\n");
}
}
//sayfa 337
/*
lutfen ilk diziyi giriniz
efe
lutfen 2.diziyi giriniz
efe
dizilerimiz ayn²d²r
*/
/*
lutfen ilk diziyi giriniz
efe
lutfen 2.diziyi giriniz
ef
dizilerimiz ayn² degildir
*/
