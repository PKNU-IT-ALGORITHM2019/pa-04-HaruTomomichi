#include "main.h"

int N = 0, status = 0;

void main() {

	char input[MAX];

	while (1) {
		printf("Command : ");
		scanf("%[^\n]", input);

		if (!word_analysis(input)) {
			break;
		}

		getchar();
	}
}

bool word_analysis(char *input) {
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
		return false;
	}
	return true;
}

void read_data(char *token) {
	char temp[MAX];

	FILE *fp = fopen(token, "r");
	fgets(temp, MAX, fp);

	while (!feof(fp)) {
		fgets(temp, MAX, fp);
		data_save(temp,N);
		N++;
	}

	fclose(fp);
}

void data_save(char temp[],int i) {
	char *token;

	token = strtok(temp, ",");
	data[i].ip = strdup(token);

	token = strtok(NULL, ",");
	data[i].time = strdup(token);

	token = strtok(NULL, ",");
	data[i].url = strdup(token);

	token = strtok(NULL, ",");
	data[i].status = strdup(token);
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
	sub_sort_data(status,N);
	return;
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

	printf("현재 저장된 데이터는 %d개\n", N);
}