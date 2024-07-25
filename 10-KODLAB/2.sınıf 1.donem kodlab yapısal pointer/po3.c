
//burasý dogru 
int sayi=5;

//adres operatörü value ürettiði için asagýdaki kullaným gecerlidir
int *p=&sayi;


//hatalý kullaným sayisal degerler her zaman sag degerdýr.144 bir sag degerdir ve adres öperatörü sag degerlere uygulanamaz.
int *p1=&144;

-------------
int sayi=5;
int *p=&sayi;

//hatalý kullaným erisim operatoru sag degerlere uygulanamaz
p=*5;


//dogru kullaným erisim operatoru bir sol deger(value)uretýr.bir value esitligin iki tarafýnda da olabilir.erisim operatörü esitliðin saginda olabilir
int gecici=*p;
//dogru kullaným.erisim operatörü esitliðin solunda da olabilir
*p=8;

*/
//sayfa 376
