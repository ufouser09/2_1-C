#include <stdio.h>
#include <stdlib.h> 
typedef struct complex{
	int r;
	int i;
	struct complex *next;//pointerl� bir �eyi boyle tutabilirsin struct�n i�ince fakat pointers�z tutamazs�n
}COMPLEX;
void ekrana_yaz(COMPLEX [],int);
void ekrana_yazv2(COMPLEX *c,int N);
void sil(COMPLEX c[],int N);
void sil_v2(COMPLEX *c,int N);
void silref(COMPLEX *c);
void silvalue(COMPLEX c);
int main(){
	int a=7;
	int *pa;
	pa=&a;//bu i�lemi yapman cok onemli pointer�n bir yeri g�stermeden deger at�yamazs�n
	*pa=9;
	
	COMPLEX *c5=malloc(1*sizeof(COMPLEX));
	c5->r=1;
	c5->i=2;
	COMPLEX *c6=malloc(1*sizeof(COMPLEX));
	c6->r=3;
	c6->i=4;
	COMPLEX *c7=malloc(1*sizeof(COMPLEX));
	c7->r=3;
	c7->i=4;
	
	c5->next=c6;
	c6->next=c7;
	c7->next=NULL;//NULL yerine c5 dersek dairesel bir donguye girer yani sonsuz d�nguye girer.
	COMPLEX *tmp;
	tmp=c5->next;
	while(tmp!=NULL){
		printf("%d %d -------%d %d \n ",tmp->i,tmp->r,tmp->next->i,tmp->next->r);
		tmp=tmp->next;
	}
	
	
	
	
	COMPLEX c[3],*c2;
	int N=5;
	ekrana_yaz(c,3);//ekrana yazma i�lemini pass by referancela da yapabilirim pass by value ile de yapabilirim bir �ey fark etmez
	sil(c,3);//array-pass by reference 
	//ekrana_yaz(c,3);
	
	printf("\n%d %d",c[2].r,c[2].i);
	silvalue(c[2]);
	printf("\n%d %d",c[2].r,c[2].i);
	
	printf("\n%d %d",c[2].r,c[2].i);
	silref(&c[2]);
	printf("\n%d %d",c[2].r,c[2].i);
	
	c2=(COMPLEX*)malloc(N*sizeof(COMPLEX));
	ekrana_yazv2(c2,N);
	sil_v2(c2,N);
	ekrana_yazv2(c2,N);
}
void ekrana_yazv2(COMPLEX *c,int N){
	int j=0;
	for(j=0;j<N;j++){
		printf("%d %dj\n",c[j].r,c[j].i);
	}
}
void ekrana_yaz(COMPLEX c[],int N){
	int j=0;
	for( j=0;j<N;j++){
		printf("%d %dj\n",c[j].r,c[j].i);
	}
}
void silref(COMPLEX *c){
	c->r=c->i=0;
}
void silvalue(COMPLEX c){
	c.r=c.i=0;
}
void sil(COMPLEX c[],int N){
	int j=0;
	for(j=0;j<N;j++){
		c[j].r=c[j].i=0;
	}
}
void sil_v2(COMPLEX *c,int N){
	int j=0;
	for(j=0;j<N;j++){
		c[j].r=c[j].i=0;
	}
}
/*

