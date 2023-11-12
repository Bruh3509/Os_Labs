#include "BankAccount.h"
BankAccount::BankAccount()
{
	value = 0;
}

BankAccount::BankAccount(float initialValue)
{
	this->value = initialValue;
}

void BankAccount::change(float operation)
{
	std::lock_guard<std::mutex> mtxGuard(mtx1);

	ConsoleInformation::calculationsEmulate();
	std::this_thread::sleep_for(std::chrono::milliseconds(75));
	float prevValue = this->value;
	this->value += operation;
	float curValue = this->value;

	ConsoleInformation::accountChange(prevValue, operation, curValue);
}

float BankAccount::getValue()
{
	std::lock_guard<std::mutex> mtxGuard(mtx1);
	return value;
}
