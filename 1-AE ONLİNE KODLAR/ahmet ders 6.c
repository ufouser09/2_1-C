//soru:bir �ifreleme algoritmas� harflerin asc�� kars�l�klar�ndan olusan MxM matristen meydana gelen bir image yarat�yor.
//(matrisin her bir h�cresi 0-255 arasinda bir pixel degerine kar��l�k geliyor.bir pixelin degeri 0 ise bu pixelde harf olmad�g� anlam�na gelmektedir)bir kelimenin ilk harfi 0x0 h�cresinde ikinci harf 0x1....�eklinde saklan�yor.
//bir metni �ifreleyen ve �ifreli metnin �ifresini ��zen birer algoritmay� c dilinde gercekleyelim
//not �ifrenin uzunlugu �nceden bilinmedigi varsayilacaktir.
//�rnek input ve output
/*    89 73 76 68
      73 90 84 69
      75 78 73 75
      0  0  0  0 
      //matrix representetation of �mage
      //the str�ng "YILDIZTEKN�K"
      
      */
      //bir hucresinde 0 varsa orda harf yok demek olucak
      //�ncelikle hang� degiskenlere �ht�yac�m�z var 
	  //ilk once mesela str�ng�n uzunlugunu al�caz bu y�zden 
	  //kelimemizin uzunlugunu tutan degiskene �ht�yac�m�z var 
	  //bu uzunlugu ald�ktan sonra nap�caz fotograf�m�z MxM boyutunda bir matris olucag�na g�re
	   //bu harflerin bu kelimerin s�gacag� sekilde M degerini hesaplamam�z gerekiyor 
	  //yani M �n karesinden kucuk olucak sekilde olmal� bu kelimenin uzunlugu
	  
	  #include <stdio.h>
	  #include <stdlib.h>//dynamic memory allocation i�in
	  #include <math.h>
	  
	  
	  int main(int argc,char *argv[]){
	  	
		int textSize,m,i,j,k,pixel;
	  	
		//text dizisi 1D boyutundad�r.
		//kullan�c�dan al�nacak kelimenin tutuldugu array.
	  	char *text;//kullan�c�dan ald�gm�z text i�in bir dizi tutucaz
	  	
		  char junk;
	  	
	  	//ayn� �ekilde dizimizi tan�ml�yal�m
	  	//bu bir matris 	
		  int **theImage;
	  	
	  	//kullan�c�dan bir tam sayi girmesini isticez
	  	printf("enter the length of text to encrypt\n");
	  	scanf("%d",&textSize);
	  	
	  	//dizimizi kullan�c�dan aldg�m�z tam say� dogrultusunda olustural�m
	  	//textSize boyutunda text dizimizi tekrar g�ncellemi� olduk
		  text=(char *)(malloc)(sizeof(char)*textSize);
	  	
	  	
	  	
	  	printf("enter the text \n");
	  	scanf("%c",&junk);
	   	scanf("%[^\n]s",text);
	  	//alternatif scanf("%s",text);
	  	
	  	//burda sunu yap�yoruz mesela kelimemiz 12 harfli bunun karekoku 3 olur bunu yuvarlay�nca  4 eder 4x4=16 olur yan� text�m�z matrisimizin i�ine s�gm�s oluyor
	  	
	  	m =ceil(sqrt(textSize));
	  	
		//text dizisi i�in indextir
	  	k=0;
	  	theImage=(int**)(calloc)(m,sizeof(int*));
	  	for(i=0;i<m;i++){
	  		theImage[i]=(int*)(calloc)(m,sizeof(int));
		  }
	  	
	  	for(i=0;i<m;i++){
	  	//	theImage=(int**)realloc(theImage,(i+1)*sizeof(int*));
	  		for(j=0;j<m;j++){
	  	//		theImage[i]=(int*)realloc(theImage[i],(j+1)*sizeof(int));
	  			if (k<textSize){
	  				pixel=(int )text[k];
	  				theImage[i][j]=pixel;
	  				
				  }
				  else {
				  	theImage[i][j]=0;
				  }
				  k++;
	  		  	
			  }
		  }
	  	printf("the �mage is:\n");
	  	for(i=0;i<m;i++){
	  		for(j=0;j<m;j++){
	  			printf("%3d",theImage[i][j]);
			  }
			  printf("\n");
		  }
		  free(theImage);
		  free(text);
	  	return  0;
	  }
	  //KOD CALISIYOR
	  //a��klamalar� yaz�ld�
