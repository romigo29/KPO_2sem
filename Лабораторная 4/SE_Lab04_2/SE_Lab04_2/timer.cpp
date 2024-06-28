#include <iostream>
using namespace std;

typedef unsigned short hours;
typedef unsigned short minutes;
typedef unsigned short seconds;
struct Timer {
	hours hour;
	minutes minute;
	seconds second;
};

Timer time1 = { 0, 10, 60 };
Timer time2 = { 1, 00, 30 };
Timer time3 = { 3, 10, 10 };
Timer time4 = { 3, 10, 10};

//���������� ==
bool operator == (Timer time3, Timer time4) {
	return (time3.hour == time4.hour && time3.minute == time4.minute && time3.second == time4.second);
}
//���������� +
int operator + (Timer timer1, Timer timer2) {
	int result = (timer1.hour + timer2.hour) * 3600 + (timer1.minute + timer2.minute) * 60 + (timer1.second + timer2.second);
	return result;
}

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "����� ����� ������ ���� ��������: " << time1 + time2 << " ������/�" << endl;

	if (time3 == time4) {
		cout << "����� �� ������� 3 ����� ������� �� ������� 4" << endl;
	}
	else {
		cout << "����� �� ������� 3 ���������� �� ������� �� ������� 4" << endl;
	}
	return 0;
}