#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "ConsoleInformation.h"
#include <mutex>
#include <thread>

class BankAccount
{
private:
	float value;
	std::mutex mtx1;

public:
	BankAccount();
	BankAccount(float);
	void change(float operation);
	float getValue();
};


#endif//BANKACCOUNT_H
