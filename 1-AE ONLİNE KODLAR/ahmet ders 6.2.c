#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *argv[]){ 
int n,m,i,j,pixel,textIndex=0;
char *text;
int **theImage;



printf("enter Image Size:M\n");
scanf("%d",&m);

text=(char *)(malloc)(sizeof(char));

theImage=(int**)(calloc)(m,sizeof(int*));
for(i=0;i<m;i++){
	
	theImage[i]=(int*)(calloc)(m,sizeof(int));
	
}
printf("enter the pixel values from top left to bottom right\n");
for(i=0;i<m;i++){
	for(j=0;j<m;j++){
		printf("(%d,%d)=",i,j);
		scanf("%d",&pixel);
		theImage[i][j]=pixel;
	}
}
//�imdi hesaplad�gm�z her bir deger i�in text arrayini geni�leticez
for(i=0;i<m;i++){
	for(j=0;j<m;j++){
		//text arrayimizi bir karakter boyutunda geni�lettik
		text=(char*)(realloc)(text,sizeof(char));
		//daha sonra geni�lettigimiz indextte  
		text[textIndex]=(char)theImage[i][j]; 
		textIndex++;
		   
	}
}
printf("the text that was hidden �nto the Image is:%s\n",text);
free(theImage);
free(text);   
return 0;
}
//KOD CALISIYOR 
//ACIKLAMALAR YAZILDI
