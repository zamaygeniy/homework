#include <iostream>
#include <fstream>

using namespace std;

int* creatematrix(int, int);
int* creatematrix(int);
void initmatrix(int*, int, int);
void initmatrix(int*, int);
void writebinary(const char*, int, int);
void readbinary(const char*, int);
void show(int*, int, int);
void show(int*, int);
int** transform(int*, int);
void processing(const char*, const char*, int&, int, int&);
void identitywrite(const char*, int, int);
void identityinit(int*, int);
int order(const char*, int);
void readwnumber(const char*, int);
void answer(const char*, const char*, int, int);
void enter(int&, int&, int&);

int main()
{
	int k, n, l;
	enter(k, n, l);
	writebinary("source1.bin", n, k);
	writebinary("source2.bin", rand() % 5 + 1, l);
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
	readwnumber("source1.bin", k);
	cout.width(7);
	cout << "//////////SECOND FILE//////////\n" << endl;
	readwnumber("source2.bin", l);
}

void identityinit(int* matrix, int n) {

	int i = 0;
	for (int* p = matrix; p < matrix + n * n; p++)
	{
		*p = 0;
	}
	for (int* p = matrix; p < matrix + n * n; p += n + 1)
	{
		*p = 1;
	}
}

void identitywrite(const char* path, int n, int k) {
	ofstream out(path, ios::app, ios::binary);
	int* a = creatematrix(n);
	int size = n * n * sizeof(int);
	for (int i = 1; i <= k; i++)
	{
		identityinit(a, n);
		out.write((char*)a, size);
	}
	delete[] a;
	out.close();
}

void processing(const char* path1, const char* path2, int& k, int n, int& l) {

	if (k > l && k != 1) {
		int size = order(path2, l);
		identitywrite(path2, size, k - l);
		l = k;
	}
	else
		if (k < l && k != 1) {
			identitywrite(path1, n, l - k);
			k = l;
		}
}

void show(int** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(5);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void show(int* matrix, int n, int m)
{
	for (int* p = matrix, count = 0; p < matrix + m * n; p++, count++)
	{
		if (!(count % m))
		{
			cout << endl;
		}
		cout.width(5);
		cout << *p;
	}
}

void show(int* matrix, int n)
{
	for (int* p = matrix, count = 0; p < matrix + n * n; p++, count++)
	{
		if (!(count % n))
		{
			cout << endl;
		}
		cout.width(5);
		cout << *p;
	}
}

int* creatematrix(int n, int m)
{
	int* matrix = new int[n * m];
	return matrix;
}

int* creatematrix(int n)
{
	int* matrix = new int[n * n];
	return matrix;
}

void initmatrix(int* matrix, int n, int m)
{
	for (int* p = matrix; p < matrix + m * n; p++)
	{
		*p = rand() % 20;
	}
}

void initmatrix(int* matrix, int n)
{
	for (int* p = matrix; p < matrix + n * n; p++)
	{
		*p = rand() % 20;
	}
}

void writebinary(const char* path, int n, int k)
{
	ofstream out(path, ios::binary);
	//TODO validation
	int* a = creatematrix(n);
	int size = n * n * sizeof(int);
	for (int i = 1; i <= k; i++)
	{
		initmatrix(a, n);
		out.write((char*)a, size);
	}
	delete[] a;
	out.close();
}

void readbinary(const char* path, int n)
{
	ifstream in(path, ios::binary);
	int* a = creatematrix(n);
	int size = n * n * sizeof(int);
	while (in.read((char*)a, size))
	{
		int** matrix = transform(a, n);
		show(matrix, n);
		cout << endl;
	}
	delete[] a;
	in.close();
}

void readwnumber(const char* path, int l)
{
	ifstream in(path, ios::binary);
	int n = order(path, l);
	int size = n * n * sizeof(int);
	int* a = creatematrix(n);

	while (in.read((char*)a, size))
	{
		int** matrix = transform(a, n);
		show(matrix, n);
		cout << endl;
	}

	delete[] a;
	in.close();
}

int order(const char* path, int l)
{
	ifstream in(path, ios::binary);
	in.seekg(0, ios::end);
	int n = sqrt(in.tellg() / l / sizeof(int));
	in.close();
	return n;
}

int** transform(int* arr, int n)
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = arr[i * n + j];
		}
	}
	return matrix;
}