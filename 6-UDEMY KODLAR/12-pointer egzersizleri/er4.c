#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//dizi adli bir dizi tan�mlars�n	
    char dizi[100];
    //eleme adl� bir degisken tan�mlars�n
    char eleme;
    //*can adl� bir degisken tan�mlars�n
    char *can;
	//kullan�c�dan bir karakter dizisi istersin
    printf("Lutfen bir karakter dizisi girin\n");
    //String ifadeleri gets ile al�rs�n
    gets(dizi);
    //karakter dizisinden ��karmak istediginiz karakteri kullan�c�dan al�rs�n
    printf("Karakter dizisinden c�karmak istediginiz karakter nedir :");
    scanf("%c",&eleme);
	//dizinin bas�ndaki eleman� can'a atars�n
    can=dizi;
    //dizinin sonuna kadar gider
    while(*can)
    {
    	//dizinin i�inde gezerken ��karmak istedigimiz elemanla kars�las�rsak bu if'e gireriz
        if(*can==eleme)
        {
        	//dizinin bir sonraki eleman�n� su anki degerimiz yerine yerlestiririz
            strcpy(can,can+1);
        }
        else
        {
        	//can indis degerimiz gibidir onu bir artt�r�r�z
            can++;
        }
    }


    printf("Eleme yapildiktan sonra karakter dizimizin son hali :%s ",dizi);
    return 0;
}
/*
output:
Lutfen bir karakter dizisi girin
efeee
Karakter dizisinden c�karmak istediginiz karakter nedir :e
Eleme yapildiktan sonra karakter dizimizin son hali :f
*/
