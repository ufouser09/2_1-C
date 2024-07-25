
-klavye----------> input, ekran----------> output
-input sadece klavye olmayabilir.
-ekran sadece output olmayabilir .

-Eger program�n�zda kulland�g�n�z verileri kal�c� olarak saklamak istiyorsan�z program kapand�ktan sonra da saklans�n diyorsan�z 
"hard-disk �zzerinde"(kal�c� haf�za �zerinde) "belli alanlar olusturup" bu alanlarda verilerinizi saklaman�z gerekiyor.

-buna biz "�nput/output" diyoruz ve burda kullan�lan �ey daha cok "file islemleri" olucak 
 Biz burda bir �ekilde "i�letim sistemi" ile beraber bir �ekilde haberle�me halinde olucaz.

**veri okurken hard-diske eri�mek gerekiyor**.

-hard-disk'in �zellikle cal�sma mant�g� sudur:
hard-disk uzerindeki veri ram'e kopyalan�yor i�eri�i neyse bu kopyalama esnas�nda bir veri ak�s� meydana geliyor 
ve bu dosyalar ya dogrudan "clear bir �ekilde" saklan�r veya "binary �ekilde" kodlanarak saklan�r.
��letim sistemi bu kodlar� cozecek dosya okuma formatlar�yla alakal� bilgiye sahip olmas� gerekir.

-Buffer olmas�n�n anlam� s�rekli git gel yapm�yo hard-diske belirli aral�klarla yap�yor.

-I/O ve stream sudur:
Bir program c program� olmak zorunda degil bir dosyay� okumak istediginde veya bir yaz�c�ya veri gondermek istediginde 
veriler bu sekilde bir dizi halinde kopyalan�yor ak�s gerceklesiyor.

-stream dedigimiz sey i�letim sistemi taraf�ndan ayr� bir yap�.

-Bizim I/O operasyonlar�n� program�m�z i�inde ger�ekle�tirebilmemiz i�in stream'i bir �ekilde elde etmemiz gerekir,
onunla bir �ekilde haberle�memiz gerekir.
Assosiciate bir ili�ki kurmam�z gerekiyor.
Bunu bir C dilinde yapman�n yolu "FILE" turunde bir pointer tan�mlamaktan gecer ve bu asl�nda bir "struct't�r".
FILE struct'�r�ndan bir pointer tan�mlamak gerekiyor.

-Bir stream�n oldugunu ,i�letim sistemiyle bir �ekilde haberle�meye ge�memiz gerekti�ini bilmemiz gerekiyor.

-Temelde 3 tane standart stream vard�r ve bu i�letim sistemiyle alakal�d�r:
Bir �nput yap�lacaksa streamde "stdin" stream t�r� kullan�l�yor.
Output kullan�lacaksa "stdout" kullan�l�yor.
Herhangi bir hata durumunda da "stderr" kullan�l�yor.
bu i�letim sistemiyle alakal� bunun uygulamas�n� C de de g�r�cez.	
 
-Bizim printf scanf fonksiyonlar�n�n arkada yapt�g� sey su
printf--->stdout kullan�yor.
scanf----->stdin kullan�l�yor.

-Bu fonksiyonlar� kullanarak dosyalar �zerinde herhangi bir dosyay� i�aret ederek.
yap�cag�m�z sey o dosya uzerinden I/O yapmak.

printf nas�l program �zerinde ve bir comment line �zerinde �al���yor ise 
bizde ayn� �ekilde bir dosya �zerinde ayn� bir comment line gibi �al���caz.

-Asl�nda printf'in yapt�g� da arkada bir dosya okumakt�r.

-O dosya comment line'�n �zel dosyas� arka planda cal�san dosyas�.

Dosya nedir?
Bi kere dedik ki bunlar "hard-disk �zerinde" kal�c� olarak saklanacak.
Dosya dedigimiz sey ---->0 ve 1'ler dizisi.

Ama biz bunu genelde su sekilde g�steriyoruz

**


-Kulland�g�m�z hemen hemen her dosya bu �ekilde "0 ve 1'ler dizisi" �eklinde saklan�yor.
O zaman ben bu 0 ve 1'lerin yerle�imine bir anlam katarsam �zel ama�l� bir dosya olusturmus olurum.

�rne�in k�s�lerin ad�n� soyad�n� ID s�n� bir excelde sakl�ycam.
Excel'in daha basit hali csv dir ve virg�llerle ve noktal� virg�llerle ayr�lan bir dosya format�d�r.
Bunu clear text olarak saklad�g�n�z� d�s�n�n.

Eger ben 0 ve 1'lerle sakl�yorsam buna binary ,ad=efe soyad=girgin diye sakl�yosam da buna text format� demi� olurum.

�imdi her bir dosya i�in baz� �nemli meta veriler laz�m.

�imdi bizim bir 0 ve 1 ler dizisi olan bir binary formatta dosyam var.
biz bu dosyay� 3'e b�ld�g�m�z� d���n�n:
ilk k�sm� "header" olur
2.si "data" olur.
3.s� "fonter" olur.----------->fonter her zaman olmak zorunda degil.

-dosyaya ait bazi �n bilgileri "header" dosyas�nda saklamak gerekebilir.

�rne�in bir resim dosyas� acmak istiyorsunuz veya bizim C dosyas�n� a�mak isterken surda detaylar� var:
bunun ad� ney ,uzant�s� ney ,tipi ne ,i�te bulundugu lokasyon ne
Bu bilgilerin bi yerde saklanmas� laz�m ki sen bu dosyay� acmak istediginde ilgili programlar ili�kilendirilsin.

�lgili program �rne�in bir g�r�nt� a��caks�n�z.
Ne kadar boyutta oldugunu biliyor muyuz t�klarken bilmiyoruz.
T�klay�nca bir malloc gibi bir �ey arka tarafta �al��mas� laz�m ki git bak bellekte �u kadar yer a� bi g�r�nt� geliyor demesi laz�m.

��te o bilgiler arka tarafta o "header" taraf�ndan al�nmas� gerekiyor.

Sadece boyut t�r degil �rnegin bu dosyan�n nas�l bir yap�da olucag� orda soylenmesi gerekiyor.

-Binary saklanmas�n�n sebebi "daha az yer kaplamas�" ve "dosya i�eri�inin gizlenmesi" ile alakal�d�r.

Bizim dosyalar�m�zda bu �� alan olur ama "fonter" bazen olmayabilir,"header" genellikle vard�r.

Biz bunu C de yapmak i�in "stream'e eri�mek i�in" bir "FILE pointer" kullanmak gerekiyor.

Bu FILE pointer "stdio.h" i�indedir.

**Bu FILE pointer'�ndan bir degisken olustururken hard-diskt'te "bir dosyan�n adresini" point etmesini isticez.**

Ve bu pointer vas�tas�yla stream �zerinde i�lemler yapabilicez--------->ister text dosya olsun ister binary dosya olsun. 

Bu stream,identifier'� tutuyor asl�nda 

**�ncelikle dosyan�n file pointer'�n�n olusturcaz olusturduktan sonra dicez ki dosyay� acmaya calis.

Bir program ayn� anda birden fazla stream i�lemi yapabilir mi?  ----------->yapabilir.
Yani bi yandan okurken bi yandan yazma yapabilirsiniz.
Bunlar "concurrent stream" dedigimiz �eyler.


"File pointer" ile "file position indicator'�" kar�st�rmamak gerekir.

File pointer sudur iste "FILE turunden" olusturcaz ben�m bir hard-disktte dosyam vard� ben bunu bir �ekilde bellege getirdim.
��te O bellekteki dosyan�n adresi FILE pointerd�r. 

file position dosyan�n i�indeki �u "curser'�n pozisyonunu" g�steriyor.
file pointer dosyan�n adresini ifade ediyor.
file position belli bir byte pozisyonunu ifade ediyor.
oburu dosyan�n device uzerindekki adresini soyluyor.


�imdi biz "<stdio.h>" i�indeki "header file'a" bakt�g�m�zda
Ornegin I/O fonksiyonlar� i�in baz� prototip declarationlar vard�r:
Ne demek bu declarationlar �rnegin "EOF" veya baz� macro sabitleri burda kullan�lan sey veya typedef'ler file struct'�r�n definition'u vard�r.
Yine bunun i�erisinde file struct'�r�n i�erisindeki elemanlar i�te stdin stdout stderr gibi standart streamler vard�r.

Biz fscanf d�s�nda bu "stdin" ve "stdout'u" kullanarak klavyeden veri okuyusu ornegi yap�caz.
fscanf kullanmadan baska bir sekilde 

"EOF" lar vard�r bunlar dosyan�n sonuna ulas�p ulasmad�g�n� g�sterir.
File position EOF'n�n ulas�p ulasmad�g�n� kontrol eder.
 
 
��te null dedigimiz null pointer ile ilgili i�lemler i�te dosya a��ld� m� a��lmad� m� gibi 
 
bu stddef ile stdio ile kullan�rsak dosya i�erisindeki null i�lemlerini gorebilicez
 
Ve bundan sonra dosya �zerindeki i�lemleri yapmak kal�yor.

Genel olarak konsept bu sekilde 
 
Dedik ki dosyalar "binary" veya "text" olarak bir �ekilde s�ralan�yor.
 
 eri�imlerine gore dosyalar� s�ralamak �imdi 2 turlu erisim var:--------------------------------------
 bir "random access dosyada"
 bir de "sequantial access"
 
sequantial access de olan olay sudur bu bir bit dizisi ister sat�r seklinde dusunun ister sadece 0 ve birler �eklinde dusunun
bu dosya ac�ld�g�nda bunun pozisyon controller'� burdad�r.
 
 Sen ister bir bit okursun ister bir byte okursun ister bir sat�r okursun istersen bir blok okursun.
 Bak�n "bit" okuyabiliyorum ,"byte" okuyabiliyorum, "formatted data" okuyabiliyorum .
 Yani git bi tane string bi tane integer bi tane float oku bi seferde bunu okuyabiliyoruz "line" okuyabiliyorum 
 Yani bi sat�r�n tamam�n� okuyabiliyorum veya bir blok okuyabiliyorum.ve bu okuma i�leminden sonra bit okuduysam 
 Bu curser bir bit kay�yor su formatta okuduysak onun size'� kadar kay�yor.bi sonrakini okuyabilmek i�in 
 bu tamamen text dosyalar�n�n i�erisinde de olabilir.
 binarylerde de olabilir.genellikle biz text dosyalar�nda "formatted data" dedigimizi �ok kullan�r�z.
 binarylerde bit okumam�z gerekir.byte okumam�z gerekir.
 
 
 Random access de olan olay sudur.
 File position eleman�n� dersin ki sen suan burdas�n git suraya kopyala 
 aradaki elemanlar� okumadan buraya konumland�r.veya end-of-file'a git.veya rewrite diye bir fonksiyon vard�r.
 o fonksiyonu g�r�nce tekrar basa don i�te sat�r�n bas�na gel.
 
 tape lerde verilerin s�ral� girisine izin veren veri kaydetme birimleri vard�r.eski kasetler buna bir ornektir.
 
 
random accessde de bulundugun yerden git ordan bir bit oku diyebilirsin.veya bir byte oku diyebilirsin.veya bir formatl� data oku diyebilirsin.---------------------------------
 
 
 "F�LE OP":
 �imdi genel olarak dosya i�lemleri neler:
 Dosyay� "create" edebilirim,"delete" edebilirim,"rename" edebilirim.
 
 Bunlar bildigimiz klasorde mouse'un uzerine sa� t�klay�p yapt�g�m�z veya comment line uzerinden yapt�g�m�z seyler.
 Bu operasyonlar tamam ama as�l yap�lacak islem bir "read i�lemi" vard�r,birde "write i�lemi" vard�r.
 
 Write i�lemi,i�erisindeki "bir veriyi update etmek olabilir",veya i�erisinde "s�f�rdan bir veri yazmak olabilir","append etmek olabilir"
 append etmek sonuna eklemek demektir.
 
 Write i�lem,hi�bir �ey yapmadan s�f�rdan yazmak anlam�na da gelir.
 
 Genellikle write modu ,"i�erigini �nce bosalt�r","ondan sonra s�f�rdan yazmaya baslar".
 
 Update i�erisindeki bir veriyi degistirmek demektir.
 
 Append de kald�g� yerden yani su file position eleman�n�n kald�g� yerden oraya veri ekle demektir,i�erigini bozma. 
 
 Read de sadece read yap�yor.----------------------------------------------------------------------------------
 �stedigin yerden ister bastan ister sondan okuma demektir.
 
peki dosya nas�l okunur? siz dosyay� nas�l okuyorsunuz? C de ya da herhangi bir programlama dilinde dosyay� nas�l okutursunuz?

 Dosyan�n bir ad� vard�r ,bir de uzant�s� vard�r.
 Ben bi tane C de dosyay� a�t�m ben bunun i�erigini nas�l okucam?

Dosyada birinci onemli �ey yaz�ld�g� gibi okunur. 
dosya dedigimiz sey 0 ve 1 ler yani burda EOF dedigimiz sey en son -sonda- dosya ,ister text olsun ister binary olsun
sonucta bu 0 ve 1 ler degil mi her halde her bilgisayarda ben�m programlama dilim gidicek onu 0 ve 1'lere cevirecek.

Dosya nas�l yaz�ld�ysa ona g�re okunacak nas�l yaz�ld�ktan kast�m�z su okuyacag�n ilk 4 eleman i�te dosyan�n ad� olucak
sonra dosyan�n uzant�s� gelicek yani dosyay� yazan k�s� burda hangi mant�kla yazd�ysa nas�l yaz�ld�ysa dedigimden kast�m bu.

Ona g�re o 0 ve 1 leri al�yosun tek tek nap�yosun anlamland�r�yosun.

burda ben su ornegi veriyorum protein sentezi denilen bir olay var demi s�md� prote�n sentezini baslatan bir 3 lu bir kodon vard�r,
bi de bitiren bir �ey vard�r.Arada da kodlar vard�r.
O baslat�c� kodonu gorunce sentezin basl�cag�n� yani i�lem basl�yo diyo sonra ondan sonra gelen her �c�nden bir am�noas�t kars�l� uretip 
nap�yo sistem protein sentezi yap�yor.
ayn� burda da oldugu gibi bu text dosyas� da olsa binary de olsa bunun genel hali burda baslay�p dosyan�n sonuna kadar giden
su 0 ve birler diyoki bu su kadar k�s�mda bunu al bu dosyan�n ad� olsun art�k bunu yazan k�s� nas�l yazd�ysa.
ondan sonraki	eleman� al o da dosyan�n size'� olsun gibi 
 
 head'�rda ilk okuyacag�m�z 2 byte dosyan�n type'�na giriyomus.sonraki size'�na giriyomus.soonra dosya kac tane renktten olusuyor 
 kac tane genislikte pixel var kac tane yuksekl�kte pixel var yani boyutlar�n� bunlar burdaki mant�kla kodlanm�s.
 art�k siz dosyay� nas�l tasarlad�ysan�z o tasarlanan mant�ga g�re okumak zorundas�n�z
  kural� kim koyduysa o kurala uygun okumak zorundas�n�z mesela ac�n bir pdf dosyas�n�n header'ini inceleyin 
  internetten o pfd okuyucular�n hepsi napmak zorunda o pdf �n versiyonuna g�re bikac tane versiyonu var ------------------------------------------
  o versiyona g�re dosya okumak zorundad�r.yoksa program a�maz.mesela word program� baska hangi uygulamalarda �al�s�yo mesela free ofis programlar�nda cal�s�yor neden cal�s�yor word'un headerini ve yaz�m seklini o uygulamalar destekl�yor word'un uzant�s� ne doc ve docx.bunlar acaba nas�l bir dosyada kodlanm�s onu okuyan k�s� ona sahiptir ona gore dosya ac�l�r.ayn� �ekilde dosyada bir veri degisikli�i update veya yaz yat�g�nda da kaydederken o yazma format�n� kullanmak zorunda.dosya nas�l okunur:nas�l yaz�ld�ysa oyle okunur.
 
 DOSYA NASIL YAZILIR:
 dosya nas�l istiyosan�z oyle yaz�l�r.
 peki nas�l istememiz laz�m:
 Kolay okunacak sekilde,kolay yaz�lacak sekilde,anlaml� olucak rahat olucak bizi yorm�cak sekilde yoksa bunun belli bir �eyi olsa 
 butun dosyalar belli formatta yaz�l�r.
 
 Derler ki yan� sunu diyebilirlerdi resim dosyalar� �c�n mesela bu iste png dosyas� png ler ne olsun bundan sonra 0 ve 1 olarak kodlans�n 
 veya 20 tane resim dosyas� var biz bunu en fazla 4 bitle kodlar�z mesela ilk 4 bit onun hangi turden oldugunu soylesin.
 ondan sonra sonraki 4bit size'�n� soyles�n sonraki bilmem kac bit kac pixelden olustugunu soylesin ondan sonra datas� gelsin iste 
 red green red green falan en sona durdurucu bir bit dizisi ekliyelim..
 yani h�c bir �ekilde boyle bir standart yok.opt�mum verimliligi sagl�cak dosya format� nedir yani �yle bir tasarl�yal�m ki okumam�z 
 yazmam�z guncellememiz yap�cag�m�z her i� kolay olsun herkesin kullanabilicegi bir �ey olsun anla��labilir olsun sade olsun.
 
 Dosya nas�l okunur?---------------> yaz�ld�g� gibi okunur.
 Dosya nas�l yaz�l�r?---------------> istendigi gibi. 
 Nas�l isticez ?-------------------->opt�mum sekilde yani performans kriterini goz onunde bulundurarak.
 
 Tabi performanstan kast�m sadece erisim de olmamaml� baz� durumlarda dosyan�n az yer kaplamas� gerekir.
 Az yer kaplamas� i�in i�in i�ine burda "data compression" konusu giriyor.
 
 --file organization diye bizde bir ders var.yani bu cok kapsaml� bir dersttir.--
 
 Dosyalar� "ram uzerinde" degil de sonuca bunu "harddisk �zerinde" sakl�caz.
 Hard-disk uzerinde i�te bi-treeler   2 3 4 tree dedigimiz tree yap�lar� var.
 Veri yap�lar� onlar� kullanarak sakl�cak sekilde bir sistem olusturmas� laz�m. 
   

	mesela size proje verdik C de pdf okuyucu yaz�n diye napmam�z laz�m once pdf okuyucu yaz�caksak
 	ben once pdf 'in bu dosya format�n� bir ogreniyim ayn� surda yapt�g�m gibi eger ben bu dmp y� okucaksam bunun dosya format�n�
  	ogreniyim o dosya format�n� olusturan format neyse o mant�g� bilip ona g�re ben ahmet.pdfreader veya imaj.reader gibi
   	bir �ey yazmam gerekir.    
   
   
   �lk yap�cag�m�z �ey okuma yazmadan once dosyay� acmak dosyay� acarken 2 tane arguman g�nderiyooruz:------------------------
   Birincisi dosyan�n ad�. 
   dosyan�n ad�ndan kast�m�z C'nin i�indeki deneme.c mesela 
   sonra hangi access modu ile eriscez 
   s�md� bu access modlar� okumak i�in m� ac�yosun yazmak i�in m� ac��yosun eklemek i�in m� ac�yosun 
   onun yan�na �oyle scanf'de kulland�g�m�z gibi "r" yazar�z.
   �oyle olur yani:("C://Deneme.c","r").
   fopen fonksiyonu bunu yap�yor bize ve burdan geriye bir pointer donuyor.--------------->bu da file pointer'd�r.
   File pointer neydi FILE dan �retilen FILE struct�n dan uretilen bir �ey :------------->FILE * fp=("C://Deneme.c","r") boyle 
   
   Text streamler i�in ve Binary streamler i�in farkl� access modlar� var.
   
   Text streamler i�in access modlar� slayttaki gibi 
   
   Binary moddakiler de bunlar�n ayn�s� fakat bunlara ek olarak bunun sonuna bir "b" ekleniyor.
   
   �rnegin bu "r" var olan bir dosyay� okumak i�in a� demektir.
   
   Okuma nerden basl�yor dosyan�n bas�ndan basl�yor.
   
   Dosyan�n var olmad�g� durumda hata al�rs�n�z file pointer "null" doner.
   
   	"w"ile act�g�m�zda yazmak i�in yeni bir dosya a� 
   	eger dosya zaten varsa bu i�i bosalt�lacak yani tamamen silinecek.
   	onun i�in cok tehlikelidir.
   	
	write modda acarken dosyan�z� yedekleyin ve bu yazmak i�in ac�lacag� i�in s�f�rdan olusturulacag� i�in 
   	file position dosyan�n bas�na geliyor.
   
   	"a" ile acarsak "a" append demektir.
   	Var olan bir dosyay� append moddda yani ekleme yap�lacak modda a�.
   	
   	Dosyan�n file position'u nerdeyse en sondaysa en sondad�r sonra ne kadar yazd�ysam oraya kadar gelmi�imdir.
	sen dosya pozisyonunu farkl� bi yere tas�san bile dosyan�n sonuna ekliyor.Bu append mod birazc�k boyle bir k�s�t� var 
	
	
	"r+" dosyay� okumak ve yazmak i�in ac dosya pointer'� yani file pointer �nd�cator'u
	baslang�cta dosyan�n bas�na gelir dolay�s�yla ben bu dosyan�n bas�na ne yapabilirim 
	bu file'� yazabiliyorum bak�n a ile yazd�g�mda sona g�t�r�yor beni
	"r+" ile act�g�mda dosyan�n bas�na bir �ey ekliceksem yapabilir.
	  
	"w+" yeni bir dosya olustur okumak ve yazmak i�in yukar�daki sadece yazmak i�indi
	eger zaten dosya var ise bu bosalt�lacakt�r.
	"+" ekleyince buna bir okuma opsiyonu da ekleniyor.
	"a+"bir dosya ac veya yeni bir tane olustur.bu su demek dosya var ise o dosyay� acar yoksa o dosyay� olusturur datay� herhangi bir yerden okuaybilirsiniz.
	fakat yaz�cag�n�z sey ne olucak dosyan�n sonuna olucak diyo.
	  
	Bunlar C programlama dilinin dosya okuma yazma ile alakal� kulland�g� modlar.
	Tabi neler i�in text streamler i�in eger ben bunlar� binary streamler i�in kullan�caksam 
	yaz�cag�m sey mesela r yerine rb ,w yerine wb ,ab,r+b,w+b,a+b gibi olur.
	 
	***************************************  
	|  dosya onceden olmas� gerekir:r,r+  |
	|  eski dosya s�l�n�yor:w,w+          |
	|  dosya okunabiliyor:r,r+,w+,a+      |
	|  dosya yazabiliyoruz:w,a,r+,w+,a+   |
	|  stream sadece sona yollucaksam:a,a+|
	***************************************  
	  
	fopen bir file pointer'� dondurcek bunun tipi "FILE" olucak bunu program i�erisinde kullan�caz. 
	Bizim structtan ya da int pointer'dan fark� var m� pek yok sadece "fp." diyince baz� �eyler gorucez o kadar 
	ama her yerde parametre aktar�m� falan filan heps� ayn�.
	Bu pointer�n�n pointer�n� kullanmaya pek gerek yok. 
	Hata al�rsa null d�nduruyor hatadan farkl� ise null dan farkl� bir �ey donduruyor.
	 
	fprintf() printf'�n hemen hemen ayn�s�d�r sadece printf ile ekrana yazd�g�m�z seyi fprintf ile stream uzerinden istenilen locasyona yazd�r�yoruz.
	 
	�imdi dosyay� act�k operasyonlar�m�za bakal�m �imdi pointer�m�z da var.
	bir karakter okumak i�in kullan�cag�m�z fonksiyonlar getc ve putc okumak veya yazmak i�in. 
	bir sat�r okumak istiyosak gets diye bir fonksiyonumuz vard� bu ne demekti stream oku demekt� bunu nerden okuyodu kullan�c�dan yani comment line uzerinden 
	klavye ile veya okumak yazmak i�indi 
	ben buna fgets,fputs dersem o zaman dosyadan okuma yapmay� sa�l�cam 
	block i�in fread veya fwrite bunlar�n kendilerine gore avantaj ve dezavantajlar� var eger ben bit okumam gerekiyorsa gidip burdan block okumak olmaz veya 
	sat�r okumama gerek yok karakter okumama gerek yok nap�cam yan� bi karakter okuyup 7 biti silecek degilim veya bir block okucaksam i�i garantiye al�y�m 
	tek tek karakter karakter bit bit okuyam o da olmaz ve bu da performans� kotulest�r�r.bunlar dikkat etmemiz gereken seyler.
	 
	 bir diger �ey butun I/O seviyelerinde bir kural streamden bir veri okuyamazs�n�z 
	 o zaman su fseek() rewind() ve fflush() fonksiyonlar�n� rahats�z etmeden kullan�cag�n�z bir yazma fonksiyonu var bunlara bakacaz 
	 fseek dedigimiz belli bir noktaya git 
	 
	 Write moddan read moda gecis program cal�s�rken mumkun degil hangi modda act�ysak acal�m.
	 
	 bu �� fonksiyon sadece I/O fonksiyonudur,buffer'� temizlemek i�in kullan�lan diger fonksiyonlar demi�. 
	 
	Eger memory shortage'�n�z yoksa stream'den bir veri okursunuz onu construct edersiniz ve outputu yazmak i�in output stream'e g�nderebilirsiniz.
	eger herhangi bir memory probleminiz yoksa.
	 
	 input ve output streamleri bir dosyay� g�sterebilir.fakat 	dosya ile i�iniz bitti bunu kapatmak gerekiyor.
	 tekrar yazma oncesinde.dosyay� da kapat�caz yani en son i�imiz bitince.
	 
	closing functionda verdiginiz dosya pointer'�na erisimi kapat�yor.
	ne demek bu streami sonland�r diye i�letim sistemine bir sinyal g�nderiyor.ve buffer'�n temizlenmesi soyleniyor.
	 
	i�letim sistemlerininde processlere tahsis edicegi streamler s�n�rl� say�dad�r.
	bir de streamler kar�s�rsa mevcut olan dosyan�z�n i�erigi bozulabilir.onun i�in dosyay� kapatmak onemlidir.
	eger program�n�z abort ederse kapan�rsa i�letim sistemlerinin �ogu art�k o dosyalar�n cogunu kendisi otomatik kapat�yor.
	fakat bu her zaman da garanti bir �ey degil.yani windows garanti kapat�yor diyoruz ama kapatmad�g� durumlarda olabiliyor.
	 
	 
	//burda bir karakter okucaz 
	//�imdi FAIL ve SUCCESS diye 2 tane �eyimiz var.
	//Bir dosyadan al�caz oburune kopyal�caz iki tane file pointer'�m�z var.
	 
	#include <stdio.h>
	#define FAIL 0 
	#define SUCCESS 1
	
	int copyfile(char * infile, char * outfile){
	FILE *fp1, *fp2;
	
	//burda diyorum ki dosyay� a�.
	//infile yerine bir isim gelicek "rb"'su modda a� yani binary modda eger null ise dosya ac�lamad� hatas�. 
	if ((fp1 = fopen(infile, "rb" )) == NULL) {
	printf("Could not open the input file\n"); return FAIL; 
	}
	
	//ikinci dosyay� ac bunu da "wb" modunda a� birini okumak i�in birini yazmak i�in a� eger a�amad�ysam.
	//eger bu da olmad�ysa dosyay� act�k.
	if ((fp2=fopen (outfile, "wb" )) == NULL) {
	printf("Could not open the output file\n"); fclose( fp1 ); return FAIL;
	}
	
	
	//yukardakilerde olmad�ysa dosyay� act�k feof �zel bir fonksiyondur dosyan�n sonuna geldin mi demektir.
	//hangi dosyan�n fp1 ile g�sterilen dosyan�n sonuna geldin mi veya gelene kadar bu while dongusunu dondur.
	//while ve alt�ndaki putc olan sat�r dongusu bunu dondur demek.putc ile nereye yaz fp2'ye yaz neyi yaz getc ile fp1 den ald�gm�z�.dondu dondu bir karakter ald� bunu yazd�.bu sayede nap�yosunuz dosyan�n i�erigini diger yere yaz�yosunuz.fclose i�imiz bitti.return success dedik suralarda herhangi bir hata olmad�ysa success de donduyse program tamamlan�yor.bu kodu al�p bilgisayar�n�zdaki herhangi bir dosya i�in deneyin mp3 dosyas� i�in falan 
	
	while (!feof( fp1 ))
	putc( getc(fp1), fp2 );
	fclose(fp1); fclose(fp2); return SUCCESS;
	} //to be continued with the main method

  	


getc() return value'sunu kullanam�yoruz yan� dosyan�n sonuna gelip gelmedigini kontrol etmek i�in binary modda eger soyle yazarsak 


int c;
while ((c = getc( fp1 )) != EOF)
putc( getc(fp1), fp2 );

  EOF ile arada baska EOF karakteri varsa o zaman exit edicektir.onun i�in bunu kullanmak cok makul degil.
  
  getc n�n return value'sunu kullanmak yerine yukardak� sekildekin� kullan�p bunun dosyan�n sonuna gelip gelmedigini kontrol etmek daha iyi.
  cunku burda binary dosyalarda EOF ile kar�sacak durumlar olabilir.
  
  bu i�i kesinlikle sa�l�cak seu feof() fonksiyonudur.
  
  ornegin geri kalan�na bakt�g�m�zda 
  
  int main(){
char infl[100], outfl[100]; 
int result;
//birinci dosyan�n ad�n� girin demis 
printf("enter name of the input file\n"); scanf("%s", infl);
//ikinci dosyan�n ad�n� girin demis 
printf("enter name of the output file\n"); scanf("%s", outfl);

//dosyay� kopyala 
result=copyfile(infl, outfl);
if(result == SUCCESS)
printf("input file is copied to the output file \n");
if(result == FAIL)
printf("input file could not be copied to the output file \n");
return 0; 
}
//burda ne okuduk �imdi bir kopya operasyonunda karakter okuduk 

makro olarak kullan�lan getc ve putc bu i�i streamle yapar


fgetc ve fputc ise fonksiyondurlar ve bunlar ayn� i�lemleri yaparlar

putc ve getc zaten makrolar implement edildigi i�in bunlar�n daha h�zl� cal�st�g� soyleniyor.
putc ve getc ,fgetc ve fputc 'nin 2 kat� h�zl�d�r.
Fakat bunlar makro oldugu i�in baz� side effect'lere yatk�nd�r.
�rne�in ben putc i�erisine bi macro cag�rd�g�mda g�nderilen argumana parametreler kar�sabiliyor.
o yuzden putc ve getc kullan�rken dikkat edin 
eger bu arguman�n�z yanl�s argumanlar i�erirse bunun yerine fonksiyon kullanmak daha garantidir.

asag�da bir ornek var mesela:
�imdi macro tan�mlad�k mesela soyle 
#define SQR(x) x*x
ben bunu asag�da cag�r�rken soye cag�r�rsam 
SQR(x) dogru sonucu al�r�m 
fakat soyle cag�r�sam 
SQR(4+3) 
mesela burda 7 nin karesini alm�yor.
soyle yap�yor bu i�lemi
4+3*4+3 soyle yap�yo sonuc da 19 c�k�yor.sonuc boyle s�k�nt�l� geliyor.bu da kullan�c� taraf�ndan delinebiliyor.onun i�in dikkat etmek gerekiyor.


//diger copy operation'u 


#include <stdio.h>
//#include <stddef.h> 
#define FAIL 0 
#define SUCCESS 1
#define LINESIZE 100
int copyfile(char * infile, char * outfile){
FILE *fp1, *fp2; char line[LINESIZE];
if ((fp1 = fopen(infile, "r" )) == NULL) {
printf("Could not open the input file\n"); return FAIL; 
}
if ((fp2=fopen (outfile, "w" )) == NULL) {
printf("Could not open the output file\n"); fclose( fp1 ); return FAIL;
}
//bir gets al�yo burdaki bir line kadar line Size'�m�z su kadarm�s,file pointer'�n� al�cak bu get str�ng� line '�n i�erisine kopyal�cak line da bir eleman,bir karakter dizisi,bu kadarl�k bir eleman oku ve okudugun sey null dan farkl� ise devam et okudugun sey� de al diger dosyaya kopyala geri kalan� main methodu ile ayn� biraz �nce ne okumustuk tek bir byte okumustum bak�n burda asl�nda biz string okuyoruz tam bir blok degil kucuk bir blok ama bloktan kast�m�z struct� dusunun struct'�n s�ze'� kadar veri okumaktan bahsediyoruz. 
//line dan kast�m�z burda bir string karakter dizisi olarak ne oluyor bir karakter dizisi bilgisi okunuyor.fgets okumak i�in yazmak i�in ise fputs
//line �n yan�ndaki ne kadarl�k bir dosyadan okucag�m�z ve hangi dosyadan okucag�m�z 



while (fgets ( line, LINESIZE-1, fp1 ) != NULL)
fputs( line, fp2 ); 
fclose(fp1); fclose(fp2); return SUCCESS;
} //the main method will be the same as the previous example




line I/O:
char *fgets( char *s, int n, FILE stream );

s pointer:Okuyacag�m�z seyi bellekte nereye yaz�caz onun baslang�c eleman� 
N :streamden kac tane karakter okunacag�  
FILE stream:Bu da hangi dosyay� okuyacag�m�z� soyleyen �ey.
�imdi bunu okuyunca neden kod i�inde LINE-1 dediniz soyled�r burda mesela normalde 100 tane bunu okuyunca bunun sonuna otomat�k olarak \0 ekleniyor 
onun i�in 100 tane okuyacaksan 99'unu oku 100.su o olsun bunun oyle bir ozelligi var.
null karakter dedigimiz sey \0'd�r.


dolay�s�yla burdaki n parametresi s'nin size'�ndan 1 eksik oluyor.

eger dosyan�n sonuna ulast�ysak NULL dondurecek 
yoksa dondurecegi sey� fgets'�n dondurecegi seyi okudugumuz string'in first arguman�n� yani string okuyosak s'yi dondurecek bize 

fputs'de
fputs(char *s, FILE stream) 
bunun tam simetrigi diyebiliriz.nap�yo bu karakter dizisini bu file stringini okuyo burda boyut verilmiyo dikkat edin 


gets nedir gets stdin ile karakter okuyan bir fonksiyondur.
ama bunu nerden okuyor? dosyadan okumuyor otomatik olarak bizim comment line dan okuyor.
okudugu zaman sonuna \0 ekliyor.
iki fonksiyonda sonuna null karakter ekliyor.
bu fgets sonland�ran newline karakterini include eder yani kendi i�inde ayr�ca vard�r.


bu fgets'in i�inde bir specification yapmam�z mumkun fakat gets'in i�erisinde nap�yo gets dogrudan newline veya EOF'yi gorene kadar kendisi okuyor.

i�te isim girince mesela ahmet girdik ali girdik su aradaki boslugu gorup onun ��z�m yontemlerinden bir tanesi bunu kullanmak 

block I/O da 
bir data turunu ozellikle structlarda cok kullan�l�yor.block seklinde okumakt�r.veya block seklinde yazmakt�r.bunun i�in kulland�g�m�z fread() ve fwrite() burda bir pointer void pointer neden bir void pointer bu ,void pointer'� ne i�in kullan�yoduk generic bir durum var burda okuyacag�m�z blok karakter de olabilir integer dizisi de olabilri ondan sonra bir struct'�r dizisi de olabilir veya bir struct'�r eleman� da olabilir bunun i�in oyle pointer .diyoruz ki su kadarlik size da bir veri oku bir defa oku 2 defa oku nerden oku file struct'�r�ndan oku F�LE pointer'�ndan oku 
size_t dedigimiz sey integer olucak genellikle biz buralarda sizeof'u cok kullan�r��z.mesela sizeof benim struct'�r�m kadar oku meslea sizeof employee kadar oku veya sizeof integer kadar oku 
ptr dedigimiz onu okuduktan sonra onu nereye yaz�cag�m�z 
su dedigimiz sey de kac defa okunacak bu elemanlar onu soyluyoruz 
fread kac defa eleman okundugunu donduruyor.bu asl�nda 3.argumanla ayn� eger herhangi bir hata olmazsa EOF' e gelmek ile alakall� kac defa okundugunu dondurur.fwrite da onun tam mirror dedigimiz simetrigidir.hemen hemen ayn� argumanlar� al�yor.
bu pointerdan su kadar size kadar veriyi al bir defaya mahsus olmak �zere suraya yaz 2 defa yazarsam pes pese 2 veriyi alm�s olucam 
block size lar� fread ve fwrite i�in I/O operasyonlar�n�n say�s�n� etkilemiyo ornek olarka buffer size'�m�z 1024 byte ise ve block size '�m�z bir read operasyonunda 512 byte ise operat�n system bize 1024 byte getirecek ve bunu bellekte store edicek fakat ilk 512 byte fread taraf�ndan okunacakt�r.
b�r sonraki fread'de bu guzel bir �ey normalde buffer 1024 getirdi duruyo sen fread yapt�n farkl� bir veri g�r�yosun o �u demek fread'�n okudugu veri tamamlanmam�s yani buffer da belli bir k�s�m duruyor.2 seferde gelicek bu birazc�k s�k�nt�l� bu kontrol edilmesi gereken bir �ey 


� size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream); 
� void fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);

bir binary modda blok okuma orneg� 
block size'�m�z� 512 vermi�iz 
onun asag�s�nda bir karakter data �eyi var 

#include <stdio.h>
#include <stddef.h> 
#define FAIL 0 
#define SUCCESS 1
#define BLOCKSIZE 512
typedef char DATA;
//continued in the next slide


//yine ayn� �rnek dosyay� a��yoruz veya a�am�yoruz 


int copyfile(char * infile, char * outfile){
FILE *fp1, *fp2; int num_read; char block[BLOCKSIZE];
if ((fp1 = fopen( infile, "rb" )) == NULL){
printf( "Error opening file %s for input.\n", infile ); return FAIL;
}
if ((fp2 = fopen( outfile, "wb" )) == NULL){
printf( "Error opening file %s for output.\n", outfile );
fclose(fp1); return FAIL;
}

//bloack oku sizeof(DATA) kadar sizeof(DATA) dedigimiz bir karakter kadar ve bu block size'� 512 demis sizeof(DATA) 1 byte degil mi 512 defa 1 byte oku demektir.file pointer'da ve bu okudugumuz sey� blogu.bu blogu al sizeof(DATA) kadarki �eyi yine num_read kadar file pointer'a yaz sonra en son okunan k�sm� tekrar yazmak i�in soyle bir seye ihtiyac duyuyoruz ondan sonra dosyalar kapan�yor.
//sonra herhangi bir hata olduysa FAIL yoksa SUCCESS diye dondur.bunlar daha cok s�ral� erisim ile alakal�yd� 
while ((num_read = fread( block, sizeof(DATA), BLOCKSIZE, fp1 )) == BLOCKSIZE)
fwrite( block, sizeof(DATA), num_read, fp2 );
fwrite( block, sizeof(DATA), num_read, fp2 ); //notice this line!
fclose(fp1); fclose(fp2);
if (ferror(fp1)) { printf( "Error reading file %s\n", infile ); return FAIL; }
return SUCCESS;
} //the main method will be the same as the previous example





	RANDOM ACCESS:
	burda da genelde 3 tane fonksiyon var:
	-fseek 
	-ftell    

	-fseek bizi istedigimiz yere g�turuyor.
	
ftell ise bulundugumuz yerin pozisyon bilgisini veriyor.
	
Bu sayede random access'i saglam�s oluyoruz.
	
fseek in i�erisinde dedik ki pointer tas�nacak burdaki gibi FILE stream'�n pointer'�n� veriyoruz
offset bilgisini veriyoruz ve whence dedigimiz seyi veriyoruz.

bunlar ne bulundugumuz yerden ornegin diyoruz ki itibaren bir onceki noktaya git veya bir sonraki noktaya git. 

int fseek( FILE *stream, long int offset, int whence);

Bulundugun yeri de long int offset g�sterir.
file stream i�erisinden bulundugun yerden offsete +1 dersek bir sonrakine gider -1 dersem bir oncekine gider bir karakter a��s�ndan 

whence dedigimiz sey de start�ng position dosyan�n pozisyon eleman�n� dosyan�n bas�na g�nder dosyan�n bas�na g�nderince
dosyan�n bas�ndan itibaren bas�ndakinden bir sonrakine gec 

	current position dersek nerdeysem onun bir oncesine bir sonrasina git end-of-file'a da gittiginde dosyan�n sonundan itibaren bir gezinti yap


	stat = fseek(fp, 10, SEEK_SET);

mesela  yukar�daki dosyan�n bas�ndan itibaren 10 tane sonraya g�nderiyor.
bu ne olabilir okunacak veya yaz�lacak bir karakter olabilir.
bulundugun yerdesin bundan 10 tane ileriye git oraya ulas. 

	streamler 0.pozisyon ile basl�yor.bu 10.karakter gercekte 11.karakterin yerine geliyor.

fseek den donen deger 0 ise bizim istegimiz yerine getirilmis.
0'dan farkl� bir �ey ise bir hata olusmus demektir.
Bu �e�itli sebeplerden oluyomus �rneg�n ben set'teyken buraya bir eksi bir �ey yazarsam nolur.
bunun eksisi yok ki bu bir s�k�nt�d�r veya and'deyken 1 yazarsam bi sonrakisi yoktur.

bu seek_end genellikle read-only file'larda kullan�l�r.
offset degeri de i�te 0 dan kucuk veya 0'a esit olmal�.
seek_set'de ayn� sekilde 0 dan buyuk veya esit olmal�.
bu file pozisyonunu dikkat edin indicator'u dosyan�n sonuna eklememeye dikkat etmek gerekiyor.

ftell de bir parametresiz fonksiyon bize dosyada kald�g�m�z yeri soyluyor.genellikle biz bunu surdaki sey yerine de kullanabiliyoruz.current pozisyon dedik ya current yerine ftell dersek bulundugun yeri getir demektir.

binary streamlerde bastan itibaren kac�nc� karakterde oldugumuzun bilgisini return eder.
text streamlerde ise bu implementasyona bagl� olarak nerede kald�g�n� nerede oldugunu soyleyen bir fonksiyon cag�r�s�d�r.

personalstat struct'�r�m�z varm�s 
veriler random bir �ekilde duzenlenm�s bunu diyoruz ki isimlerine g�re s�ral�yal�m yan� struct'�r�n i�erisinde isimlerine g�re s�rala ve bunlarda dosyada saklan�yor.

dynam�c memory allocation + file operation + pointer +function bunlar�n hepsinin bir arada oldugu ornekler geliyor.

bunu s�ralamak istiyoruz bunu s�ralamak i�in dosya i�erisinde s�ralamak cok zor bir �ey
onu �nce bellege al�caks�n bellekte s�ralay�p dosyaya geri yaz�caks�n.



	oncelikle demis ki data'm�z su sekilde olucak bizim datan�n format�n�n boyle oldugunu soylem�s bunlara bir index verdigimizi dusunelim.struct i�erisinde okuduk structta indexlerimiz var s�ralad�ktan sonra bunlar� isme g�re s�ralad�ktan sonra su sekilde dosya da g�r�lmesini isticez tabi diger bilgilerde saklan�cak sekilde diger bilgiler nas�l saklan�cak �imdi biz structlarda s�ralama yapt�k s�ralad�g�m�z struct� buraya oldugu gibi blok seklinde yazarsak nolur dosyan�n i�erisinde s�ralanm�s g�r�r�z.

	bunun i�in ilk once struct'� tan�mlamam�z gerekiyor.bu asl�nda butun yaz�l�m projelerinde yap�lan sey oncelikle data base iliskisel semas� s�ralan�r.biz burda bas�t bir database'i file larla olusturucaz.ve bu database ne tarafta HDD taraf�ndan bize ne laz�m ram uzer�nde cal�sacak 


2.56.40










