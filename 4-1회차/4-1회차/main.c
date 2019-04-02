#include "main.h"
#include "sub.h"

int data[MAX] = { 0 }, N = 0, status = 0;

bool test = true; // true이면 랜덤 / false라면 reverse

void main() {

	srand((unsigned)time(NULL));

	print1();
	print2();
	print3();
	printf("Process Complete\n");
	
	getchar();
	getchar();
}

void print1() {

	printf("\t\tRand1000\tReve1000\tRand10000\tReve10000\tRand100000\tReve100000\n");

	status = 0;
	printf("Bubble   \t");
	print_all();

	status = 1;
	printf("Selection\t");
	print_all();

	status = 2;
	printf("Insertion\t");
	print_all();
}

void print2() {

	status = 3;
	printf("Merge    \t");
	print_all();

	status = 4;
	printf("Quick1    \t");
	print_all();

	status = 5;
	printf("Quick2    \t");
	print_all();
}

void print3() {

	status = 6;
	printf("Quick3    \t");
	print_all();
}

void print_all() {

	printf("%8lf\t", test_start(1000));

	test = false;
	printf("%8lf\t", test_start(1000));

	test = true;
	printf("%8lf\t", test_start(10000));

	test = false;
	printf("%8lf\t", test_start(10000));

	test = true;
	printf("%8lf\t", test_start(100000));

	test = false;
	printf("%8lf\n", test_start(100000));
}

double test_start(int temp) {
	N = temp;
	double time = 0.0;
	
	for (int f = 0; f < 10; f++) {

		test_make();

		clock_t start, end;
		start = clock();

		switch (status) {
		case 0: {
			bubble_sort();
			break;
		}
		case 1: {
			selection_sort();
			break;
		}
		case 2: {
			insertion_sort();
			break;
		}
		case 3: {
			merge_sort(data, 0, N - 1);
			break;
		}
		case 4: {
			quick_sort(data, 0, N - 1);
			break;
		}
		case 5: {
			quick_sort(data, 0, N - 1);
			break;
		}
		case 6: {
			quick_sort(data, 0, N - 1);
			break;
		}
		}

		end = clock();

		time += ((double)(end - start) / CLOCKS_PER_SEC);
	}

	return time / 10.0;
}

void test_make() {
	if (test) {
		for (int i = 0; i < N; i++) {
			data[i] = rand() % N;
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			data[i] = N - i;
		}
	}
}