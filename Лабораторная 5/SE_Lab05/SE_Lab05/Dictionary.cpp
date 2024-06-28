#include "stdafx.h"
#include "Dictionary.h"
using namespace std;

namespace Dictionary {
	//�������� �������
	Instance Create(char name[DICTNAMEMAXSIZE], int size) {
		if (strlen(name) > DICTNAMEMAXSIZE) {
			throw(char*)THROW01;
		}
		if (size > DICTMAXSIZE) {
			throw(char*)THROW02;
		}

		Instance newDictionary{};
		strcpy_s(newDictionary.name, name);
		newDictionary.maxsize = size;
		newDictionary.size = 0;
		newDictionary.dictionary = new Entry[size];
		return newDictionary;
	}
	//���������� �������� � �������
	void AddEntry(Instance& inst, Entry ed) {
		if (inst.size >= inst.maxsize) {  //������������ �������
			throw(char*)THROW03;
		}
		for (int i = 0; i < inst.size; i++) {  //������������ ��������������
			if (inst.dictionary[i].id == ed.id) {
				throw(char*)THROW04;
			}
		}
		inst.dictionary[inst.size] = Entry();
		inst.dictionary[inst.size].id = ed.id;
		for (int i = 0; i < strlen(ed.name); i++) {
			inst.dictionary[inst.size].name[i] = ed.name[i];
		}
		inst.dictionary[inst.size].name[strlen(ed.name)] = '\0';
		inst.size++;
	}

	void DelEntry(Instance& inst, int id) {
		bool isFound = false; //�� ��������� ���������, ��� ������� �� ������
		for (int i = 0; i < inst.size; i++) {

			if (inst.dictionary[i].id == id) {  //���� ������
				isFound = true;
				for (int j = i; j < inst.size; j++) {
					inst.dictionary[j] = inst.dictionary[j + 1];
				}
				inst.size--;
				break;
			}
		}
		if (!isFound) {  //���� �� ��� ������
			throw(char*)THROW06;
		}
	}

	Entry GetEntry(Instance inst, int id) {
		for (int i = 0; i < inst.size; i++) {
			if (inst.dictionary[i].id == id) {  //���� ������
				return inst.dictionary[i];
			}
		}
		throw(char*)THROW05;

	}

	void UpdEntry(Instance& inst, int id, Entry new_ed) {
		bool isFound = false; //�� ��������� ���������, ��� ������� �� ������
		for (int i = 0; i <= inst.size; i++) {
			if (inst.dictionary[i].id == new_ed.id) {  //������������ ��������������
				throw (char*)THROW08;
			}
			if (inst.dictionary[i].id == id) {  //���� ������
				isFound = true;
				inst.dictionary[i] = new_ed;
				break;
			}
		}
		if (!isFound) {  //���� �� ��� ������
			throw (char*)THROW07;
		}
	}


	void Delete(Instance& d) {
		delete[] d.dictionary;
		d.size = 0;
	}

	void Print(Instance d) {
		cout << "-------- " << d.name << "--------" << endl;
		for (int i = 0; i < d.size; i++) {
			cout << d.dictionary[i].id << " " << d.dictionary[i].name << endl;
		}
		cout << "" << endl;
	}
}

