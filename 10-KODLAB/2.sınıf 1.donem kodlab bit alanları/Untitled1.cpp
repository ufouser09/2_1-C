BIT ALANLARI (BITFIELDS) KAVRAMI
C programýnýn en önemli özelliklerinden biri hafýzanin en küçük noktalarýna (bittere) eriþim saðlayabilmesidir.

 Bu özellik sayesinde çok küçük bellek alarki sistemlerde çalýþabilecek küçük ve hýzlý uygulamalar geliþtirebiliriz.
 
 Bitliside yapýsý buna olanak sunan yapýlardan bir tanesidir.
 Önceki bölümlerde bir tam sayý deðiþkenin bellekte (genellikle) 4 bayt (32-bit) yer kapladýðýný söylemiþtik.
 
 Örneðin; bir kiþinin yaþýný tutmak istiyoruz.
  
  Yas deðeri mantýksal olarak negatif deðer alamaz ve bir kiþi en fazla 100 küsur yaþar. Bir kiþinin 128 yaþýna kadar yaþayamayacaðýný varsayarsak aslýnda ya
deðiþkeni için sadece 7 bit yeterlidir (2 = 128). Yaþ deðerini tam sayý olarak
tuttuðunuzda geriye kalan 25 bit israf edilmiþ demektir.
Benzer þekilde bir kiþinin doðum tarihini gun, ay, y21 olarak 3 tam say
deðiþkende tuttuðunuzu varsayalým.
• Gün deðeri 1 ile 31 arasýnda deðiþir. Yani gün deðeri için aslýnda 5 bite ihtiyaç
vardýr. 5 bit ile O'dan 31'e kadar olan sayýlarý ifade edebiliriz (2932). Bir baþka
deyiþle 5 bit ile 32 farklý sayý deðerini kullanabiliriz.
• Benzer þekilde ay deðeri de 1 ile 12 arasýnda deðiþir. ay deðeri her zaman
16'dan küçük olduðu için 4 bit yeterlidir(24 = 16).
- Benzer þekilde (milattan sonra doðan kiþiler için) yýl deðeri Oila 2048 yýlýna kada
deðiþtiðini farz edersek (2" = 2048) yil için de bize 11 bit'in yeterli olduðunu
söyleyebiliriz. (Programýmýzýn 2048 yýlýna kadar çalýþacaðýný var sayýyoruz 2048
yýlýndan sonra kullanmak istersek yýl için 12 bit'e ihtiyacýmýz olacaktýr. O zaman de
programýmýz 4096 yýlýna kadar geçerli olur.)


Dolayýsýyla gün ay ve yýl için toplamda 5 + 4 + 11 = 20 bit yeterliyken biz
bu deðerleri 3 farklý tam sayýda tuttuðumuzda toplamda 12 bayt'a karþýlýk
gelen 96 bitlik bir alanla karþýlaþýlacaktýr. 72 bitlik bir alan boþuna kullanýlmýþ
demektir. Bu kullanýmý düþürebilmek için C programlama dili Bitfields adý
verilen bir yapý getirmiþtir.
sadece
ahip bir
Bu yapý ilgili deðiþkenin kaç bit yer kaplayacaðýný tanýmlayabilmemize
olanak tanýr. Bitfield tanýmlayabilmek için struct yapýsýna ihtiyacýmýz vardýr.
Tanýmlama esnasýnda her bir üye deðiþkenin adýndan sonra kaç bit deðer
kaplayacaklarý, iki nokta iþaretinden sonra belirtilmelidir:
	
	
typedef struct{
	unsigned int gun:5;
	unsigned int ay:4;
	unsigned int yil:11;
}DogumTarihi;



yukarýda DogumTarihi isimli bir yapý görmektesiniz.
bu yapý kullanýlarak olusturulmus dogumTarihi isimli bir degisken bellekte toplamda 20-bit'lik bir alan kaplar.
bu degiskenin bellekteki görüntüsü asagýdaki gibidir.

-
-Resim

	
