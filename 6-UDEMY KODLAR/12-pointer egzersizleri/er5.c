#include <stdio.h>
#include <stdlib.h>

int main()
{
	//dizi diye bir degisken tanımlarız	
    int dizi[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    //*pointer diye bir degisken tanımlarız
    int *pointer;
    //i diye bir degisken tanımlarız
    int i;
	//dizimizin ilk halini yazdiririz
    printf("Dizimizin ilk hali : \n");
    for(i=0;i<15;i++)
    {
    	//dizimizin degerlerine *(dizi+i)diye erisebiliriz.
        printf("%4d",*(dizi+i));
    }
    printf("\n");
    //dizimizin cift sayilarini yazdırırız
    printf("Dizimizdeki cift sayilar :\n");
    for(i=0;i<15;i+=2)
    {
    	//dizimizin degerlerine *(dizi+i)diye erisebiliriz.
        printf("%4d",*(dizi+i));
    }
    printf("\n");
    //dizimizin tek sayilari bu sekilde erisebiliriz
    printf("Dizimizde bulunan tek sayilar:\n");
    for(pointer=dizi+1;pointer<dizi+15;pointer+=2)
    {
        printf("%4d",*pointer);
    }
    return 0;
}
/*
Dizimizin ilk hali :
   0   1   2   3   4   5   6   7   8   9  10  11  12  13  14
Dizimizdeki cift sayilar :
   0   2   4   6   8  10  12  14
Dizimizde bulunan tek sayilar:
   1   3   5   7   9  11  13
   */
