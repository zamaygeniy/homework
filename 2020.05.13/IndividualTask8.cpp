#include <iostream>
#include <fstream>

using namespace std;

int* createMatrix(int);
void initMatrix(int*, int);
void writeBinary(const char*, int, int);
void readBinary(const char*, int);
void readWithNumber(const char*, int);
void identityWrite(const char*, int, int);
void identityInit(int*, int);
int** transform(int*, int);
void processing(const char*, const char*, int&, int, int&);
int order(const char*, int);
void show(int*, int);
void answer(const char*, const char*, int, int);
void enter(int&, int&, int&);

int main() {
	int k, n, l;
	enter(k, n, l);
	writeBinary("source1.bin", n, k);
	writeBinary("source2.bin", rand() % 5 + 1, l);
	processing("source1.bin", "source2.bin", k, n, l);
	answer("source1.bin", "source2.bin", k, l);
	return 0;
}

void enter(int& k, int& n, int& l) {
	cout << "enter k = ";
	cin >> k;
	cout << "\nenter n = ";
	cin >> n;
	cout << "\nenter l = ";
	cin >> l;
}

void answer(const char* path1, const char* path2, int k, int l) {
	cout.width(7);
	cout << "\n//////////FIRST FILE//////////\n" << endl;
	readWithNumber("source1.bin", k);
	cout.width(7);
	cout << "//////////SECOND FILE//////////\n" << endl;
	readWithNumber("source2.bin", l);
}

void identityInit(int* matrix, int n) {
	int i = 0;
	for (int* identity = matrix; identity < matrix + n * n; identity++)
		*identity = 0;
	for (int* identity = matrix; identity < matrix + n * n; identity += n + 1)
		*identity = 1;
}

void identityWrite(const char* path, int n, int k) {
	ofstream out(path, ios::app, ios::binary);
	if (!out.is_open()) {
		cout << "\nERROR: in file is not open\n";
	}
	else {
		int* array = createMatrix(n);
		int size = n * n * sizeof(int);
		for (int i = 1; i <= k; i++) {
			identityInit(array, n);
			out.write((char*)array, size);
		}
		delete[] array;
	}
	out.close();
}

void processing(const char* path1, const char* path2, int& k, int n, int& l) {
	if (k > l&& k != 1) {
		int size = order(path2, l);
		identityWrite(path2, size, k - l);
		l = k;
	}
	else
		if (k < l && k != 1) {
			identityWrite(path1, n, l - k);
			k = l;
		}
}

void show(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout.width(5);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void show(int* matrix, int n) {
	for (int* p = matrix, count = 0; p < matrix + n * n; p++, count++) {
		if (!(count % n))
			cout << endl;
		cout.width(5);
		cout << *p;
	}
}

int* createMatrix(int n) {
	int* matrix = new int[n * n];
	return matrix;
}

void initMatrix(int* matrix, int n) {
	for (int* p = matrix; p < matrix + n * n; p++) {
		*p = rand() % 20;
	}
}

void writeBinary(const char* path, int n, int k) {
	ofstream out(path, ios::binary);
	if (!out.is_open()) {
		cout << "\nERROR: out file is not open\n";
	}
	else {
		int* array = createMatrix(n);
		int size = n * n * sizeof(int);
		for (int i = 1; i <= k; i++) {
			initMatrix(array, n);
			out.write((char*)array, size);
		}
		delete[] array;
	}
	out.close();
}

void readBinary(const char* path, int n) {
	ifstream in(path, ios::binary);
	if (!in.is_open()) {
		cout << "\nERROR: in file is not open\n";
	}
	else {
		int* array = createMatrix(n);
		int size = n * n * sizeof(int);
		while (in.read((char*)array, size)) {
			int** matrix = transform(array, n);
			show(matrix, n);
			cout << endl;
		}
		delete[] array;
	}
	in.close();
}

void readWithNumber(const char* path, int l) {
	ifstream in(path, ios::binary);
	if (!in.is_open()) {
		cout << "\nERROR: in file is not open\n";
	}
	else {
		int n = order(path, l);
		int size = n * n * sizeof(int);
		int* array = createMatrix(n);
		while (in.read((char*)array, size)) {
			int** matrix = transform(array, n);
			show(matrix, n);
			cout << endl;
		}
		delete[] array;
	}
	in.close();
}

int order(const char* path, int l) {
	ifstream in(path, ios::binary);
	int order;
	if (!in.is_open()) {
		cout << "\nERROR: in file is not open\n";
	}
	else {
		in.seekg(0, ios::end);
		order = sqrt(in.tellg() / l / sizeof(int));
	}
	in.close();
	return order;
}

int** transform(int* array, int n) {
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++) {
			matrix[i][j] = array[i * n + j];
		}
	}
	return matrix;
}
