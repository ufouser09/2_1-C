-
-
-
-
-
-

Eleman *eklenecek;
eklenecek=(Eleman *)malloc(sizeof(Eleman));
eklenecek->deger=val;

-
-
-
-
-


eklenecek->sonraki=baslangic->sonraki;
baslangic->sonraki=eklenecek;

-
-
-
-
-
-

int val=baslangic->sonraki->deger;
gecici=baslangic->sonraki;
baslangic->sonraki=baslangic->sonraki->sonraki;
free(gecici);



programin cal�sma an�ndaki bir g�r�nt�s� asagidaki resimdeki gibidir.

tamsayi giriniz(cikis icin -1):1
tamsayi giriniz(cikis icin -1):2
tamsayi giriniz(cikis icin -1):3
tamsayi giriniz(cikis icin -1):4
tamsayi giriniz(cikis icin -1):5
tamsayi giriniz(cikis icin -1):6
tamsayi giriniz(cikis icin -1):7
tamsayi giriniz(cikis icin -1):8
tamsayi giriniz(cikis icin -1):-1
y�g�n�n ustten alta durumu:
8
7
6
5
4
3
2
1

