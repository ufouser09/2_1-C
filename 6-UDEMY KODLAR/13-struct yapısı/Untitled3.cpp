#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//burda struct ��renci diye bir strucut tan�ml�yoruz
struct ogrenci{

char ad[10];
char soyad[10];
int yas;
};
//structlardan sonra int main() yapar�z
int main()
{
	//struct i�inde tan�mlad�g�m�z 3 degiskene b�yle atama yapabiliriz.burda ayr�ca struct ogrenci dedigimiz structa can ismini veririz
   struct ogrenci can={"Can","Boz",27};
   
   //structlarda bir degere erisebilmek i�in struct�n ismi sonra nokta sonra ise struct i�indeki degiskenin ismini koyar�z mesela burda struct�n ismi can.ad diyip atad�g�m�z ad degiskenine erisebiliriz 
   /*strcpy(can.ad,"Can");
   strcpy(can.soyad,"Boz");
   can.yas=27;*/
	//burda atad�g�m�z degerleri ekrana yazd�r�r�z
   printf("%s \t %s \t %d",can.ad,can.soyad,can.yas);

    return 0;
}
/*
Can      Boz     27
*/
