/*
butun fonksiyonlar parametre al�yor ve fonkisyonlar� cag�r�rken arguman gonderiyoruz
acaba ma�n fonksiyonu parametre alablir mi veya ma�n fonksiyonunu cag�r�rken arguman g�nderebilir miyiz evet g�nderebiliyoruz

su ana kadar ki �al��malar�m�zda hep tek bir veri tipleriyle �al��t�k �nt karakter float gibi
fakat g�nl�k hayatta daha cok nesnelerle ugras�yoruz ve nesneler tek boyutlu bir durumda degiller tek bir �zellikten olusmuyorlar
burda structlar devreye giriyor
mesela bizim bir personumuz var bunun yas� var �sm� var memleketi var
�imdi biz 100 ��renci i�in bunlar� yap�yor olsak 100 ��rencinin ad� i�in 100 elemanli bir dizi
yas� i�in 100 elemanl� baska bir dizi mesela
fakat bu primitive obsession dedigimiz temel veri tiplerine ba�l� olmaktan kaynakl� bir kod kusuru meydana getirir
mesela biir fonksiyonun i�inde f(ad,yas,memleke...)boyle yap�cag�m�za f(kisiler) boyle bir structla i�imizi haleldebiliyoruz bu bir programlama kolayl�g�d�r

struct Employee(struct�m�z�n ismi){
	char name[20],surname[20];
	int ID;
	float salary;
};
bu global bir degisken olabilir
fonksiyon i�erisinde tan�mlayabiliriz
bizden istenen global bir degisken olarak struct�n tan�m�n� yapmak
fonksiyonlar i�inde strcuttan degisken �retmek

strcut Employee(bu ikisi birbirinden ayr�lm�yo g�rd�g�n�z gibi) employess(buna bir isim verdik ve bunun 1000 elemanl� olams�n� istedik)[1000];

baska ne yapabiliriz mesela strcut Employee *E;mesela boyle bir pointer tan�mlayabiliriz.
baska ne yapabilriz struct Employee E;boyle bir degisken tan�mlayabilirzi bu tek elemanl� bir struct

bunu her defa tan�mland�g�nda struct demek yerine Employee ifadesini yani verilen etiketi kullanmak daha dogru
burda da type definition dan yararlan�yoruz

typedef kullan�m� s�yle bir �ey
#typedef int tamsayi;(art�k biz int yazmam�z gereken yerlere tamsayi yazabilirsin demek)

typedef struct{
	char name[20],surname[20];
	int ID;
	float salary;
}EMPLOYEE;


EMPLOYEE employees[1000];
typedef sayesinde biz EMPLOYEE ifadesini dogrudan kullanabiliyoruz;

ya da soyle bir �ey olusturabiliyoruz;
EMPLOYEE *E;mesela burda bir pointer tan�mlad�k

ya da soyle 
EMPLOYEE E;burda E degiskeni olusturduk

struct Employee{
 ---------
 ---------
 ----------
};
typdef struct Employee EMPLOYEE;
(typedef ifadesini boyle de kullanabiliyoruz)


