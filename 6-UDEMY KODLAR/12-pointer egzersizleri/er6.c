#include <stdio.h>
#include <stdlib.h>
#define MAX 15

int main()
{
	//dizi diye bir degisken olustururuz
    char dizi[MAX]={'k','l','b','d','q','i','s','t','e','f','o','r','c','h','x'};
    //*sayi1 degiskeni tan�mlar�z
    char *sayi1;
    //*sayi2 degiskeni tan�mlar�z
    char *sayi2;
    //dizi_kopya diye bir dizi tan�mlar�z
    char dizi_kopya[MAX];
    //i diye bir degisken tan�mlar�z
    int i;
	//dizi_kopyanin bas�ndaki eleman� sayi2 degiskenine atar�z
    sayi2=dizi_kopya;
	
    for(sayi1=dizi;sayi1<dizi+MAX;sayi1++)
    {
        *sayi2=*sayi1;
        sayi2++;

    }
    printf("Original tablo : ");

    for(i=0;i<MAX;i++)
    {
        printf("%c",*(dizi+i));
    }
    printf("\nKopya Tablo :");
    for(i=0;i<MAX;i++)
    {
        printf("%c",*(dizi_kopya+i));
    }

    return 0;
}
/*Original tablo : klbdqisteforchx
Kopya Tablo :klbdqisteforchx
*/
