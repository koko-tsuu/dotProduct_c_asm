#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

extern double asmDotProduct(long long int n, double A[], double B[]);

double dotProduct(long long int n, double A[], double B[]) {
	double sdot = 0;
	double dTemp = 0;

	int i = 0;
	for (i = 0; i < n; i++) {
		dTemp = A[i] * B[i];
		sdot += dTemp;
	}

	return sdot;
}

int main() {
	int userInput = 0;

	//results
	double total = 0;
	double sdot = 0;

	//util
	clock_t start, end;
	
	//vector size
	long long int n = 67108864;
	// 2^20 = 1048576
	// 2^24 = 16777216
	// 2^26 = 67108864

	while (userInput != 5) {
		
		double* A = malloc(sizeof(double) * n);
		double* B = malloc(sizeof(double) * n);

		int i;
		for (i = 0; i < n; i++) {
			A[i] = (double)((i + 1) % 100);
			B[i] = (double)((i + 1) % 100);
		}
		

		printf("[1] C kernel\n");
		printf("[2] Assembly kernel\n");

		printf("[5] End\n\n");
		printf("Choose sDot kernel operation: ");
		scanf_s("%d", &userInput);
		
		if (userInput == 1) {
			start = clock();
			sdot = dotProduct(n, A, B);
			end = clock();

			total = (double)(end - start) / CLOCKS_PER_SEC;

			printf("Total time : %lf\n", total);

			printf("Dot product: %lf\n", sdot);


		}
		else if (userInput == 2) {

			start = clock();
			sdot = asmDotProduct(n, A, B);
			end = clock();

			total = (double)(end - start) / CLOCKS_PER_SEC;

			printf("Total time : %lf\n", total);

			printf("Dot product: %lf\n", sdot);
			

		}
		printf("\n__________________________\n\n");

		free(A);
		free(B);
	}

	
	return 0;
}
