#include <stdio.h>
int main(int argc,const char *argv){
	//bir tane kullanici dizisi olustur
	char kullanici[20];
	unsigned long karakterSayisi=0;
	//kullanýcýdan bir string alýnýz
	printf("lutfen bir isim giriniz\n");
	//kullanýcýdan string alýrken & adres isaretine gerek yok
	scanf("%s",kullanici);
	
	//kullanýcýdaki karakter sayisinin boyutunu strlen sayesinde alýrýz ve onu da karaktersayisi degiskenine atarýz
	karakterSayisi=strlen(kullanici);
	//girilen karakterin boyutuna göre kontrol yaparýz
	if(karakterSayisi<6){
		printf("girdiginiz isim 6 karakterden fazla olmalidir\n");
		
	}
	else{
		printf("girdiginiz kelime gecerli");
	}
	
	return 0;
}
//sayfa 332
