/*
bir kutuphanedeki 11 rafl� bir kitapl��a cesitli kitaplar yerlestirilecektir.
raflara hangi kitaplar�n yerlest�r�lecegine,isimlerine gore hesaplanan birer unique kodla karar verilmektedir.

N harf uzunlugundaki bir kitap ismi i�in kod su sekilde hesaplanmaktad�r.

kod-(asc��kodu(Kitap_ismi[0])(asc��kodu(Kitap_ismi[1])....asc��kodu(Kitap_ismi[i])..asc��kodu(Kitap_ismi[n])

raf_no-kod mod raf say�s�

kitap,koda denk gelen rafa yerle�tirilecektir.

�rnegin o�uz atay�"tutunamayanlar" kitab�:

RAF_No(tutunamayanlar)=84+117+116+117+110+97+109+97+121+97+114=(1494)
MOD 11=9.rafa yerle�tirilecektir.

-ismi verilen kitab�n raf numaras�n� belirleyerek listeye ekleyen

-kitapl��a eklenen t�m kitaplar�n raf bilgilerini listeleyen 

-ismi verilen bir kitab� kitapl�kta aray�p bulunursa raf numaras�n� g�steren,bulunmasa k�sa bir mesaj g�steren

bir algoritmay� C dilinde gercekleyiniz.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHELF 11//shelf raf demek 

#define MAXSIZE 20//maxS�ze kitab�n isim uzunlugu olabiliyor

//bu yap�(struct) link list'dir ��nk� kendisinden sonra gelicek olan eleman� i�aret edicek pointer� da bar�nd�r�yor.
struct node{
	char name[MAXSIZE]; //kitap ismi
	int code;			//kod
	int index;			//raf no
	struct node *next;
};

typedef struct node List;


void insert(List **headRef,char bookName[]);//�nsert fonksiyonunda neden double point kullan�yorum ?
//Eger bi degisiklik kal�c� bir i�lem yap�caksam o zaman double point kullanmam gerekiyor.
//Double point olmazsa geri donuse gerek kalmaz.yani fonksiyonumuz void olabilir art�k.


void search(List *head);
void display(List *head);
int findKey(char *s);


int main(){
	int opt;
	List *head=NULL;
	char bookName[MAXSIZE];
	
	while(1){
		printf("\nPress 1.Insert\t 2.Display \t3.Search\t4.Exit \n");
		scanf("%d",&opt);
		
		switch(opt){
			case 1:
				printf("\nEnter Book Name\n");
				scanf("%s",&bookName);//biz mesela seker portakal� yazsayd�k burda sadece seker kelimesini al�rd� 
				//bu y�zden scanf'i formatlamam�z gerekiyor.gets ya da fscanf()fonksiyonlar� gibi;
				
				insert(&head,bookName);
				break;
				
				case 2:
				display(head);
				break;
				
				case 3:
				search(head);
				break;	
				
				case 4:
				exit(0);
					
				default:
				exit(1);
		}
	}
	return 0;
	
}

int findKey(char *s){//�imdi stringimizi buraya g�nderdik.

	//eger string�m bos ise 0 don,degilse birinci karakterini al yani s'i al sonra s+1 den devam et
	return *s == 0 ? 0 : *s + findKey(s+1);//if(s==0)(return 0;)else(return *s+findKey(s+1);)
}


//Bu kitapl�g�m�za kitap eklemek i�in.
//kitab�n bilgilerini kullan�c�dan ald�ktan sonra i�ine yazabilmemiz i�in yeni bir node olusturduk.
//bu node link list struct�na ait bir node.
void insert(List **headRef,char bookName[]){
	
	List *newnode =(List*)malloc(sizeof(List));//yeni bir node olusturacag�m�z i�in dinamik bellek allacotainonu yapt�k.
	//ondan sonra yeni node'un i�ini gerekli bilgilerle dolduruyoruz.
	//burda null m� diye bir control yapabilirdik.
	
	int i,key;//burda i'miz bizim index'imiz key ise bizim kodumuzu olusturur.
	
	key=findKey(bookName);//burda kodu elde ediyoruz.//burda kitap ismini ald�k mesela burdan bir key elde ettik key dedigimiz kitab�n kitap ismindeki harflerin asc�� kodlar�n�n toplam� yani  
	
	//ondan sonra i diye bir index elde ediyoruz bu da az once buldugumuz key'in shelf'e gore modunu ald�g�m�z zaman ortaya c�k�yor.bu index bu kitab� bizim hangi rafa koyucag�m�z� soylicek.o yuzden index'e i'yi yazd�k.data m�za da key'i yazd�k.sonra kitap ismini nodu'muzun i�indeki bookname'e kaydettik.
	i=key%SHELF;//raf sayimiza boldugumuzde ise indeximizi bulmus oluyoruz.
	
	newnode->code=key;//bu k�s�mlarda esitleme yapt�k.
	newnode->index=i;
	strcpy(newnode->name,bookName);//stringlerde direk esitleme yapam�yorduk.
	
	//sonra geldik newnode'un nextine �unku bi tane de next laz�md�,o ana kadar ki listenin birinci en bastaki eleman�n� newnode'un nextine koyuyoruz.bu ne demek oluyor.art�k new node en bastakinden basla demek oluyor bu yani en basa ekledik listede biz bunu ondan sonra new node'u getirip yeniden listemizin adresine yazd�g�m�z zaman art�k su newnode arkas�ndan gelen sonraki listenin gerisi ilk satirdaki (*headRef) bu oluyor arkas�ndan gelen listenin gerisi ile birlikte en basa eklenm�s newNode ile birlikte yeni bir liste olusuyor.yani new node 'u getirdik listenin en bas�na yazd�k 
	//case 1: de insert i�inde &head yap�yoruz burda neden adresini g�nderiyoruz listenin ��nk� listenin �zerinde mesela soyle dusunebilirsiniz mesela bir integer'� gonderdigimiz bir fonksiyonun i�inde degistirmek istiyoruz ve bu degisikligin kal�c� olmas�n�n istiyoruz o zaman napar�z o integer'�n adresini g�ndeririz demi.misal scanf.ayn� sekilde �nserte de head'�n adresini g�nderiyoruz.head'�m�z ne surda tan�mlad�g�m�z bir linkli liste.structta tan�mlad�g�m�z bir node d�ye dusunebilirsiniz.biz bunun i�inde bir degisiklik yapmak istiyorsak onun adresini g�ndericez.insert c�ft pointer'� bu y�zden al�yor.linkli listenin birinci eleman� nedir.ilk eleman�n oldugu yerin adresidir.
	//bizim bir menumuz var �imdi insert yapmak istedigimizde yukar�da tan�mlad�g�m�z ve en bas�nda null atad�g�m�z yani i�inin bos oldugunu soyledigimiz.listeyi gonderdik.liste bookName den olusan bilgilerle dolduruldu ve bize her seferinde bir tanecik data i�ine koydugumuz listemiz geri donuyor.
	newnode->next=(*headRef);//newnodun headin g�sterdigi nodu gostermesini sagl�yoruz.
	
	(*headRef) = newnode;//sonrada newnodu head'e esitliyoruz.yani art�k head'�m�z new node olmus oluyor.ve en basa head'i eklemis oluyorum.
}

//Peki search de nap�yoruz:bir tane kitab�n ad�n� soylicez.
//O da varsa hangi raftta oldugunu soylicek.yoksa da yok dicek.
//Bunu nas�l yap�yoruz burda g�rd�g�n�z gibi listemizi sadece okuycaz.
//Yani onun i�inde herhangi bir degisiklik yapm�caz bu search fonksiyonu bitip bize geri dondugunde 
//Bu head'de bir degisiklik olm�cak biz sadece i�ine bakmak istiyoruz.
//O yuzden adresini g�ndermemize gerek yok.

void search(List *head){
	List *tempNode;//listeyi taramam gerekiyor bunun i�in gecici bir degisken tan�mlad�k.
	char bookName[MAXSIZE];//kullan�c�dan bir kitap ismi isticegim i�in tekrar bir bookname dedik.
	
	//kullan�c�dan hangi kitab� aramak istedigini soruyoruz.onun key'ini de ayn� yukar�daki gibi olusturuyoruz.
	printf("\n Enter A Book Name to Search on Bookshelf\n");
	scanf("%s",&bookName);
	
	if(head==NULL){
		//burda ben liste bos olup olmad�g�n� kontrol ediyorum.liste eger bos ise benim herhangi bir eleman aramama gerek yok.
		printf("\n Book could not be Found");
	}
	
	else{
		//ilk once temp node' a bir head'i att�k listemiz art�k temp node'un i�inde diye dusunun listenin i�inde gezicez ondan sonra eger tempNode null degilse null olmad�g� muddetce ama ayn� zamanda tempNode'un datas� da bizim burda buldugumuz key'e esit olmad�g� surece link listteki bir sonraki elemana geciyoruz yani next'ine geciyoruz.bu while'� ne zaman k�rabiliriz.ya tempNode dedigimiz sey next yapt�k next yapt�k art�k null oldu yani listemiz bitti ya bunda ��kar ya da tempNode'un datas� key'e esitse ��kar bu while'dan peki neden c�kt�g�m�z� hemen asag�da kkontrol etmemiz gerekiyor.biz bu while dan c�kt�k da neden c�kt�k.eger data key'e esit oldugu i�in c�kt�ysak ne demektir bu kitab�m�z orda bi yerde biz onu bulduk demektir.peki liste bittiyse de ��kt�ysak nedir  bu ne demektir liste bitti ama kitab� bulamad�k demektir.yani bu durumda liste tamamen bossa ya da listenin sonuna kadar geldiysek kitab�n bizim hesaplad�g�m�z datayla burdaki data key birbirine esitse bu durumda nap�yoruz bu tempNode'un index'inin bulundugu raftad�r diyoruz 
		tempNode=head;//head'i tempnode'a esitliyorum neden cunku en basta listeyi gezicem.
		while(tempNode!=NULL && strcmp(tempNode->name,bookName)!=0)
			//temp nodu s�rekli artt�r�yorum.
			tempNode=tempNode->next;
		
		
		if(strcmp(tempNode->name,bookName)==0)
			//kitab� buldum ve hangi rafta buldugumu yazd�rabilirim.
			printf("Book is on the %dth shelf\n",tempNode->index);
			
			
		
		if(tempNode==NULL)
			printf("\n Book is not in the Bookshelf\n");
		
	}
}
//display i�in de yine ayn� �ekilde burda da yine while dongusu yap�yoruz 
//Nodun i�inde ilerliyerek node'lar� yazd�r�yoruz.
void display(List *node){
	while(node!=NULL){
		printf("%s(%d)->%d\n",node->name,node->code,node->index);
		node =node->next;
	}
}
//34.00
21.07
