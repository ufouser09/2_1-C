#include <stdio.h>
#include <string.h>

int main(int argc,const char *argv[]){
	//i degiskenini tan�mla
	int i;
	//bir tane char dizisi olustur
	//[3][10] demek 3 elemanl� 10 harfli bir dizin var
	char iller[3][10]={"ankara","izmir","antalya"};
	
	//illeri s�ras�yla yazd�rmana yarar
	for(i=0;i<3;i++){
		puts(iller[i]);
	}
	
	//bir tane char dizisi olusturursun
	char filmler[][40]={"asddas","adsads","qqweq","asdasd"};
	//asagidaki ifadeyi ekrana yazd�rmaya yarar
	puts("------film-listesi----");
	//illeri s�ras�yla ekrana yazd�r�r
	for(i=0;i<4;i++){
		puts(filmler[i]);
	}
	
	return 0;
	
	
}
//sayfa 329
