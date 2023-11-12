#ifndef QUEUEAPPLIER_H
#define QUEUEAPPLIER_H
#include "Queue.h"
#include <vector>
#include <thread>
#include <mutex>

class QueueApplier
{
private:
	std::vector<float> operations;
	Queue *operationsQueue;
	std::mutex mtx2;

public:
	QueueApplier(std::vector<float> &, Queue *);
	void pushToQueue();
};


#endif//QUEUEAPPLIER_H
