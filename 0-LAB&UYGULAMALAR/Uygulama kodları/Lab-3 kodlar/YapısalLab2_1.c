#include <stdio.h>
#include <stdlib.h>

int f(int N);

int main()
{
	int N = 7;

	int *A = (int *) calloc(2, sizeof(int));
	int current_length = 2;
	printf("N = %d\n", N);
	A[0] = N;
	int i = 1;
	while (N != 1)
	{
		N = f(N);
		A[i++] = N;
		if (i == current_length)
		{
			current_length *= 2;
			A = (int *) realloc(A, current_length * sizeof(int));
		}
	}
	int j;
	
	printf("Dizi elemanlari: ");
	for (j = 0; j < i; j++)
	{
		printf("%d ", A[j]);
	}
	printf("\nDizinin Eleman Sayisi = %d \nDizinin Hafizada Kapladigi Alan = %d \n", i, current_length);
	free(A);
	return 0;
}

int f(int N)
{
	if (N % 2 == 0)
		return N / 2;
	else
		return 3*N + 1;
}



