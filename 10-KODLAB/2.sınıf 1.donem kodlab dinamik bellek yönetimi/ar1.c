#include <stdio.h>
#include <stdlib.h>
int main(){
	//*ptr point�r�n� tan�mlar�z
	int *ptr;
	//bellekte int boyutunuda bir yer ay�r�r�z bunun i�in ptr pointer�n� kullan�r�z
	ptr=(int *)malloc(sizeof(int));
	//eger bellekte bos yer yoksa null olarak d�ner bunu kontrol etmen laz�m
	if(ptr==0){
		printf("hata->bellekten yer ayr�lmad�!");
		//bellekte bos yer yoksa 1 olarak d�ner
		return 1;
	}
	//ptr pointer�na 225 degeri at�l�r
	*ptr=225;
	//ptr pointer�ndaki deger ekrana yazd�r�l�r
	printf("%d\n",*ptr);
	//en son bellegi bosaltman laz�m
	free(ptr);
	return 0;
	
}
//sayfa 430
/*
225
*/
