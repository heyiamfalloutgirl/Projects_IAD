#include <iostream>
#include <string>
#include <locale>
#include <fstream> // ��� ��������� ������
#include <ctime> // ��� ������� clock
#include <cstdlib> // ��������� �xit
#include "Header.h"

using namespace std;

int main()
{
	const int n = 1200; // ���-�� ��������� �������
	unsigned long start, end, t1, t2;  // ���������� ��� ������ �� ��������
	ifstream f; // ������ ��� ��������� ������

	f.open("passengers1200.txt"); // �������������� f � ������
	if (!f.is_open()) // �������� �� �������� �������� �����
	{
		cout << "Couldn't open the file." << endl;
		exit(EXIT_FAILURE);
	}

	Passenger *p = new Passenger[n]; // ��������� ������ �� ������ ����������
	Passenger *p1 = new Passenger[n]; // ���� ��������� �������� ������ ��� ����� ������ ����������

	// ���������� ������ �� ����� � ������ p
	int i = 0; // ������� ���������
	while ((i < n) && (!f.eof())) // ���� �� ����� ����� � �� ������ ��� �������� - ��������� ��������
	{
		f >> p[i].flightnum;
		f >> p[i].date.day;
		f >> p[i].date.month;
		f >> p[i].date.year;
		f >> p[i].fio.f;
		f >> p[i].fio.i;
		f >> p[i].fio.o;
		f >> p[i].seatnum;
		f.get(); // ���������� ������ �������� �� ����� ������
		i++;
	}
	if (f.eof()) // �������� �� ������ ����
	{
		cout << "Your file is empty!\n";
		f.close(); // ��������� ���� � ��������� ������ ���������
		system("pause");
		return 1;
	}
	f.close(); // ��������� ����

	//cout << "Your masssive:\n";
    //print(p, n); // �������� �������� ������
	//cout << "\n";

	for (int i = 0; i < n; i++) // ���������� ����������� �������� ������ p � p1
		p1[i] = p[i];

	start = clock(); // �������� ����� ������ ������ ������� �� ����������
	p = bubbleSort(p, n); // ��������� ������ ���������
	end = clock(); // �������� ����� ���������
	t1 = end - start; // ��������� ����� ������ �������

	start = clock();
	p1 = insertSort(p1, n); // ��������� ������ �������� ���������
	end = clock();
	t2 = end - start; 

	cout << "Time of bubble sort: " << t1 << "\nTime of insert sort: " << t2 << endl;

	//cout << "\nYour sorted masssive:\n";
	//print(p, n); // �������� ��������������� ������

	delete[] p; // ������� ������
	delete[] p1;
	system("pause");
	return 0;
}