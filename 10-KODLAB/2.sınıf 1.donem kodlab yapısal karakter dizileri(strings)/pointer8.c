#include <stdio.h>
int main(){
	//bir tane char dizisi olustururuz
	char dizi[20];
	//i degiskeni tanýmlar ve ona 0 degerini atarýz
	int i=0;
	//kullanýcýdan bir kelime alýrýz
	printf("lutfen bir kelime giriniz\n");
	//kullanýcýdan bir String aldýgýmýzda & adres isaretini kullanmamýza gerek yok
	scanf("%s",dizi);
	//bu while in içindeki ifade dizinin sonuna kadar gider
	while(dizi[i]!='\0'){
	//indisi bir arttýrýrýz
	i++;
}
//harf sayisini ekrana yazdýrýrýz
printf("%d",i);
return 0;
}
//sayfa 333
