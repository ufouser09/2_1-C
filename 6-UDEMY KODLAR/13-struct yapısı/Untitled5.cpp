#include <stdio.h>
#include <stdlib.h>

//typedef ile struct'a tan�mlama esnas�nda isim at�yabiliriz
typedef struct {
float x_ekseni;
float y_ekseni;
}nokta;
//struct tan�mland�ktan sonra int main() gelir
int main()
{
	//burda struct nokta can dicegimize direk nokta can diyebildik
    nokta can;
    //can.x_ekseni diyip o struct�n o degerine erisebiliriz
    can.x_ekseni=3.154446545;
    //can.y_ekseni diyip o struct�n o degerine erisebiliriz
    can.y_ekseni=2.26474186;
	//atad�g�m�z degerleri burda yazd�rabiliriz
    printf("X eksenimiz %.2f Y eksenimiz %.2f",can.x_ekseni,can.y_ekseni);
    return 0;
}
/*
X eksenimiz 3.15 Y eksenimiz 2.26
*/
