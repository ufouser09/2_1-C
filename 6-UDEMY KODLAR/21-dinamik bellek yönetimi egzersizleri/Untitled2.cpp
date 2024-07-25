#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Bilgisayar taraf�ndan rastgele �retilen N adet tamsay�y� belle�e yazan ve bellekten okuyarak
    karelerini ekrana listeleyen C program�n� yaz�n�z.*/
	//p pointer� ve i ve N degiskenleri tan�mlan�r
    int *p,i,N;
	//kac adet sayi �retilecegini kullan�c�dan al�r�z
    printf("Kac adet sayi uretilecek\n");
    scanf("%d",&N);
    //int boyutunda N tane bellekte yer ayr�l�r
    p=(int *)malloc(N*sizeof(int));
    //random
    srand(time(0));
    
    printf("Uretilen sayilar\n");
    for(i=0;i<N;i++)
    {
    	//random sayilar atar�z 
        *(p+i)=rand()%100;
        printf("%d  ",*(p+i));
    }
    printf("\n");
    printf("Kareleri:");
    printf("\n");
    //sonra bu atanan degerlerin karelerini yazd�r�r�z
    for(i=0;i<N;i++)
    {
        printf("%d  ",(*(p+i))*(*(p+i)));
    }
    return 0;
}
//programda bir sorun var
