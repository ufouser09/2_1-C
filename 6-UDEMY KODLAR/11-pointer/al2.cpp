#include <stdio.h>
#include <stdlib.h>

int main()
{
	//pointer cinsinde 3 tane degisken tutar�z
    int *ad1,*ad2,*ad;
    //n degiskeni 10,p degiskenine 20 degerini atar�z
    int n=10,p=20;


	//n'in adresini ad1 adresine atar�z
    ad1=&n;
    //p'nin adresini ad2 adresine atar�z
    ad2=&p;
	//ad1 art�k n in degerini g�sterir o da 10 dur
    printf("Atamadan �nce ad1 degeri %d\n",*ad1);
	//ad1 yazd�g�m�z i�in ad1 in adresini g�sterir
    printf("%d\n",ad1);
	//ad2'nin degerini 2 artt�r�p ad1'e atarsak 22 diye c�kar �unku ad2 20'ydi 2 artt�r�p ad1'e atad�k
    *ad1=*ad2+2;
	//ad1 degerimiz art�k 22 diye c�kar
    printf("Atamami yaptiktan sonra ad1 degeri %d\n",*ad1);
    //ad1 dedigimiz i�in adresi c�kar
    printf("%d\n",ad1);

    return 0;
}
/*
output:
Atamadan �nce ad1 degeri 10
6487564
Atamami yaptiktan sonra ad1 degeri 22
6487564
*/
