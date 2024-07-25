-
-
-

typedef struct{
	int deger;
	struct eleman *sonraki;
}Eleman;

bu listelerin bellekteki görüntüsü asagýdaki resimdeki gibi olur.her eleman bir sonrakine ait adres referansýný tutar.

-resim

**baglantýlý listelerdeki en son elemaný ayýrt edebilmek için bu elemanýn sonraki degeri NULL olmalýdýr.
eger bir baglantýlý listeyi gezerken herhangi bir elemanýn sonraki degeri NULL ise;o listenin sonuna geldigi cýkarýmýný yapabiliriz.

baglantýlý listenin en temek bileseni Eleman adý verilen bilesendir.kimi kaynaklarda bu bilesen Node olarak da gecer.Listeye bir eleman ekleyecegimizde bellekten o eleman için yer ayýrýrýz ve listedeki en son elemanýn sonuna ekleme islemi yaparýz.

//BAGLANTILI LÝSTEYÝ OLUSTURMA

typedef struct liste{
	Eleman* baslangýc;
	int elemanSayisi;
}Liste;

yukarýda baglantýlý listemizin temel bileseni olan Eleman bileseni ve bu bileseni kullanan Liste isimli bir yapý verilmistir.
bu yapýyý baglantýlý listemizi tanýmlarken kullanacagýz.Listeye her eleman ekledigimizde elemanSayisi degiskenin degerini bir arttýracagýz.

programa ilk giriste bir adet liste degiskeni olusturulur ve bu degisken hazirla fonksiyonuna gönderilir ve listemiz ilk kullanýma hazýrlanýr.

Liste liste;
hazirla(&liste);

hazirla fonksiyonu içerisinde listemizin ilk elemaný için bellekten yer ayrýlýr ve listemiz ilk kullanýma hazýrlanýr.

//listeyi ilk kullanýma hazýrlayalým
liste->baslangic?(Eleman*)malloc(sizeof(Eleman));
liste->baslangic->sonraki=NULL;
lÝste->elemanSayisi=0;

daha sonra kullanýcýya bir menu sunulur.
bu islem için menuYazdir fonksiyonu cagrýlýr.
Menudeki her fonksiyon üzerinde durmayacagým.
Dikkatinizi cekmek istedigim iki fonksiyon bulunuyor:ekle ve cikar.bu iki fonksiyonun imzalarý asagidaki sekildedir.

void ekle(Liste *liste,int deger);
void cýkar(Liste *liste,int sira);



//BAGLANTILI LÝSTEYE ELEMAN EKLEME
ekle fonksiyonu kendisine parametre olarak gelen liste referansýný kullanarak,bu listenin en sonuna yeni bir eleman ekler.Ekleyecegi eleman için bellekten yer ayýrýr ve bu elemanýn degerini kendisine parametre olarak gelen deger olarak belirler.
//listeye yeni eleman ekliyelim 
Eleman* yeniEleman=(Eleman*)malloc(sizeof(Eleman));
yeniEleman->deger=deger;

baglantýlý listelerde dizilerdeki gibi indisleri kullanamayýz.bir listeye eleman ekliyecegimizde eklenecek elemanýn lokosyonunu kendimiz bulmalýyýz.
bunu yapabilmek için dongulerden faydalanabiliriz.Eger dizi 5 elemanlýysa dizinin baslangýc elemanlarýndan itibaren 5 defa bir sonraki elemana gecersek bulunan listenin en son elemanýna ulasmýs oluruz.

birazdan tam kodu verilecek olan programýmýzda da eklenecek elemanýn yerini bulmak için bir döngü kullanýlýr ve döngü sonucunda ptr degiskeni içerisinde listenin en son elemaný adresi olur.artýk bu noktadan sonra yeniEleman'ýmýzý listenin sonuna ekliyebiliriz.

bu ekleme asagidaki gibi olur(EKleme sonrasinda listedeki eleman sayisi bir arttýrýlýr.)

ptr->sonraki=yeniEleman;
yeniEleman->sonraki=NULL;
liste->elemanSayisi++;



//BAGLANTILI LÝSTELERDEN ELEMAN CIKARMA
-
-
-

//cikarma isi burada yapýlýyor.

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



-RESÝM


yukarýdaki kod parcasinda çýkarilacak elemandan sonra gelen deger,cikarilacak elemandan önce gelen deger ile baglanýyor.
daha sonra çýkarilacak elemanýn kullandýgý bellek alaný free isimli fonksiyon kullanýlarak bellege iade ediliyor.
-
-
-
//BAGLANTILILÝSTE-main.c
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
								printf("\nkacinci elemani cýkarayim:");
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
	//tek eleman varsa özel islem
	
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
	printf("3.listeden eleman cýkar\n");
	printf("0.cikis\n");
	printf("seciminizi giriniz:");
	
	
	
}

-
-
-




-
-
-

