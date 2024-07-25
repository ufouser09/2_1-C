asagida bu yapýyý kullanan örnek bir program verilmistir.

//BÝTFÝELDSORNEK1-maim.c

#include <stdio.h>
#include <string.h>

typedef struct{
	unsigned int gun:5;
	unsigned int ay:4;
	unsigned int yil:11;
}DogumTarihi;

int main(int argc,const char * argv[]){
	int tarýhGun,tarihAy,tarihYil;
	
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
programý inceleyecek olursanýz ilk önce tam sayi degiskenlere(tarihGun,tarihAy,tarihYil)dogum tarihindeki gun,ay,yil degerleri okunmustur.
daha sonra bu degerler dogumTarihi isimli yapý degiskeninin üyelerine atanmýstýr.
bu atama sonrasý yapý üyelerin bellekte toplamda 20 bit yer kaplayacaktýr. 

Soru:
Bit seviyesinde uzunluk verilmiþ bir alana, olanda tanýmlanabilecek saytenten
daha böyük bir sayý atandýðýnda ne olur Omegjin yukarýdaki gun sistem
31'den büyük olan 50 atansaydý ne olurdu?
Cevap:
Bu durumda atanan sayý, ilgili geniþlikten küçük oluncaya kadar ata
sayýdan geniþlik çýkarýlýr. atansaydý 50'den 32 deðeri çikarilacagim
deðiþkenine 18 deðiþkeni atanacaktý. Bu durumu daha iyi anlayabilmek om
aþaðýdaki örneðe göz atalým:
