#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Dizi_yazdir(char** ,int ,int );
int main(){
	int N;//kelime sayisi
	int k,i,j,length=0;
	char pixel;
	char txt[50];
	int max=0;
	char**text;
	printf("lutfen girilecek kelime sayisini giriniz\n");
	scanf("%d",&N);
	
	
	text=(char**)calloc(N,sizeof(char*));
	for(i=0;i<N;i++){
		text[i]=(char*)calloc(50,sizeof(char));
	}
	
	k=0;
	while(k<N){
		printf("lutfen bir cumle giriniz\n");
		scanf("%s",txt);
		
		length=strlen(txt);
		if(length>max){
			max=length;
		}
		
		
		
		for(i=0;i<N;i++){
			for(j=0;j<50;j++){
				if(j<length){
				
				
				text[k][j]=(char)txt[j];
			}
			else{
				text[k][j]='*';
			}
			
		}
	}
	k++;	
	}
	Dizi_yazdir(text,N,max);
	
	for (i = 0; i < N; i++) {
        free(text[i]);
    }
    free(text);
	
	
	
}
void Dizi_yazdir(char **text,int N,int max){
	int i,j;
	printf("__DÝZÝMÝZ__\n");
	for(i=0;i<N;i++){
		for(j=0;j<max;j++){
			printf("%c",text[i][j]);
		}
		printf("\n");
	}
}
