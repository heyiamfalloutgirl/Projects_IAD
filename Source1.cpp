#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Header.h"

using namespace std;

// ���������� ��������� ==
bool Passenger::operator ==(const Passenger &ps)const
{
	return !(*this != ps);
}

// ���������� ��������� !=
bool Passenger::operator !=(const Passenger &ps)const
{
	if (fio.f != ps.fio.f) // ������������� ��������� ��� ���� �����
		return true;
	if (fio.i != ps.fio.i)
		return true;
	if (fio.o != ps.fio.o)
		return true;
	if (date.day != ps.date.day)
		return true;
	if (date.month != ps.date.month)
		return true;
	if (date.year != ps.date.year)
		return true;
	if (flightnum != ps.flightnum)
		return true;
	if (seatnum != ps.seatnum)
		return true;
	return false;
}

// ���������� ��������� >=
bool Passenger::operator >=(const Passenger &ps)const
{
	if (date.year > ps.date.year) // ���������� ��� ���� � ��������� ����������: ����.��� �����
		return true;
	else if (date.year == ps.date.year)
		if (date.month > ps.date.month) // ����.����� �����
			return true;
		else if (date.month == ps.date.month)
			if (date.day > ps.date.day) // ����.���� �����
				return true;
			else if (date.day == ps.date.day)
				if (flightnum > ps.flightnum) // ����� �����
					return true;
				else if (flightnum == ps.flightnum)
					if (fio.f > ps.fio.f) // ������� ���������
						return true;
					else if (fio.f == ps.fio.f)
						if (fio.i > ps.fio.i) // ��� ���������
							return true;
						else if (fio.i == ps.fio.i)
							if (fio.o > ps.fio.o) // �������� ���������
								return true;
	return false;
}

// ���������� ��������� <
bool Passenger::operator <(const Passenger &ps)const
{
	return !(*this >= ps); // ����������� � ������� ���������� �����������������: !(>=) ���� <
}

// ���������� ��������� >
bool Passenger::operator >(const Passenger &ps)const
{
	if ((*this >= ps) && (*this != ps)) // ����������� � ������� ���������� ������������������: >= � != ���� >
		return true;
	return false;
}

//���������� ��������� <=
bool Passenger::operator <=(const Passenger &ps)const
{
	if (!(*this >= ps) || *this == ps) // ����������� � ������� ���������� ������������������: !(>=) ��� == ���� < ��� ==
		return true;
	return false;
}

// ���������� ��������� �� ����������� (https://codelessons.ru/cplusplus/algoritmy/puzyrkovaya-sortirovka-v-c-glavnye-momenty.html)
Passenger *bubbleSort(Passenger *ps, int n) // �������� � ��� ������ ���������� � ���-�� ��������� �������
{
	Passenger s; // ���������� ��� ������ ��������� �������

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (ps[j] > ps[j + 1])
			{
				// ������ �������� �������
				s = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = s;
			}
		}
	}

	return ps;
}

// ���������� ��������� �� ����������� (http://cppstudio.com/post/462/)
Passenger *insertSort(Passenger *ps, int n) 
{
	Passenger s; // ���������� ��� �������� �������� �������� ������������ �������
	int	j; // ������ ����������� ��������

	for (int i = 1; i < n; i++)
	{
		s = ps[i]; // �������������� ��������� ���������� ������� ��������� �������� �������
		j = i - 1; // ���������� ������ ����������� ��������
		while (j >= 0 && ps[j] > s) // ���� ������ != 0 � ���������� ������� ������� > ��������
		{
			ps[j + 1] = ps[j]; // ������ �������� �������
			ps[j] = s;
			j--;
		}
	}

	return ps;
}

// ������ �������
void print(Passenger *ps, int n)
{
	cout << "flnum" << std::setfill(' ') << std::setw(9) << "dd mm yy" << std::setfill(' ') << std::setw(15)
		<< "FIO" << std::setfill(' ') << std::setw(17) << "seatnum" << "\n"; // ����������� ��������
	for (int i = 0; i < n; i++) // � ���� �������� ��� �������
		cout << ps[i].flightnum << " " << ps[i].date.day << " " << ps[i].date.month << " " << ps[i].date.year
		<< " " << ps[i].fio.f << " " << ps[i].fio.i << " " << ps[i].fio.o << " " << ps[i].seatnum << endl;
}
