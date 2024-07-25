#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//head degiskenimiz gloabal bir degiskendi.
//biz kodlama yaparken global degisken kullanmaktan kac�n�r�z �unku bunun baz� zararlar� var.

typedef struct Employee {
	
	char name[21];
	char surname[21];
	char id[11];
	struct Employee *next;//----------->bu struct linked list t�r�nde olacag� i�in bir sonraki eleman�n adresini tutucak.
}EMPLOYEE;

//Kay�tlar� listelerken mesela once ad� yaz sonra id'yi yaz falan dicez
//Boyle ayn� i�i yapan ama kucuk detaylarla yapan bir fonksiyon pointer yap�caz.

EMPLOYEE *createNode();
void addRecord(EMPLOYEE **phead);
void removeRecord(EMPLOYEE **phead);
void printRecords(EMPLOYEE *head,void(*fptr)(EMPLOYEE*));
void printfNameFirst(EMPLOYEE *emp);
void printIdFirst(EMPLOYEE *emp);

int main(){
	EMPLOYEE *head=NULL;
	//Butun pointer degiskenler yukar�daki verileri saklamaz o veriye ait adres saklar. 
	
	//Biz linked listlerde ekle c�karma listeleme yap�caz ama bunlar� belirli �artlara g�re degistiricez:
	//mesela ada g�re sirala ya da ilk �nce surname yaz falan dicez.
	
	int choice=0;
	
	while(choice!=3){
		
		printf("1-Add \n2-Remove\n3-Exit");
		scanf("%d",&choice);
		
		switch(choice){
			
			case 1:addRecord(&head);//Adrecord'u cag�r�rken burda yapt�g�m siralama algoritmas� head'i g�ncellicek.
			//basa ekle sona ekle ortaya ekle bunlar� biz yap�caz.
			//adrecord'da head'in adresini �a��rcaz ��nk� head'in g�sterdigi deger fonksiyon i�erisinde degisecek 
			//ben bunu soyle de yapabilirdim mesela head=addRecord();
			//ama ben void bir method istedigim i�in boyle istedim.
			//yani hem gitsin parametre olarak hem de degissin...............................................
			
			
			printRecords(head,printfIdFirst);//Kay�tlar� yazd�rma fonksiyonu �a��rd�k burda 
			break;
			
			
			case 2:removeRecord(&head);
			printRecords(head,printNameFirst);//Kay�tlar� yukar�da ID ye gore yazd�k burda name'e gore yapt�k.
			break;
		
		}
	}	
}
//Void olm�cak bu,EMPLOYEE t�r�nde bir pointer dondursun.
//Bu sayede nolur yani createNode sayesinde basa ekle sona ekle ada g�re ekle 
//yani nas�l eklicekseniz bu fonksyion her biri i�in ca��r�l�p tekar tekrar malloc'lar falan yaz�lmaz.
EMPLOYEE *createNode(){
	
	EMPLOYEE *emp;
	
	//EMPLOYEE cast ettik 
	emp=(EMPLOYEE*)malloc(sizeof(EMPLOYEE));//-----------------------(1)-----------------------------------------------------------
																																	
																																	
	//sonra surdan kullan�c�dan verilerimizi de alal�m. 
	//burda degerleri okuduk.
	
	printf("enter id,name and surname,respectively\n");
	scanf("%s %s %s\n",&emp->id,&emp->name,&emp->surname);
	//�imdi ben employee'n�n adresini biliyorum employee'nin g�sterdigi yerdeki ID part�n�n alan�n� bilmiyorum 
	//dolay�s�yla ampersant koymazsak hata al�r�z.
	//git employee'nin g�sterdigi yerdeki ID adres alan�n�n adresini getir demek i�in burda ampersant kullanmam�z gerekiyor.
	//ayn� �ekilde employee name'i getir.sonra ayn� sekilde employee surname'i getir.bu bilgi al�ndiktan sonra sunu diyebiliriz.
	
	
	printf("eleman olusturuldu\n");
	
	return emp;
}


//buraya gelen �ey bir head pointer adresi 
void addRecord(EMPLOYEE **phead){

	//�imdi yeni bir kay�t olusturacag�m zaman �ncelikle belli alanlar okuycam 
	//bu belli okudugum alanlar olusturdugumuz struct eleman�na ve bu olusturdugumuz struct eleman�
	//listenin i�erisinde kal�c� halde olmas� i�in belle�in heap b�lgesinde olusturmas� laz�m 
	//belleg�n heap bolgesinde olusturmak i�in 
	//ne kullanmam gerekiyor.---------------------------(1)
	
	//dynam�c memory allocation kullanmam gerekiyor.
	//bu employee gecici bir pointer kulland�k.
	//employee pointer'�n�n g�sterecegi adrese bellegin heap bolgesinden bir degisken olustural�m 
	//yukar�daki return i�leminden sonra(yani createNode fonksiyonunun sonundaki return'den bahsediyor.) 
	//buraya gelen deger ne ise buraya aktar�lacak 
	EMPLOYEE *emp=createNode();
	
	
	//Degerleri okuduktan sonra geldik bu iki sat�ra.
	//�imdi emp'nin kendi i�inde bir next alan� var m� var bu next alan� head'in tabi burdaki phead'den bahsediyoruz.
	//Emp'nin next alan� yani emp buray� g�steriyor.
	//Bunun next'i phead'in i�erisindeki degeri g�stericek phead'in i�erisindeki deger neydi suan 100.
	//yan� buras� 100 nolu adresi g�stersin diyorum.bu ne demek oluyor.
	//ana programdaki yani bu nas�l buray� i�aret ediyorsa bu da buray� i�aret ediyo demektir.
	//sonra phead'in g�sterdigi adrestteki deger demektir bu phead nereyi g�steriyor buray� g�steriyor.
	//bu NULL bunun g�sterdigi adrestteki degere 300 yaz�cakm�s�z yani emp'nin adresini yaz�caz demektir.
	//burda da bunu yaz�yoruz.�imdi bu buray� g�steriyor.bu 100 nolu adreste su an i�in head'i g�steriyor.
	//sanki bir c�rcular durum var gibi.bi sonra bi tane daha kay�r ekliyelim hadi fonksiyon bi da �a��r�ld� fonksiyon cag�r�ld�ktan sonra head'imiz art�k null degil head bir adres g�steriyor.
	//ama head'in adresi sabit ��n� burda main i�erisinde tan�mlad�k herhangi bir �ekilde main fonksiyonu daha tamamlanmad� hala head degiskeni stack bolgesinde yas�yor.
	//Suraya geldik hala phead 100'u gostericek ayn� degisken yeni bir emp olusturuldu hatta yeni olusturulunca sunun i�erisini su dali kopard�k art�k yeni bir emp olusturulduktan sonra bir bellekte yer ac�ld� buraya 500 nolu adresi diyelim bu art�k bu sey art�k 500'u gostericek bunun kendine g�re degerleri okundu emp'nin next'i yan� suras� phead'in g�sterdigi degeri gosteriyomus.phead 100'u gosteriyodu buras� da 300'� gosteriyor.yani suraya 300 yaz dicekmi�.buraya 300 yaz diyerek art�k nap�yoruz.biz buray� g�steriyoruz.sonra emp'yi de head'in g�sterdigi yerdeki degere ata diyoruz.suras� da 500 olucakm�s.napt�k bu buraan koptu.bu art�k buraya geldi.c�rcular olma durumu nedir.head buray� g�stericek bu dugumu g�stericek.bu buray� g�stericek bunun en son adresini null yapmad�k da basa dondurduk.�imdi bunu birazdan yazd�rma k�sm�na gelince detay�na bakar�z.
	//employee'nin next'i e�ittir head olsun 
	emp->next=*phead;
	
	//sonra head'i de emp olsun diyorum. 
	*phead=emp; 
	
}
//�imdi baslnag�cta bir head'�m�z var head degiskenimiz var 
//head'in kendine gore 100 diye bir adresi var
//ilk basta i�erisi neyi g�steriyor.
//program a��l�nca null gosteriyor.

//surda fonksiyon i�erisine geldigimizde  headpp diye bi tan degiskenimiz var.
//head pointer yani addrecord fonksiyonundaki parametre.buraya gelen sey.
//buras� pointer oldugu i�in buray� 2.dereceden pointer yapt�k.
//addRecord i�indeki fonksiyonumuzun parametresi double pointer olucak.
//cunku adresi geliyor adresi geldigi i�in buran�n 2.derece pointer olmas� laz�m.buraya gelcek olan �ey 100 gelicek 
//sonra bir emp diye bir �ey olusturduk pointer.emp neyi tutucak malloc ile bellegin heap bolgesinde olusturulmus bir struct eleman�n�n adresini tutucak 
//i�te bu struct eleman� orneg�n 300 nolu adreste tutulsun bu 300 no'lu adresi g�stermek i�in emp i�ine 300 yaz�ld�.





//kay�t silme k�sm�:yine ayn� �ekilde bir head degiskenini al�caz.
//silmek istedigimiz kisinin ID sine g�re silicez genellikle ID uzerinden silinir.
void removeRecord(EMPLOYEE **phead){
	//burda bir ID degiskeni tan�mlad�k.silme i�lemi yaparken ��yle bir �ey yap�caz arad�g�m dugumler i�erisinde 
	//yani s�yle bir durum var bunlar birbirini g�steriyor.mesela 2.yi siliceksem burdaki su dugum art�k surdaki baglant� nap�cak suraya gidicek 
	//dolay�s�yla benim sunu tutmam gerekiyor.bi yandan da sunu tutmam gerekiyor.yani buraya geldigimde silicegim eleman� buldugumda 
	//bir �ncekinin next'i ile bir sonrakini linklemem gerekiyor sadece.onun i�in 2 tane degiskene ihtiyac�m var burda.
	
	char id[11];
	//birincisi current pointer diyelim.bu head �zerinden baslay�p arama yapmam� sagl�cak bir �ey olucak bunu boyle dereferans ile .
	EMPLOYEE *current=*phead;
	//bir digeri de EMPLOYEE arama i�lemi yaparken kullan�cag�m pointer �imdilik bu null olucak.
	EMPLOYEE *prev=NULL;
	//ve arama yaparken bi tane integer found degiskeni kullanal�m bulana kadar arama durumunda bir de 
	int found=0;
	
	//kald�r�lacak silinecek ki�inin ad�
	printf("enter id of the employee to be remove");
	scanf("%s",id);
	
	
	
	//2 tane �art�m olucak burda eger bulursam tekrar aramas�n diye �imdi current eleman yani s�rekli next next diye gidicez NULL dan farkl� oldugu muddetce ayn� zamanda ve bulunmad�g� muddetce aramaya devam et demek istiyorum.
	while(current!=NULL && !found){
		
		//sonra bir string kars�last�rmas� yap�cam i�te current eleman� g�sterdigi yerdeki ID degeri tabi bunu kar��last�rmak i�in strcmp kullanmak en dogrusu current '�n g�sterdigi yerdeki ID degeri bizim surda girdigimiz ID'ye e�itse yani bulduysak �ncelikle found=1 diyelim.
		if(strcmp(current->id,id)==0){
			found=1;
			
			//�imdi burda �ncelikle yap�cag�m�z sey onceki dugumu kontrol edicez.yani pev dugumunu kontrol edicez.prev dugumunun null olmas� durumunda mesela ilk elemanda bulduk head'i dogrudan silme durumumuz var.bir sonraki adresini kontrol etmek i�in �urda ��yle bir kontrol diyelim.mesela ilk elemanda bulduk.su head'in pointer'�n� phead tabi g�sterdigi yerin adresini phead e�ittir current eleman�n�n next'ine bi sonraki elemana dogru aktar�yoruz.phead'im e�ittir current next diyorum eger boyle bir durum yoksa 
			if(prev==NULL){
				*phead=current->next;//phead'imiz current next'imiz nereyi gosteriyorsa art�k oray� gosteriyor.
			}
			
			//boyle bir durum yoksa ne demek ilk eleman� degil baska bir eleman� siliceksem o zaman nap�cam previous'u bi yerde saklamam laz�m.prev'in next'i e�ittir current'in next'i diyebiliriz.bu i�lemi yaparak asl�nda silmi� oluyorum.yani aradaki dugumu devreden c�kard�m.tabi buldugum i�in nap�cam ordaki current eleman�n�n g�sterdigi yerdeki bellek alan�n� serbest b�rakmam gerekiyor.eger bu i�lem yanl�ssa yani bulmad�ysak.
			else{
				prev->next=current->next;
			}
			free(current);
		}
		
		//bu durumda yap�cag�m�z sey ne olur.su ank� eleman� previous olarak yani en son kald�g�m bi �nceki eleman olarak al�cam.yani prev e�ittir current olucak current'� da bi sonraki elemana g�ndercem.current e�ittir.niye current �zerinde gezdim.head'i kaybetmemek i�in bu ancak ya dizinin sonuna kadar ki burda basa donme durumu da var asl�nda bi �ekilde bu bu �ekilde aramaya devam edicek.
		else{
			prev=current;
			current=current->next;
		}
	}
	
}
//�imdi bu fonksiyonu �a��rd�g�mda bana phead geliyor.su an i�in phead'in adresi 100.
//�imdi current diye bir degiskenim var prev diye bir baska degiskenim var.
//head'in g�sterdigi yerdeki adresin degeri yani head'in g�sterdigi yerdeki deger neymi� 500 olucakm��.
//EMPLOYEE *current=*phead  bu sat�rda bunu yapt�k.
//prev olusturduk buras� null olucakm��.
//sonra found demi� i�te bir ID girin demi�.ID girildi.
//su arada bi dugum daha olsun buras� da 800 olsun bu 800 buray� gostersin head'de nereyi g�stericek.
//Boyle 3 tane listedeki eleman olsun.
//oncelikle biz diyelim ki suradaki bir ID'ye kars�l�k gelen bir sey bulduk.
//�imdi donguye giriyoruz.current'�n ID'si �imdi current dedigimiz sey neyi g�stericek.
//current da buray� gostericek.
//bu girdigim ID burdaki ID'ye esit oldugunu kabul edelim.yani su sart dogru oldu.
//found'� 1 yapt�k.
//previous su an null mu:evet.null oldugu i�in phead'i nap�yorum current'�n nextine current'�n nexti ne demek current buray� g�steriyor.
//bunun nexti de 500'� g�steriyor.sonra phead'in gosterdigi adrese git 500 yap yani git suray� 500 yap dedi 500 yap�nca noldu su bag gitti.
//tekrar buray� gosterdi.dedi ki su current'� free et.

//degilse k�sm�na gectik tekrar basa gecti kayd�m�z silindi tabi tekrar basa donmedik buldugumuz i�in donguden ��kt� gitti.
//sonra bu fonksiyon tekrar cag�r�ld�.bu fonksiyon tekrar cag�r�ld�g�nda kim cag�r�yor bunu main cag�r�yor.
//ma�n'den head'le cag�r�yor.head'in hala program kapanmad�g� i�in head'in adresi hala 100 sonra current'�m�z var 
//current'�m�za bu sefer neyi atad�k phead'i atad�k.yani phead'in g�sterdigi adres.su an 500'du.bu da buray� g�steriyor olsun.burda da null var.
//ID girelim girdik bir ID i�te surdaki ID ye e�it olucak bi �ey yapal�m �imdi de.
//s�md� current'�n ID's� ID'ye e�it m� hay�r.hay�r oldugu i�in geliyorum su else k�sm�na diyorum ki current'� prev'e ata current'�n i�indeki deger ne 500.bunu 500'e atad�k.
//)art�k bu da buray� g�steriyor.current'� current'�n next'ine ata current buray� g�steriyor.bunun next'i nereyi g�steriyor.buras� 300 olucakm�s demek ki.
//bu ne oldu bu art�k buray� g�sterdi.donduk basa tekrar girilen ID ID ye e�it mi evet.bulduk olarak i�aretledik.previous null'a e�it mi previous null' a e�it degil 
//�u k�sma geldik.diyo ki prev'in next'ine.prev nereyi g�steriyor buray� g�steriyor.bunun next'i nereyi g�steriyor.suray� gosteriyor.bu prev'in g�sterecegi next alan�.
//prev'in next'ine dedigimiz sey su alan current'�n next'ine atan�cakm�s.
//current'�n next'inde ne var.100 var.current'�n next'inde 100 var.suraya getir d�yoruz.yani bu nap�acak burdaki baglant�y� kopard�k.
//bu buray� g�stericek �imdi.bu buray� g�sterince bu da buray� g�steriyor.bu ilk ad�mda bunu yapt�k.sonra bu c�kt�ktan sonra current'� diyo ki free et.
//current'� free etmek ne demek burdaki dugumu yok et.burdaki dugum yok olunca surdaki baglant� tamamen gitmi� oluyor.
//ondan sonra ne kald� else k�sm�nda herhangi bir �ey kalmad� dongu bitti.bu buldugumuz i�in.fonksiyon bitti ve maine geri donduk.ekle ve sil bu kadar.
//napt�k �ift pointer kullanarak head'in gosterdigi k�sm� dinamik olarak degistirdik.

//�imdi su printNameFirst alanlar�n� da yazal�m.





-----------------
|		500		|				
|				|				
-----------------


-----------------
|		500		|
|				|
-----------------

-----------------
|		500		|
|				|
-----------------














//�imdi bunu cag�racak printRecord ��nk� bu fonksiyon dogrudan  �a�r�lm�yo hi�bir �ekilde.
//cag�r�lacak sey ne asl�nda kay�tlar� yazd�rmak ne asl�nda dizinin bas�ndan basla sonuna kadar git ben asag�daki fonksiyonlar i�in ayr� ayr� while dongusu yazmama gerek yok.her �ey ayn� ilerliyor.bunun i�in daha generics bir fonksiyon yaz�yorum.
//bir head'i al�yorum bir de head ile birlikte burda hangi fonksiyonu �a��racaksam onun pointer'�n� al�cam.pointer tan�m� bu iki fonksiyonu da prototopi ile yaz�caz.void turunde bir pointer tan�m� gelicek iste buna *fptr diyelim fonksiyon pointer oldugunu soyliyelim.ve burda parametre olarak kullan�lacak olan sey bu fonksiyonlarda EMPLOYEE �eklinde bir pointer kullan�lacak boyle bir prototip ald�m.bu prototipi aktar�lacak degisken nereye geliyor.sunun adresi su degiskene geliyor.gelelim bunun i�erisine yazal�m.

//printRecord �a��r�lacak �ey ne asl�nda
void printRecords(EMPLOYEE *head,void (*fptr)(EMPLOYEE*)){
	//tmp eleman olusturuyoruz gezinmek i�in bu elemana da direk head'i atayabiliriz.
	EMPLOYEE *tmp=head;
	
	while(tmp!=NULL){
		//ne yap her bir gordugun dugumde fptr'yi cag�r.neyle cag�r nas�l parametre istiyosam onla cag�r.
		fptr(tmp);
		//su tmp'yi de guncelle
		tmp=tmp->next;
	}
}

//oncelikle bu bir void bir method
void printfNameFirst(EMPLOYEE *emp){
	printf("%s %s %s\n",emp->name,emp->id,emp->surname);
}
//bir de printIDfirst yazal�m ikisini de kullanal�m.s�md� burda herhangi bir head uzerinde degisiklik yapm�caz.head �zerinde degisiklik yapm�cag�m�z i�in burda dogrudan head'in kendisini adresini g�ndermeden ki kendisini gondermek daha dogru.pointer'�n� al�p napabiliriz burda tabi burda sadece bir degisken yaz�cam onun i�in diyorum ki tek bir pointerla bu i�i yapabiliriz.
//Bunu birazdan fonksiyon pointer'� olan baska bir fonksiyon cag�racak 
void printfIdFirst(EMPLOYEE *emp){
	printf("%s %s %s\n",emp->id,emp->name,emp->surname);
}
//cal�sman�z i�in soru istersek neler yap�labilir.
//mesela ID ye gore aray� ekle ada gore aray� ekle veya sona ekle dogrudan basa ekle diyebilirsiniz.bunu cesitlendirebilirsiniz.bunu cesitlendirirkende addRecord'un ilk 4 sat�r� ayn� olucak 



