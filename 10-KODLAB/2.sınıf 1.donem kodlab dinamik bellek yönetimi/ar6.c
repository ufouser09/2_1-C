#include <stdio.h>
#include <stdlib.h>

//fonksiyonlar� koda baslamadan �nce tan�mlar�z
void matrisYazdir(int **,int,int);
void transpozYazdir(int **,int,int);

int main(){
	//matris degiskenini tan�mlar�z
	int **matris;
	//satirSayisi ve sutunSayisi degiskenlerini tan�mla
	int satirSayisi,sutunSayisi;
	//kullan�c�dan satir sayisini al�n�z
	printf("olusturacag�n�z matrisin satir sayisini giriniz\n");
	scanf("%d",&satirSayisi);
	//kullan�c�dan sutun sayisini al�n�z
	printf("olusturacag�n�z matrisin sutun sayisini giriniz\n");
	scanf("%d",&sutunSayisi);
	
	matris=(int **)malloc(sizeof(int*)*satirSayisi);
	//i ve j degiskenlerini tan�mla
	int i,j;
	//her bir satir i�in sutun a�
	for(i=0;i<satirSayisi;i++){
		matris[i]=(int *)malloc(sizeof(int)*sutunSayisi);
		
		
	}
	
	printf("---------------\n");
	printf("matris icin elemanlari giriniz\n");
	printf("-------------------\n");
	
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<sutunSayisi;j++){
			printf("matris[%d][%d]=",i,j);
			scanf("%d",&(matris[i][j]));
		}
	}
	printf("------------------\n");
	printf("girdiginiz matris\n");
	printf("----------------\n");
	matrisYazdir(matris,satirSayisi,sutunSayisi);
	
	
	printf("--------------\n");
	printf("matrisin transpozu\n");
	printf("--------------\n");
	transpozYazdir(matris,satirSayisi,sutunSayisi);
	
	//matr�s�n bellekteki adresi bosalt�l�r
	for(i=0;i<satirSayisi;i++){
		free(matris[i]);
	}
		free(matris);
		
		return 0;
	}
	
	void matrisYazdir(int ** matris,int satir,int sutun){
		//i ve j degiskenlerini tan�mla
		int i,j;
		
		for(i=0;i<satir;i++){
			for(j=0;j<sutun;j++){
				printf("%5d",matris[i][j]);
				
				
			}
			
			printf("\n");
		}
	}
	void transpozYazdir(int ** matris,int satir,int sutun){
		int i,j;
		for(i=0;i<sutun;i++){
			for(j=0;j<satir;j++){
				printf("%5d",matris[j][i]);
			}
			printf("\n");
		}
	}
	//sayfa 444
	/*
	olusturacag�n�z matrisin satir sayisini giriniz
3
olusturacag�n�z matrisin sutun sayisini giriniz
2
---------------
matris icin elemanlari giriniz
-------------------
matris[0][0]=1
matris[0][1]=2
matris[1][0]=3
matris[1][1]=4
matris[2][0]=5
matris[2][1]=6
------------------
girdiginiz matris
----------------
    1    2
    3    4
    5    6
--------------
matrisin transpozu
--------------
    1    3    5
    2    4    6
*/
	

