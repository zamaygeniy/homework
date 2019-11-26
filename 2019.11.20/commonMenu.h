#if !defined COMMONMENU_H
#define COMMONMENU_H

using namespace std;

void menu();
void menuText();
//void runTests();
void workWithConsole();

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	//cout << "Press 2 to run tests." << endl;
	cout << "Press 3 to exit." << endl;
}

void menu()
{
	while (true)
	{
		char operation;
		menuText();
		cin >> operation;

		switch (operation)
		{
		case '1':
			workWithConsole();
			break;
		/*case '2':
			runTests();
			break;*/
		case '3':
			return;
		default:
			cout << "Invalid operation. Try again." << endl;
		}
		system("pause");
		system("cls");
	}
}

//void runTests()
//{
//	int testNumber = 1;
//	SortTests(testNumber++, -10, 10);
//	SortTests(testNumber++, -3, 3);
//	SortTests(testNumber++, 0, 0);
//	SortTests(testNumber++, 2, 4);
//	SortTests(testNumber++, -5, 10);
//}

void workWithConsole()
{
	int n;
	cout << "Enter the size of the string n = ";
	cin >> n;
	cout << endl << "Enter the elements of the string" << endl;

	char* string = AllocateMemory(n);
	char* stringref = &string[0];
	InputArray(stringref, n);

	int subn;
	cout << "Enter the size of the substring subn = ";
	cin >> subn;
	cout << endl << "Enter the elements of the substring" << endl;

	char* substring = AllocateMemory(subn);
	char* substringref = &substring[0];
	InputArray(substringref, subn);

	cout << "Search " << Searching(stringref, n, substringref, subn) << endl;

	DeleteMemory(stringref);
	DeleteMemory(substringref);
}

#endif