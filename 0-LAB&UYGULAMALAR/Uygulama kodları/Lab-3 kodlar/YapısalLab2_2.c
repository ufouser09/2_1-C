#include <stdio.h>
#include <stdlib.h>

int f();

int main()
{
	
	int current_size = 3;
	int *Sepet = (int *) malloc(current_size * sizeof(int));
	int i = 0;
	srand(time(NULL));
	Sepet[i++] = f();
	Sepet[i++] = f();
	while(Sepet[i-2] + Sepet[i-1] != 12)
	{
		Sepet[i++] = f();
		if (i == current_size)
		{
			current_size += 3;
			Sepet = (int *) realloc(Sepet, current_size * sizeof(int));
		}

	}
	int j;
	printf("Dizi elemanlari: ");
	for (j = 0; j < i; j++)
	{
		printf("%d ", Sepet[j]);
	}
	printf("\nDizinin Eleman Sayisi = %d \nDizinin Hafizada Kapladigi Alan = %d \n", i, current_size);
	free(Sepet);
	return 0;
}

int f()
{
	return rand()%6+1;
}


