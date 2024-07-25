/*Car isminde bir struct olusturunuz.bu struct araca ait fiyat,model yili ve marka bilgilerini saklamal�d�r.
main i�erisinde kullan�c�dan N eleman sayisi alindiktan sonra 
1-CAR * AllocateSpace(N) isimli fonksiyon N degerini alacak ve N elemanl� car dizisi olusacakt�r�
2-1.madde olusturulan dizi i�ine veriler main() i�erisinde kullanicidan alinacaktir.
3-main() i�erisinde kullanicidan alinan yil bilgisine g�re ara� bulma i�lemi yap�lacakt�r
bu islem i�in void FindCars(CAR *,int N,int year);fonksiyonunu yaz�n�z.
fonksiyonda modelYear degeri year degerine esit olan ara�lar�n tum bilgilerini ekrana yazdiriniz
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct car{
unsigned int fiyat;
unsigned int model;
char marka[25];

}CAR;

CAR* AllocateSpace(int);
void get_info(CAR *,int);
void write_info(CAR *,int);
void FindCars(CAR *,int ,int );

int main(){
	CAR *ptrCar;
	int N;
	int i,yil;
	printf("N ?");
	scanf("%d",&N);
	
	ptrCar=AllocateSpace(N);
	get_info(ptrCar,N);
	write_info(ptrCar,N);
	printf("Aranacak yil bilgisi");
	scanf("%d",&yil);
	FindCars(ptrCar,N,yil);
	
}
void FindCars(CAR *ptrCar,int N,int year){
	int i;
	printf("SiraNo \t Yil \t Fiyat \t Marka\n");
	for(i=0;i<N;i++){
		if(ptrCar[i].model==year){
			printf("%d \t %d \t %d \t %s \n",i,ptrCar[i].model,ptrCar[i].fiyat,ptrCar[i].marka);
		}
	}
}
void get_info(CAR *ptrCar,int N){
	int i;
	for(i=0;i<N;i++){
		printf("yil giriniz");
		scanf("%d",&ptrCar[i].model);
		
		printf("fiyat giriniz\n");
		scanf("%d",&ptrCar[i].fiyat);
		
		printf("marka giriniz\n");
		scanf("%s",ptrCar[i].marka);
	}
}
void write_info(CAR *ptrCar,int N){
	int i;
	printf("sitaNo \t Yil \t Fiyat \t Marka\n");
	for(i=0;i<N;i++){
		printf("%d \t %d \t %d \t %s \n",i,ptrCar[i].model,ptrCar[i].fiyat,ptrCar[i].marka);
	}
}

CAR * AllocateSpace (int N){
	CAR *ptrCar;
	ptrCar=(CAR*)malloc(N*sizeof(CAR));
	if(ptrCar==NULL){
		printf("yer ayrilmadi");
		return NULL;
	}
	else{
		printf("yer ayrildi");
		return ptrCar;
	}
	
}
