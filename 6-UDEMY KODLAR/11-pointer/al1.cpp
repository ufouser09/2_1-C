#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int can=10;
    int *p;

    p=&can;


    printf("%d\n",*p);
     printf("%d\n",p);
      printf("%d\n",can);
       printf("%d\n",&can);*/

	//sayi pointer� tutar�z bir tane
    int *sayi;
    
	//n degiskeni tan�mlar�z
    int n;
   
    //n degerine 20 degeri at�l�r
    n=20;
	
	//n'in adresini sayi degiskenin�n adresine atar�z
    sayi=&n;
	
	//sayi degiskeni n'in adresini g�sterdi�i i�in 20 olarak ��kar
    printf("%d\n",*sayi);
    
	//sayi dedigimiz i�in adresi g�sterir
    printf("%d\n",sayi);
     
	//n degiskenin degeri 20 dir
    printf("%d\n",n);
      
	  //&n dedigimiz i�in n degiskeninin adresini g�sterir
       printf("%d\n",&n);
		
		//sayi degiskenimizin g�sterdigi degeri 30 yapar�z
       *sayi=30;
		//n'in adresini sayi degiskenine atad�g�m�z i�in n de art�k 30 degerini g�sterir
       printf("%d\n",n);
       //&n dedigimiz i�in adresi g�sterir
        printf("%d",&n);



}
/*output:
20
6487572
20
6487572
30
6487572
*/
