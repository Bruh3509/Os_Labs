#include "BankAccountQueue.h"
BankAccountQueue::BankAccountQueue()
{
	value = 0;
}

BankAccountQueue::BankAccountQueue(float initialValue)
{
	this->value = initialValue;
}

void BankAccountQueue::change(float operation)
{

	ConsoleInformation::calculationsEmulate();
	std::this_thread::sleep_for(std::chrono::milliseconds(75));
	float prevValue = this->value;
	this->value += operation;
	float curValue = this->value;

	ConsoleInformation::accountChange(prevValue, operation, curValue);
}

float BankAccountQueue::getValue() const
{
	return value;
}
