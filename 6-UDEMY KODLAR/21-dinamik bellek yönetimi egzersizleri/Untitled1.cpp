#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Klavyeden girilen N adet tamsayının bellekten yer ayrılarak belleğe yazılmasını ve bellekten okunarak
    ekrana listelenmesini sağlayan C programını yazınız.*/
	//p pointer� tan�mlanm�s
    int *p;
    //N degiskeni tan�mlan�r
    int N;
    //i degiskeni tan�mlan�r
    int i;
    //kullan�c�dan N degerini al�r�z
    printf("N degerini giriniz\n");
    scanf("%d",&N);
	//bellekte int boyutunda N tane yer ayr�l�r
    p=(int *)malloc(N*sizeof(int));
	//kullan�c�dan degerler al�n�r
    for(i=0;i<N;i++)
    {
        printf("%d. sayi",i+1);
        scanf("%d",&(*(p+i)));
    }
    //kullan�c�dan ald�g�m�z degerleri ekrana yazd�r�l�r
    for(i=0;i<N;i++)
    {
        printf("%d\n",*(p+i));
    }

    return 0;
}
/*
output:
N degerini giriniz
3
1. sayi1
2. sayi4
3. sayi6
1
4
6
*/
