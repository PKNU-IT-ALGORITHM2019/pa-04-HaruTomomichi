#include "main.h"

int N = 0, status = 0;

void main() {

	char input[MAX];

	scanf("%[^\n]", input);

	word_analysis(input);
}

void word_analysis(char *input) {
	char *token;

	token = strtok(input, " ");

	if (strcmp(token, "read") == 0) {
		token = strtok(NULL," ");
		read_data(token);
	}
	else if (strcmp(token, "sort") == 0) {
		token = strtok(NULL," ");
		sort_data(token);
	}
	else if (strcmp(token, "print") == 0) {
		print_data();
	}
	else {
		return; // 사실상 의미는 없다고 생각 = exit
	}
}

void read_data(char *token) {
	FILE *fp = fopen(token, "r");

	// 쉼표로 구분되어 있다 / 수정해야함

	while (!feof(fp)) {
		fscanf(fp, "%s %s %s %s", data[N].ip, data[N].status, data[N].time, data[N].url);
		N++;
	}

	fclose(fp);
}

void sort_data(char *token) {
	if (strcmp(token, "-t") == 0) {
		status = 1;
	}
	else if (strcmp(token, "-ip") == 0) {
		status = 0;
	}
	else if (strcmp(token, "-u") == 0) {
		status = 2;
	}
	else if (strcmp(token, "-s") == 0) {
		status = 3;
	}
	else {
		return;
	}
}

void print_data() {
	// 0 : ip 우선 / 1 : 시간 우선 / 2 : URL 우선 / 3 : 상태 우선
	
	switch (status)
	{
	case 0: {
		for (int i = 0; i < N; i++) {
			printf("%s\n\tTIME : %s\n\tURL : %s\n\tSTATUS : %s\n", data[i].ip, data[i].time, data[i].url, data[i].status);
		}
		break;
	}
	case 1: {
		for (int i = 0; i < N; i++) {
			printf("%s\n\tIP : %s\n\tURL : %s\n\tSTATUS : %s\n", data[i].time, data[i].ip, data[i].url, data[i].status);
		}
		break;
	}
	case 2: {
		// 일단 후에 만들 수도 있기 때문에 공란
		break;
	}
	case 3: {
		// 일단 후에 만들 수도 있기 때문에 공란
		break;
	}
	}
}