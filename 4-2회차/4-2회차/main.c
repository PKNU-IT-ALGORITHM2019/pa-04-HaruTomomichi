#include "main.h"

void main() {

	char input[MAX];

	scanf("%[^\n]", input);

	word_analysis(input);
}

void word_analysis(char *input) {
	char *token;

	token = strtok(input, " ");

	if (strcmp(token, "read") == 0) {
		
	}
	else if (strcmp(token, "sort") == 0) {
		
	}
	else if (strcmp(token, "print") == 0) {
		
	}
	else {
		return; // ��ǻ� �ǹ̴� ���ٰ� ���� = exit
	}
}