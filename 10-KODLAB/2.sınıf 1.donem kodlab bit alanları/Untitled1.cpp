BIT ALANLARI (BITFIELDS) KAVRAMI
C program�n�n en �nemli �zelliklerinden biri haf�zanin en k���k noktalar�na (bittere) eri�im sa�layabilmesidir.

 Bu �zellik sayesinde �ok k���k bellek alarki sistemlerde �al��abilecek k���k ve h�zl� uygulamalar geli�tirebiliriz.
 
 Bitliside yap�s� buna olanak sunan yap�lardan bir tanesidir.
 �nceki b�l�mlerde bir tam say� de�i�kenin bellekte (genellikle) 4 bayt (32-bit) yer kaplad���n� s�ylemi�tik.
 
 �rne�in; bir ki�inin ya��n� tutmak istiyoruz.
  
  Yas de�eri mant�ksal olarak negatif de�er alamaz ve bir ki�i en fazla 100 k�sur ya�ar. Bir ki�inin 128 ya��na kadar ya�ayamayaca��n� varsayarsak asl�nda ya
de�i�keni i�in sadece 7 bit yeterlidir (2 = 128). Ya� de�erini tam say� olarak
tuttu�unuzda geriye kalan 25 bit israf edilmi� demektir.
Benzer �ekilde bir ki�inin do�um tarihini gun, ay, y21 olarak 3 tam say
de�i�kende tuttu�unuzu varsayal�m.
� G�n de�eri 1 ile 31 aras�nda de�i�ir. Yani g�n de�eri i�in asl�nda 5 bite ihtiya�
vard�r. 5 bit ile O'dan 31'e kadar olan say�lar� ifade edebiliriz (2932). Bir ba�ka
deyi�le 5 bit ile 32 farkl� say� de�erini kullanabiliriz.
� Benzer �ekilde ay de�eri de 1 ile 12 aras�nda de�i�ir. ay de�eri her zaman
16'dan k���k oldu�u i�in 4 bit yeterlidir(24 = 16).
- Benzer �ekilde (milattan sonra do�an ki�iler i�in) y�l de�eri Oila 2048 y�l�na kada
de�i�ti�ini farz edersek (2" = 2048) yil i�in de bize 11 bit'in yeterli oldu�unu
s�yleyebiliriz. (Program�m�z�n 2048 y�l�na kadar �al��aca��n� var say�yoruz 2048
y�l�ndan sonra kullanmak istersek y�l i�in 12 bit'e ihtiyac�m�z olacakt�r. O zaman de
program�m�z 4096 y�l�na kadar ge�erli olur.)


Dolay�s�yla g�n ay ve y�l i�in toplamda 5 + 4 + 11 = 20 bit yeterliyken biz
bu de�erleri 3 farkl� tam say�da tuttu�umuzda toplamda 12 bayt'a kar��l�k
gelen 96 bitlik bir alanla kar��la��lacakt�r. 72 bitlik bir alan bo�una kullan�lm��
demektir. Bu kullan�m� d���rebilmek i�in C programlama dili Bitfields ad�
verilen bir yap� getirmi�tir.
sadece
ahip bir
Bu yap� ilgili de�i�kenin ka� bit yer kaplayaca��n� tan�mlayabilmemize
olanak tan�r. Bitfield tan�mlayabilmek i�in struct yap�s�na ihtiyac�m�z vard�r.
Tan�mlama esnas�nda her bir �ye de�i�kenin ad�ndan sonra ka� bit de�er
kaplayacaklar�, iki nokta i�aretinden sonra belirtilmelidir:
	
	
typedef struct{
	unsigned int gun:5;
	unsigned int ay:4;
	unsigned int yil:11;
}DogumTarihi;



yukar�da DogumTarihi isimli bir yap� g�rmektesiniz.
bu yap� kullan�larak olusturulmus dogumTarihi isimli bir degisken bellekte toplamda 20-bit'lik bir alan kaplar.
bu degiskenin bellekteki g�r�nt�s� asag�daki gibidir.

-
-Resim

	
