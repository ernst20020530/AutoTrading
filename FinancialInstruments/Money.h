#pragma once


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::istream;

class Money {

public:

	Money();
	Money(double asMoney);
	Money(int justDollars);
	Money(int withDollars, int withCents);

	friend const Money operator +(const Money& amount1, const Money& amount2);
	friend const Money operator -(const Money& amount1, const Money& amount2);

	//friend const Money operator %(const Money& amount, double percentage);

	friend bool operator ==(const Money& amount1, const Money& amount2);
	friend bool operator <(const Money& amount1, const Money& amount2);
	friend bool operator >(const Money& amount1, const Money& amount2);
	friend const Money operator -(const Money& amount1);
	friend ostream& operator <<(ostream& outputStream, const Money& amount);
	friend istream& operator >> (istream& inputStream, Money& amount);

	int getDollars() const { return dollars; }
	int getCents() const { return cents; }

	//int asCents(const Money& amount) const; // unused
	Money percent(const Money& amount, double percentage) const;

private:

	int dollars;
	int cents;
	int dollarsPart(double amount) const;
	int centsPart(double amount) const;
	int round(double number) const;
};