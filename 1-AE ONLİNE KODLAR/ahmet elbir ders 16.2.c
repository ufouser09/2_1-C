//-----bu C dosyam�z�n� ad� struct_patient.h'dir.

//Creating Patient Structure
//-----hastalar� belirttigimiz bir dosya 
typedef struct{
	char name[20],surname[30];
	char ID[12];
	int age;
	int prior;
}Patient;

//-----bu hastalar� bir listenin i�inde tutmak istiyoruz ya 
//-----o listenin bir tane eleman�n� belirticek 
//-----baska bir yap�ya daha ihtiyac�m�z var.bu yap�da da nolucak 
//-----hem hasta verisini tutan bir yap� olucak node'umuz.
//-----hem de bir sonraki ifadeyi g�stericek pointer i�aretcimize ihtiyac�m�z var.
//-----bir Patient_Node i�aretcisine ihtiyac�m�z var.

//Creating Patient_Node structure
typedef struct Patient_Node{
	Patient data;
	struct Patient_Node *next;
	
}Patient_Node;
