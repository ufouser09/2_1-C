#include <stdio.h>
//fonksiyonu algoritmaya tan�t�r�z
int my_strlenV2(char *diziPtr);

int main(){
	//bir string ifadeyi karakterDizisi pointer�na atar�z
	char *karakterDizisi="her yonuyle c";
	//burda strlen ile karakter dizisinin uzunlugunu bulur ve onu uzunluk degiskenine atar�z
	int uzunluk=my_StrlenV2(karakterDizisi);
	//uzunluk degiskenini ekrana yazd�r�r�z
	printf("karakter dizisinin uzunlugu=%d\n",uzunluk);
	
	return 0;
}
//
int my_StrlenV2(char *diziPtr){
	int sayac=0;
	while(*diziPtr!='\0'){
		sayac++;
		diziPtr++;
	}
	return sayac;
}
//sayfa 401
