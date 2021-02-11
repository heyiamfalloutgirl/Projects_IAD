#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "Header.h"

using namespace std;

// Перегрузка оператора ==
bool Passenger::operator ==(const Passenger &ps)const
{
	return !(*this != ps);
}

// Перегрузка оператора !=
bool Passenger::operator !=(const Passenger &ps)const
{
	if (fio.f != ps.fio.f) // Рассматриваем равенство для всех полей
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

// Перегрузка оператора >=
bool Passenger::operator >=(const Passenger &ps)const
{
	if (date.year > ps.date.year) // Сравниваем все поля в требуемом приоритете: дата.год рейса
		return true;
	else if (date.year == ps.date.year)
		if (date.month > ps.date.month) // дата.месяц рейса
			return true;
		else if (date.month == ps.date.month)
			if (date.day > ps.date.day) // дата.день рейса
				return true;
			else if (date.day == ps.date.day)
				if (flightnum > ps.flightnum) // номер рейса
					return true;
				else if (flightnum == ps.flightnum)
					if (fio.f > ps.fio.f) // фамилия пассажира
						return true;
					else if (fio.f == ps.fio.f)
						if (fio.i > ps.fio.i) // имя пассажира
							return true;
						else if (fio.i == ps.fio.i)
							if (fio.o > ps.fio.o) // отчество пассажира
								return true;
	return false;
}

// Перегрузка оператора <
bool Passenger::operator <(const Passenger &ps)const
{
	return !(*this >= ps); // Перегружаем с помощью логической противоположности: !(>=) дает <
}

// Перегрузка оператора >
bool Passenger::operator >(const Passenger &ps)const
{
	if ((*this >= ps) && (*this != ps)) // Перегружаем с помощью логических противоположностей: >= и != дает >
		return true;
	return false;
}

//Перегрузка оператора <=
bool Passenger::operator <=(const Passenger &ps)const
{
	if (!(*this >= ps) || *this == ps) // Перегружаем с помощью логических противоположностей: !(>=) или == дает < или ==
		return true;
	return false;
}

// Сортировка пузырьком по возрастанию (https://codelessons.ru/cplusplus/algoritmy/puzyrkovaya-sortirovka-v-c-glavnye-momenty.html)
Passenger *bubbleSort(Passenger *ps, int n) // Передаем в нее массив пассажиров и кол-во элементов массива
{
	Passenger s; // Переменная для обмена элементов местами

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (ps[j] > ps[j + 1])
			{
				// Меняем элементы местами
				s = ps[j];
				ps[j] = ps[j + 1];
				ps[j + 1] = s;
			}
		}
	}

	return ps;
}

// Сортировка вставками по возрастанию (http://cppstudio.com/post/462/)
Passenger *insertSort(Passenger *ps, int n) 
{
	Passenger s; // Переменная для хранения значения элемента сортируемого массива
	int	j; // Индекс предыдущего элемента

	for (int i = 1; i < n; i++)
	{
		s = ps[i]; // Инициализируем временную переменную текущим значением элемента массива
		j = i - 1; // Запоминаем индекс предыдущего элемента
		while (j >= 0 && ps[j] > s) // Пока индекс != 0 и предыдущий элемент массива > текущего
		{
			ps[j + 1] = ps[j]; // Меняем элементы местами
			ps[j] = s;
			j--;
		}
	}

	return ps;
}

// Печать массива
void print(Passenger *ps, int n)
{
	cout << "flnum" << std::setfill(' ') << std::setw(9) << "dd mm yy" << std::setfill(' ') << std::setw(15)
		<< "FIO" << std::setfill(' ') << std::setw(17) << "seatnum" << "\n"; // Обозначение столбцов
	for (int i = 0; i < n; i++) // В цике печатаем все столбцы
		cout << ps[i].flightnum << " " << ps[i].date.day << " " << ps[i].date.month << " " << ps[i].date.year
		<< " " << ps[i].fio.f << " " << ps[i].fio.i << " " << ps[i].fio.o << " " << ps[i].seatnum << endl;
}
