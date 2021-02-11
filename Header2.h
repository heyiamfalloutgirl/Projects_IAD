#pragma once
#include <string>

using namespace std;

typedef struct{ // �������� ��� ���� ������
	int day;
	int month;
	int year;
} DATE;

typedef struct{ // �������� ��� ���
	string f;
	string i;
	string o;
} FIO;

class Passenger{ // ����� ������ ���������
public:
	int flightnum; // ����� �����
	DATE date; 
	FIO fio;
	int seatnum; // ����� �����

	Passenger() { // �����������
	}
	~Passenger() { //����������
	}

	// ���������� ���������� �������� � ���������:
	bool operator >= (const Passenger&) const;
	bool operator > (const Passenger&) const;
	bool operator < (const Passenger&) const;
	bool operator <= (const Passenger&) const;
	bool operator != (const Passenger&) const;
	bool operator == (const Passenger&) const;
};

// ��������� �������
Passenger *bubbleSort(Passenger *ps, int n); // ���������� ���������
Passenger *insertSort(Passenger *ps, int n); // ���������� ���������
void print(Passenger *ps, int n); // ������ �������