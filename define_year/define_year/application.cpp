#include "stdafx.h"

int main() {
    setlocale(LC_ALL, "Rus");
     char date[9];
     cout << "������� ���� � ������� ��������:" << endl;
     cin >> date;
     if (!isDateValid(date)) {
        while (!isDateValid(date)) {
            cout << "������� ����������� �������� ����. ���������� ��� ���" << endl; cin >> date;
        }
     }
     // ���, ���������� ���, ����, �����
     int year = getYear(date);
     int leap_year = isYearLeap(year);
     int day = getDay(date);
     int month = getMonth(date);
     int months_list[] = { 31, 28 + leap_year, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
     //������������ ����
     if (leap_year) {
        cout << "��� ����������" << endl;
     }
     else {
        cout << "��� �� �������� ����������" << endl;
            }
     // ���������� ����� + �������� ������ + ���� ������������
     cout << "��������� ���� ����� ���������� ����� - " << getOrderOfDay(leap_year, day, month, months_list) << endl;
     cout << "��������� ����� ����: " << getMonthName(month) << endl;

     cout << "� " << year << " ���� ���� ������������ �������� �� " << 13 - leap_year << " �������� " << endl;
     // �� ������� ���� �� ��
     char current_date[9], birth_date[9];
     cout << "������� ������� ����: " << endl;
     cin >> current_date;
     if (!isDateValid(current_date)) {
        while (!isDateValid(current_date)) {
            cout << "������� ����������� �������� ����. ���������� ��� ���" << endl; cin >> current_date;
        }
     }
     cout << "������� ���� ��� ��������: " << endl;
     cin >> birth_date;
     if (!isDateValid(birth_date)) {
        while (!isDateValid(birth_date)) {
            cout << "������� ����������� �������� ����. ���������� ��� ���" << endl; cin >> birth_date;
        }
     }
     cout << "�� ��� �������� �������� ����: " << leftUntilBirthday(current_date, birth_date, months_list) << endl;
     return 0;
}
