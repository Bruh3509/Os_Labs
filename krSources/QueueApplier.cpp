#include "QueueApplier.h"

QueueApplier::QueueApplier(std::vector<float> &operations, Queue *operationsQueue)
	: operations{operations},
	  operationsQueue{operationsQueue}
{}

void QueueApplier::pushToQueue()
{
	for (auto operation : operations) {
		while (operationsQueue->isFull()); // block
		std::lock_guard<std::mutex> guardMtx(mtx2); // ???
		operationsQueue->push(operation);
	}
}