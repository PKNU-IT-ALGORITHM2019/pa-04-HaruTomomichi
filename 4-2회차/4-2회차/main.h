#pragma once
#include <stdio.h>

#pragma warning(disable:4996)

#define MAX 100

typedef struct WEB {
	char *ip;
	char *time;
	char *url;
	char *status;
}WEB;

WEB data[MAX];

void word_analysis(char *input);

void read_data(char *token);

void sort_data(char *token);

void print_data();