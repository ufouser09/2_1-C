#include <stdio.h>
int main(int argc,const char *argv){
	//bir tane kullanici dizisi olustur
	char kullanici[20];
	unsigned long karakterSayisi=0;
	//kullan�c�dan bir string al�n�z
	printf("lutfen bir isim giriniz\n");
	//kullan�c�dan string al�rken & adres isaretine gerek yok
	scanf("%s",kullanici);
	
	//kullan�c�daki karakter sayisinin boyutunu strlen sayesinde al�r�z ve onu da karaktersayisi degiskenine atar�z
	karakterSayisi=strlen(kullanici);
	//girilen karakterin boyutuna g�re kontrol yapar�z
	if(karakterSayisi<6){
		printf("girdiginiz isim 6 karakterden fazla olmalidir\n");
		
	}
	else{
		printf("girdiginiz kelime gecerli");
	}
	
	return 0;
}
//sayfa 332
