#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

NODE *head=NULL;//yine mant�g�m�z ayn� head global bir degisken bunu daha sonra degistircez.

NODE *create_node();
void insert_at_begin(int d);
void insert_at_end(int d);
void traverse();
void delete_from_begin();
void delete_from_end();
int main(){
	int data;
	
	int i=0;
	
	while(i!=6){
		
		printf("Enter choice\n1-Insert begin\n2-Insert end\n 3 -traverse\n");
		printf("4-Delete begin\n5-Delete end\n 6-Exit");
		scanf("%d",&i);
		
		if(i==1){
			printf("Enter data");
			scanf("%d",&data);
			insert_at_begin(data);
		}
		else if(i==2){
			printf("Enter data");
			scanf("%d",&data);
			insert_at_end(data);
		}
		else if(i==3){
			traverse();
		}
		else if(i==4){
			delete_from_begin();
		}
		else if(i==5){
			delete_from_end();
		}
	}
	head=NULL;
	free(head);
	
	
}

void delete_from_begin(){
//Bastan bir eleman� silmek ne demek:
//head bir eleman� i�aret ediyor ve ben bu head'in g�sterdigi eleman� silicegim demektir.
//head'in g�sterdigi eleman� silerken once suna bak�cam head acaba bir yeri g�steriyor mu yani null mu degil mi ona bakar�m.
//eger null degilse o zaman da su durum ortaya ��kar.
//listenin 2. veya 3.elemanlar� olabilir demek olur.
//ben linked list'i gezmek i�in node t�r�nde temprorary degisken olusturuyorum.
	
	NODE *tmp;//�imdilik bu bos duracak.
	
	int n;//hangi eleman� sildigimi g�stermek i�in bir tane degisken tutal�m,yani su deger silindi gibisinden.
	
	if(head==NULL){//eger head dugumumuz e�it null ise linked listimiz bostur.
		printf("list is empty");
		return;//void de return kullan�lmaz degil voidte bir degisken return edilmez.
		//void pointer olursa return edilir ona sonraki konularda gelicez.
	}
	n=head->data;//head'in g�sterdi�i yerdeki datay� al dersem bu bana data'y� vericektir.
	
	tmp=head->next;//burda tmp degiskenine head'in next'ini at�yorum head'in nexti ne demek yani head hangi dugumu gosteriyor bu gosterdigi dugumu al�yorum yani ve bu dugumu tmp ye at�yorum.
	
	
	free(head);//bu fonksiyonda yapt�g�m�z i� bastan bir eleman silmek.en bastaki dugumumuze de head diyoruz.head'in g�sterdi�i yerdeki d���m� serbest b�rak�yoruz.
	//head'in g�sterdi�i yerin next'ini tutuyoruz bi yerde ama.
	
	head=tmp;//ilk basta head'in gosterdi�i ikinci dugumumuz art�k bizim head'imiz oldu.head'imizi guncelledil burda.
	
	printf("%d was deleted",n);//silinen eleman� boyle g�steriyoruz.silinen eleman da n 'dir.
	
}

void delete_from_end(){
	//listede sondan silerken �una dikkat etmemiz gerekir.
	//listede son eleman� silerken mesela sondan bir �nceki eleman�n son eleman olarak i�aretlenmesi i�in
	//head'den itibaren arama yaparken bir yedek degisken kullan�cam.bu yedek degisken s�rekli bir �nceki,
	//yani birisi bir sonrakine giderken birisi bir �nceki d���m� tutacak ta ki next null'u g�rene kadar null'u g�rd� m�
	//bu arama i�lemi de bitecek.ben de 2 tane pointer olucak birisi arama yapt�g�m pointer birisi de bir �ncekinin pointer'� olucak 
	//��nk� bu diziler tek y�nl� tek y�nl� dizi oldugu i�in b�yle bir �eye ihtiyac�m var.arama bitti�i zaman son eleman� free edicez 
	//ve sondan bir �nceki eleman�m ise null'u g�stericek ve bu i�lemi tamaml�ycaz.
	//bir de silme i�lemini sondan yaparken suna dikkat edicez bir tane eleman�m�z varsa o da head'imizdir.
	//��nk� listede bir eleman varsa 
	//burda yine node t�r�nde 2 tane de�i�kene ihtiyac�m�z var.
	//yani sondan eleman silerken 2 tane �eye dikkat edicez birisi head'imiz null mu ikincisi headimizin gosterdigi dugum null mu.
	
	NODE *tmp,*u;
	
	int n;//hangi eleman� sildigimizi g�stermek i�in yine n degiskenini kullan�yoruz.
	
	if(head==NULL){
		printf("List is empty");
		return;
	}
	if(head->next==NULL){//head'in next'inin null olmas� durumu var
		n=head->data;//n'in hangi datay� saklad�g�n� alal�m.
		free(head);
		head=NULL;
		printf("%d was deleted",n);
		return;
	}
	//eger yukar�daki de degilse birden fazla eleman varsa yani d�ng�yle arama yap�caz.
	tmp=head;//head'i kaybetmemek i�in boyle bir �ey yapt�k.
	while(tmp->next!=NULL){
		u=tmp;
		tmp=tmp->next;//tmp'yi g�ncelledik.
		
	}
	n=tmp->data;//hangi veriyi sildigimiz g�rmek ad�na
	u->next=NULL;
	free(tmp);//ilgili d���m� bellekten temizlemek i�in bunu dicez.
	printf("%d was deleted",n);
	
}
void insert_at_begin(int d){
	NODE *tmp=create_node();
	//tmp->data=d;
	
	if(head==NULL){
		head=tmp;
		head->next=NULL;
		head->data=d;//instead of //tmp->data=d;
	}
	else{
		tmp->next=head;
		head=tmp;
		head->data=d;//inplage of//tmp->data=d;
	}
	
}
