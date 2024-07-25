//yýgýnV2
#include <stdio.h>
#include <stdlib.h>
typedef struct eleman{
	int deger;
	struct eleman *sonraki;
}Eleman;

void push(int val,int *head);
int pop(Eleman *head);

int main(void){
	Eleman *baslangic,*bitis;
	int deger;
	
	baslangic=(Eleman *)malloc(sizeof(Eleman));
	bitis=(Eleman *)malloc(sizeof(Eleman));
	baslangic->sonraki=bitis;
	
	do{
		printf("tamsayi giriniz(cikis için -1):");
		scanf("%d",&deger);
		
		if(deger!=-1){
			push(deger,baslangic);
		}
	}while(deger !=-1);
	
	printf("yýgýn ustten alta durumu:");
	
	
	do{
		printf("%d\n",pop(baslangic));
	}
	while(baslangic->sonraki !=bitis);
}
	void push(int val,Eleman *baslangic){,
	Eleman *eklenecek;
	eklenecek=(Eleman *)malloc(sizeof(Eleman));
	eklenecek->deger=val;
	eklenecek->sonraki=baslangic->sonraki;
	baslangic->sonraki=eklenecek;
	}
	int pop(Eleman *baslangic){
		Eleman *gecici;
		int val=baslangic->sonraki->deger;
		gecici=baslangic->sonraki;
		baslangic->sonraki=baslangic->sonraki->sonraki;
		free(gecici);
		
		return val;
	}
	
	

