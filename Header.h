#pragma once
#define N 20

using namespace std;

// Пользовательский класс Pair (пара чисел)
class Pair{
private:
	int val1;
	double val2;
public:
	Pair() : val1(0), val2(0.0) {}
	Pair(const int &a, const double &b) : val1(a), val2(b) { } // Конструктор по заданным значениям
	~Pair() {}
	void Show(){ // Вывод на экран
		cout << val1 << ":" << val2 << endl;
	}
	friend ostream &operator<<(ostream &os, const Pair &p){ // Дружественная функция перегрузки оператора вывода
		os << p.val1 << ":" << p.val2;
		return os;
	}
	friend istream &operator>>(istream &is, Pair &p){ // Дружественная функция перегрузки оператора ввода
		cout << "Введите пару чисел (int и double): ";
		is >> p.val1;
		is >> p.val2;
		return is;
	}
	const Pair &operator=(const Pair &p){ // Перегрузка оператора присваивания
		val1 = p.val1;
		val2 = p.val2;
		return *this;
	}

	// Перегрузка операторов равенств и сравнения:
	bool operator==(const Pair &p) const{
		return (val1 == p.val1 and val2 == p.val2); 
	}
	bool operator!=(const Pair &p) const{
		return !(*this == p); // Перегружаем с помощью логической противоположности
	}
	bool operator>=(const Pair &p) const{
		if (val1 > p.val1) // Рассматриваем по 1м цифрам из пары
			return true;
		else if (val1 == p.val1) // Если они равны - смотрим вторые
			if (val2 > p.val2)
				return true;
		return false;
	}
	bool operator>(const Pair &p) const{
		return ((*this >= p) && (*this != p)); // >= и != дает >
	}
	bool operator<(const Pair &p) const{
		return !(*this >= p); // !(>=) дает <
	}
	bool operator<=(const Pair &p) const{
		return (!(*this >= p) || *this == p); // !(>=) или == дает < или == (<=)
	}
};


// Шаблон класса-контейнера (множество)
template <class Type>
class Set{ // Множество
private:
	Type arr[N];
	int size = 0; // Количество элементов множества
public:
	Set() {}

	Set(const Type *a, int length){ // Конструктор по переданному массиву
		size = length; // Запоминаем длину = кол-во элементов
		for (int i = 0; i < size; i++) // Поэлементно присваиваем значения
			arr[i] = a[i];
	}

	~Set() {}

	const Set<Type> &operator=(const Set<Type> &set){ // Перегрузка оператора присваивания
		size = set.size;
		for (int i = 0; i < size; i++)
			arr[i] = set.arr[i]; // Поэлементно присваиваем значения
		set.insertSort(); // Сортируем элементы множества
		return *this;
	}

	Set(const Set<Type> &set) { // Конструктор копирования
		*this = set; // Перегруженный оператор присваивания!
	}

	int ShowSet(){ // Вывод на экран
		if (size == 0){ // Проверка на пустое множество
			cout << "Set is empty :(" << endl;
			return 1;
		}
		cout << "{";
		for (int i = 0; i < size - 1; i++)
			cout << arr[i] << ", ";
		cout << arr[size - 1];
		cout << "}" << endl;
		return 0;
	}

	friend ostream &operator<<(ostream &os, Set<Type> &set){ // Перегрузка оператора вывода
		set.insertSort(); // Сортируем элементы множества перед выводом
		set.ShowSet();
		return os;
	}

	friend istream &operator>>(istream &is, Set<Type> &set){ // Перегрузка оператора ввода
		Type a;
		int n;
		cout << "Введите кол-во элементов множества: ";
		cin >> n;
		cout << "Введите эти элементы:" << endl;
		for (int i = 0; i < n; i++){ // В цикле вводим элемент а типа Type и добавляем его во множество
			is >> a; 
			set.add(a);
		};
		set.insertSort();  // Сортируем элементы множества после ввода
		return is;
	}

	bool IsElmInSet(const Type &value){ // Проверка принадлежности множеству
		for (int i = 0; i < size; i++) // Проходим по циклу, сравниваем все элементы с заданным
			if (value == arr[i])
				return true;
		return false;
	}

	int add(const Type &value){ // Добавление элемента во множество
		if (size >= N){ // Проверка на выход за пределы множества
			cout << "No space in Set!" << endl;
			return 1;
		}
		if (IsElmInSet(value)){ // Проверка есть ли уже во множестве такой элемент
			cout << "This element is already exist in Set!" << endl;
			return 1;
		}
		arr[size] = value; // Добавляем элемент во множество
		size++;
		cout << "Element " << value << " is added." << std::endl;
		return 0;
	}

	void del(const Type &value){ // Удаление элемента из множества
		if (IsElmInSet(value)){ // Проверка есть ли во множестве такой элемент
			int i;
			for (i = 0; i < size; i++)
				if (value == arr[i]) // Доходим до элемента, который нужно удалить
					break;
			for (int j = i; j < size; j++) // Сдвигаем все элементы нна место удаленного
				arr[j] = arr[j + 1];
			--size; // Уменьшаем размер множества
			cout << "Element " << value << " is deleted." << endl;
		}
		else
			cout << "There is no " << value << " in this Set!" << endl;
	}

	void getsize() const{ // Определение размера множества
		cout << "Size of set: " << size << endl; // Выводим кол-во элементов множества
	}

	int IsEmpty(){ // Проверка на пустоту
		if (size != 0){ // Определяем по размеру 
			cout << "Set isn't empty." << endl;
			return 0;
		}
		else{
			cout << "Set is empty." << endl;
			return 1;
		}
	}

	// Сортировка вставками по возрастанию для элементов множества
	void insertSort()
	{
		Type s; // Переменная для хранения значения элемента сортируемого массива
		int	j; // Индекс предыдущего элемента
		for (int i = 1; i < size; i++)
		{
			s = arr[i]; // Инициализируем временную переменную текущим значением элемента массива
			j = i - 1; // Запоминаем индекс предыдущего элемента
			while (j >= 0 && arr[j] > s){ // Пока индекс != 0 и предыдущий элемент массива > текущего
				arr[j + 1] = arr[j]; // Меняем элементы местами
				arr[j] = s;
				j--;
			}
		}
	}
};