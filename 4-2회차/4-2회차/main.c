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
		return; // ��ǻ� �ǹ̴� ���ٰ� ���� = exit
	}
}

void read_data(char *token) {
	FILE *fp = fopen(token, "r");

	// ��ǥ�� ���еǾ� �ִ� / �����ؾ���

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
	// 0 : ip �켱 / 1 : �ð� �켱 / 2 : URL �켱 / 3 : ���� �켱
	
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
		// �ϴ� �Ŀ� ���� ���� �ֱ� ������ ����
		break;
	}
	case 3: {
		// �ϴ� �Ŀ� ���� ���� �ֱ� ������ ����
		break;
	}
	}
}