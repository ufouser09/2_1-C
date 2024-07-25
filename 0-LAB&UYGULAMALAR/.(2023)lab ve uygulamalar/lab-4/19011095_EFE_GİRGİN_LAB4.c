#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
	int Id[4];
	int kod[4];
	char name[20];
	char type[20];
	char day[10];
	struct order *next;
}ORDER;
void printOrders(char name,ORDER *head);
ORDER *createOrder(ORDER *head);
void Sirala(ORDER *tmp,ORDER *head);
int main(){
	ORDER *head=NULL;
	ORDER ord;
	ORDER *tmp;
	FILE *fp;

	

	tmp=createOrder(head);
	Sirala(tmp,head);
	printOrders(ord.name,head);
	
}
ORDER *createOrder(ORDER *head){
	FILE *fp;
	char name;
	ORDER *ord;
	char dosya[20];
	printf("lutfen dosyanin ismini giriniz\n");
	scanf("%s",name);
	strcpy(dosya,name);
	fp=fopen(dosya,"wb");

	
    
		while(!(feof(fp))){
			 ord = (ORDER *)malloc(sizeof(ORDER));
    if (ord == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;

		}
		printf("lutfen bilgileri giriniz\n");
		fscanf(stdin,"%s %s %s %d %d",ord->day,ord->name,ord->type,ord->kod,ord->Id);
		fwrite(&ord,sizeof(ORDER),1,fp);
	}
	fclose(fp);
	return ord;
	
    
}
void Sirala(ORDER *tmp,ORDER *head){
	ORDER *tmp2=head;
	ORDER *prev=NULL;
	while(tmp2!=NULL){
		if(tmp->kod<tmp2->kod)
		{
			if(prev==NULL){
				tmp->next=head;
				head=tmp;
			}
			else{
				prev->next=tmp;
				tmp->next=tmp2;
			}
		}else{

		
		tmp2=tmp2->next;
		prev=tmp2;
		}
	}
}
void printOrders(char name,ORDER *head){
	ORDER *tmp;
	FILE *fp;
	fp=fopen(name,"r");

	while(tmp!=NULL && !feof(fp)){
		fread(&tmp,sizeof(ORDER),1,fp);
	}
	fclose(fp);

}
