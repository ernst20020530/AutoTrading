

#include "stdafx.h"
#include "Money.h"


Money Money::percent(const Money& amount, double percentage) const {
	int amountToCents = amount.getCents() + amount.getDollars() * 100;
	double pScaledMoney = amountToCents * percentage;
	int scaledDollars = abs((round(fabs(pScaledMoney / 100))) / 100);
	int scaledCents = abs((round(fabs(pScaledMoney / 100))) % 100);
	if (pScaledMoney < 0) {
		scaledDollars = -scaledDollars;
		scaledCents = -scaledCents;
	}
	return Money(scaledDollars, scaledCents);
}

// Varying constructors
Money::Money() : dollars(0), cents(0) {}
Money::Money(int justDollars) : dollars(justDollars), cents(0) {}
Money::Money(double asMoney) : dollars(dollarsPart(asMoney)), cents(centsPart(asMoney)) {}
Money::Money(int withDollars, int withCents) {
	dollars = withDollars;
	cents = withCents;
}

const int asCents(const Money& amount) {
	int amountAsCents = amount.getCents() + amount.getDollars() * 100;
	return amountAsCents;
}

ostream& operator <<(ostream& outputStream, const Money& amount) {
	int absDollars = abs(amount.dollars);
	int absCents = abs(amount.cents);
	if (amount.dollars < 0 || amount.cents < 0)
		outputStream << "$-";
	else
		outputStream << '$';
	outputStream << absDollars;
	if (absCents >= 10)
		outputStream << '.' << absCents;
	else
		outputStream << '.' << '0' << absCents;
	return outputStream;
}

istream& operator >> (istream& inputStream, Money& amount) {
	char dollarSign;
	while (inputStream >> dollarSign && dollarSign != '$') {
		cout << "\nPlease enter a dollar sign ($) for money input.\n" << endl;
		cin.ignore();
		cout << "Enter an amount of money: ";
	}
	double amountAsDouble;
	inputStream >> amountAsDouble;
	amount.dollars = amount.dollarsPart(amountAsDouble);
	amount.cents = amount.centsPart(amountAsDouble);
	return inputStream;
}

const Money operator +(const Money& amount1, const Money& amount2) {
	int centsSum = asCents(amount1) + asCents(amount2);
	int absAllCents = abs(centsSum);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;
	if (centsSum < 0) {
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}
	return Money(finalDollars, finalCents);
}

const Money operator -(const Money& amount1, const Money& amount2) {
	int centsDifference = asCents(amount1) - asCents(amount2);
	int absAllCents = abs(centsDifference);
	int finalDollars = absAllCents / 100;
	int finalCents = absAllCents % 100;
	if (centsDifference < 0) {
		finalDollars = -finalDollars;
		finalCents = -finalCents;
	}
	return Money(finalDollars, finalCents);
}

bool operator ==(const Money& amount1, const Money& amount2) {
	return ((amount1.getDollars() == amount2.getDollars())
		&& (amount1.getCents() == amount2.getCents()));
}

bool operator <(const Money& amount1, const Money& amount2) {
	return ((amount1.getDollars() < amount2.getDollars())
		&& (amount1.getCents() < amount2.getCents()));
}

bool operator >(const Money& amount1, const Money& amount2) {
	return ((amount1.getDollars() > amount2.getDollars())
		&& (amount1.getCents() > amount2.getCents()));
}

const Money operator -(const Money& amount) {
	return Money(-amount.getDollars(), -amount.getCents());
}

int Money::dollarsPart(double amount) const { return static_cast<int>(amount); }
int Money::round(double amount) const { return static_cast<int>(floor(amount + 0.5)); }

int Money::centsPart(double amount) const {
	double doubleCents = amount * 100;
	int intCents = (round(fabs(doubleCents))) % 100;
	if (amount < 0)
		intCents = -intCents;
	return intCents;
}