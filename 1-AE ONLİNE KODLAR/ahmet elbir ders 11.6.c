#include <stdio.h>
#include <stdlib.h>
//bu oyunda futbolcu farkl� �ekillerde gol at�yor ne kadar s�rede gol att�g�yla alakal� 3 mac� dikkate al�nm�s

typedef struct{
	int no,duration,goal[3];
}GAME;

GAME *allocate(int);
int calculate(GAME *,int);
GAME calculatev2(GAME *,int );
GAME calculatev3(GAME *,int );
GAME calculatev4(GAME *,int );

//yield=(goal1+goal2+goal3)/duration;//toplam gol say�s�n� toplam ne kadar s�re oynad�g�na boluyoruz.ve b�ylece bu oyuncunun puan� hesaplanacak.
int main(){
	int n,i;
	int index;
	GAME *ptr;
	GAME element,element2,element3;
	printf("Oyuncu sayisi");
	scanf("%d",&n);
	ptr=allocate(n);
	
	for(i=0;i<n;i++){
		printf("%dth player\n",i);
		printf("No:");
		scanf("%d",&ptr[i].no);
		printf("Duration");
		scanf("%d",&ptr[i].duration);
		printf("Goals");
		scanf("%d %d %d",&ptr[i].goal[0],&ptr[i].goal[1],&ptr[i].goal[2]);
	}
	index=calculate(ptr,n);
	printf("NO:%d",ptr[index].no);
	element=calculatev2(ptr,n);
	printf("\nNO(v2):%d",element.no);
	element2=calculatev3(ptr,n);
	printf("\nNO(v3):%d",element2.no);
	element3=calculatev4(ptr,n);
	printf("\nNO(v4):%d",element3.no);
}
GAME calculatev4(GAME *ptr,int n){
	int i;
	GAME yield1;
	float yield=0,maxyield=0;
	for(i=0;i<n;i++){
		yield=(float)((*(ptr+i)).goal[0]+(*(ptr+i)).goal[1]+(*(ptr+i)).goal[2])/((*(ptr+i)).duration);
	if(yield>maxyield){
		maxyield=yield;
		yield1=*ptr;
	}	
	}
	return yield1;
}
GAME calculatev3(GAME *ptr,int n){
	int i;
	GAME yield1;
	float yield=0,maxyield=0;
	for(i=0;i<n;i++){
		yield=(float)(ptr->goal[0]+ptr->goal[1]+ptr->goal[2])/(ptr->duration);
		if(yield>maxyield){
			maxyield=yield;
			yield1=*ptr;
		}	
		ptr++;
		
	}
	return yield1;
}
GAME calculatev2(GAME *ptr,int n){
	int i;
	GAME yield1;
	float yield=0,maxyield=0;
	for(i=0;i<n;i++){
		yield=(float)(ptr[i].goal[0]+ptr[i].goal[1]+ptr[i].goal[2])/ptr[i].duration;
		if(yield>maxyield){
			maxyield=yield;
			yield1=ptr[i];
		}	
	
		
		}
		return yield1;
}
int calculate(GAME *ptr,int n){
	int i,index;
	
	float yield=0,maxyield=0;
	for(i=0;i<n;i++){
		yield=(float)(ptr[i].goal[0]+ptr[i].goal[1]+ptr[i].goal[2])/ptr[i].duration;
		
	if(yield>maxyield){
			index=i;
			maxyield=yield;
			
		}		
	}
	return index;
}
GAME *allocate(int n){
	GAME *ptr=(GAME*)malloc(n*sizeof(GAME));
	
	return ptr;
}
//38.00
