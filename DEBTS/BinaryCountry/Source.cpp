#include <io.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include "Country.h"

using namespace std;

void InitFile(char*);
void DisplayFile(char*);
void AddToEndFile(char*);
void ChangeFile(char*);
void RemoveFromFile(char*);
void InitNumber(long&);
void SystemFun();
void InitNameFile(char*);
int Menu();
void DisplayCountry(char*);
int CompareString(char*, char*);
void SortingFile(char*);
int SortMenu();
int Compare(Country, Country, int);
int CompareInt(int, int);
int CompareDouble(double, double);


int main() {

	char fileName[N] = "List.bin";
	enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
	while (true) {
		int Key = Menu();
		if (Key == Exit)
			return 0;
		system("cls");
		switch (Key) {
		case Init:
			InitNameFile(fileName);
			SystemFun();
			break;
		case Create:
			InitFile(fileName);
			SystemFun();
			break;
		case Display:
			DisplayFile(fileName);
			SystemFun();
			break;
		case Add:
			AddToEndFile(fileName);
			SystemFun();
			break;
		case Change:
			ChangeFile(fileName);
			SystemFun();
			break;
		case Remove:
			RemoveFromFile(fileName);
			SystemFun();
			break;
		case Sort:
			SortingFile(fileName);
			SystemFun();
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}
	}
}

void InitFile(char* fileName) {
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open()) {
		cout << "\nCan't open file to write!";
		SystemFun();
		return;
	}
	int buffSize = sizeof(Country);
	Country country;
	char Ok = 'y';
	while (Ok == 'y') {
		country.EnterCountry();
		streamOut.write((char*)&country, buffSize);
		cout << " If do you want to continue, press 'y' :";
		cin >> Ok;
	}
	streamOut.close();
}

void AddToEndFile(char* fileName) {
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open()) {
		cout << "Can't open file to write!";
		SystemFun();
		return;
	}
	int buffSize = sizeof(Country);
	Country country;
	char Ok = 'y';
	while (Ok == 'y') {
		country.EnterCountry();
		streamOut.write((char*)&country, buffSize);
		cout << " If do you want to continue, press 'y' : ";
		cin >> Ok;
	}
	streamOut.close();
}

void ChangeFile(char* fileName) {
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut) {
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	DisplayCountry(fileName);
	int buffSize = sizeof(Country);
	Country country;
	long Position;
	InitNumber(Position);
	streamInOut.seekp((Position - 1) * buffSize, ios::beg);
	country.EnterCountry();
	streamInOut.write((char*)&country, buffSize);
	streamInOut.close();
}

void RemoveFromFile(char* fileName) {
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut.is_open()) {
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	DisplayCountry(fileName);
	streamInOut.seekp(0, ios::end);
	long N = streamInOut.tellp();
	int buffSize = sizeof(Country);
	Country country;
	long Position;
	InitNumber(Position);
	streamInOut.seekp(Position * buffSize, ios::beg);
	while (streamInOut.read((char*)&country, buffSize)) {
		streamInOut.seekp(-2 * buffSize, ios::cur);
		streamInOut.write((char*)&country, buffSize);
		streamInOut.seekp(buffSize, ios::cur);
	}
	streamInOut.close();
	int DiskriptorFile = open(fileName, 2);
	chsize(DiskriptorFile, N - buffSize);
	close(DiskriptorFile);
}

void SortingFile(char* fileName) {

	int sortNumber = SortMenu();
	bool flag = true;

	while (flag) {
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open()) {
			cout << "Can't open file to read and write!";
			SystemFun();
			return;
		}

		flag = false;
		Country countryOne, countryTwo;
		int buffSize = sizeof(Country);
		streamInOut.read((char*)&countryOne, buffSize);

		while (streamInOut.read((char*)&countryTwo, buffSize)) {
			if (Compare(countryOne, countryTwo, sortNumber)) {
				streamInOut.seekp(-2 * buffSize, ios::cur);
				streamInOut.write((char*)&countryTwo, buffSize);
				streamInOut.write((char*)&countryOne, buffSize);
				flag = true;
			}
			streamInOut.seekp(-buffSize, ios::cur);
			streamInOut.read((char*)&countryOne, buffSize);
		}
		streamInOut.close();
	}
}

void DisplayFile(char* fileName) {

	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open()) {
		cout << "Can't open file to read!";
		SystemFun();
		return;
	}

	int buffSize = sizeof(Country);
	Country* country = new Country;

	while (streamIn.read((char*)country, buffSize)) {
		country->DisplayCountry();
	}
	streamIn.close();
}

void DisplayCountry(char* fileName) {

	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open()) {
		cout << "Can't open file to read!";
		SystemFun();
		return;
	}

	int buffSize = sizeof(Country);
	Country* country = new Country;
	int counter = 0;
	cout << "List of avaliable countries:\n";

	while (streamIn.read((char*)country, buffSize)) {
		cout << ++counter << ") ";
		country->DisplayCountryOnly();
	}
	streamIn.close();
}

void InitNumber(long& n) {
	cout << "Enter the number of the country: " << endl;
	cin >> n;
	system("cls");
}

void SystemFun() {
	cout << endl;
	system("pause");
	system("cls");
}

int SortMenu() {
	cout << "1) Name\n";
	cout << "2) Capital\n";
	cout << "3) Language\n";
	cout << "4) Currency\n";
	cout << "5) Statehood\n";
	cout << "6) CEO\n";
	cout << "7) Population\n";
	cout << "8) Area\n";
	cout << "Enter the number of sort: ";
	int a;
	cin >> a;
	//system("cls");
	return a;
}

void InitNameFile(char* fileName) {
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}

int Menu() {
	int k;
	cout << "Enter the number - the mode of operations with file:"
		"\n 1 - INITIALIZATION THE NAME OF FILE"
		"\n 2 - FORMATION OF THE FILE"
		"\n 3 - VIEWING OF CONTENTS OF THE FILE"
		"\n 4 - ADD AN ELEMENT TO AND OF FILE"
		"\n 5 - CHANGE THE ELEMENT IN THE FILE"
		"\n 6 - REMOVE THE ELEMENT IN THE FILE"
		"\n 7 - SORTING THE ELEMENT IN THE FILE"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}



int CompareString(char* lhs, char* rhs) {
	size_t i = 0;
	for (; i < strlen(lhs) && i < strlen(rhs); ++i) {
		if (lhs[i] < rhs[i]) return 1;
		if (lhs[i] > rhs[i]) return 0;
	}
	if (strlen(lhs) < strlen(rhs))
		return 1;
	return 0;
}

int Compare(Country lhs, Country rhs, int n) {
	
	int CompareResult = 0;

	switch (n) {
	case 1:
		CompareResult = CompareString(lhs.GetName(), rhs.GetName());
		break;
	case 2:
		CompareResult = CompareString(lhs.GetCapital(), rhs.GetCapital());
		break;
	case 3:
		CompareResult = CompareString(lhs.GetLanguage(), rhs.GetLanguage());
		break;
	case 4:
		CompareResult = CompareString(lhs.GetCurrency(), rhs.GetCurrency());
		break;
	case 5:
		CompareResult = CompareString(lhs.GetStatehood(), rhs.GetStatehood());
		break;
	case 6:
		CompareResult = CompareString(lhs.GetCEO(), rhs.GetCEO());
		break;
	case 7:
		CompareResult = CompareInt(lhs.GetPopulation(), rhs.GetPopulation());
		break;
	case 8:
		CompareResult = CompareDouble(lhs.GetArea(), rhs.GetArea());
		break;
	default:
		break;
	}

	return CompareResult;

}


int CompareInt(int lhs, int rhs) {
	if (lhs > rhs)
		return 1;
	return 0;
}

int CompareDouble(double lhs, double rhs) {
	if (lhs > rhs)
		return 1;
	return 0;
}