#include <stdio.h>
#include <stdlib.h>

int main()
{
	//cumlem diye bir dizi tan�mlar�z
    char cumlem[100];
    //*p1 ve *p2 degiskenlerini tan�mlar�z
    char *p1,*p2;
    //kontrol diye bir degisken tan�mlar�z
    int kontrol;


	//kullan�c�dan cumle girmesi istenir
    printf("Lutfen maksimum 100 karakterli bir cumle giriniz\n");
    //gets ile string yani cumle alabilirsin
    gets(cumlem);
	//p2=cumlem demek cumlenin bas�ndaki karakterden basla demek 
    for(p2=cumlem;*p2;p2++);

    p2--;

	//kontrol degiskenini tan�mlar ve 1 say�s�n� atar�z
    kontrol=1;
    //p1=cumlem cumlem dizisinin bas�ndan basla demek
    for(p1=cumlem;kontrol && p1<p2;p1++,p2--)
    {
        if(*p1 != *p2)
        {
            kontrol=0;
        }
    }

    if(kontrol)
    {
        printf("Girilen %s bir palendomdur",cumlem);
    }
    else
    {
        printf("Girilen %s bir palendrom degildir",cumlem);
    }
    return 0;
}
/*
output:
Lutfen maksimum 100 karakterli bir cumle giriniz
efe girgin
Girilen efe girgin bir palendrom degildir

Lutfen maksimum 100 karakterli bir cumle giriniz
efe
Girilen efe bir palendomdur

*/

