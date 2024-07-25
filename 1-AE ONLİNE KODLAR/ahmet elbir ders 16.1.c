//-----bu dosyan�n ad� file_opr.c'dir.
//-----burda dosyadan okuma ve yazma i�lemleri yap�caz.
#include <stdio.h>

//this function is used for printing to the file
//gonderdigimiz hasta bilgilerini al�cak 
void printListWithAllInformations(Patient_Node **head){
	FILE *fs=fopen("list.txt","wb");
	if(fs==NULL){
		printf("File cannot be opened\n");
		exit(0);
	}
	Patient_Node *var_head=(*head);
//-----dosya yazd�rma yaparkende yine ayn� �ekilde fwrite fonksiyonumuz ile
//-----yazd�rcag�n�z nesnenin boyutu,kac tane yazd�r�yoruz,
//-----gene stream nesnemiz var.bu sekilde yazd�rma i�lemi yap�yoruz.
	while(var_head != NULL){
		//bu fonksiyonu kullanarak dosyaya yazma yap�cak 
		fwrite(&(var_head->data),sizeof(Patient),1,fs);
		var_head=var_head->next;
	}
	fclose(fs);
	printf("\nFile is update\n");
}
//this function is used for reading from file
void read_File(){
	Patient patient;
	
	//-----dosyadan okuma yaparken stream nesnemizi olusturuyoruz.
	FILE *fs=fopen("list.txt","rb");
	if(fs==NULL){
		printf("File cannot be opened\n");
		exit(0);
	}
	
	/*
fread(void *buffer,size_t size,size_t count,FILE *stream)
buffer:Pointer to the buffer where data will be stored
size:The size of each element to be read in bytes
count:Number of elements to be read
stream:Pointer to the FILE object from where data is to be read
	*/
//-----asag�daki fread()fonksiyonu ile okuma yap�yoruz.
//-----burda fread fonksiyonunun parametreleri var.
	
//-----buffer,size,count ve stream olarak.
//-----buffer dedigimiz:yani datan�n tutuldugu yeri i�aret eden i�aretcimizi biz buraya parametre olarak veriyoruz.
//-----ondan sonra dosyadan okunacak olan verinin boyutunu belirtiyoruz.
//-----ne kadar boyutta bir okuma yap�caz diye.
//-----biz burda hastalar� okuyacag�m�z i�in Patient yap�m�z� veriyoruz.
//-----ondan sonra her bir seferde okunacak veri say�s� 1 olucak.
//-----1 tane patient okuyacak.
//-----fs de bizim stream parametremiz.
//-----sonra okudugum veriler art�k patient nesnesinin i�erisinde bulunacak
//-----ben burda okudugum veriyi print ediyorum.
//-----patient nokta diyip patient nesnesinin verilerine erisebiliyorum.

	while(fread(&patient,sizeof(Patient),1,fs)){
		printf("\nPatient Informations\n");
		printf("Name : %s\n",patient.name);
		printf("surname:%s\n",patient.surname);
		printf("ID      :%s\n",patient.ID);
		printf("Age : %d\n",patient.age);
		printf("prior:%d\n",patient.prior);
	}
	fclose(fs);
}
