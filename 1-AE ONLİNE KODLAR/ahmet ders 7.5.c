/*
N tane complex bir sayi saklamak istiyorum yani bir dizi olucak mesela ama bu N taneyi bellekte pe� pe�e saklamak m�mk�n degil
cunku o kadar yerimiz yok
linked list ile array fark� burda ortaya c�k�yor
mesela N elemanl� malloc ile bir array olusturduk 
bunlar bellekte biti�ik olarak s�ralan�r
ama linked listte ayr� ayr� yerlerde olur 
biti�ik olmad�g� i�in bir yerden baslay�p teker teker elemanlar� gezmem laz�m
mesela en bastaki eleman head olarak adland�r�l�r 
ondan sonra 2.eleman 3.elemanlar� bir yerde saklamam laz�m
i�te burda pointer mant�g� ile structlar birbiriyle saklanabiliyor

linked listler soyle oluyor mesela bi tanesi bir integer imaj�ner tutuyor bir tanesi integer reel tutuyor bi de node tutuyor
bu node bir sonraki node un adresini tutuyor
en sondaki elemanda son yerinde node degil art�k null tutuyor
bu sayede N elemanl� bir �ey saklanabilir

linkli listin i�inde birden fazla data saklayabiliriz ama mutlaka bir sonraki dugumun pointer�n� sakl�caz
en sondaki eleman null u g�stercek ama linked list i�indeki baska bir eleman� da g�sterebilir boylece circular linked list olusturursunuz
linked listin bir tek yonlusu vard�r bi de c�ft yonlusu vard�r
�ift yonlusune double l�nked list diyoruz

tek yonlude mesela *next tutuyorduk ya c�ft yonlusunda *prev de tutyoruz ayn� yerde b�ylece ileri geri yapmak daha kolay oluyor bizim i�in
burda bellekten kay�p veriyoruz ama

linked listte ilk eleman head dir
dizinin ilk eleman�n� g�steren pointer head dir

array[i]
*(array+i)

(array)
array++;
burda yukardakinden farkl� olarak ilk eleman�n adresini kaybediyoruz

en son dugum null u g�sterir

dizinin sonuna daha kolay ula�abilmek i�in *last pointer kullan�r�z diziye ekleme c�karma yapt�g�m�zda bu last pointer� ayr�ca guncellersiniz bu da head gibi ayr� bir pointerd�r

mesela bir dizide ekleme c�karma yapmak istedigimizde noluyordu surekl� elemanlar� shift ediyorduk ama bu linked listte buna gerek yok
linked listte ekleme c�karmalarda shift yapm�yoruz o yuzden dizilerde olan ekleme c�karmadan daha kolay


//2.05.11 de kald�k
