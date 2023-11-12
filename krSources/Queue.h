#ifndef QUEUE_H
#define QUEUE_H
#include <queue>
#include <thread>
#include "BankAccountQueue.h"

class Queue : public std::queue<float>
{
private:
	static const int MAX_ATTEMPTS = 2;
	static const int MAX_SIZE = 4;
	std::queue<float> delayedOperations;
	BankAccountQueue *bankAccount;
	int attemptsCounter;

	void cntrlDelayedOper();

public:
	Queue(BankAccountQueue *);
	void apply();
	bool isFull();
};


#endif//QUEUE_H
