#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma warning(disable:4996)

#define MAX 100000

typedef struct WEB {
	char *ip;
	char *time;
	char *url;
	char *status;
}WEB;

WEB data[MAX];

bool word_analysis(char *input);

void read_data(char *token);

void data_save(char temp[], int i);

void sort_data(char *token);

void print_data();