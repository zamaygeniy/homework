#include <iostream>
#include <cstring>
#include "Country.h"

using namespace std;

Country::Country(char* name, char* capital, char* language, char* currency, char* statehood, char* ceo, int population, double area) {
	this->SetCountry(name, capital, language, currency, statehood, ceo, population, area);
}

void Country::SetCountry(char* name, char* capital, char* language, char* currency, char* statehood, char* ceo, int population, double area) {
	this->SetArea(area);
	this->SetName(name);
	this->SetCapital(capital);
	this->SetLanguage(language);
	this->SetCurrency(currency);
	this->SetCEO(ceo);
	this->SetStatehood(statehood);
	this->SetPopulation(population);
}

void Country::SetName(char* name) {
	strcpy(this->name, name);
}
void Country::SetCapital(char* capital) {
	strcpy(this->capital, capital);
}
void Country::SetLanguage(char* language) {
	strcpy(this->language, language);
}
void Country::SetArea(double area) {
	this->area = area;
}
void Country::SetCurrency(char* currency) {
	strcpy(this->currency, currency);
}
void Country::SetPopulation(int population) {
	this->population = population;
}
void Country::SetCEO(char* ceo) {
	strcpy(this->ceo, ceo);
}
void Country::SetStatehood(char* statehood) {
	strcpy(this->statehood, statehood);
}

char* Country::GetName() {
	return this->name;
}
char* Country::GetCapital() {
	return this->capital;
}
char* Country::GetLanguage() {
	return this->language;
}
char* Country::GetCurrency() {
	return this->currency;
}
char* Country::GetCEO() {
	return this->ceo;
}
char* Country::GetStatehood() {
	return this->statehood;
}
double Country::GetArea() {
	return this->area;
}
int Country::GetPopulation() {
	return this->population;
}

void Country::DisplayCountry() {
	cout << "----------------8<-------------------------------------------" << endl;
	cout << this->name << endl;
	cout.precision(3);
	cout << "Capital: " << this->capital << endl;
	cout << "Language: " << this->language << endl;
	cout << "Population: " << this->population << " p." << endl;
	std::cout.setf(std::ios::fixed);
	std::cout.precision(0);
	cout << "Country area: " << this->area << " m." << endl;
	cout << "Currency: " << this->currency << endl;
	cout << "Statehood: " << this->statehood << endl;
	cout << "CEO: " << this->ceo << endl;
}


void Country::DisplayCountryOnly() {
	cout << this->name << endl;
}


void Country::EnterCountry() {
	const int N = 256;
	char name[N] = "", capital[N] = "", language[N] = "", currency[N] = "", statehood[N] = "", ceo[N] = "";

	cout << "Enter the name of the country:";
	
	cin.getline(name, N, '\n');
	cout << "Enter the capital of the country:";
	cin.getline(capital, N, '\n');
	cout << "Enter the language of the country:";
	cin.getline(language, N, '\n');

	cin.ignore();
	cout << "Enter the population of the country:";
	int population;
	cin >> population;
	if (population < 0) //потом доделаю
		population = 1;
	cin.ignore();
	cout << "Enter the country area:";
	double  area;
	cin >> area;
	if (area < 0)
		area = 1;

	cout << "Enter the currency of the country:";
	cin.getline(currency, N, '\n');
	cout << "Enter the statehood of the country:";
	cin.getline(statehood, N, '\n');
	cout << "Enter the CEO of the country:";
	cin.getline(ceo, N, '\n');
	

	this->SetCountry(name, capital, language, currency, statehood, ceo, population, area);
}