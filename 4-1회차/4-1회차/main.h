#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#pragma warning(disable:4996)

#define MAX 2000000

extern int data[MAX], N, status;
// 0 : bubble / 1 : selection / 2 : insertion / 3 : Merge
// 4 : quick (������ ��) / 5 : quick (�� ���� ����) / 6 : quick (����)
// 7 : �� ��Ʈ / 8 : ���̺귯�� qsort

void print1();

void print2();

void print3();

void print_all();

double test_start(int temp);

void test_make();

