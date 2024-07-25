#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//boyle bir noktalar format�nda noktalar�n kordinatlar�n� i�eren bir dosyam var.Bunlar� okuycam ve bunlar� linked list i�erisine al�caz.
//linked list i�erisinde i�lemler yap�p orj�ne en yak�n,en uzak gibi senaryolarla buna cal�scaz.

//Oncelikle yap�cag�m�z sey bunun struct'�r�n� olusturmak daha sonra fonksiyonlar�n� yazmak.
//burda bir nokta struct'�r�m�z olsun.
//Bir linked list �eklinde olucag� i�in i�erisindeki her bir noktan�n bir sonraki degerini de tutmak istiyorum.
struct Nokta{
	int x,y;
	struct Nokta *next;
};
typedef struct Nokta NOKTA;

//bir de en uzak noktan�n bilgilerini isticem.bunun i�in de soyle bir �ey yapmak istiyorum.
typedef struct EnUzak{
 	int d;//en uzak noktan�n distance'si.
 	NOKTA *pt;//bir de bu hangi noktaysa bu distance's� g�steren bir pointer tutucam.yani yukar�daki elemanlardan bir tanesinin pointer'�n� tutucam.
 }ENUZAKNOKTA;
 
 //NOKTA t�r�nde pointer donduren bir fonksiyonumuz olsun burda sadece dosyan�n ad�n� verelim.
 NOKTA* dosyadanOku(char*);
 //listeyi yazd�ral�m hatta listeyi iki t�rl� yazd�ral�m.
 void listeYaz(NOKTA*);
 //bu versiyon 2 de recursive yazd�r�caz.
 void listeYazRec(NOKTA*);
 //parametre olarak nokta turunde bir pointer als�n.
 NOKTA* enUzakNoktaBul(NOKTA *,int*);
 
 ENUZAKNOKTA *enUzakNoktaBulv2(NOKTA *);
 
 int main(){
 	//okunacak dosyan�n ad�nn� kullan�c�dan al�yoruz.
 	char dosyaAdi[30];
 	NOKTA *head;//------------------------(1)
 	
 	//max isminde b�r dugumum olsun
	NOKTA *max;
 	ENUZAKNOKTA *n;
 	int d;
 	printf("Okunacak dosyan�n adi");
 	scanf("%[^\n]s",dosyaAdi);
 	
 	//dosyadan oku fonksyonuna dosyan�n ad�n� gondericem.
 	//okuma i�lemini bitirdikten sonra bir linked list yaz�cak.o linked list'te bana head laz�m.
 	//yani bir donus degeri olsun diyorum.head diye bir �ey olusturuyorum burda head'e aktar�lacak.
 	//bunu yapmak i�in de NOKTA turunde bir pointer yazmam laz�m.----------------------(1)
 	head=dosyadanOku(dosyaAdi);
 	//Dosyadan okuduktan sonra bu listeyi alal�m ekrana yazd�ral�m.
 	//listeYaz'a head'i gonderiyorum.
 	listeYaz(head);
 	printf("Recursive printf\n");
 	listYazRec(head);
 	
 	//bu max'a en uzak nokta bul'dan return gelicek.ben ona ne g�ndercem.head'i g�ndericem bir de integer olarak bir degiskneim olucak,bu d'nin adresini g�nderiyor.
 	//bu sayede boyle yaparak napabiliriz asl�nda fonksiyonlarda birden fazla veriyi dolayl� olarak return edebiliyoruz.
 	//normalde burda bi tane veri dondurulebilir.
	 max=enUzakNoktaBul(head,&d);
 	printf("en buyuk uzakl�k degeri:%d\n",d);
 	printf("en uzak nokta(%d,%d)\n",max->x,max->y);
 	
	//ayn� �ekilde dondurdugu sey ne olsun yine bunu max'�n i�erisine alabilir miyiz alamay�z.onun i�in nap�caz su turden enuzaknokta turunden n isimli bir pointer olusturuyorum.bu n isimli pointer daha once malloc ile asag�da olusturulmus bir adres alan�n� tutacak ve bu n'nin degerlerini surda oldugu gibi yaz�caz 
 	n = enUzakNoktaBulv2(head);	
 	printf("en buyuk uzakl�k degeri_v2:%d\n",n->d);
 	printf("en uzak nokta(%d,%d)_v2\n",n->pt->x,n->pt->y);
	
 	
 }
 
 //NOKTA t�r�nde bir pointer dondurcek.
 //parametre olarak ne alcak:bi tane karakter dizi al�cak.
 Nokta* dosyadanOku(char *dosyaAdi){
 	//oncelikle bizim FILE pointer'�na ihtiyac�m�z var.
 	FILE *fp;
 	//�imdi linked list'ten okurken ��yle bir �ey yapal�m:
 	//dizinin bas�ndan sonuna surekli git git yapm�yla�m her defas�nda basa don sonra sona git olmas�n
 	//ben hem head'i tutay�m hem de en son dugumu tutuy�m.
 	//surekl� sona ekl�yelim yan�.
 	//ama sona eklemek i�in surekli bastan arama da yapm�yal�m.
 	
 	//ilk basta head'imiz NULL.
 	//bi tane end dugumumuz olucak.
 	//bi tane de tmp pointer'�m�z olsun.
 	NOKTA *head=NULL,*end,*tmp;
 	//file pointer e�ittir fopen
 	fp=fopen(dosyaAdi,"r");
 	if(fp==NULL){
 		printf("Dosya acilamadi");
 		
	 }
	 else{
	 	//�imdi gelelim dosyay� acmaya.bi kere burda yap�cag�m�z i� dosyan�n sonuna kadar gitmek.while dongusu ile butun elemanlar� okucaz.
	 	//bu i�lem bittikten sonra dondurceg�m�z sey nolucak return diyelim head'i dondurecez.
	 	//while'�n alt�nda da okucaz.
	 	//dosyay� zaten yukar�da act�k.
	 	//bu while'�n i�inde okuycaz sonra linked list'e eklicez.
	 	while(!feof(fp)){
	 		//once bir dugum olustural�m tmp i�in bir tek elemanl� dugum olustural�m.
	 		//cunku bu linked list'in her defas�nda b�r eleman okuyunca olusturdugum bir dugum olucak.
	 		//asag�daki gibi bir dugum olusturduk.
	 		//daha sonra fscanf ile bu dugume veri okuyorum.
	 		tmp=(NOKTA*) malloc(sizeof(NOKTA));
	 		//file pointer'dan oku.
	 		fscanf(fp,"%d %d\n",&tmp->x,&tmp->y);
	 		//tmp'nin next'ini default olarak null yap.
	 		//s�md� bu dugum olustu.
	 		tmp->next=NULL;
	 		//soyle bir algoritma dusunelim eger head'�m NULL ise yani hi� eleman yoksa ilk basta nap�cak ilk dugum olarak bunu eklicek.
	 		//ve ilk dugum de son dugum de dogrudan tmp'n�n bulundugu adresi gostericek.
	 		//art�k tmp malloc ile olusturuldugu i�in heap bolgesinde bir �ey yani fiziksel olarak program yasad�g� muddetce var olan bir �ey.hatta baz� durumlarda program crash etse bile cal�s�yor.garbage olarak kal�yor.
	 		//ilk ad�mda head'imiz null oldugunda ilk eleman olarak bu geldi.
	 		
	 		if(head==NULL){
	 			head=end=tmp;
			 }
			 //eger ilk eleman null degilse end'imiz onceden vard� bi yeri g�steriyodu end'�n next'ini dogrudan tmp yap diyorum.
			 //end'i de guncelle 
			 //ama bize laz�m olan butun listeye erismek i�in gerekl� olan sey surdaki head dugumumuz.-------------------------->(2)
			 else{
			 	end->next=tmp;//art�k end'imizin next'i yeni ekledigimiz dugumu gostericek.
			 	end=end->next;//bir dugum ekledigimiz i�in son dugumu tutan node'umuz bir ileri gidicek.
			 }
		 }
		 //Dosyam�z� kapat�r.
		 fclose(fp);
	 }
	 return head;//------------------>(2)
 }
 //ne laz�m bize parametre olarak NOKTA turunde head pointer'�m�z laz�m burda liste uzerinde gezinecegimiz i�in ikinci bir pointer daha gerekiyor.
 //ve bunu head'e at�yoruz dogrudan----------->(3) tmp uzerinden gezinecegiz.
 void listeYaz(NOKTA *head){
 	NOKTA *tmp=head;//------------------>(3)
 	
 	printf("noktalar listesi\n");
 	
 	//tmp NULL dan farkl� ise 
 	while(tmp!=NULL){
 		printf("(%d,%d)->",tmp->x,tmp->y);
 		tmp=tmp->next;
	 }
	 //sonunu g�stersin diye yapt�k.
	 printf("null");
 }
 //yukar�daki klas�k iteratif algoritma bi de bunun recursive'ini yazal�m.
 //recursive methodlar�n �zelli�i neydi kendini cag�racak.
 //yine burda bana head'in tmp dugumu laz�m.
 void listeYazRec(NOKTA *head){
 	NOKTA *tmp=head;
 	
	//eger tmp NULL'dan farkl� ise yani son dugume ulasmam�ssak.
 	//ulasmam�ssak demek ki suan aradaki herhangi bir yerdeyiz.
 	if(tmp!=NULL){
 		//oncelikle nap�caz dugumu yazd�racaz.
 		printf("(%d,%d)->",tmp->x,tmp->y);
 		//sonra bir sonraki dugume gecmek i�in fonksiyonumu tekrar cag�racam.
 		//�imdi ilk gelen head dugum ilk eleman null olmad�g� i�in yaz�ld� sonra tmp'nin next'i diyerek ikinci eleaman� head'm�s gibi cag�racaz.i�te bu tmp olucak null degilse.en son bi yerde bu null olucak yani if'in i�erisinden c�k�caz.	 
 		listeYazRec(tmp->next);
	 }
	 //o zaman da sunu yapal�m.
	 else{
	 	printf("null");
	 	
	 }
 }
 //en uzak noktan�n bulundugu dugumu al�p bu dugumu dogrudan yukar�daki structer eleman�ye return etmek istiyorum.
 //buraya bir parametre olarak bir head gelicek ve ben burda maximum distance'� bulmak i�in soyle bir yani kacsa o deger o degeri bulmak i�in boyle bir deger istiyorum.yani parametre al�cam.
 NOKTA *enUzakNoktaBul(NOKTA *head,int *dmax){
 	//bir tane yine tmp dugumumuz olucak ilk basta bunu head'e esitlicez.bir de en buyugun oldugu max dugumum olsun diyorum.
 	//art�k her �ey linked list'te oldugu i�in nap�caz tekrar dosyaya gitmicez.
	NOKTA *tmp=head,*max;
	//bir distance i�in soyle bir �ey tutal�m.
 	int d=0;
 	while(tmp!=NULL){
 		//bulundugumuz dugumun oncelikle distance'sini hesapl�yal�m.
 		d=pow(tmp->x,2)+pow(tmp->y,2);
 		if(d>*dmax){
 			*dmax=d;
 			//max�mum dugumum de tmp olsun.
 			max=tmp;
		 }
		 //yukar�daki i�lemden sonra bir sonraki dugume gecelim.
		 tmp=tmp->next;
	 }
	 //bu i�lemler bittiginde return edicegim sey max�mum dugumun bulundugu hangi dugumse onun pointer'�n� return ediyorum.
	 //dmax degeriyle de parametre olarak degeri degistirip bir call by reference mant�g�yla bu i�i yap�yoruz.
	 return max;
 }
 //ikinci bir method yazal�m bu sefer buldugumuz en uzak nokta.
 //biz parametre olarak buraya sadece head almak istiyoruz.
 //oncelikle dondurecegimiz sey enUzaknokta turunden bir �ey olucak.
 ENUZAKNOKTA *enUzakNoktaBulv2(NOKTA *head){
 	//NOKTA turunde bir pointer'�m�z var.
 	//buna tmp dedik head'i atad�k.bi tane de max bu max'� sunun i�inde sakl�caz.bunu sakl�yabilmem i�in burdan return edicegim seyin.
 	//surekl� yasamas� laz�m.scop kurallar�ndan ve duration kurallar�ndan hat�rl�yal�m.
 	//surekl� yasamas� i�in napmam laz�m.
 	//2 �ey yapabilirim.
 	//bunlardan bir tanesi malloc gibi bir �ey kullan�cam ne i�in en uzak nokta i�in.
 	//bir digeri ne olabilir.bir digeri de 
 	//bellekte soyle bir duzen var :bilgisayar�n�z�n program�n�z�n i�in  ay�rd�g� bellekte bi yerde program memory saklan�yor.program�n�z�n hangi programsa ilgili kodlar�n�n bulundugu sey ,bi yerde static ve global variables bir yerde initialized variable,bir yerde stack,bir yerde de heap bolgesi var.biliyorum ki stack bolgesi k�s�tl� limitli ve bir methodda bir degisken tan�mlarsam integer gibi karakter gibi.bu tan�mlad�g�m sey stack bolgesinde tan�mlan�r eger dynam�c memory kullanmad�ysam.o method veya fonksiyon tamamlan�nca o degiskene ulasamama olas�l�g�m cok yuksek yani tekrar onun yerine baska bir yer tahsis edilir.dolay�s�yla heap bolgesinden yer tahsis edebilirim.nap�yoduk program kald�g� muddetce bu i� yap�labiliyordu.heap bolgesinden yer almak i�in de dinam�c memory alloccasyonu fonksiyonlar�n� kullanmam gerekiyordu.veya static gloabal variables dedigimiz static ile bu i�i yapabiliriz.static de nap�yor bir degiskeni bir defa olusturuyor program kapanana kadar sakl�yabiliyoruz.
 	//tabi biz burda static kullanm�caz.i�te bu i�in 2 farkl� yolu var burda dynam�c memory allocation ile bu i�i yapal�m.
 	
 	NOKTA *tmp=head,*max;
 	
 	
 	//enuzaknokta isminde bir pointer olusturuyorum.ptr e�ittir en uzak nokta t�r�nde pointerima soyle bir.1 eleamnl� bir �ey olucak bu niye bi tane eleman cunku en uzak nokta bir tane gidicez bir tane elemanl�k yer ac�caz ve bunun pointer'� stack bolgesinde saklancak tabi ama e�itli�in sag�ndaki k�s�m heap bolgesinde var edilen bir bellek hucresinin adresi ben bunu ptr ile burda sakl�yorum ne zaman bunu return edersem.ptr'yi return edicem isin sonunda.bunu return ettigim yer neresi ise neresi olursa olsun gidicek orda saklan�cak ptr'n�n kendisi e�itli�in sol taraf� stack bolgesindedir ama e�itli�in sag�ndaknden gelen deger heap bolgesindedir.dolay�s�yla ptr'n�n fonksiyon bitince bir hukmu kalm�yor.sadece dondurdugu pointer adresi her zaman yasayabilen bir adres
 	ENUZAKNOKTA *ptr=(ENUZAKNOKTA*)malloc(sizeof(ENUZAKNOKTA*));
 	//yine d=0 diye bir �ey saklayal�m
 	int d=0;
 	//bi tane de gecici bir degisken hangisi en buyuktur diye bir dmax d�yem.gecici degiskeni ben kars�last�rma yaparken kullan�cam.
 	int dmax=0;
 	//tmp null dan farkl� iken 
 	while(tmp!=NULL){
 		d=pow(tmp->x,2)+pow(tmp->y,2);
 		if(d>dmax){
 			dmax=d;
 			max=tmp;
		 }
		 //bir sonraki dugume gitmek i�in yapt�k
		 tmp=tmp->next;
		 //bu dongu tamamland�g�nda el�mde en fazla uzakl�ga sah�p dugumun adres bilgisi ve tabi ne var max uzerinde adres bilgisi d uzerinde de deger bilgisi var.o zaman diyoruz ki.
		 
	 }
	 //o zaman diyoruz ki ptr'nin d'sine dmax'� yaz�caz
	 ptr->d =dmax;
	 //ptr i�indeki pt'yede max isimli dugumumuzu al�caz 
	 ptr->pt=max;
	 
 	//daha sonra ben bu ptr'yi return edicem 
 	return ptr;
 }  
   
   
   48.39
