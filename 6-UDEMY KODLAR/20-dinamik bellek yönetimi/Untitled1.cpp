#include <stdio.h>
#include <stdlib.h>

int main()
{
	//ptr pointer 
  int *ptr;
	//n degeri tan�mlan�r
  int n;
  //n'e 5 degeri at�l�r
  n=5;
  //i degsikeni tan�mlan�r
  int i;
  //n degerini ekranda g�sterir
  printf("Girdigimiz sayi degeri %d\n",n);
	//bu ifade n tane int boyutunda dizi yapar
  ptr=(int*)malloc(n*sizeof(int));
	//ama bellek i�inde yeterli alan olm�yabilir o zaman null d�ner sistemin null d�n�p d�nmedi�ini kontrol etmen laz�m
  if(ptr==NULL)
  {
      printf("Hafiza bolunmedi\n");
  }

  else
  {
  	
  		//burda diziye sayilar aktar�l�r 
      for(i=0;i<n;i++)
      {
          ptr[i]=i+1;
      }
		//diziye tan�mlanan sayilar yazd�r�l�r
      printf("Elemanlarim\n");
      for(i=0;i<n;i++)
      {
          printf("%d, ",ptr[i]);
      }
		//en son kulland�g�n alan� bosaltman laz�m
      free(ptr);

  }
    return 0;
}
/*
Girdigimiz sayi degeri 5
Elemanlarim
1, 2, 3, 4, 5,
*/
