#include "main.h"
#include "sub.h"

IP made_ip[2];
TIME made_time[2];

int day_analysis(char temp[]) {
	char result[MAX];

	result[0] = temp[1];
	result[1] = temp[2];

	return atoi(result);
}

int month_analysis(char temp[]) {
	if (strcmp(temp, "Jan") == 0) {
		return 1;
	}
	else if (strcmp(temp, "Feb") == 0) {
		return 2;
	}
	else if (strcmp(temp, "Mar") == 0) {
		return 3;
	}
	else if (strcmp(temp, "Apr") == 0) {
		return 4;
	}
	else if (strcmp(temp, "May") == 0) {
		return 5;
	}
	else if (strcmp(temp, "Jun") == 0) {
		return 6;
	}
	else if (strcmp(temp, "Jul") == 0) {
		return 7;
	}
	else if (strcmp(temp, "Aug") == 0) {
		return 8;
	}
	else if (strcmp(temp, "Sep") == 0) {
		return 9;
	}
	else if (strcmp(temp, "Oct") == 0) {
		return 10;
	}
	else if (strcmp(temp, "Nov") == 0) {
		return 11;
	}
	return 12;
}

void make_time(WEB a, WEB b) {
	char *token, *test1, *test2, *test3;

	test1 = strdup(a.time);
	test2 = strdup(b.time);

	// a 분석 결과 제작

	token = strtok(test1, "/");
	made_time[0].day = day_analysis(token);

	token = strtok(NULL, "/");
	made_time[0].month = month_analysis(token);

	token = strtok(NULL, ":");
	made_time[0].year = atoi(token);

	token = strtok(NULL, ":");
	made_time[0].hour = atoi(token);

	token = strtok(NULL, ":");
	made_time[0].minute = atoi(token);

	token = strtok(NULL, ":");
	made_time[0].second = atoi(token);

	// b 분석 결과 제작

	token = strtok(test2, "/");
	made_time[1].day = day_analysis(token);

	token = strtok(NULL, "/");
	made_time[1].month = month_analysis(token);

	token = strtok(NULL, ":");
	made_time[1].year = atoi(token);

	token = strtok(NULL, ":");
	made_time[1].hour = atoi(token);

	token = strtok(NULL, ":");
	made_time[1].minute = atoi(token);

	token = strtok(NULL, ":");
	made_time[1].second = atoi(token);
}

void make_ip(WEB a, WEB b) {
	char *token, *test1, *test2;

	test1 = strdup(a.ip);
	test2 = strdup(b.ip);

	// a 분석 결과 제작

	token = strtok(test1, ".");
	made_ip[0].first = atoi(token);

	token = strtok(NULL, ".");
	made_ip[0].second = atoi(token);

	token = strtok(NULL, ".");
	made_ip[0].third = atoi(token);

	token = strtok(NULL, ".");
	made_ip[0].fourth = atoi(token);

	// b 분석 결과 제작

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

	int result = made_time[0].year - made_time[1].year;

	if (result != 0) {
		return result;
	}

	result = made_time[0].month - made_time[1].month;

	if (result != 0) {
		return result;
	}

	result = made_time[0].day - made_time[1].day;

	if (result != 0) {
		return result;
	}

	result = made_time[0].hour - made_time[1].hour;

	if (result != 0) {
		return result;
	}

	result = made_time[0].minute - made_time[1].minute;

	if (result != 0) {
		return result;
	}

	result = made_time[0].second - made_time[1].second;

	return result;
}

void sub_sort_data(int status,int N) {
	// 0 : ip 우선 / 1 : 시간 우선 / 2 : URL 우선 / 3 : 상태 우선
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
		// 일단 후에 만들 수도 있기 때문에 공란
		break;
	}
	case 3: {
		// 일단 후에 만들 수도 있기 때문에 공란
		break;
	}
	}
}