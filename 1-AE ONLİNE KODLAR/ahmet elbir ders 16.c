/* 
uygulama-3
bir hastanenin acil servisinde kullan�lmak �zere bir kuyruk haz�rlanacakt�r.
kuyruk hastalar�n s�ralar�n� takip edebilmesi i�in kullan�lacakt�r.

hastalar hastaneye kay�t yapt�rmak i�in isim,soy isim,TC kimlik numaras� ve ya� bilgilerini payla�mal�d�r.

hastanelerde vakalar acil vaka olarak incelenmektedir.
bu dogrultuda asag�daki ilkeleri gercekleyen kuyruk modelini olusturun.

1-yeni bir hasta geldiginde eger acil bir vaka degilse dogrudan kuyruga eklenmelidir.
asag�daki ornekte ilk olarak 1'inci hasta gelir ard�ndan 2,3,4 ve 5'inci hastalar gelir.

1...2...3...4...5

2-oncelikli bir hasta geldiginde ise listedeki son oncelikli hastadan sonraki s�raya yerlest�r�lmelidir.
listede hi� �ncelikli hasta olmad�g�nda eklenecek oncelikli hasta listenin bas�na eklenir.6'�nc� hasta onceliklidir ve listenin bas�na eklenmistir.

6...1...2...3...4...5

ard�ndan yeni bir oncelikli vaka geldiginde kuyruk asag�daki gibi olmal�d�r.

6...7...1...2...3...4...5

3-hastalar doktora gorunmekten vazgect�kler�nde kuyruktan c�kar�lmal�d�r.
3'uncu hasta,hasta ismi kullan�larak kuyruktan c�kar�lm�st�r.

6...7...1...2...4...5

4-kuyrukta bulunan hastalar�n bilgileri dosyada tutulmal�d�r.

5-istenildiginde kuyrukta bekleyenlerin bilgileri dosyadan okunmal�d�r.

*/
//-----bu dosyan�n ad� uygulama.c main kodumuz burda yaz�l�yor.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_patient.h"
#include "file_opr.c"

#define MAX_SIZE 20
#define WARNING "malloc failed!"




Patient_Node* create_new_patient();
void insert_patient_to_list(Patient_Node *new_node,Patient_Node **head);
void delete_patient(char *name,Patient_Node **head);

//yeni hasta olusturma fonksiyonunda da �ncelikle yeni bir node olusturuyoruz.
Patient_Node* create_new_patient(){
	Patient_Node *new_node;
	
//-----allocation memory for new patient
	new_node=(Patient_Node*)malloc(sizeof(Patient_Node));
	
	if(new_node==NULL){
		printf(WARNING);
		exit(1);
	}
	//kullan�c�dan verileri al�yoruz.
	//getting inputs from user
	printf("\nPlease enter patient informations...\n");
	printf("Name  :");
	scanf("%s",new_node->data.name);
	printf("surname:");
	scanf("%s",new_node->data.surname);
	printf("ID   :");
	scanf("%s",new_node->data.ID);
	printf("Age   :");
	scanf("%d",&new_node->data.age);
//-----asag�daki printf'de patient'�n �nceli�i varsa 1 degerini al�r eger onceli�i yoksa 0 degerini al�r diyor.
	printf("if patient has a priorty enter 1 otherwise enter 0 for prior..\n");
	printf("prior :");
	scanf("%d",&new_node->data.prior);
	new_node->next=NULL;
//-----ve sonra yeni bir node olusturuyoruz.bu olusturdugumuz node insert_patient_to_list fonksiyonuna bi parametre olarak gidiyor yani
	return new_node;
	
} 
//this function is used for inserting new patient to list.
//-----eklemek istedigim zaman buraya geliyorum.yeni bir hasta eklemek istedigim zaman bu fonksiyonu kullan�yorum.

//-----�imdi new_node ve head parametremizi kullanarak �imdi bir ekleme yap�caz.
void insert_patient_to_list(Patient_Node *new_node,Patient_Node **head){
//-----if head equals to NULL,new patient will be the head of list.
//-----�imdi bizim listemizde su anda bosken hi�bir head'imiz yok link list'in bas�n� ifade eden bir node'umuz yok.o zaman ben ne eklersem ekliyim bu benim listemin bas� olucak.o yuzden head ifadem yani listenin bas�n� ifade eden degiskenim eger NULL ise direk priority'si var m� yok mu kontrol etmeden direk o hastay� listenin bas� olarak esitliyorum.ve ekleme fonksiyonumdan geri donuyorum.
//-----bu arada en basta node'umuzun head'ini olusturuyoruz yukar�da ve bu head'i global bir degisken olarak degilde fonksiyonlar�m�za parametre olarak g�nderiyoruz.mesela yukar�da patient_node'un head pointer'�n� olusturmusuz.ekleme fonksiyonumuzda adresiyle g�nderiyoruz case 1'de.parametre olarak da case1'de create_new_patient()fonksiyonunu al�yor.
	
//-----liste tamamen bossa eklememizi asag�daki gibi yapt�k.
		if((*head)==NULL){
			(*head)=new_node;
			return;
		}
//-----liste tamamen bos degilse yani bir head'imiz varsa nas�l ilerlicez
		Patient_Node *var_head=(*head);
		Patient_Node *last_prior=(*head);
		Patient_Node *temp;
		
//-----check the new patient priorty,has it high priorty.
//-----sonra kotrol ediyoruz bu yeni hastan�n prioritisini eger prioritisini 0 dan farkl� derse zaten prioritimiz i�in �ncelik yoksa 0 onceligi varsa da 1 degerini al�r.eger hasta olustururken patient'�n �nceligi var ise 1 degeri giricez.onceligi yok ise 0 degeri giricez.kullan�c�dan daha veriyi alirken.
//-----ondan sonra burda kontrol ediyoruz eger hastan�n priritisi var ise
		if(new_node->data.prior !=0){
			
//-----buraya geliyoruz ne diyor.yani bastan kontrol edicez listenin bas�nda prioritisi olan bir hasta var m� varsa o benim ilk last_prioriti diye bir degiskenim var ya ona esit olucak eger ondan sonraki node da prioritisi 1 ise bu sefer last_prior'imi ikinciye esitlicem yani 1.indextte bulunan hastaya i�aretlemi� olucam.bir sonrakininde prioritisi yuksek ise bu sefer 3.eleman benim prioritisi yuksek olan hastam olucak yani last priorim olucak ��nk� onun ard�na ekleme yap�cam ya o yuzden listedeki en uctak� .bu i�lemde bunu yap�yorum.
//-----detect the last patient with high priorty.
//-----priority i�in �nceli�i yoksa 0 onceli�i varsa da 1 degerini al�cak.
			while(var_head != NULL){
				if(var_head->data.prior !=0){
					last_prior=var_head;
				}
					var_head=var_head->next;
				
				
			}
			
			
			
			
			
			//yukar�daki i�lemi yapt�ktan sonra �ncelikle sunu yap�yoruz.bakal�m hala head yani listenin bas�ndaki ifade last prior mu yoksa degisti mi bu diye bunu kontrol ediyoruz.eger last_prior hala listenin bas�ndaki ifadeye esitse o zaman sunu kontrol ediyorum 
			//we set the initial last prior as head node.
			//check is the last prior still head of the still.
			if(last_prior==(*head)){
				
				
				//if head of least has not high priorty,new patient will be head of list.
				//listenin bas�ndaki eleman�n prioritisi var m� yok mu cunku biz initial olarka biz last_prior'u yukar�da head olarak i�aretledik.yani listede hi� prioritisi olan hasta yoksa bu hala head olarak kalm�s olucak listede e �yle olunca da eklememizi biz head'in sonras�na yap�cak �ekilde ayarlam�st�k.yani last prioritinin bi sonrasina ekleme yap�caz.ve last prior head'e esitse ve head'in prioritisi yoksa o zaman orda bir kar�s�kl�k olucak.yani bir tane onceliksiz hasta sonra �ncelikli hasta sonra �nceliksiz hasta diye devam edicek sekilde bir s�k�nt� yas�yabiliriz.bunu kontrol alt�na almak i�in de bunu kontrol ediyoruz.last prior hala head'e esit mi eger head'e esitse nap�caz oncelikli hastay� ben yeni head yap�caz ama eger head'e esit degilse last_prior o zaman elde etti�im last_prior'un bir sonrakine ekleme yap�caz.
			if((*head)->data.prior==0){
				//head'in degerini bir temprorary degiskende tutuyoruz.
				temp=(*head);
				//sonra yeni head'imiz new_node oluyor.yani yeni hastam�z �ncelikli olan hastam�z sonra yeni nodun bi sonra i�aret etti�i node da temproray de tuttugumuz eski listenin bas� olucak.eger tam tersi ise yani head'e esit degilse o zaman bir sonraki i�aret etti�i veriye yeni hastay� ekliycez. 
				(*head)=new_node;
				new_node->next=temp;
			}
			else{
				//else,new patient will be added after the last prior.
				//last prior'�n i�aret etti�i bir sonraki ifadeyi temp te tutuyorum sonra last_prior'�n bi sonra i�aret etti�i yere yeni hastam� ekliyorum sonra yeni hastan�n i�aret etti�i yere de bir onceki temp te tuttugum degeri eklemis oluyorum.
				temp=last_prior->next;
				last_prior->next=new_node;
				new_node->next=temp;
			}	
			
			}
			else{
				//burda da else durumu bu neyin else'i
				//e�it degilse yine burda da ekleme yap�caz
				//else,new patient will be added after the last prior.
				temp=last_prior->next;
				last_prior->next=new_node;
				new_node->next=temp;
			}
		}
		//bu hasta prioritisi olmayan bir hasta ise o zaman nap�caz direk listenin son eleman�n� bulucaz.asag�daki while sayesinde   
		else{
			while(var_head->next!=NULL){
				var_head=var_head->next;
			}
			var_head->next=new_node;
		}

	
}
//hastalar� isimleri ile birlikte silicez.asl�nda tc numaralar�yla silmek daha iyi olurdu �unku birden fazla ahmet olabilir.
//parametre olarak hem ismi al�yo hem de listenin bas�n� al�cak haliyle �unku listede arama yap�caz ismini buldugumuz hastay� silicez listeden.
void delete_patient(char *name,patient_Node **head){
	//su anda patient'in tuttugu veri null var_head'de bizim listemizin bas�n� isaret ediyor.
	//var_head null olana kadar biz listede arama yap�yoruz.
	//strcmp komutu eger 0 donerse iki stringin birbirine esit oldugunu ifade ediyor.
	//var head'in ismiyle var head'in i�aret ettigi data'n�n ismini ve bizim kullan�c�dan ald�g�m�z ismi compare ediyoruz.eger bu deger 0'a esitse fonksiyonun return'u bu hastay� bulduk demektir.sonra patient'i var_head'e e�itliyoruz.��nk� buldugumuz hastan�n bilgileri hepsi burda tutulmus.
	//sonra bu dongu bittigi zaman patient art�k arama yapt�g�m�z isimdeki hastan�n bilgilerini tutuyor.o zmaan nap�caz sunu kontrol ediyoruz.buldugumuz hasta listenin bas�ndaki hasta m� degil mi ona bak�yoruz.eger bas�ndaki hasta ise yeni head'imiz head'in bi sonra i�aret etti�i hasta olucak ama eger bas degil ise
	Patient_Node *patient=NULL,*var_head;
	var_head=(*head);
	while(var_head !=NULL){
		//if patient's name and entered name is equal,variable patient keeps patient that will delete.
		if(strcmp(var_head->data.name,name)==0)//0 means,two string is equal.
		patient = var_head;
		
		var_head=var_head->next;
	}
	//if patient is the head of list,new head will be the head->next.
	if(patient ==(*head)){
		(*head)=(*head)->next;//art�k head dedigimiz yer onceden headin gosterdigi yer
		
	}
	else{
		//patient'�n null olup olmad�g�n� kontrol ediyoruz ��nk� hi� listede olmayan bir eleman da olabilir. eger oyleyse zaten listede bulunamad� diye print ediyoruz ve donuyoruz.eger boyle bir durum yoksa listede buluyoruz bu degiskeni ve hastay� nap�yoruz o node'u aradan c�kart�yoruz yani var_head'in next'i o hastan�n nextinin nextine i�aret ediyor
		//if patient is NULL,there is no patient in list with entered name.
		if(patient==NULL){
			printf("\nCould not find the element with %s",name);
			return;
		}
		var_head=(*head);
		//finding patient in list.
		while(var_head->next !=patient){
			var_head=var_head->next;
		}
		//yani burda tekrar arama yapmam�z�n� sebebi su patient'tan onceki asl�nda  bizim buldugumuz patient'� b�r onceki node'a set ediyoruz.var_head'in next'i patient olana kadar bu dongu cal�sacak oldugu anda burdan c�kacak yani bu asl�nda wihle ' girmeyip silmek istedigim nodun bir onceki nodu asl�nda yani dolay�s�yla var_head'in i�aret ettigi bi sonraki i�aret ettirmek istedigim verinin yerine i�aret ettigi nodun bi sonra isaret etti�ini alm�s olucam(31.29) 
		//when we delete the patient,previous node's next node will be the patient's next node.
		var_head->next=var_head->next->next;
		free(patient);
	}
}

//-----oncelikle main'de biz nap�caz kac tane i�lemimiz var.
//-----kullan�c� girebilicez.ya da hasta ekliycez kuyruga,
//-----ondan sonra ismiyle bu hastay� silebilicez.
//-----sonra ben her istedigimde dosyadan bu listeyi print edebilicem.
//-----3 tane ana i�lemimiz var.ekleme yapma ��karma yapma ve 
//-----g�r�nt�leme bunlar i�in bir dongu olusturmusuz.
//-----her seferinde kullan�c�dan eklemek istiyorsa 1-silmek istiyorsa
//----- 2-print etmek istiyosa da 3 verisini alarak okuyarak secimlerimizi bu sefer switch case yap�s� ile degerlendiriyoruz.
int main(){
	char name[MAX_SIZE];
	int choose=1;
	
//-----head node specify the head of list.
	Patient Node *head=NULL;
	
	while(choose>0){
		printf("\nFor entering new patient press 1..\n");
		printf("For deleting patient with name press 2..\n");
		printf("For reading list from the file press 3..\n");
		printf("For exit press 0..\n");
		printf("\nPlease enter your choice:");
		scanf("%d",&choose);
		case 1:
//-----eklemek istedigim zaman ben asag�daki fonksiyonu �al�st�r�yormusum.
			insert_patient_to_list(create_new_patient(),&head);
			printListWithAllInformations(&head);
			break;
			
			case 2:
				printf("\nEnter patient name that want to delete:");
				scanf("%s",name);
				delete_patient(name,&head);
				printListWithAllInformations(&head);
				break;
				
				
					case 3:
						read_file();
						break;
	}
}
return 0;
//31.29
