#include <stdio.h>
int main(){
	//i degiskenini tan�mla
	int i;
	char dizi1[30];
	char dizi2[50];
	printf("lutfen dizi1 giriniz\n");
	scanf("%s",dizi1);
	
	printf("lutfen dizi2 giriniz\n");
	scanf("%s",dizi2);
	
	int uzunluk1=strlen(dizi1);
	if(uzunluk1==strlen(dizi2)){
		for(i=0;i<=uzunluk1;i++){
			if(	dizi1[i]==dizi2[i]){
				i++;
			}
			else{
				printf("diziler ayn� degildir\n");
			}
			
			}
		
		}
			else{
			printf("diziler ayn� degildir\n");
	
		}
	
		}
	
	
	


//sayfa 338
