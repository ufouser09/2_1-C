#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Bilgisayar tarafından üretilen N adet rastgele tamsayının bellekten yer ayrılarak
    belleğe yazılmasını ve bu tamsayılar içerisinden en küçüğünün bulunmasını sağlayan
    C programını yazınız.*/
    //p pointer�n� tan�mlar�z
    int *p;
    //N degiskenini tan�mlar�z
	int N;
    //i degiskenini tan�mlar�z
    int i;
    //enk degiskenini tan�mlar�z
    int enk;
    //kullan�c�dan kac adet sayi girilecegini al�r�z
    printf("Kac adet sayi uretilecek\n");
    scanf("%d",&N);
    //p ponter� i�in N tane int boyutunda bellekte yer ay�r�r�z
    p=(int *)malloc(N*sizeof(int));
	//random
    srand(time(0));
    //random sayilar dizimize aktar�l�r
    for(i=0;i<N;i++)
    {
        *(p+i)=rand()%50;
        printf("%d  ",*(p+i));
    }
    
    printf("\n");
    //p pointer� enk deg�skenine aktar�l�r
	enk=*p;
    for(i=1;i<N;i++)
    {
        if(*(p+i)<enk)
        {
            enk=*(p+i);
        }
    }

    printf("En kucuk tamsayi =%d\n",enk);
    free(p);




    return 0;
}
/*
output:
programda bir sorun var
*/
