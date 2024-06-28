#include "D:\BSTU\2 �������\���\������������ 6\SE_Lab06S\SE_Lab06L\Dictionary.h"
#pragma comment(lib, "D:\\BSTU\\2 �������\\���\\������������ 6\\SE_Lab06S\\Debug\\SE_Lab06L.lib")

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//���� ���������� ����� ������ �������
#if defined(TEST_CREATE_01) || defined(TEST_CREATE_02) || defined(TEST_ADDENTRY_03) || defined(TEST_ADDENTRY_04) || defined(TEST_GETENTRY_05) || defined(TEST_GETENTRY_06) ||  defined(TEST_UPDENTRY_07) ||  defined(TEST_UPDENTRY_08)
#error ����������� ����� ������ �������!
#endif

	try {
#ifdef TEST_CREATE_01   //������������ ����� �������
		Dictionary::Instance test1 = Dictionary::Create((char*)"AAAAAAAAAAAAAAAAAAAAAAAAA", 5);
#endif

#ifdef TEST_CREATE_02   //������������ ������� �������
		Dictionary::Instance test2 = Dictionary::Create((char*)"test2 info", 101);
#endif

#ifdef TEST_ADDENTRY_03  //������������ �������
		Dictionary::Instance test3 = Dictionary::Create((char*)"test info3", 0);
		Dictionary::Entry test3_ed = { 1, (char*)"test3_ed" };
		Dictionary::AddEntry(test3, test3_ed);
#endif

#ifdef TEST_ADDENTRY_04   //������������ ��������
		Dictionary::Instance test4 = Dictionary::Create((char*)"test4", 2);
		Dictionary::Entry test4_info = { 1, (char*)"test4_info" };
		Dictionary::AddEntry(test4, test4_info);
		Dictionary::AddEntry(test4, test4_info);
#endif

#ifdef TEST_GETENTRY_05  //������� � ������� �� ������ �� id
		Dictionary::Instance test5 = Dictionary::Create((char*)"test5", 2);
		Dictionary::Entry test5_info = { 1, (char*)"test5_info" };
		Dictionary::AddEntry(test5, test5_info);
		Dictionary::GetEntry(test5, 2);
#endif

#ifdef TEST_GETENTRY_06  //������� � ������� �� ������ �� id
		Dictionary::Instance test6 = Dictionary::Create((char*)"test6", 2);
		Dictionary::Entry test6_info = { 1, (char*)"test6_info" };
		Dictionary::AddEntry(test6, test6_info);
		Dictionary::DelEntry(test6, 2);
#endif

#ifdef TEST_UPDENTRY_07  //������� � ������� �� ������ �� id
		Dictionary::Instance test7 = Dictionary::Create((char*)"test7", 2);
		Dictionary::Entry test7_info = { 1, (char*)"test7_info" };
		Dictionary::AddEntry(test7, test7_info);
		Dictionary::UpdEntry(test7, 2, test7_info);
#endif

#ifdef TEST_UPDENTRY_08   //������������ ��������
		Dictionary::Instance test8 = Dictionary::Create((char*)"test8", 2);
		Dictionary::Entry test8_info = { 1, (char*)"test8_info" };
		Dictionary::AddEntry(test8, test8_info);
		Dictionary::UpdEntry(test8, 1, test8_info);
#endif


		SetConsoleOutputCP(1251);
		SetConsoleCP(1251);
		Dictionary::Instance d1 = Dictionary::Create((char*)"�������������", 5);    //�������� �������
		Dictionary::Entry e1 = { 1, "�������" }, e2 = { 2, "�������" },      //�������� �������
			e3 = { 3, "������" }, e4 = { 4, "���������" }, e5 = { 2, "�����" };
		Dictionary::AddEntry(d1, e1);                                        //���������� �������� � �������
		Dictionary::AddEntry(d1, e2);                                        //���������� �������� � �������
		Dictionary::AddEntry(d1, e3);                                        //���������� �������� � �������
		Dictionary::AddEntry(d1, e4);                                        //���������� �������� � �������
		Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);                 //����� ������� � ������� �� ��������������
		Dictionary::DelEntry(d1, 2);                                         //������� ������� �� �������������
		Dictionary::Entry newentry1 = { 6, "�����" };                        //������� ������� �� ��������������
		Dictionary::UpdEntry(d1, 3, newentry1);                              //�������� ������� ������� �� ��������������
		Dictionary::Print(d1);                                               //����������� �������� ������� 
		Dictionary::Instance d2 = Dictionary::Create((char*)"��������", 5);
		Dictionary::Entry s1 = { 1, "������" }, s2 = { 2, "������" }, s3 = { 3, "�������" };
		Dictionary::AddEntry(d2, s1);
		Dictionary::AddEntry(d2, s2);
		Dictionary::AddEntry(d2, s3);
		Dictionary::Entry newentry3 = { 4, "��������" };
		Dictionary::UpdEntry(d2, 3, newentry3);
		Dictionary::Print(d2);
		Delete(d1);
		Delete(d2);
	}

	catch (char* e) {
		cout << e << endl;
	}
	return 0;
}