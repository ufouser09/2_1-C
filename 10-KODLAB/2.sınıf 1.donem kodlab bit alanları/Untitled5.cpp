-
-
-

typedef struct{
	int deger;
	struct eleman *sonraki;
}Eleman;

bu listelerin bellekteki g�r�nt�s� asag�daki resimdeki gibi olur.her eleman bir sonrakine ait adres referans�n� tutar.

-resim

**baglant�l� listelerdeki en son eleman� ay�rt edebilmek i�in bu eleman�n sonraki degeri NULL olmal�d�r.
eger bir baglant�l� listeyi gezerken herhangi bir eleman�n sonraki degeri NULL ise;o listenin sonuna geldigi c�kar�m�n� yapabiliriz.

baglant�l� listenin en temek bileseni Eleman ad� verilen bilesendir.kimi kaynaklarda bu bilesen Node olarak da gecer.Listeye bir eleman ekleyecegimizde bellekten o eleman i�in yer ay�r�r�z ve listedeki en son eleman�n sonuna ekleme islemi yapar�z.

//BAGLANTILI L�STEY� OLUSTURMA

typedef struct liste{
	Eleman* baslang�c;
	int elemanSayisi;
}Liste;

yukar�da baglant�l� listemizin temel bileseni olan Eleman bileseni ve bu bileseni kullanan Liste isimli bir yap� verilmistir.
bu yap�y� baglant�l� listemizi tan�mlarken kullanacag�z.Listeye her eleman ekledigimizde elemanSayisi degiskenin degerini bir artt�racag�z.

programa ilk giriste bir adet liste degiskeni olusturulur ve bu degisken hazirla fonksiyonuna g�nderilir ve listemiz ilk kullan�ma haz�rlan�r.

Liste liste;
hazirla(&liste);

hazirla fonksiyonu i�erisinde listemizin ilk eleman� i�in bellekten yer ayr�l�r ve listemiz ilk kullan�ma haz�rlan�r.

//listeyi ilk kullan�ma haz�rlayal�m
liste->baslangic?(Eleman*)malloc(sizeof(Eleman));
liste->baslangic->sonraki=NULL;
l�ste->elemanSayisi=0;

daha sonra kullan�c�ya bir menu sunulur.
bu islem i�in menuYazdir fonksiyonu cagr�l�r.
Menudeki her fonksiyon �zerinde durmayacag�m.
Dikkatinizi cekmek istedigim iki fonksiyon bulunuyor:ekle ve cikar.bu iki fonksiyonun imzalar� asagidaki sekildedir.

void ekle(Liste *liste,int deger);
void c�kar(Liste *liste,int sira);



//BAGLANTILI L�STEYE ELEMAN EKLEME
ekle fonksiyonu kendisine parametre olarak gelen liste referans�n� kullanarak,bu listenin en sonuna yeni bir eleman ekler.Ekleyecegi eleman i�in bellekten yer ay�r�r ve bu eleman�n degerini kendisine parametre olarak gelen deger olarak belirler.
//listeye yeni eleman ekliyelim 
Eleman* yeniEleman=(Eleman*)malloc(sizeof(Eleman));
yeniEleman->deger=deger;

baglant�l� listelerde dizilerdeki gibi indisleri kullanamay�z.bir listeye eleman ekliyecegimizde eklenecek eleman�n lokosyonunu kendimiz bulmal�y�z.
bunu yapabilmek i�in dongulerden faydalanabiliriz.Eger dizi 5 elemanl�ysa dizinin baslang�c elemanlar�ndan itibaren 5 defa bir sonraki elemana gecersek bulunan listenin en son eleman�na ulasm�s oluruz.

birazdan tam kodu verilecek olan program�m�zda da eklenecek eleman�n yerini bulmak i�in bir d�ng� kullan�l�r ve d�ng� sonucunda ptr degiskeni i�erisinde listenin en son eleman� adresi olur.art�k bu noktadan sonra yeniEleman'�m�z� listenin sonuna ekliyebiliriz.

bu ekleme asagidaki gibi olur(EKleme sonrasinda listedeki eleman sayisi bir artt�r�l�r.)

ptr->sonraki=yeniEleman;
yeniEleman->sonraki=NULL;
liste->elemanSayisi++;



//BAGLANTILI L�STELERDEN ELEMAN CIKARMA
-
-
-

//cikarma isi burada yap�l�yor.

Eleman* ptr=liste->baslangic;
int i=0;
//cikarilacak elemana kadar git
while(i<sira-1){
	ptr=ptr->sonraki;
	i++;
}
Eleman *temp=ptr->sonraki;
ptr->sonraki =ptr->sonraki->sonraki;
free(temp);



-RES�M


yukar�daki kod parcasinda ��karilacak elemandan sonra gelen deger,cikarilacak elemandan �nce gelen deger ile baglan�yor.
daha sonra ��karilacak eleman�n kulland�g� bellek alan� free isimli fonksiyon kullan�larak bellege iade ediliyor.
-
-
-
//BAGLANTILIL�STE-main.c
#include <stdio.h>
#include <stdlib.h>

typedef struct eleman{
	int deger;
	struct eleaman *sonraki;
}Eleman;

typedef struct liste{
	Eleman* baslangic;
	int elemanSayisi;
}Liste;

void menuGoster();
void hazirla(Liste* liste);
void ekle(Liste *liste,int deger);
void cikar(Liste *liste,int sira);
void yazdir(Liste *liste);
void temizle(Liste *liste);

int main(int argc,char *argv[]){
	Liste liste;
	hazirla(&liste);
	
	int secim,sira,deger;
	
	while(1){
		menuGoster();
		
		scanf("%d",&secim);
		switch(secim){
			case 0:
				temizle(&liste);
				printf("sistemden cikiliyor!");
				
				exit(EXIT_SUCCESS);
				break;
				
				case 1:
					yazdir(&liste);
					break:
						case 2:
							scanf("%d",&deger);
							ekle(&liste,deger);
							break;
							
							case 3:
								printf("\nlistedeki eleman sayisi:%d",liste.elemanSayisi);
								printf("\nkacinci elemani c�karayim:");
								scanf("%d",&sira);
								cikar(&liste,sira);
								break;
								default:
									printf("gecersiz secim.lutfen gecerli bir sayi giriniz!");
									break;
		}
	}
	return EXIT_SUCCESS;
}

void hazirla(Liste *liste){
	//listeyi ilk kullanima hazirlayalim
	liste->baslangic=(Eleman*)malloc(sizeof(Eleman));
	yeniEleman->deger=deger;
	
	if(liste->elemanSayisi==0){
		liste->baslangic->sonraki=yeniEleman;
	}
	else{
		Eleman* ptr=liste->baslangic;
		int i=0;
		while(i<liste->elemanSayisi){
			ptr=ptr->sonraki;
			i++;
		}
		ptr->sonraki=yeniEleman;
	}
	yeniEleman->sonraki=NULL;
	liste->elemanSayisi++;
}
void cikar(Liste *liste,int sira){
	if(sira<1|| sira>liste->elemanSayisi){
		printf("\ngecersiz deger!");
		return;
	}
	liste->elemanSayisi--;
	//tek eleman varsa �zel islem
	
	if(liste->elemanSayisi==1){
		free(liste->baslangic->sonraki);
		liste->baslangic->sonraki=NULL;
		return;
	}
	//cikarma isi burada yapiliyor.
	Eleman* ptr=liste->baslangic;
	int i=0;
	//cikarilacak elemana kadar git
	while(i<sira-1){
		ptr=ptr->sonraki;
		i++;
	}
	Eleman *temp=ptr->sonraki;
	ptr->sonraki=ptr->sonraki->sonraki;
	free(temp);
}
void temizle(Liste *liste){
	Eleman *ptr=liste->baslnagic;
	Eleman *temizlenecek;
	
	printf("\nListe temizleniyor.");
	while(ptr->sonraki !=NULL){
		temizlenecek=ptr;
		ptr=ptr->sonraki;
		free(temizlenecek);
	}
	free(ptr);
}
void yazdir(Liste *liste){
	printf("\n listedeki eleman sayisi:%d\n",liste->elemanSayisi);
	Eleman* ptr=liste->baslangic;
	int i=1;
	while(ptr->sonraki !=NULL){
		printf("%2d.eleman:%d\n",i,ptr->sonraki->deger);
		ptr=ptr->sonraki;
		i++;
	}
}
void menuGoster(){
	printf("\n---------------\n [Menu]   \n------------\n");
	printf("1.listeyi yazdir\n");
	printf("2.listeye eleamn ekle\n");
	printf("3.listeden eleman c�kar\n");
	printf("0.cikis\n");
	printf("seciminizi giriniz:");
	
	
	
}

-
-
-




-
-
-

