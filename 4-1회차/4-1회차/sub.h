#pragma once
#include <stdio.h>

void swap(int i, int j);

void bubble_sort(); // ���� / �ּҰ� ����

void selection_sort(); // ���� / �ִ밪 ����

void insertion_sort(); // �񱳰��� ���� / ������ ���� / �ִ밪 ����

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
