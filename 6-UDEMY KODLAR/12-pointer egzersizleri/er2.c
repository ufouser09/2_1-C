#include <stdio.h>
#include <stdlib.h>

int main()
{
	//can dizisi tan�mlar�z
    int can[5];
    //*sayi1 ve *sayi2 pointerlar�n� tan�mlar�z
    int *sayi1,*sayi2;
    //n degiskenini tan�mlar�z
    int n;
    //gecici degiskenini tan�mlar�z
    int gecici;


	//dizinin eleman sayisini girmemiz istenir burda
    printf("Lutfen dizimizin eleman sayisini giriniz\n");
    scanf("%d",&n);
//dizimizin eleman sayilari burda kullan�c�dan al�n�r
    for(sayi1=can;sayi1<can+n;sayi1++)
    {
        printf("Lutfen eleman giriniz:\n");
        scanf("%d",sayi1);
    }
    //dizimizin ilk hali ekrana yazd�r�l�r
    printf("Dizimizin ilk hali");

    for(sayi1=can;sayi1<can+n;sayi1++)
    {
        printf("%4d",*sayi1);
    }
    printf("\n");
    
    for(sayi1=can,sayi2=can+n-1;sayi1<sayi2;sayi1++,sayi2--)
    {
        gecici=*sayi1;
        *sayi1=*sayi2;
        *sayi2=gecici;
    }
    printf("Dizimizin elamanlari yer degistirdikten sonra :");

    for(sayi1=can;sayi1<can+n;sayi1++)
    {
        printf("%4d",*sayi1);
    }
    printf("\n");
    return 0;
}
/*
output:
Lutfen dizimizin eleman sayisini giriniz
3
Lutfen eleman giriniz:
5
Lutfen eleman giriniz:
2
Lutfen eleman giriniz:
7
Dizimizin ilk hali   5   2   7
Dizimizin elamanlari yer degistirdikten sonra :   7   2   5

/*
