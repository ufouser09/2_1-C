asagida bu yap�y� kullanan �rnek bir program verilmistir.

//B�TF�ELDSORNEK1-maim.c

#include <stdio.h>
#include <string.h>

typedef struct{
	unsigned int gun:5;
	unsigned int ay:4;
	unsigned int yil:11;
}DogumTarihi;

int main(int argc,const char * argv[]){
	int tar�hGun,tarihAy,tarihYil;
	
	printf("dogum tarihinizi gun/ay/yil formatinda giriniz:");
	scanf("%d/%d/%d",&tarigGun,&tarihAy,&tarihYil);
	
	DogumTarihi dogumTarihi;
	dogumTarihi.gun=tarihGun;
	dogumtarihi.ay=tarihAy;
	dogumTarihi.yil=tarihYil;
	
	printf("dogumTarihi.gun:%d\n",dogumTarihi.gun);
	printf("dogumTarihi.ay:%d\n",dogumTarihi.ay);
	printf("dogumTarihi.yil:%d\n",dogumTarihi.yil);
	
	return 0;
}
program� inceleyecek olursan�z ilk �nce tam sayi degiskenlere(tarihGun,tarihAy,tarihYil)dogum tarihindeki gun,ay,yil degerleri okunmustur.
daha sonra bu degerler dogumTarihi isimli yap� degiskeninin �yelerine atanm�st�r.
bu atama sonras� yap� �yelerin bellekte toplamda 20 bit yer kaplayacakt�r. 

Soru:
Bit seviyesinde uzunluk verilmi� bir alana, olanda tan�mlanabilecek saytenten
daha b�y�k bir say� atand���nda ne olur Omegjin yukar�daki gun sistem
31'den b�y�k olan 50 atansayd� ne olurdu?
Cevap:
Bu durumda atanan say�, ilgili geni�likten k���k oluncaya kadar ata
say�dan geni�lik ��kar�l�r. atansayd� 50'den 32 de�eri �ikarilacagim
de�i�kenine 18 de�i�keni atanacakt�. Bu durumu daha iyi anlayabilmek om
a�a��daki �rne�e g�z atal�m:
