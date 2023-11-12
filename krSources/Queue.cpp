#include "Queue.h"
Queue::Queue(BankAccountQueue *bankAccount)
	: bankAccount{bankAccount},
	  delayedOperations{},
	  attemptsCounter{0}
{}

void Queue::apply()
{
	do {
		if (this->empty()) {
			std::this_thread::sleep_for(std::chrono::milliseconds(10));// if there is not operation -- exit
		}
		else {
			float operation = this->front();
			this->pop();
			if (bankAccount->getValue() + operation < 0) {
				delayedOperations.push(operation);
			}
			else {
				bankAccount->change(operation);
			}

			cntrlDelayedOper();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}

	} while (!this->empty() || !delayedOperations.empty());
}

void Queue::cntrlDelayedOper()
{
	if (!delayedOperations.empty()) {
		if (attemptsCounter >= MAX_ATTEMPTS) {
			delayedOperations.pop();
			attemptsCounter = 0;
		}
		if (bankAccount->getValue() + delayedOperations.front() >= 0) {
			bankAccount->change(delayedOperations.front());
			delayedOperations.pop();
			attemptsCounter = 0;
		}
		else {
			++attemptsCounter;
		}
	}
}

bool Queue::isFull()
{
	return this->size() == MAX_SIZE;
}