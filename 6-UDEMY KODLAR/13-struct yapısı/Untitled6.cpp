#include <stdio.h>
#include <stdlib.h>

 typedef struct
{
    char isim[10];
    float x_ekseni;
    float y_ekseni;
}nokta;
	//buraya parametre olarak gelen can,nokta can[] diye geldigi i�in i�erde de nokta p[] yapar�z,5 sayimiz normal bir integer'd�r onu int n diye tan�mlar�z
    void ekranayazdir(nokta p[],int n)
    {
    	//i degiskenini tan�mlar�z
        int i;
        
        for(i=0;i<n;i++)
        {
        	
            printf("%s = (%.2f,%.2f)\n",p[i].isim,p[i].x_ekseni,p[i].y_ekseni);
        }

    }

int main()
{
	//typedef dedigimiz i�in struct nokta can dicegimize nokta can diyebildik
    nokta can[5]={{"Can",3,4},{"Hakan",5,3},{"Osman",5,3},{"Deniz",5,3},{"Merve",5,3}};
    //can degiskenimizi ve 5 sayisini ekrana yazd�r fonksiyonuna atar�z
    ekranayazdir(can,5);

    return 0;
}
/*
Can = (3.00,4.00)
Hakan = (5.00,3.00)
Osman = (5.00,3.00)
Deniz = (5.00,3.00)
Merve = (5.00,3.00)
*/
