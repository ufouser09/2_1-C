#include <stdio.h>
#include <stdlib.h>

//bir struct yarismaciTip diye bir struct olustururuz
struct yarismaciTip{

char isim[10],soyad[10];
float puan[10],performans;

};

float puanHesap(struct yarismaciTip pat)
{
    int i;
    //sonuc degiskenimizi tan�mlar�z
    float sonuc=0;
    float max=0.0;
    float min=6.0;
    for(i=0;i<10;i++)
    {
    	//burda hakemlerin vermis oldugu max puan� buluruz
        if(pat.puan[i]>max)
        {
            max=pat.puan[i];
        }
        //burda hakemlerin vermis oldugu min puan� buluruz
        if(pat.puan[i]<min)
        {
            min=pat.puan[i];
        }
		//t�m puanlar� burda toplar�z
        sonuc +=pat.puan[i];
    }
    
	//sonuc degiskenimizden max ve min puan� c�kart�r�z onu da kalan 8 hakeme bolup ortalamay� buluruz
    sonuc=(sonuc-max-min)/8;
    return(sonuc);
}



int main()
{
    /*Bir buz pateni kars�lasmas�nda,bir yar�smac�n�n performans� 6.00 �zeinden puanlanarak 10 hakem taraf�ndan
    degerlendirilmektedir.yar�smac�n�n performans puan� ise hakemlerin vermi� oldugu en d���k ve en y�ksek puan
    at�l�p,geri kalan puanlar�n aritmetik ortlamas� al�narak bulunmaktadır.Yazacag�n�z programda yar�smac�n�n
    ad�,soyad� performans puan� hesaplay�p ekranda g�r�nt�leyiniz.Performans hesaplamas�nda tek parametreli
    bir fonksiyonda yap�n�z.Bu fonksiyon yar�smac�ya ait yapp�l� parametre olarak almal� ve performans puanlar�n�
    hesaplayarak geri d�nd�r�lmelidir.*/
    
	//i diye bir degisken tan�mlar�z
	int i;
	//struct yarismac�Tip struct�na patenci ismini verirsin
    struct yarismaciTip patenci;
	
	//&patenci.isim diyerek patencinin ismini al�rs�n
    printf("Yarismacinin adi\n");
    scanf("%s",&patenci.isim);
	//&patenci.soyad diyerek patencinin soyad�n� al�rs�n
    printf("Soyadi\n");
    scanf("%s",&patenci.soyad);

	//ekrana hakem puan� yazd�r�l�r
    printf("Hakem puani\n");
	
    for(i=0;i<10;i++)
    {
    	//patenci.puan[i] ile kullan�c�dan s�ras�yla 10 hakemin verdigi puanlar� al�n�r
        scanf("%f",&patenci.puan[i]);
    }
	//puan hesap fonksiyonuna gidilir orda puan hesaplan�r bu da patenci.performans degerini olustururuz.
    patenci.performans=puanHesap(patenci);
	
    printf("Performans puani = %f",patenci.performans);
    return 0;
}
/*
output:
Yarismacinin adi
efe
Soyadi
f
Hakem puani
3
4
5
6
7
3
2
1
2
3
Performans puani = 3.500000
*/
