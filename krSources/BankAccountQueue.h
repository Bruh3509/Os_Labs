#ifndef BANKACCOUNTQUEUE_H
#define BANKACCOUNTQUEUE_H
#include "ConsoleInformation.h"
#include <thread>

class BankAccountQueue
{
private:
	float value;

public:
	BankAccountQueue();
	BankAccountQueue(float);
	void change(float operation);
	float getValue() const;
};


#endif//BANKACCOUNTQUEUE_H
