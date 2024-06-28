#include <iostream>
#include <Windows.h>
using namespace std;
// ���������
struct SANATORIUM
{
    char name[40]; // �������� ���������
    char location[40]; // ��������������
    char profile[40]; //�������
    unsigned int amount_package; //���������� �������
};
// ��������� �������
void sortStructures(SANATORIUM sanat[], int num);
void findSanat(SANATORIUM sanat[], char ask_sanat[]);
void outputSanatoriums(SANATORIUM sanat[], int num);
//���������� ��������� ��� ���������� � ���������� � � ���
SANATORIUM sanat[5] = {
    {"��������", "��������", "������� A", 13},
    {"������� ���", "��������", "������� �", 7},
    {"������", "��������", "������� A", 2},
    {"�������", "��������", "������� A", 9},
    {"���", "��������", "������� �", 6}
};
// ������� �������
int main()
{
    SetConsoleOutputCP(1251); // ��� ������������� ��������� ��� ������ � ������
    SetConsoleCP(1251);
    char ask_sanat[40]; // ���������� ��� ������� �������
    //���� ������ � ������ ���������
    

    sortStructures(sanat, 5); //��������� ��������
    outputSanatoriums(sanat, 5);
    cout << "����� ��������� ��� ����������? " << endl;
    cin >> ask_sanat;
    findSanat(sanat, ask_sanat); //���� ������ ���������
    return 0;
}
// ������� ��� ���������� ���������� �� ��������
void sortStructures(SANATORIUM sanat[], int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) { 
            if (strcmp(sanat[j].name, sanat[j + 1].name) > 0) { // ���������� ������ �������� ����������
                swap(sanat[j].name, sanat[j + 1].name);
            }
        }
    }
}
//����� ���������� � ���� �������
void outputSanatoriums(SANATORIUM sanat[], int num) {
    // ������ ������ �������
    cout << "�������� �������" << "\t \t";
    cout << "��������" << "\t \t";
    cout << "��������������" << endl;
    // ������ ������ �������
    cout << "��������� �� ������� �" << "\t \t";
    for (int i = 0; i < num; i++) {
        if (strcmp(sanat[i].profile, "������� A") == 0) {
            cout << sanat[i].name << "\t \t \t";
            cout << sanat[i].location << endl << "\t \t \t \t";
        }
    }
    // ������ ������ �������
    cout << "\r��������� �� ������� �" << "\t \t";
    for (int i = 0; i < num; i++) {
        if (strcmp(sanat[i].profile, "������� �") == 0) {
            cout << sanat[i].name << "\t \t";
            cout << sanat[i].location << endl << "\t \t \t \t";
        }
    }
    cout << "\r"; //����������� ������� � ������ ������
}
// ����� ������� �� �������� ���������
void findSanat(SANATORIUM sanat[], char ask_sanat[]) {
    bool found = false; // ���� ��� ������������, ��� �� ������ ���������
    for (int i = 0; i < 5; i++) {
        if (strcmp(sanat[i].name, ask_sanat) == 0) {
            cout << "���������� ��������� �������: " << sanat[i].amount_package << endl;
            found = true;
            break; // ���� ����� ���������, �� ������� �� �����
        }
    }
    if (!found) { // ���� ��������� �� ��� ������
        cout << "��������� �� ��� ������" << endl;
    }
}