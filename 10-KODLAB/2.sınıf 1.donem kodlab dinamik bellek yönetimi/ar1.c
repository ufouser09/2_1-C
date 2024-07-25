#include <stdio.h>
#include <stdlib.h>
int main(){
	//*ptr pointýrýný tanýmlarýz
	int *ptr;
	//bellekte int boyutunuda bir yer ayýrýrýz bunun için ptr pointerýný kullanýrýz
	ptr=(int *)malloc(sizeof(int));
	//eger bellekte bos yer yoksa null olarak döner bunu kontrol etmen lazým
	if(ptr==0){
		printf("hata->bellekten yer ayrýlmadý!");
		//bellekte bos yer yoksa 1 olarak döner
		return 1;
	}
	//ptr pointerýna 225 degeri atýlýr
	*ptr=225;
	//ptr pointerýndaki deger ekrana yazdýrýlýr
	printf("%d\n",*ptr);
	//en son bellegi bosaltman lazým
	free(ptr);
	return 0;
	
}
//sayfa 430
/*
225
*/
