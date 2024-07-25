#include <stdio.h>
#include <stdlib.h>
#include <time.h>
										//Kýzma Birader Oyunu
				// 2 - 4 kiþi arasýnda oynanabilen bir oyundur. Bir kiþi kazandýðýnda oyun bitmektedir.

void menu();
void hakkinda();
void kurallar();
void oyun(int oyuncusayisi); //Oyunda sýradaki oyuncuya geçme ve oyunu bitirme bölümlerinin olduðu genel bölüm
void oyunaBasla(); //Oyuncu ismi ve sayýsý giriþ kýsmý
void oyunTahtasi(); //oyun tahtasýný ekrana getiren fonksiyon
void sira(int oyuncu); //sýranýn kimde olduðunu ekrana yazdýran fonksiyon
void yerlestirme(); //oyun içi yer deðiþtirmeleri kolaylaþtýrmak amacýyla açýlan dizilere karakterleri yerleþtirme
void piyonCikar(int oyuncu); //yuvadan piyon çýkarma
void hareket (int oyuncu, int zar);	//zara göre piyon hareket ettirme
void sonKonum(int oyuncu, int index, int zar); //hareketteki sonuçlar sonucu piyonlarý son pozisyonlarýna yerleþtirme
void temizleVeBasla(int oyuncu); //ekraný temizleyip son hali yeniden yazdýrmak için kýsayol
void piyonYe(int oyuncu, int position, int zar); //Ýki piyon ayný kareye geldiðinde olacaklar
void finaleVaris(int oyuncu, int index, int zar); //Piyonlarýn final poziyonuna ulaþtýðýnda olacaklar

int disaridakiPiyonlar(int oyuncu); //yuvanýn dýþýnda (tahtada) piyon olup olmadýðý kontrolü
int piyonUygunMu(int oyuncu, char piyonsecimi); //Seçilen piyonun oynanabilirliði kontrolü
int uygunPiyon(int oyuncu); //oynanabilir kaç tane piyon var kontrolü
int finaleUlasan(int oyuncu); //Finale ulaþan kaç piyon var kontrolü

int kazan = 0; //oyunun bitip bitmediði kontrolü
int kontrol = 0; //kendi piyonu üzerine gelip gelmediði kontrolü

int yuva[4][4] = {{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};//Piyonlarýn yuvadaki yerleri
int baslangicNoktasi[4] = { 16,26,36,46};//Her oyuncunun kendi baþlangýç poziyonlarý
int ekle[3] = {20,24,28};//piyonlarýn koridordan final poizyonuna geçmeleri için gerekli olan eklemeler
int ilerleme[4][4];//piyonlarýn tahtada kaç kutu hareket ettiklerinin deðerleri

char tahtadakiPiyonlar[4][4];//tahtada bulunan piyonlar
char final[4][4];//final pozisyonundaki piyonlar
char piyonlar[4][4];//Oyuncularýn sahip olduðu piyonlar
char uygunpiyon[4][4];//oyunda oynamaya müsait piyonlar
char isimler[4][20];//oyuncu isimleri
char board[72];//oyundaki hareketi kolaylaþtýrmak amacýyla yaptýðým harita dizisi

int main() {
	ShowWindow(GetConsoleWindow(), 3);//Oyun tam ekranda açýlmasý için fonksiyon
	system("COLOR F0");//Ekran ve yazý rengi için fonksiyon

	menu();
	
	return 0;
}

void menu()
{
	system("CLS"); //Ekraný temizle
	printf("\n\n\n\n\n\t\t\t\t\t\t\t\t*** ANA MENU ***\n\n");
	printf("\t\t\t\t\t\t\t\t1. OYUNA BASLA\n");
	printf("\t\t\t\t\t\t\t\t2. KURALLAR\n");
	printf("\t\t\t\t\t\t\t\t3. HAKKINDA\n");
	printf("\t\t\t\t\t\t\t\t4. CIKIS\n\n");
	printf("\t\t\t\t\t\t\t\tLutfen seciminizi yapiniz <1-4> : ");

char secim;	
	do {
		scanf("%c", &secim);
		if (secim < '1' && secim > '4')
			printf("\nLutfen dogru secenegi seciniz. <1-4> ");
	} while (secim != '1' && secim != '2' && secim != '3' && secim != '4');
	if (secim == '1'){
		oyunaBasla();
	}
	else if (secim == '2'){
		kurallar();
	}
	else if (secim == '3'){
		hakkinda();
	}
	else if (secim == '4'){
		printf("\t\t\t\t\t\t\t\t\tCIKIS YAPILIYOR...");
		exit(0);
	}
}

void kurallar(){
	system("CLS");
	printf ("\n\n\n\n\n\t\t\t\t*** KURALLAR ***\n\n");
	printf ("\t\t1. Oyun 2, 3 veya 4 oyuncuyla oynanabilir. Her oyuncunun 4 piyonu vardir.\n");
	printf ("\t\t2. Her turda oyuncular 1'den 6'ya kadar deðer veren bir zar cevirirler.\n");
	printf ("\t\t3. Ancak zar '6' sayisini verdiginde oyuncular 'yuva'larindan bir piyon cikarabilirler.\n");
	printf ("\t\t4. Oyun tahtasinda piyon varken zarda 6 gelmesi durumunda oyuncu istege gore ya \n\t\t   bulunan piyonunu hareket ettirmelidir ya da yeni piyon cikarmalidir.\n");
	printf ("\t\t5. Piyonlar zarda gelen sayi kadar kutucuk ilerleyebilirler.\n");
	printf ("\t\t6. Ayni anda ayni kutucukta iki piyon bulunamaz.\n");
	printf ("\t\t7. Eger oynanan piyon rakibin piyonunun uzerine gelmisse rakibin piyonunu yuvasina gonderir.\n");
	printf ("\t\t8. Kullanici kendi piyonunun bulunduðu kareye oynayamaz. Farkli bir piyonunu oynamasi istenir.\n");
	printf ("\t\t9. 'Final' pozisyonuna ulasan piyonlari baska oyuncular yiyemez.\n");
	printf ("\t\t10. 4 piyonunu da finale ulastiran oyuncu oyunu kazanir.\n\n\n");
	printf("\t\tAna Menuye donmek icin herhangi bir tusa basiniz... ");
	getch(); //Menüye dönmek için bir tuþa basmak için fonksiyon
		menu();
}

void hakkinda(){
	system("CLS");
	printf("\n\n\n\n\n\t\tHAKKINDA\n\n");
	printf("\t\tBu oyun Yildiz Teknik Universitesi Bilgisayar Muhendisligi ogrencisi Muhammed Ali LALE tarafindan"
	"\n\t\tBilgisayar Bilimlerine Giris Dersi Donem Odevi icin hazirlanmistir.\n\t\t\t\t\t\t\t\t\t\t\t\t\t©2020-2021\n\n\n");
	printf("\t\tAna menuye donmek icin herhangi bir tusa basiniz... ");
	getch(); //Menüye dönmek için bir tuþa basmak için fonksiyon
	menu();
}

void oyunaBasla(){
system("CLS");
	int oyuncusayisi;
	printf("\n\n\n\t\tOyuncu Sayisini Giriniz <2-4> : ");
	do {
		scanf("%d", &oyuncusayisi );
		if (oyuncusayisi <= 1 || oyuncusayisi > 4)
			printf("\t\tOyuncu sayisi 2 ile 4 arasinda olmalidir! ");
	} while (oyuncusayisi <= 1 || oyuncusayisi > 4);
	int i;
	for (i = 0; i < oyuncusayisi; i++) {
		printf("\t\t%d. Oyuncunun ismini giriniz. : ", i+1);
		scanf("%s", isimler[i]);
	}
	yerlestirme(oyuncusayisi);
	system("CLS");
	oyun(oyuncusayisi);
}

void yerlestirme(int oyuncusayisi){
		int i;
	for (i = 0; i < 56; i++){
		board[i] = ' ';
	}
	for (i = 56; i < 72; i++){
		board[i] = 'x'; //final kýsmý
	}
	char piyon;
	piyon = 'a';
	for (i = 0; i < oyuncusayisi; i++) {
		int j;
		for (j = 0; j < 4; j++) {
			tahtadakiPiyonlar[i][j] = ' ';
			final[i][j] = ' ';
			ilerleme[i][j] = 0;
			board[4*i + j] = piyon;//baslangýçta yuvaya piyonlarý yerleþtirmek
			piyonlar[i][j] = piyon;//piyonlarý dizisini doldurma
			uygunpiyon[i][j] = piyon++;//oynamaya müsait olan piyonlar
		}
	}
}

void oyun(int oyuncusayisi){
	int oyuncu;
	char getch;
	int zar;
	int i;
	short int check = 1;
	while (check == 1)	{
		i = 0;
		while(kazan == 0 && i < oyuncusayisi){
			system("CLS");
			sira(i);
			oyunTahtasi();
			printf("\n\tZar atmak icin herhangi bir tusa basin... ");
			_getch();
			srand(time(NULL));
			zar = rand() % 6 + 1;
			printf("\n\tGelen Sayi %d: ", zar);
 
			if (zar == 6 && disaridakiPiyonlar(i) == 0){//piyonu dýþarý çýkar
				piyonCikar(i);
			}
			else if (disaridakiPiyonlar(i) != 0){//dýþarýda piyon varsa oynat
				hareket(i, zar);
			}
			else if (zar != 6 && disaridakiPiyonlar(i) ==0){
				printf("\n\tOynamak icin bir sonraki raundu bekleyiniz.");
			}
			if (kazan == 0){
			printf("\n\tSiradaki Oyuncuya gecmek icin bir tusa basin...");
			_getch();
			}
			i++;
		}
		if (kazan == 1) {
		check = 0;
			}
	}
	printf("\n\n\n\t\t\t\t\t\tAna Menuye donmek icin herhangi bir tusa basiniz ");
	_getch();
	menu();
}

void sira(int oyuncu){
	printf ("\t\t\t\t\t      ______________________\n");	
	printf ("\t\t\t\t\t     |                      |\n");
	printf("\t\t\t\t\t          Sira %s'de   \n", isimler[oyuncu]);	//Sýranýn kimde olduðu göstergesi
	printf ("\t\t\t\t\t     |______________________|\n\n");
}

void oyunTahtasi(){ //alt çizgi ve düz çizgilerden oluþturduðum oyun tahtasý
printf ("\t\t\t _________________________________________________________________\n");
printf ("\t\t\t|       |       |       |  %c  |  %c  |  %c  |       |       |       |\n",board[24],board[25],board[26]);
printf ("\t\t\t|   %c   |   %c   |       |_____|_____|_____|       |   %c   |   %c   |\n",board[0],board[1],board[4],board[5]);
printf ("\t\t\t|_______|_______|       |  %c  |  %c  |  %c  |       |_______|_______|\n",board[23],board[60],board[27]);
printf ("\t\t\t|       |       |       |_____|_____|_____|       |       |       |\n");
printf ("\t\t\t|   %c   |   %c   |       |  %c  |  %c  |  %c  |       |   %c   |   %c   |\n",board[2],board[3],board[22],board[61],board[28],board[6],board[7]);
printf ("\t\t\t|_______|_______|       |_____|_____|_____|       |_______|_______|\n");
printf ("\t\t\t|                       |  %c  |  %c  |  %c  |                       |\n",board[21],board[62],board[29]);
printf ("\t\t\t|_______________________|_____|_____|_____|_______________________|\n");
printf ("\t\t\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",board[16],board[17],board[18],board[19],board[20],board[63],board[30],board[31],board[32],board[33],board[34]);
printf ("\t\t\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
printf ("\t\t\t|  %c  |  %c  |  %c  |  %c  |  %c  | ... |  %c  |  %c  |  %c  |  %c  |  %c  |\n",board[55],board[56],board[57],board[58],board[59],board[67],board[66],board[65],board[64],board[35]);
printf ("\t\t\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
printf ("\t\t\t|  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |  %c  |\n",board[54],board[53],board[52],board[51],board[50],board[71],board[40],board[39],board[38],board[37],board[36]);
printf ("\t\t\t|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|\n");
printf ("\t\t\t|                       |  %c  |  %c  |  %c  |                       |\n",board[49],board[70],board[41]);
printf ("\t\t\t|_______________        |_____|_____|_____|        _______________|\n");
printf ("\t\t\t|       |       |       |  %c  |  %c  |  %c  |       |       |       |\n",board[48],board[69],board[42]);
printf ("\t\t\t|   %c   |   %c   |       |_____|_____|_____|       |   %c   |   %c   |\n",board[12],board[13],board[8],board[9]);
printf ("\t\t\t|_______|_______|       |  %c  |  %c  |  %c  |       |_______|_______|\n",board[47],board[68],board[43]);
printf ("\t\t\t|       |       |       |_____|_____|_____|       |       |       |\n");
printf ("\t\t\t|   %c   |   %c   |       |  %c  |  %c  |  %c  |       |   %c   |   %c   |\n",board[14],board[15],board[46],board[45],board[44],board[10],board[11]);
printf ("\t\t\t|_______|_______|_______|_____|_____|_____|_______|_______|_______|\n");

}

int disaridakiPiyonlar(int oyuncu){
	int disarida;
	disarida=0;
	int i;
	for (i = 0; i < 4; i++)
	if (tahtadakiPiyonlar[oyuncu][i] != ' ')
		disarida++;
	return disarida; //disarida kaç tane piyon olduðu bilgisi
	}

void piyonCikar(int oyuncu){
	 int index;
	 int i;
		printf("\n\tYuvadan cikarmak istediginiz piyonu seciniz: < ");
		for (i = 0; i < 4; i++) {
			if (uygunpiyon[oyuncu][i] != ' ')
				printf("%c ", uygunpiyon[oyuncu][i]);
		}
		printf("> : ");
		
		char piyonsecimi;
		do {//doðru seçimi yapma
		piyonsecimi= getch();
			if ((piyonUygunMu(oyuncu, piyonsecimi)) == 0)
				printf("\n\tGecersiz secim! Lutfen uygun bir piyon seciniz. ");
		} while (piyonUygunMu(oyuncu, piyonsecimi) == 0);

		for (i = 0; i < 4; i++){
			if (piyonlar[oyuncu][i] == piyonsecimi){
				index = i;//Seçilen piyonun indisi
			}
		}

	int start;
	start = baslangicNoktasi[oyuncu];
	if (board[start] != ' ') {
		piyonYe(oyuncu, start, 6);
	}
	if(kontrol != 2){
		board[start] = board[yuva[oyuncu][index]];//piyonu tahtaya koyma
		board[yuva[oyuncu][index]] = ' ';//yuvadaki piyonun yerþne boþluk koy
		uygunpiyon[oyuncu][index] = ' ';//Secilebilir piyonlar arasýndan çýkar
		tahtadakiPiyonlar[oyuncu][index] = piyonsecimi;
	
		int zar;
		srand(time(NULL));
		zar = rand() % 6 + 1;
		temizleVeBasla(oyuncu);
		printf("\n\tPiyon cikardiginiz icin bonus raund\n\tZarda Gelen Sayi : %d", zar);
		hareket(oyuncu,zar);
	}
}	

int piyonUygunMu(int oyuncu, char piyonsecimi){ //seçilen piyon oynamaya müsaitse 1 verir
	int i;
	int count;
	count = 0;
	for (i= 0; i < 4; i++){
		if (uygunpiyon[oyuncu][i] == piyonsecimi){
			count = 1;
		}
	}
	return count;
}

void temizleVeBasla(int oyuncu){
	system("CLS");
	sira(oyuncu);
	oyunTahtasi();
}

void hareket(int oyuncu, int zar){
	char secim = 'u';
	int move = 1;
	int i;
	int index;
	kontrol = 0;
	if (zar == 6 && uygunPiyon(oyuncu)!=0) { //Zar 6 gelirse yeni piyon çýkarýp çýkarmama isteme sorusu
		move = 0;
		printf("\n\tYuvadan yeni  bir piyon cikarmak istiyor musunuz? <e/h> ");
		do { 
			secim = getch();
			if (secim != 'e' && secim != 'h')
				printf ("\n\tGecersiz Secim! Lutfen 'e' ya da 'h' secin : ");
		} while (secim != 'e' && secim != 'h');
	}
	
	if (secim == 'e')
		piyonCikar(oyuncu);
	else if (secim == 'h' || move==1) { //istenen piyonu hareket ettirme
		char choice;
		printf("\n\tHangi piyonu oynamak istiyorsunuz? <");
		for(i = 0; i < 4; i++){
			if (tahtadakiPiyonlar[oyuncu][i] != ' ')
			printf(" %c", tahtadakiPiyonlar[oyuncu][i]);
		}
		printf(" > : ");
		
		do {
			index = -1; //yanlýþ seçim yapýlýrsa döngü baþa alsýn diye belirlediðim index
			choice = getch();
			for (i=0; i < 4; i++) {
				if (piyonlar[oyuncu][i] == choice){
					index = i;//seçili piyonun indisi
				}
			}
			if (index == -1 || tahtadakiPiyonlar[oyuncu][index] != choice)
				printf("\n\tPiyon musait degil! Lutfen dogru secimi yapiniz: ");
		} while (index == -1 || tahtadakiPiyonlar[oyuncu][index] != choice);

		//Finale ulaþýlýnýrsa olacaklar
		if (ilerleme[oyuncu][index] + zar > 39 && ilerleme[oyuncu][index] + zar < 44){
			printf("\n\t*** Finale ulastiniz ***" );
			finaleVaris(oyuncu, index, zar);
			return;
		}
		//oyun tahtasýnýn sonuna gelme uyarýsý
		else if (ilerleme[oyuncu][index] + zar > 42) {
			printf("\n\tDaha fazla ileri gidemezsiniz");
			if (disaridakiPiyonlar(oyuncu) == 2 || disaridakiPiyonlar(oyuncu) == 3 || disaridakiPiyonlar(oyuncu) == 4) {
				printf ("\n\tFarkli bir piyon secin"); 
				hareket(oyuncu, zar);
			}
			else return;
		}
		
		sonKonum(oyuncu, index, zar);
		if (zar == 6) { //6 geldiðinde tekrar oynama
			zar = rand() % 6 + 1;
			srand(time(NULL));
			temizleVeBasla(oyuncu);
			printf ( "\n\tALTI geldigi icin bonus raund");
			printf ("\n\tGelen sayi: %d", zar);
			hareket(oyuncu, zar);
		}
	}
}

void sonKonum(int oyuncu, int index, int zar) {
	short int position; 
	short int start = baslangicNoktasi[oyuncu];
	short int previous = start + ilerleme[oyuncu][index];
 //harita 16'dan 55'e kadar olduðu için 1. oyuncu hariç diðerlerinin konumu tekrar yazýlmalý
	if (oyuncu >= 1) {
		if (previous > 55)
		previous %= 40;
			
		if (ilerleme[oyuncu][index] + zar > 39) {
				previous = ilerleme[oyuncu][index] + ekle[oyuncu - 1];
				board[ilerleme[oyuncu][index] + zar + ekle[oyuncu - 1]] = board[previous];
				board[previous] = ' ';
				ilerleme[oyuncu][index] += zar;
			return;
		}
		
		if (previous == 55) {
			position = 15 + zar;
			piyonYe(oyuncu, position, zar);
			if(kontrol == 0){
				board[position] = board[previous];
				board[previous] = ' ';
				ilerleme[oyuncu][index] += zar; 
			}
			if(kontrol == 1){
				position = position - zar; 	//kendi piyonunun üzerine gelmiþse eski yerine geri getirme
			}
		}
		else if ((start + ilerleme[oyuncu][index] + zar > 55)) {
			position = (start + ilerleme[oyuncu][index] + zar) % 40;
			
			piyonYe(oyuncu, position, zar);
			if(kontrol == 0){
				board[position] = board[previous];
				board[previous] = ' ';
				ilerleme[oyuncu][index] += zar;
			}
			if(kontrol == 1){
				position = position - zar;
			}
		}
		else {
			position = start + ilerleme[oyuncu][index] + zar;
			piyonYe(oyuncu, position, zar);
			if(kontrol == 0){
				board[position] = board[previous];
				board[previous] = ' ';
				ilerleme[oyuncu][index] += zar;
			}
			if(kontrol == 1){
				position = position - zar;
			}
		}
	}
	else {
		position = start + ilerleme[oyuncu][index] + zar;
		piyonYe(oyuncu, position, zar);
		if(kontrol == 0){
			board[position] = board[previous];
			board[previous] = ' ';
			ilerleme[oyuncu][index] += zar;	
		}
		if(kontrol == 1){
			position = position - zar;
		}
	}
}

int uygunPiyon(int oyuncu) {
	int count = 0;
	int i;
	for (i = 0; i < 4; i++)
		if (uygunpiyon[oyuncu][i] != ' ')
			count++;
	return count; //oynamaya müsait piyon sayisini verir
}

void piyonYe(int oyuncu, int position, int zar) {
	if (board[position] != ' ') {
		int i, j, y_oyuncu, index;
		for (i = 0; i < 4; i++){
			for (j = 0; j < 4; j++)
				if (piyonlar[i][j] == board[position]) {
					y_oyuncu = i;
					index = j;
				}
		}

		if (y_oyuncu == oyuncu) {	//Kendi piyonunu yememe
			printf ("\n\tKendi piyonunuzu yiyemezsiniz");
			printf("\n\tFarkli bir piyon seciniz.");
			hareket(oyuncu, zar);			
			kontrol = 1;
			if (position == baslangicNoktasi[oyuncu]){
				kontrol = 2;
			}
		}
		else if(y_oyuncu != oyuncu){	//rakibin piyonunu yeme
			board[yuva[y_oyuncu][index]] = board[position];
			board[position] = ' ';
			uygunpiyon[y_oyuncu][index] = piyonlar[y_oyuncu][index];//seçilemez yap
			tahtadakiPiyonlar[y_oyuncu][index] = ' ';
			ilerleme[y_oyuncu][index] = 0;
			if (position == baslangicNoktasi[oyuncu]) {
				piyonCikar(oyuncu);
			}
			printf("\n\t%c piyonu yuvasina dondu.", piyonlar[y_oyuncu][index]);
		}
	}
}

void finaleVaris(int oyuncu, int index, int zar) {
	int previous = baslangicNoktasi[oyuncu] + ilerleme[oyuncu][index];
	if (oyuncu != 0) {
		if (previous > 55){
			previous = previous % 40;
		}
		if(ilerleme[oyuncu][index] > 39){
			previous = ilerleme[oyuncu][index] >= 51;	
		}
	}
	if (oyuncu == 0){
		board[previous + zar] = board[previous];
	}
	else {
		board[ilerleme[oyuncu][index] + zar + ekle[oyuncu - 1]] = board[previous];
	}
	final[oyuncu][index] = piyonlar[oyuncu][index];
	tahtadakiPiyonlar[oyuncu][index] = ' ';
	uygunpiyon[oyuncu][index] = ' ';
	board[previous] = ' ';
	if (finaleUlasan(oyuncu) == 4) {
		system("CLS");
		printf("\n\n\n\n\t\t\t\t\t\t");
		printf("%s KAZANDI!!!", isimler[oyuncu]);
		kazan = 1;
		return;
	}
}

int finaleUlasan(int oyuncu) { //Final bölümüne ulaþan piyon sayýsý 4 olursa kazandýrýyor
	int count = 0;
	int i;
	for (i = 0; i < 4; i++)
		if (final[oyuncu][i] != ' ')
		count++;
	return count;
}
