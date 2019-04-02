#include "main.h"
#include "sub.h"

int make_merge_data[MAX] = { 0 };

void swap(int i, int j) {
	int temp = 0;

	temp = data[i];
	data[i] = data[j];
	data[j] = temp;
}

void bubble_sort() {
	for (int i = N-1; i > 1; i--) {
		for (int j = 0; j < i; j++) {
			if (data[j] > data[j+1]) {
				swap(j,j+1);
			}
		}
	}
}

void selection_sort() {
	int max_value = 0;

	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (j == 0) {
				max_value = j;
				continue;
			}
			else if (data[max_value] < data[j]) {
				max_value = j;
			}
		} // 최대값을 찾는 과정
		swap(max_value, i);
	}
}

void insertion_sort() {
	for (int i = 0; i < N; i++) {
		int temp = data[i];

		for (int j = i - 1; j >= 0; j--) {
			if (data[j] > temp) {
				data[j + 1] = data[j];
			}
			else {
				data[j + 1] = temp;
				break;
			}
		}

		if (data[0] > temp) {
			data[0] = temp;
		}
	}
}

void merge_make(int data[], int p, int q, int r) {
	int i = p, j = q + 1, k = p;

	while (i <= q && j <= r) {
		if (data[i] <= data[j]) {
			make_merge_data[k] = data[i];
			i++, k++;
		}
		else {
			make_merge_data[k] = data[j];
			j++, k++;
		}
	}

	if (i > q && j <= r) {
		while (j <= r) {
			make_merge_data[k] = data[j];
			j++, k++;
		}
	}
	else if (i <= q && j > r) {
		while (i <= q) {
			make_merge_data[k] = data[i];
			i++, k++;
		}
	}

	for (int i = p; i < r + 1; i++) {
		data[i] = make_merge_data[i];
	}
}

void merge_sort(int data[], int p, int r) {

	if (p < r) {
		int q = ((p + r)) / 2;
		merge_sort(data, p, q);
		merge_sort(data, q + 1, r);
		merge_make(data, p, q, r);
	}
}

void quick_sort(int data[], int p, int r) {
	int q = 0;

	if (p < r) {
		switch (status)
		{
		case 4: {
			q = partition_ver1(data, p, r);
			break;
		}
		case 5: {
			q = partition_ver2(data, p, r);
			break;
		}
		case 6: {
			q = partition_ver3(data, p, r);
			break;
		}
		}
		quick_sort(data, p, q - 1);
		quick_sort(data, q + 1, r);
	}
}

int partition_ver1(int data[], int p, int r) {
	int x = data[r];
	int i = p - 1;

	for (int j = p; j < r; j++) {
		if (data[j] <= x) {
			i++;
			swap(i, j);
		}
	}
	swap(i + 1, r);
	return i + 1;
}

int partition_ver2(int data[], int p, int r) {
	int temp[3] = { p,(p + r) / 2,r };

	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (data[temp[i]] > data[temp[j]]) {
				int value = temp[i];
				temp[i] = temp[j];
				temp[j] = value;
			}
		}
	}

	swap(r, temp[1]);

	int x = data[r];
	int i = p - 1;

	for (int j = p; j < r; j++) {
		if (data[j] <= x) {
			i++;
			swap(i, j);
		}
	}
	swap(i + 1, r);
	return i + 1;
}

int partition_ver3(int data[], int p, int r) {
	int temp = (rand() % (r - p + 1)) + p;
	swap(r, temp);

	int x = data[r];
	int i = p - 1;

	for (int j = p; j < r; j++) {
		if (data[j] <= x) {
			i++;
			swap(i, j);
		}
	}
	swap(i + 1, r);
	return i + 1;
}


int analysis_heap(int i) {

	if (2 * i + 2 > N - 1) {
		return (2 * i + 1);
	}
	else if (data[2 * i + 1] > data[2 * i + 2]) {
		return (2 * i + 1);
	}
	return (2 * i + 2);
}

void max_heapify(int i) {

	if (2 * i + 1 > N - 1 && 2 * i + 2 > N - 1) {
		return;
	}

	int k = analysis_heap(i);

	if (data[i] >= data[k]) {
		return;
	}

	swap(i, k);
	max_heapify(k);
}

void heap_make() {
	for (int i = N / 2; i >= 0; i--) {
		max_heapify(i);
	}
}

void heap_sort() {

	heap_make();

	for (int i = N - 1; i > 0; i--) {
		swap(0, i);
		N--;
		max_heapify(0);
	}
}