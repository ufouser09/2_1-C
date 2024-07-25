#include <stdio.h>
#include <stdlib.h>
//N sayisini basta tan�mlar�z
#define N 10

int main()
{
	//i min max degiskenlerini tan�mlar�z
    int i,min,max;
    //*canan degiskenini tan�mlar�z
    int *canan;
    //can dizisi tan�mlar�z
    int can[N];
    //N degiskenini ekrana yazd�r�r�z
    printf("%d kadar deger giriniz",N);
    //canan=can demek dizinin bas�n� isaret eder
    //burda ise diziyi kullan�c�dan al�r�z
    for(canan=can;canan<can+N;canan++)
    {
        scanf("%d",canan);
    }
//dizinin ilk degerini maks ve min olarak kabul ederiz
max=min=can[0];
	//canan=can+1 yapmam�z�n sebebi zaten ilk�n� maks ve min olarak kabul ettik o degeri digerleriyle kars�last�r�caz
    for(canan=can+1;canan<can+N;canan++)
    {
    	//s�radaki indisteki eleman max dan buyuk mu kucuk mu ona bakar 
        if(*canan>max)
        {
        	//eger maxdan buyukse buraya girer ve o degeri yeni max degiskenine atar art�k max sayimizi o sayi kabul ederiz
            max=*canan;
            
        }
        //siradaki degisken min den kucuk mu onu kontrol eder
        if(*canan<min)
        {
        	//eger min den kucukse buraya girer ve o sayiyi min degiskenine atar yeni min sayimizi o sayi kabul ederiz
            min=*canan;
        }
    }
    //max ve min'i burda ekrana yazd�r�r�z
    printf("Dizimizin maksimum degeri: %d\n",max);
    printf("Dizimizin minumum degeri : %d\n",min);

    return 0;
}
/*
output:
10 kadar deger giriniz3
2
1
4
5
6
7
8
9
8
Dizimizin maksimum degeri: 9
Dizimizin minumum degeri : 1
*/
