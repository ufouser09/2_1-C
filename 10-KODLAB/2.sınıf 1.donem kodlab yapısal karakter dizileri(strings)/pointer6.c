#include <stdio.h>
#include <string.h>

int main(int argc,const char *argv[]){
	//i degiskenini tanýmla
	int i;
	//bir tane char dizisi olustur
	//[3][10] demek 3 elemanlý 10 harfli bir dizin var
	char iller[3][10]={"ankara","izmir","antalya"};
	
	//illeri sýrasýyla yazdýrmana yarar
	for(i=0;i<3;i++){
		puts(iller[i]);
	}
	
	//bir tane char dizisi olusturursun
	char filmler[][40]={"asddas","adsads","qqweq","asdasd"};
	//asagidaki ifadeyi ekrana yazdýrmaya yarar
	puts("------film-listesi----");
	//illeri sýrasýyla ekrana yazdýrýr
	for(i=0;i<4;i++){
		puts(filmler[i]);
	}
	
	return 0;
	
	
}
//sayfa 329
