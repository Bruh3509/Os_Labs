#ifndef SCENEAPPLIER_H
#define SCENEAPPLIER_H
#include "BankAccount.h"
#include <queue>
#include <vector>

class SceneApplier
{
private:
	static const int MAX_ATTEMPTS = 2;
	std::vector<float> operations;
	std::queue<float> delayedOperations;
	void cntrlDelayedOper();
	BankAccount *bankAccount;
	int attemptsCounter;

public:
	SceneApplier(std::vector<float> &, BankAccount *bankAccount);
	void apply();
};


#endif//SCENEAPPLIER_H
