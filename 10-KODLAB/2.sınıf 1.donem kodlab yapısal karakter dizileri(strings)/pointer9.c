#include <stdio.h>
int main(int argc,const char *argv){
	//bir tane char dizisi olustur
	char dizi1[20]="merhaba";
	//bir tane char dizisi olustur
	char dizi2[20];
	
	//diiz2 ye dizi1'i kopyala
	strcpy(dizi2,dizi1);
	//dizi1'i ekrana yazdir
	printf("dizi1--->%s\n",dizi1);
	//dizi2'yi ekrana yazdir
	printf("dizi2--->%s",dizi2);
		
}
//sayfa 333
