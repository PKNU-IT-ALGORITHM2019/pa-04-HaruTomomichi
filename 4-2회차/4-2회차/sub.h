#pragma once
#include <stdio.h>

#pragma warning(disable:4996)

typedef struct IP {
	int first;
	int second;
	int third;
	int fourth;
}IP;

typedef struct TIME {
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
}TIME;

void make_time(WEB a, WEB b);

void make_ip(WEB a, WEB b);

int compare_data_by_ip(const void *p, const void *q);

int compare_data_by_time(const void *p, const void *q);

void sub_sort_data(int status, int N);