#include<stdio.h>
#include<stdlib.h>
#include<time.h>


double dotProduct(int n, double A[], double B[]){
	double sdot = 0;
	double dTemp = 0;
	
	int i = 0;
	for (i = 0; i < n; i++){
		dTemp = A[i] * B[i];
		sdot += dTemp;
	}
	
	return sdot;
}

int main()
{
	clock_t start, end;
	double total;
	int n = 33554432;
	int i;
	
	double sdot;
	double *A = malloc(sizeof(double) * n);
	double *B = malloc(sizeof(double) * n);
	
	for (i = 0; i < n; i++){
		A[i] = (i + 1) % 100;
		B[i] = (i + 1) % 100;
	}
	
	start = clock();
	sdot = dotProduct(n, A, B);
	end = clock();

	total = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Total time : %lf\n", total);
	
	printf("Dot product: %lf", sdot);
	
	free(A);
	free(B);
	getch();
	return 0;
	
}
