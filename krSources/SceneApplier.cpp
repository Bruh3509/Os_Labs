#include "SceneApplier.h"
SceneApplier::SceneApplier(std::vector<float> &scenes, BankAccount *bankAccount)
	: operations{scenes},
	  bankAccount{bankAccount},
	  delayedOperations{},
	  attemptsCounter{0}
{
}

void SceneApplier::apply()
{
	for (auto operation : operations) {
		if (bankAccount->getValue() + operation < 0) {
			delayedOperations.push(operation);
		}
		else {
			bankAccount->change(operation);
		}

		cntrlDelayedOper();

		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void SceneApplier::cntrlDelayedOper()
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