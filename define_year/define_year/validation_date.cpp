#include "stdafx.h"

bool isDateValid(char* date) {

    if (strlen(date) != 8) {   // �������� ����� ������
        return false;
    }
    for (int i = 0; i < 8; i++) {   //�������� ��������� �� �����
        if (!isdigit(date[i])) {
            return false;
        }
    }
    int day = getDay(date);   // �������� ���������� ��� ���, ������ � ����
    int month = getMonth(date);
    int year = getYear(date);
    int leap_year = isYearLeap(year);
    int months_list[] = { 31, 28 + leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day > months_list[month - 1]) {
        return false;
    }
    return true;
}