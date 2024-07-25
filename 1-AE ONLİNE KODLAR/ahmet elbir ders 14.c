Proje olusturmak �zellikle C'de cok zor bir �ey degil ama bunu yaparken projenizi modullerden meydana getirmeniz gerekir.

Bir projeniz birden fazla C dosyas� ve bunlarla alakal� birden fazla header dosyas�ndan olusabilir.


Bunun yonetilmesi ile alakal� konusal�m:
Burda baz� kavramlar var mesela "prepprocessor" dedigimiz ve baz� "macro definetionlar�n�" ve baz� "sabitlerin" tan�mland�g� bolum. 

Bu prepprocessor sayesinde biz C dosyalar�nda baz� i�lemleri macro olarak s�ralay�p i�leri k�saltabiliyoruz.

Compiler herhangi bir C kodunu "assembly" koduna donusturuyor.

Assembler olusturulmus assembly kodunu makine koduna donusturuyor.

Yani C kodunu derledigimiz zaman baz� kodlar makine koduna �evrilir baz� kodlar �evrilmez 
�zellikle daha onceden derlenmis olan kodlar. 

Tekrar derlenmez burda assemblerlar derlenmis olan kodlar�n baglanmas�n� saglarlar. 

Linker da bu derlenmis olan kodlar� getirip bizim program�m�za bagl�yo ve sonunda "executable" dosya haline getiriliyor.

Demek burada biz bir kod yazsak printf scanf gibi onu derlesek bir yerde saklasak program� s�f�rdan olustururken derlerken 
tekrar onu derlemeye gerek yok eger bir degisiklik yapmad�ysak boyle bir iyi bir taraf� da var 


Program niye split edilir parcalan�r :
Daha kolay yonetmek i�in tekrar kullan�labilirli�i artt�rmak i�in �rneg�n bu onceden cok yap�l�yodu

kendi "data struct'�r�n�z�" olusturabiliyorsunuz.

�zellikle "header file'lar�" biz fonksiyonlar�n prototiplerini saklamak i�in data struct'�r�n definitionu i�in struct'�rlar�n 
definitionu "typedef" ile oluyodu macro definitionlar�n� saklamak i�in gloabal datalar� saklamak i�in kullan�yoruz 
header file ile data.h uzant�l� stdio gibi standart input output dosyas� gibi 


bu program�m�zdakilerden bi tanesi de main fonksiyonunu bulunduran dosyam�z oluyor.
ve bu ilgili dosyalar� include ile ekliyorduk bu ilgili header dosyas� ve C dosyas�n�n birbiri ile ayn� isimde olmas� gerekir.


�nclude komutunun 2 tane formu var: 

"make file" kendisine verilen parametrelerle bi defa derlenmisse ve degistirilmemisse o dosyay� tekrar derlemeye gerek duymuyor.
ornegin sizin projeniz su headerlardan ve C dosyalar�ndan olussun 


Dependency'si nas�l cal�s�r:
Siz program�n�z� test ederken i�erisinde bir bug tespit ettiniz su io nun gittiniz napt�n�z 
bunu edit yapt�n�z edit yapt�ktan sonra bu edit yapt�g�n�z k�s�mdan etkilenen nolucak bunlar etkilenecek 
bunlardan da projenin geneli etkilenencek ve projenin tamam�n�n guncellenmesine ihtiyac duyucaz bu buyuk bir problem 
ve boyle bir dependecy durumu ortaya ��k�yor.

�rneg�n data.c de yap�lan bir degisiklik data.h da yap�lan degisiklik bunlar� etkiliyor.
Ondan sonra mainde yap�lan kimleri etkiliyor.
Problemli bir �ey i�te bundan kac�nmak i�in "make file" kullan�l�yor.

�u mesela ornek bir make file'dir.
proje dedigimiz sey neleri olusturacak.
Burdaki bag�ml�l�k durumuna g�re yaz�yoruz proje dedigimiz sey data.obje dosyas�.
main.obje dosyas� io.obje dosayas�ndan olusacak gcc derleyicisine dicez ki data.o yu main.o yu io.o yu al bunlar� bir araya getir.
proje1 executable file'�n� olustur d�yoruz.

bu data.o'nun da nas�l olusacag�n� da surada tan�ml�yoruz.

data.o,data.c ve data.h'�n gcc derleyicisinden data.c'nin derleyicisiyle elde edilecek bir dosyad�r.
main.o i�in ayn� �ey ve io.o i�in ayn� sey  

Biz art�k kodu derlerken s�rekli bunu yazm�caz nap�caz sadece bu "make file'�n" kendisini cag�r�caz. 	

"make komutu" ile bu yazd�g�m�z "makeFile'�n" ad�n� cag�r�caz.

Bizim "dev.c" veya farkl� ideler de ayn� �eyi yap�yolar 

ve burda genellikle "Makefile" ismi kullan�l�r boyle bir gelenekselle�mi� bir durum vard�r.

�ok uzun dosyalarda bu makefile bi kere yaz�l�r ve derlemede kullan�l�r. 

�zellikle "eski i�letim sistemlerinde" ve "g�m�l� sistemlerde" bu hala kullan�l�yor.

Bu "makefile" i�erisinde "macro" tan�mlanabiliyor.

Bu da makeFile'�n programlanmas� ile alakal�.

Diyoruz ki ��yle bir obje diye bir degiskenimiz var.
Bu obje'y� macro gibi dusunucez.
Nerede obje g�r�rsek bu objenin kars�s�na proje su alanlardan olusacak sonra bu alanlar birle�icek projenin dosyas�n� olusturacak.

Bu nerede kars�n�za gelir g�m�l� sistemlerde kars�m�za gelir.

Her �eyiyle kendi yazd�g�n bir program olucaksa burda bu onemli.

C prepprocessleri program cal�smadan once kodlanm�s bolumler.

Biz burda genellikle "#define" ve "#include'u" kulland�k

Fakat bunun extra komutlar� var.

Bunlar�n bir k�sm�n� gorduk baz�lar�n� gormedik.

Macro dedigimiz sey fonksiyon benzeri bir yap�yd� fonksiyondan fark�: 
Fonksiyon cagr�s� geldiginde biz fonksiyonun bulundugu yere jump yap�yoduk.

Assemblydeki kars�l�g�nda boyle gidiyoduk.
�ste burda baz� bilgiler nerde saklan�cak "stack bolgesinde" saklan�yordu.
�zellikle "program counter flag register" o anki bulundugumuz program�n degiskenlerinin degerleri bunlar stack' e at�l�yor.
Bunun belli avantajlar� oldugu gibi bu stack'e atma i�i birazc�k dezavantaj 
cunku surekli bir fonksiyon cagr�s� yapmak s�rekli dallanma yapmak demektir.
O stack'e kopyalama sureci ve tekrar geri donme sureci birazc�k uzayabiliyor.

C de makro yazarken normal "noktal� virgul kullanmadan" birden fazla sat�rda makro yaz�labiliyor.
Eger bir makronuz devam edicekse sonuna bir " \ " ekleyip buna devam ettirebiliyorsunuz.
Burda bir string �zerinde bir i�lem yap�lm�s atama i�lemi 
boyle birden fazla sat�r� kapsayan bir sey olusturulmus ve sonuna noktal� v�rgul koymuyoruz.

Bir atama yaparken e�ittir de koymuyoruz ve bu bir "substitution'dur".
Bu genelde soyle ozetlenir nas�l bir fonksiyon cagr�ld�g�nda fonksiyon cagr�ld�g� yere gidiyorsak macro ifadesi yaz�ld�g�nda 
yani �a��r�m yap�ld�g�nda "call" i�lemi yani biz ona gitmiyoruz o bizim istedigimiz yere geliyor.

yani nerde biz 
#define BUFF_LEN 512 
diye bir �ey kullansak onun yerine bu kopyalan�yor.

Asl�nda bir genisletmedir.

Program derlendiginde program�m�z�n yaz�lm�s hali ile derlenmis hali aras�nda cok ciddi fark bulunur. 

Nerede dosya a�ma ile alakal� bir i�lem yapsan�z bu yer degistirecek "substitution" yap�cakt�r.

O nedenle bazen dezavantajlar da oluyor.

�zellikle biz kendi program�m�zda baz� isimlendirmeler veya baz� k�saltmalar da bunu cok yap�yoruz i�te BUFFER_SIZE '�m�z 256 olsun.
Bunu fonksiyon benzeri bir macro haline getirmek i�in de macro'nun ad�n� verdikten sonra da al�nacak argumanlar� parantez ile 
normal bir fonksiyon gibi al�yoruz. 

Kars�na da bir bosluk b�rak�p macro'nun g�vdesini yaz�yoruz.
burada cok fazla yap�lan hata i�in sonunda noktal� v�rgul koymak birinci hatam�z 
ikinci hatam�z macro definition da e�ittir kullanmak.
i�te bu bi �ekilde cozulebilir.

���nc� hatam�z "side effect" dedigimiz hatam�z genel parametreleri guvenl� bir �ekilde almak i�in  
su parantezi macronun govdesinde her bir degiskeni kendi i�inde ayr� bir degiskene almak i�in kullanmam�z gerekiyor.nedeni a��klanacak 

#define MUL_BY_TWO(a) ((a)+(a))



ornegin say�y� 2'ye katlayan bir �ey yap�lm�s bunu cag�r�m� kod i�inde boyle olucakt�r.
bu kod i�inde boyle olucakt�r ne demek substitution biz buraya gitmicez 

j=MUL_BY_TWO(5);
f=MUL_BY_TWP(2.5);


iki say�n�n hangisinin buyuk oldugunu bulan bir program macro definition hangisinin 
kucuk oldugunu burda dikkat edin gelen parametreler 

#define min(a,b) ((a)<(b)?(a):(b))

eger ben macro'yu su sekilde cag�rsam a'n�n degeri de 3 gibi bir �ey olsun macro cag�r�lmas� demek oraya 3 -1 =2 gidicek demek degil.
soyle gidiyor 3-1   +  3-1 gidiyor eger ben burda toplama �rnegini yaparsak bunun bi etkisini gormeyiz.burda hepsi e�it oncelikli 
operatorler oldugu i�in bir problem olm�cak ama arada bir carpi olsayd�
o zaman nolurdu 3-1 * 3-1 mesela burda sonuc -1 kal�cakt� i�te boyle bir side effect'i onlemek i�in gelen 
parametrelerin parantez i�inde g�nderilmesi gerekiyor.


j=MUL_BY_TWO(a-1);


side effect dedigimiz sey su 

#define min(a,b)  ((a)<(b)?(a):(b))

//ben yukar�daki macroyu asag�daki gibi cag�rd�g�mda nolucak i�te su x++'�n once 
//tamamlanmas� bizim i�in oncelikli ise a ve b n�n parametrelerine parantez ekliyoruz 
z=min(x++,y);

z=((x++)<(y)?(x++):(y));


AVANTAJ: 

Macro genel olarak fonksiyondan daha h�zl�d�r.
�unku fonksyion cag�r�m� ile alakal� s�k�nt�dan bizi kurtar�yor.

herhangi bir tip k�s�tlamas� yoktur.
argumanlar uzerinde yani integer i�in float i�in karakter i�in veya struct i�in bunu kullanabiliyorsunuz 
normalde generic bir fonksiyon butun veri tipleri i�in yapmak pek mumkun olmuyor.
Fakat bunu macrolarla daha kolay yapabilme imkan� var i�te bir �ey print ediceksiniz.
Kendisine g�nderilen parametreyi void pointer mant�g�yla yapabilmeyi macrolarla yapabilmek biraz daha mumkun hale gelebiliyor.


Dezavantajlar�na bakt�g�m�zda fonksiyon bi defa derlenir program cal�smadan once siz derlenm�s kodu cag�r�rs�n�z dolay�s�yla herhangi bir extension gerceklesmez ama macrolarda her macro govdesini cag�rmas� tekrar bir kopyala yap�st�r gibi bir durum oluyor kod i�erisinde eger argumanlar�n�z bir side effect i�erecek sekilde tasarlan�rsa baz� problemlere neden oluyor.macrolardaki expanded bazen problem olabilen bir durum normalde fonksiyonlarda bir expanded yok.
macrolar arguman tiplerini kontrol etmiyolar sadece argumanlar�n says�n� kontrol ediyolar sizin gonderdiginiz argumanlar�n dogrulugu sizin sorumlulugunuzda C'nin genelinde oldugu gibi.
bu macrolar �zerinde dogrudan debug yapmak ozellikle step-by-step cal�st�rmak zor bir �ey cunku dogrudan cal�s�r herhangi bir �ekilde alt ad�mlar� anal�z etmek mumkun degil.onun i�in bu da bir dezavantaj'd�r.


genel yap�lan hatalar 
//bu cok yap�l�yor.buna dikkat edelim bu cal�s�r m� cal�s�r nas�l cal�s�r 
#define MAX = 100


for(j=MAX;j>0;j--)

for(j==100;j>0;j--)

bunu yaparsak cal�s�r mesela



macro definition'u remove etmek de mumkun define ettiginiz bir �eyi eger uzerinde bir degisiklik yap�caksan�z 
oncelikle "undefine" edip sonras�nda "redefine" edebiliyorsunuz.

undefine etmek i�in yap�cag�n�z sey su:
#undef min
Bu yukardaki definition'u iptal eder.sonra kendiniz define edebilirsiniz.


built-in-macro

Hangi sat�rday�z hangi dosyaday�z saat kac tarih kac sonra standart anc� standart�n� saglay�p sa�lamad�g�n� s�yluyor.
Bunlar rut�n macrolard�r.

Derleme yaparken conditional compilation da mumkun belli sarta gore derle define edildiyse ona gore derle define edilmediyse once define et oyle derle gibi baz� opsiyonlar var.

#if #elif #else #endif

Yukar�dakilerde herhangi bir �ekilde parantez kullanmaya gerek yok 

ornegin bir debug modunda debug yaparken eger debug tan�ml�ysa surdaki islemleri yap gibi opsiyonla bunu yapabilirsiniz.bunun derlenmesiyle alakal� bilgi al�rken 



bitwise i�lemler hem gomulu sistemlerde hem de uygulamalar�m�zda kars�last�g�m�z bir operatorlerden olusan genellikle bir i�lemler kumesi lojik de kulland�g�m�z bir cok operasyonu burda kullanabiliyoruz.mesela and or not xor bir de rotate i�lemleri ^ bu i�aret ust degildir.
say�lar uzerinde genellikle nap�yoruz i�te bitwise i�lemleri lojikteki i�lemlerin sonuclar�n� g�rmeye cal�s�yoruz burda 


1.00-1.22


