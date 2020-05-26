#pragma once
const int N = 50;

class Country
{
public:
	Country() {}
	Country(char*, char*, char*, char*, char*, char*, int, double);
	~Country() {}
	void SetName(char*);
	void SetCapital(char*);
	void SetLanguage(char*);
	void SetCurrency(char*);
	void SetStatehood(char*);
	void SetCEO(char*);
	void SetPopulation(int);
	void SetArea(double);
	void SetCountry(char*, char*, char*, char*, char*, char*, int, double);

	char* GetName();
	char* GetCapital();
	char* GetCurrency();
	char* GetLanguage();
	char* GetStatehood();
	char* GetCEO();
	int GetPopulation();
	double GetArea();

	void EnterCountry();
	void DisplayCountry();
	void DisplayCountryOnly();
private:
	char name[N], capital[N], language[N], currency[N], statehood[N], ceo[N];
	int population;
	double area;
};