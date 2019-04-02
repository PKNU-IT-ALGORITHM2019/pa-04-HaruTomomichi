#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#pragma warning(disable:4996)

#define MAX 2000000

extern int data[MAX], N, status;
// 0 : bubble / 1 : selection / 2 : insertion / 3 : Merge
// 4 : quick (마지막 값) / 5 : quick (톱 오브 스리) / 6 : quick (랜덤)
// 7 : 힙 소트 / 8 : 라이브러리 qsort

void print1();

void print2();

void print3();

void print_all();

double test_start(int temp);

void test_make();

