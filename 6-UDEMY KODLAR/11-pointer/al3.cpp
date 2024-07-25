#include <stdio.h>
#include <stdlib.h>

void degistir(int ad1,int ad2)
{
	//burada ad1 ve ad2'yi degistiririz
    int gecici;
    gecici=ad1;
    ad1=ad2;
    ad2=gecici;
	//degistirdikten sonra a1 20 a2 10 olur bu sefer onlar� ekranda yazd�r�r�z
    printf("Ilk sayim %d ikinci sayim %d\n",ad1,ad2);

}


int main()
{
	//a'ya 10 b'ye 20 degerini atar�z
   int a=10,b=20;
   //bu atad�g�m�z degiskenleri yazd�r�r�z yani ekranda 10 ve 20 c�kar
   printf("Cagirmadan once %d %d\n",a,b);
   //degistir fonksiyonana parametre atar�z
   degistir(a,b);
   //pointer ile yapmad�g�m�z i�in degiskenlerin degerleri tamamen degismedi
   printf("Cagirdiktan sonra %d %d",a,b);

    return 0;
}
/*
output:
Cagirmadan once 10 20
Ilk sayim 20 ikinci sayim 10
Cagirdiktan sonra 10 20
*/
