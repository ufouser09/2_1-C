#include <stdio.h>
#include <stdlib.h>

int main()
{
	//bir tane isim dizisi tutar�z
    char isim[20]={'b','o','n','j','o','u','r','\0'};
    //*can degiskeni tan�mlar�z
    char *can;
	//isim dizisinin bas�ndaki degeri can'a pointer'�na atar�z	
    can=isim;
	//*(can+1)ile de dizinin bir sonraki eleman�na yani 2.eleman� olan 'o' karakterine ulas�r�z 
    printf("%c",*(can+1));


    return 0;
}
/*
output:
o
*/
