
Structure alignment

�imdi structure alignment etti�imizde a�a��daki gibi yazdigimzida burdaki s�raya g�re bellekten yer kaplar.
ve bu bellekten yer kaplama esnas�nda arada bosluklar olabiliyor.
Bu bosluklar neye sebep oluyor:verimsiz alan kullan�m�na sebep oluyor.
G�m�l� gibi alanlarda bellek �ok �nemlidir.
Bunlar�n verimli kullan�m� sa�l�ycak yaklas�mlardan bir tanesi bit field'lar

structure ALIGN_EXAMP{
char mem1;
short mem2;
char mem3;
}s1;

//B�T F�ELDS

Normalde bir degiskenin kaplad�g� alan bellidir mesela int i�in 4 byte dedik char i�in 1 byte dedik.
Bunu daha cok k�s�tlayabiliyoruz ve bellegi daha etkin kullanabiliyoruz.
�rne�in tc kimlik numaras� say�sal olarak d���nd���n�zde a
Mesela g�n dedigimiz sey en fazla 30 olabiliyor yani 5 bit olabiliyor.
O y�zden bu alan� azaltmak gerekiyor o y�zden bit fieldlardan kullan�yoruz.

Bit field bellegin bir h�cresindeki ilgili bitlere eri�mekle alakal� oldugu i�in 2 tane s�k�nt�s� var.
1-Bunun adresini alam�yorsunuz ��nk� ben bir adrestte birden fazla veri saklamaya �al�s�yorum.
2-Bit field'larla bir dizi olusturam�yoruz.

Genellikle bit field'lar kullan�l�rken int veya unsigned int gibi �eyler kullanmak iyi olur niye gereksiz verilerin �n�ne ge�ersiniz.
Mesela g�n ay y�l bunlar� unsigned oldugunu biliyoruz bu y�zden bunlar� integer yazmak yerine unsigned yazmak daha do�ru olur.



yaz�l�m� ��yle olur

struct{
int a:3;//burda a 3 bitlik bir integer oldugunu s�yler.
int b:7;//burda b 7 bitlik bir integer oldugunu s�yler.
int c:2;
}s;
Sadece implemantasyon a�amas�nda bir veri yaz�caksan�z ona dikkat etmeniz gerekiyor.

Eger bizim burda kulland�g�m�z alan bu �eye yetmezse bir sonraki bitfield bir sonraki h�creden basl�ycakt�r.

Genellikle bunu nerde kullan�r�z:
G�n ay yil gibi belli alanlarda belli aral�klarda degerlerin girilecegi yerde kullan�l�r.
Bu sunu da saglar veri g�venli�ini de saglar


UNION 

Bu da bir structer eleman� gibidir ama structer da tan�mlanan her bir eleman�n kendine ait bir lokasyonu bellek adresi varken
Burda ortak kullan�m� sa�lamak ad�na bir bellek h�cresi birden fazla degiskene tahsis edilebiliyor.
Mesela tc vatanda�� ise tc kimlik numaras�n� gir yabanc� vatanda� ise pasaport numaras�n� gir gibi.
Bu tarz durumlarda bu t�r �eyler kullan�l�r.


