
//buras� dogru 
int sayi=5;

//adres operat�r� value �retti�i i�in asag�daki kullan�m gecerlidir
int *p=&sayi;


//hatal� kullan�m sayisal degerler her zaman sag degerd�r.144 bir sag degerdir ve adres �perat�r� sag degerlere uygulanamaz.
int *p1=&144;

-------------
int sayi=5;
int *p=&sayi;

//hatal� kullan�m erisim operatoru sag degerlere uygulanamaz
p=*5;


//dogru kullan�m erisim operatoru bir sol deger(value)uret�r.bir value esitligin iki taraf�nda da olabilir.erisim operat�r� esitli�in saginda olabilir
int gecici=*p;
//dogru kullan�m.erisim operat�r� esitli�in solunda da olabilir
*p=8;

*/
//sayfa 376
