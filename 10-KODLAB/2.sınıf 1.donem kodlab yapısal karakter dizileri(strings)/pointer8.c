#include <stdio.h>
int main(){
	//bir tane char dizisi olustururuz
	char dizi[20];
	//i degiskeni tan�mlar ve ona 0 degerini atar�z
	int i=0;
	//kullan�c�dan bir kelime al�r�z
	printf("lutfen bir kelime giriniz\n");
	//kullan�c�dan bir String ald�g�m�zda & adres isaretini kullanmam�za gerek yok
	scanf("%s",dizi);
	//bu while in i�indeki ifade dizinin sonuna kadar gider
	while(dizi[i]!='\0'){
	//indisi bir artt�r�r�z
	i++;
}
//harf sayisini ekrana yazd�r�r�z
printf("%d",i);
return 0;
}
//sayfa 333
