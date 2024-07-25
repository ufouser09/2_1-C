#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int urunKodu;
	char urunAdi[30];
	float birimFiyat;
	float kiloFiyat;

	
}Urun;

void list_yaz(Urun urunler[],int uzunluk ){
	int i;
	for(i=0;i<uzunluk;i++){
		printf("%d \t %s \t %f \t %f \n",urunler[i].urunKodu,urunler[i].urunAdi,urunler[i].birimFiyat,urunler[i].kiloFiyat);
		
	}
}

float hesapla(Urun urunler[], int alisTipi, float miktar,int urunKodu) {
    if (alisTipi == 1) {
        return urunler[urunKodu-1].birimFiyat * miktar;
    } else {
        return urunler[urunKodu-1].kiloFiyat * miktar;
    }
}


float indirimHesapla(float tutar){
	if(tutar<50){
		return tutar;
	}else if(tutar>=50 && tutar<100){
		return tutar *0.95;
	}
	else{
		return tutar*0.90;
	}
}


int main(){
	int urunKodu,alisTipi;
	float miktar,toplamTutar=0;
	float indirimliTutar=0;
	char key[]="E";
	
	
	Urun urunler[6]={
	{1,"dometes",8.25,23.75},
	{2,"biber",6.25,29.50},
	{3,"sut",15.85,27.15},
	{4,"peynir",23.00,95.50},
	{5,"muz",13.45,45.50},
	{6,"armut",5.50,20.25}
	};  
	while(key=="E"){
	
		
		list_yaz(urunler,6);
		printf("urun kodu giriniz\n");
		scanf("%d",&urunKodu);
		
		printf("alis tipi giriniz\n");
		scanf("%d",&alisTipi);
		
		printf("miktar giriniz\n");
		scanf("%f",&miktar);
		
		
		toplamTutar+=hesapla(urunler,alisTipi,miktar,urunKodu);
		printf("toplam tutar:%f\n",toplamTutar);
		
		printf("devam etmek istiyorsanýz E'ye,etmek istemiyorsanýz H'ye basýnýz\n");
		scanf("%s",key);
		
		
		}
		
		indirimliTutar=indirimHesapla(toplamTutar);
		
		printf("toplam tutar:%f",toplamTutar);
		printf("indirimli tutar:%f",indirimliTutar);
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	

