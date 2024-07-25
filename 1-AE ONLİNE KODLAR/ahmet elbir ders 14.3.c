//RECURS�ON ile alakal� bir ornek 
//linked list ve binary search treelerde traverse yaparken bu yapt�klar�m�z i�e yarar recursiondan faydalanabiliyoruz.
//sizeof(a)/sizeof(a[1]) bunun anlam� nedir.sizeof(a) nedir array�n boyutu
#include <stdio.h>
#define MAX(a) sizeof(a)

//ilk parametre dizinin ilk eleman�n� pointer olarak alabiliriz.bir i degeri gelicek bi tane de n degeri gelicek.birisi ilk eleman birisi son eleman �imdi burdaki i degeri n'den kucuk oldugu muddetce reverse cag�r�yorum bu reverse'u cag�rd�g�mda array cag�r�cam ,i+1'i cag�r�cam ve n'i cag�r�cam 
//�imdi ilk basta i'miz s�f�r.n de 5 olarak geldi i kucuk mu 5 den evet nap�yo 1 e 5 i cag�r�yo 1 e 5i cag�r�nca 1 kucuk mu 5 ten evet 2 5 cag�r�yo 3'e 5'i cag�r�yo o 4 '� 5 'i cag�r�yo sonra bi da cag�ryo 5 e 5 i cag�r�yo bunu cag�rd�ktan sonra 5 kucuk mu 5 ten hay�r hay�r oldugu i�in bu k�s�mdan donuyor burdan dondukten sonra yani 5 e 5 den dondu 4 e 5 in bu sat�r�na geri geldi sonra array'in i'sini yazd� arrayin i'si kac 4 yani son eleman bu son eleman� ekrana yazd� bunu yazd�ktan sonra if den c�k�yo return etm�s oluyor sonra bunu kim cag�rd� stack mant�g� ile dusuncez.4 e 5 ten c�kt�ktan sonra noldu 3 e 5 i cag�rcaz sonra array�n 3.sunu yazd�r�yor falan boyle devam ediyor bu sekilde ekrana terstten yazd�r�yoruz.bi orjinal diziyi bozmadan yap�caz bir de swap i�lemi yaparak bunu yapal�m buna da reverse2 diyelim.bu gercek anlamda bir reverse olucak   
void reverse(int *ar,int i,int n){
	if(i<n){
		reverse(ar,i+1,n);
		printf("%d",ar[i]);
	}
}
//yine integer array al�caz.integer i'yi al�caz.integer n'i al�caz 
void reverse2(int *ar,int i,int n){
	int tmp;
	//while'daki i<N gibi dusunebiliriz.cunku burda recursive bir dongu yap�yoruz.
	if(i<N){
		//tmp'ye dizinin birinci eleman�n� al�yorum.
		tmp=ar[i];
		ar[i]=ar[n];
		ar[n]=tmp;
		reverse(ar,i+1,n-1);
	}
}


int main(){
	int a[]={1,2,3,4,5};
	int N=MAX(a)/MAX(a[1]);
	for(i=0;i<N;i++){
		//diziyi ��yle ekrana yazd�ral�m.
		printf("%d-",a[i]);
	}
	printf("\n");
	
	reverse(a,0,N);
	//burda g�nderirken art�k N-1 olucak ��nk� yer degisimi olucak oraya kadar gitmicez.
	reverse2(a,0,N-1);
	return 0;
}
2.00
