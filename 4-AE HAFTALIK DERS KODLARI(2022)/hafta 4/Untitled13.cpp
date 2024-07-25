/* 10prg07.c:  geri donus degeri gosterici olan fonksiyon */

#include <stdio.h>

double* maxAdr(double a[], int boyut){
  double  ebd =  a[0];
  double *eba = &a[0];
  int i;
  for(i=1; i<boyut; i++){
    if(a[i]>ebd){
      ebd =  a[i]; // en b�y�k deger
      eba = &a[i]; // en b�y�k adres
    }
  }
  return eba;
}


int main()
{
  double x[6] = {1.1, 3.3, 7.1, 5.4, 0.2, -1.5};
  double *p;
  int k;
  // indis, dizi ve adresini ekrana bas
  for(k=0; k<6; k++){
    printf("%d %lf %p\n", k, x[k], &x[k]);
  }

  p = maxAdr(x,6);

  printf("En b�y�k deger: %lf\n", *p);
  printf("En b�y�k adres: %p \n",  p);
  printf("En b�y�k konum: %d \n",  int(p-&x[0]));

  return 0;
}
