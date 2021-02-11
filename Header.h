#pragma once
#define N 20

using namespace std;

// ���������������� ����� Pair (���� �����)
class Pair{
private:
	int val1;
	double val2;
public:
	Pair() : val1(0), val2(0.0) {}
	Pair(const int &a, const double &b) : val1(a), val2(b) { } // ����������� �� �������� ���������
	~Pair() {}
	void Show(){ // ����� �� �����
		cout << val1 << ":" << val2 << endl;
	}
	friend ostream &operator<<(ostream &os, const Pair &p){ // ������������� ������� ���������� ��������� ������
		os << p.val1 << ":" << p.val2;
		return os;
	}
	friend istream &operator>>(istream &is, Pair &p){ // ������������� ������� ���������� ��������� �����
		cout << "������� ���� ����� (int � double): ";
		is >> p.val1;
		is >> p.val2;
		return is;
	}
	const Pair &operator=(const Pair &p){ // ���������� ��������� ������������
		val1 = p.val1;
		val2 = p.val2;
		return *this;
	}

	// ���������� ���������� �������� � ���������:
	bool operator==(const Pair &p) const{
		return (val1 == p.val1 and val2 == p.val2); 
	}
	bool operator!=(const Pair &p) const{
		return !(*this == p); // ����������� � ������� ���������� �����������������
	}
	bool operator>=(const Pair &p) const{
		if (val1 > p.val1) // ������������� �� 1� ������ �� ����
			return true;
		else if (val1 == p.val1) // ���� ��� ����� - ������� ������
			if (val2 > p.val2)
				return true;
		return false;
	}
	bool operator>(const Pair &p) const{
		return ((*this >= p) && (*this != p)); // >= � != ���� >
	}
	bool operator<(const Pair &p) const{
		return !(*this >= p); // !(>=) ���� <
	}
	bool operator<=(const Pair &p) const{
		return (!(*this >= p) || *this == p); // !(>=) ��� == ���� < ��� == (<=)
	}
};


// ������ ������-���������� (���������)
template <class Type>
class Set{ // ���������
private:
	Type arr[N];
	int size = 0; // ���������� ��������� ���������
public:
	Set() {}

	Set(const Type *a, int length){ // ����������� �� ����������� �������
		size = length; // ���������� ����� = ���-�� ���������
		for (int i = 0; i < size; i++) // ����������� ����������� ��������
			arr[i] = a[i];
	}

	~Set() {}

	const Set<Type> &operator=(const Set<Type> &set){ // ���������� ��������� ������������
		size = set.size;
		for (int i = 0; i < size; i++)
			arr[i] = set.arr[i]; // ����������� ����������� ��������
		set.insertSort(); // ��������� �������� ���������
		return *this;
	}

	Set(const Set<Type> &set) { // ����������� �����������
		*this = set; // ������������� �������� ������������!
	}

	int ShowSet(){ // ����� �� �����
		if (size == 0){ // �������� �� ������ ���������
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

	friend ostream &operator<<(ostream &os, Set<Type> &set){ // ���������� ��������� ������
		set.insertSort(); // ��������� �������� ��������� ����� �������
		set.ShowSet();
		return os;
	}

	friend istream &operator>>(istream &is, Set<Type> &set){ // ���������� ��������� �����
		Type a;
		int n;
		cout << "������� ���-�� ��������� ���������: ";
		cin >> n;
		cout << "������� ��� ��������:" << endl;
		for (int i = 0; i < n; i++){ // � ����� ������ ������� � ���� Type � ��������� ��� �� ���������
			is >> a; 
			set.add(a);
		};
		set.insertSort();  // ��������� �������� ��������� ����� �����
		return is;
	}

	bool IsElmInSet(const Type &value){ // �������� �������������� ���������
		for (int i = 0; i < size; i++) // �������� �� �����, ���������� ��� �������� � ��������
			if (value == arr[i])
				return true;
		return false;
	}

	int add(const Type &value){ // ���������� �������� �� ���������
		if (size >= N){ // �������� �� ����� �� ������� ���������
			cout << "No space in Set!" << endl;
			return 1;
		}
		if (IsElmInSet(value)){ // �������� ���� �� ��� �� ��������� ����� �������
			cout << "This element is already exist in Set!" << endl;
			return 1;
		}
		arr[size] = value; // ��������� ������� �� ���������
		size++;
		cout << "Element " << value << " is added." << std::endl;
		return 0;
	}

	void del(const Type &value){ // �������� �������� �� ���������
		if (IsElmInSet(value)){ // �������� ���� �� �� ��������� ����� �������
			int i;
			for (i = 0; i < size; i++)
				if (value == arr[i]) // ������� �� ��������, ������� ����� �������
					break;
			for (int j = i; j < size; j++) // �������� ��� �������� ��� ����� ����������
				arr[j] = arr[j + 1];
			--size; // ��������� ������ ���������
			cout << "Element " << value << " is deleted." << endl;
		}
		else
			cout << "There is no " << value << " in this Set!" << endl;
	}

	void getsize() const{ // ����������� ������� ���������
		cout << "Size of set: " << size << endl; // ������� ���-�� ��������� ���������
	}

	int IsEmpty(){ // �������� �� �������
		if (size != 0){ // ���������� �� ������� 
			cout << "Set isn't empty." << endl;
			return 0;
		}
		else{
			cout << "Set is empty." << endl;
			return 1;
		}
	}

	// ���������� ��������� �� ����������� ��� ��������� ���������
	void insertSort()
	{
		Type s; // ���������� ��� �������� �������� �������� ������������ �������
		int	j; // ������ ����������� ��������
		for (int i = 1; i < size; i++)
		{
			s = arr[i]; // �������������� ��������� ���������� ������� ��������� �������� �������
			j = i - 1; // ���������� ������ ����������� ��������
			while (j >= 0 && arr[j] > s){ // ���� ������ != 0 � ���������� ������� ������� > ��������
				arr[j + 1] = arr[j]; // ������ �������� �������
				arr[j] = s;
				j--;
			}
		}
	}
};