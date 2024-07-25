#include <stdio.h>
#include <stdlib.h>

int main()
{
   /*Bilgisayar taraf�ndan rastgele �retilen N adet tamsay�n�n belle�e,ard�ndan bellekten okunan de�erlerin
   sayi.txt text dosyas�na yaz�lmas�n� ve dosyadan okunan degerlerin ekrana listelenmesini sa�layan C program�n�
   yaz�n�z.*/


   FILE *dosya;
   //p pointer�n� ve N,i,c degiskenlerini tan�mlar�z 
   int *p,N,i,c;
	//kullan�c�dan kac adet sayi girilecegini al�n�z
   printf("Kac adet tamsayi girilecek\n");
   scanf("%d",&N);
   
   p=(int *)malloc(N*sizeof(int));
   dosya=fopen("sayi.txt","w");
   srand(time(0));
   printf("Uretilen sayilar\n");

   for(i=0;i<N;i++)
   {
       *(p+i)=rand()%100;
       fprintf(dosya,"%d ",*(p+i));
       printf("%d ",*(p+i));
   }
   fclose(dosya);
   printf("Okunan sayılar\n");

   dosya=fopen("sayi.txt","r");
   do
   {
       c=getc(dosya);
       if(c !=EOF)
       {
           putchar(c);
       }

   }while(c != EOF);
   fclose(dosya);
   free(p);

    return 0;
}
//programda bir sorun var
