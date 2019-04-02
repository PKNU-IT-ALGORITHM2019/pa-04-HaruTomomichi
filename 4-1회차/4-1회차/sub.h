#pragma once
#include <stdio.h>

void swap(int i, int j);

void bubble_sort(); // 우향 / 최소값 정렬

void selection_sort(); // 좌향 / 최대값 정렬

void insertion_sort(); // 비교값은 우향 / 범위는 좌향 / 최대값 정렬

void merge_make(int data[], int p, int q, int r);

void merge_sort(int data[], int p, int r);

void quick_sort(int data[], int p, int r);

int partition_ver1(int data[], int p, int r);

int partition_ver2(int data[], int p, int r);

int partition_ver3(int data[], int p, int r);

int analysis_heap(int i);

void max_heapify(int i);

void heap_make();

void heap_sort();
