#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Kullanıcı tarafından girilen iki adet tamsayı için farklı bellek bölgelerinde yer ayrılmaktadır.Buna
    göre bu iki bellek bölgesinde yer alan sayıların yerlerinin değiştirilmesini sağlayan C programını
    yazınız.*/

	//*p1 pointer� *p2 pointer� ve gecici degiskeni tan�mlar�z
    int *p1,*p2,gecici;
    //p1 ve p2 pointer�nda int boyutunda bir yer ayr�l�r
    p1=(int *)malloc(sizeof(int));
    p2=(int *)malloc(sizeof(int));
	//kullan�c�dan birinci sayimizi al�r�z
    printf("Birinci sayi\n");
    scanf("%d",&(*p1));
	//kullan�c�dan ikinci sayimizi al�r�z
    printf("Ikinci sayi");
    scanf("%d",&(*p2));

	//p1 ve p2 degiskenlerini ekrana yazd�r�r�z
    printf("Sayi1 =%d Sayi2 =%d\n ",*p1,*p2);

	//p1 ve p2 pointerlar�n�n yerlerini degistiririz
    gecici=*p1;
    *p1=*p2;
    *p2=gecici;

	//p1 ve p2 pointerlar�n� ekrana yazd�r�r�z
    printf("Sayi1 =%d Sayi2 =%d",*p1,*p2);
	//son olarak p1 ve p2 pointerlar� i�in bellekte ay�rd�g�m�z yeri bosalt�r�z
    free(p1);
    free(p2);

    return 0;
}
/*
output:
Birinci sayi
3
Ikinci sayi4
Sayi1 =3 Sayi2 =4
 Sayi1 =4 Sayi2 =3
 */
