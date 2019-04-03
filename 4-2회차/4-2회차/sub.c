#include "main.h"
#include "sub.h"

IP made_ip[2];
TIME made_time[2];

void make_time(WEB a, WEB b) {
	char *token, *test1, *test2;

	test1 = strdup(a.time);
	test2 = strdup(b.time);

	// a �м� ��� ����

	// b �м� ��� ����
}

void make_ip(WEB a, WEB b) {
	char *token, *test1, *test2;

	test1 = strdup(a.ip);
	test2 = strdup(b.ip);

	// a �м� ��� ����

	token = strtok(test1, ".");
	made_ip[0].first = atoi(token);

	token = strtok(NULL, ".");
	made_ip[0].second = atoi(token);

	token = strtok(NULL, ".");
	made_ip[0].third = atoi(token);

	token = strtok(NULL, ".");
	made_ip[0].fourth = atoi(token);

	// b �м� ��� ����

	token = strtok(test2, ".");
	made_ip[1].first = atoi(token);

	token = strtok(NULL, ".");
	made_ip[1].second = atoi(token);

	token = strtok(NULL, ".");
	made_ip[1].third = atoi(token);

	token = strtok(NULL, ".");
	made_ip[1].fourth = atoi(token);
}

int compare_data_by_ip(const void *p, const void *q) {

	WEB a = *(WEB *)p;
	WEB b = *(WEB *)q;

	make_ip(a, b);

	int result = made_ip[0].fourth - made_ip[1].fourth;

	if (result != 0) {
		return result;
	}

	result = made_ip[0].third - made_ip[1].third;

	if (result != 0) {
		return result;
	}

	result = made_ip[0].second - made_ip[1].second;

	if (result != 0) {
		return result;
	}

	result = made_ip[0].first - made_ip[1].first;

	return result;
}

int compare_data_by_time (const void *p, const void *q) {
	WEB a = *(WEB *)p;
	WEB b = *(WEB *)q;

	make_time(a, b);
}

void sub_sort_data(int status,int N) {
	// 0 : ip �켱 / 1 : �ð� �켱 / 2 : URL �켱 / 3 : ���� �켱
	switch (status) {
	case 0: {
		qsort(data, N, sizeof(WEB), compare_data_by_ip);
		break;
	}
	case 1: {
		qsort(data, N, sizeof(WEB), compare_data_by_time);
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