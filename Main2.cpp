#include <iostream>
#include <string>
#include <locale>
#include <fstream> // Для файлового вывода
#include <ctime> // Для функции clock
#include <cstdlib> // Поддержка еxit
#include "Header.h"

using namespace std;

int main()
{
	const int n = 1200; // Кол-во элементов массива
	unsigned long start, end, t1, t2;  // Переменные для работы со временем
	ifstream f; // Объект для обработки файлов

	f.open("passengers1200.txt"); // Ассоциирование f с файлом
	if (!f.is_open()) // Проверка на успешное открытие файла
	{
		cout << "Couldn't open the file." << endl;
		exit(EXIT_FAILURE);
	}

	Passenger *p = new Passenger[n]; // Выделение памяти на массив пассажиров
	Passenger *p1 = new Passenger[n]; // Сюда скопируем исходный массив для теста второй сортировки

	// Считывание данных из файла в массив p
	int i = 0; // Счетчик элементов
	while ((i < n) && (!f.eof())) // Пока не конец файла и не прошли все элементы - считываем элементы
	{
		f >> p[i].flightnum;
		f >> p[i].date.day;
		f >> p[i].date.month;
		f >> p[i].date.year;
		f >> p[i].fio.f;
		f >> p[i].fio.i;
		f >> p[i].fio.o;
		f >> p[i].seatnum;
		f.get(); // Пропускаем символ перехода на новую строку
		i++;
	}
	if (f.eof()) // Проверка на пустой файл
	{
		cout << "Your file is empty!\n";
		f.close(); // Закрываем файл и завершаем работу программы
		system("pause");
		return 1;
	}
	f.close(); // Закрываем файл

	//cout << "Your masssive:\n";
    //print(p, n); // Печатаем исходный массив
	//cout << "\n";

	for (int i = 0; i < n; i++) // Запоминаем заполненный исходный массив p в p1
		p1[i] = p[i];

	start = clock(); // Засекаем время начала работы функции по сортировке
	p = bubbleSort(p, n); // Сортируем массив пузырьком
	end = clock(); // Засекаем время окончания
	t1 = end - start; // Вычисляем время работы функции

	start = clock();
	p1 = insertSort(p1, n); // Сортируем массив простыми вставками
	end = clock();
	t2 = end - start; 

	cout << "Time of bubble sort: " << t1 << "\nTime of insert sort: " << t2 << endl;

	//cout << "\nYour sorted masssive:\n";
	//print(p, n); // Печатаем отсортированный массив

	delete[] p; // Очистка памяти
	delete[] p1;
	system("pause");
	return 0;
}