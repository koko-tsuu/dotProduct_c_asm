#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

extern double asmDotProduct(long long int n, double A[], double B[]);

int main() {
	int n = 33554432;
	double *A = malloc (sizeof(double) * n);
	double *B = malloc (sizeof(double) * n);
	int i;
	for (i = 0; i < n; i++) {
		A[i] = (i+1)%100;
		B[i] = (i+1)%100;
	}

	clock_t start, end;
	double total;
	start = clock();
	double sdot = asmDotProduct(n, A, B);
	end = clock();

	total = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Total time : %lf\n", total);

	printf("dot product: %lf\n", sdot);
	free(A);
	free(B);
	getch();
	return 0;
}