  /* su ana kadar yapt�g�m�z cal�smalarda hep tek veri tipleriyle ilgilendik int character float gibi fakat gunluk hayatta daha cok nesnelerle ugras�yoruz nesneler tek bir boyuttan yani tek bir �zellikten olusmuyor burlarda structarlar devreye giriyor
mesela bir karmas�k sayi �rnegi verelim mesela a+bi ilk k�s�m reel k�s�m diger k�s�m imaj�ner k�s�m 
sonrac�ma insanlar�n ad� var yas� var memleketi var boyle bir suru durum var
s�md� 100 tane ogrenci uzerinde �slem yap�cak olsak 100 ogrencinin ad� i�in 100 elemanl� bir dizi 100 �grencinin yas� i�in 100 elemanl� bir dizi falan bunlar� yapabiliriz
fakat bu primitive obsession dedigimiz temel veri tiplerine bagl� olmak tak�nt�l� olmak dedigimiz bir kod kusuru meydana getiriyor 
neden bir fonksiyona ki�ilerin adlar�n� yaslar�n� vs hepsini g�nderiyorsunuz
fakat bunu yapmak yerine biz structlar sayesinde k�s�ler ac�p tum i�imizi ordan halledebiliriz

structu gloabal bir degisken olarak ve fonksiyon olarak tan�ml�yabiliriz ama bizden global olarak tan�mlanmas� istenicek

tan�mlamay� gloabal yap�caz fakat tan�mlamadan degisken �retmeyi gloabal yapm�caz
*/

#include <stdio.h>
struct Complex{
	int r;
	int i;
};
typedef struct complex{
	int r;
	int i;
}COMPLEX;

typedef struct Complex CMP;
#define CMP2 struct complex
int main(){
	struct Complex c1;
	COMPLEX c3,*c2;
	//*c2 herhangi bir struct�n adres bilgisini tutuyor.int i�inde integer tutar integer pointer i�inde integer adresi tutar.
	
	c2=&c3;
	//yukarda yapt�g�m�z i�lem cok onemli deger atamadan once pointer�n bir yeri isaret etmesi gerekir)
	c2->r=999;
	(*c2).i=88;
	
	CMP c4[3];
	c1.r=4;  
	c1.i=6;
	c4[3].r=0;
	c4[3].i=8;
	CMP2 c5;
	c5.r=44;
	c5.i=6;
	
	printf("%d - %di\n",c1.r,c1.i);
	printf("%d -%di\n",c4[3].r,c4[3].i);
	printf("%d-%di\n",c5.r,c5.i);

	printf("%d - %di\n",c2->r,(*c2).i);
}
/*
EMPLOYEE yunus;
yunus.ID=1234;
dogrudan bir �eye direct eri�imi kullan�yorsak nokta operat�r�n� kullan�yoruz.


eger pointer kullanarak eri�mek istiyorsak 2 t�rl� yontem var
EMPLOYEE *e_ptr;
(bu pointer tan�mlanm�s ama nereyi isaret ettigi gosterilmemis bu �rnek yanl�s)
(bunun i�in �ncesinde EMPLOYEE E;
sonra e_ptr=&E;yapmam�z gerekirdi.
yani ilk once pointer�n bir yeri g�stermesi gerekirdi.)
e_ptr->ID=1234;
(bu birinci yontem)

(*e_ptr).ID=1234;
(bu da ikinci yontem)

eger i� i�e struct olusturmak istiyorsak soyle yapar�z

typedef struct{
	short day,month;
	int year;
}DATE;
typedef struct {
	char name[20],surname[20];
	int ID;
	float salary;
	DATE enlisted;
}EMPLOYEE;

late you can write:
yunus.enlisted.year=2008;

structlari fonksiyon parametresi olarak g�ndermek

call pass by value(buradaki degisiklikler kaydedilmiyor)
EMPLOYEE emp;
printReport(emp);

call pass by referance(burdaki degisiklikler kaydediliyor)
EMPLOYEE emp;
increaseSalary(&emp);
