#include "stdafx.h"

const char* getMonthName(int month) {
	const char* months[12] = {"������", "�������", "����", "������", "���", "����", "����", "������",
	"��������", "�������", "������", "�������" };
	const char* month_name = months[month - 1];
	return month_name;
}