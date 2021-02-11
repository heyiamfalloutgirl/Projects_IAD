#pragma once
#include <string>

using namespace std;

typedef struct{ // Стукрута для даты полета
	int day;
	int month;
	int year;
} DATE;

typedef struct{ // Стукрута для ФИО
	string f;
	string i;
	string o;
} FIO;

class Passenger{ // Класс данных пассажира
public:
	int flightnum; // Номер рейса
	DATE date; 
	FIO fio;
	int seatnum; // Номер места

	Passenger() { // Конструктор
	}
	~Passenger() { //Деструктор
	}

	// Перегрузка операторов равенств и сравнения:
	bool operator >= (const Passenger&) const;
	bool operator > (const Passenger&) const;
	bool operator < (const Passenger&) const;
	bool operator <= (const Passenger&) const;
	bool operator != (const Passenger&) const;
	bool operator == (const Passenger&) const;
};

// Прототивы функций
Passenger *bubbleSort(Passenger *ps, int n); // Сортировка пузырьком
Passenger *insertSort(Passenger *ps, int n); // Сортировка вставками
void print(Passenger *ps, int n); // Печать массива