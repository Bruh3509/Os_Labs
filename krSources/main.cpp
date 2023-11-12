#include "BankAccount.h"
#include "BankAccountQueue.h"
#include "QueueApplier.h"
#include "SceneApplier.h"
#include <vector>
#include <string>

int main(int argc, char **argv)
{
	std::vector<float> scene1({-5, -21, 13});
	std::vector<float> scene2({13, 5, -3});
	std::vector<float> scene3;
	scene3.reserve(argc - 1);

	// input only one scene, others to test.
	if (argc > 1) {
		for (int i = 1; i < argc; ++i) {
			scene3.push_back(std::stof(argv[i]));
		}
	}


	// version1, with the direct account change
	BankAccount bankAccount;
	SceneApplier sceneApplier1(scene1, &bankAccount);
	SceneApplier sceneApplier2(scene2, &bankAccount);
	SceneApplier sceneApplier3(scene3, &bankAccount);

	std::thread threadScene1(&SceneApplier::apply, sceneApplier1);
	std::thread threadScene2(&SceneApplier::apply, sceneApplier2);
	std::thread threadScene3(&SceneApplier::apply, sceneApplier3);

	threadScene1.join();
	threadScene2.join();
	threadScene3.join();

	// version2, with the queue account change
	printf("\n\nVersion2(Queue).\n\n");
	BankAccountQueue bankAccountQueue;
	Queue queue(&bankAccountQueue);
	QueueApplier queueApplier1(scene1, &queue);
	QueueApplier queueApplier2(scene2, &queue);
	QueueApplier queueApplier3(scene3, &queue);

	std::thread threadSceneQueue1([&]() {
		queueApplier1.pushToQueue();
	});
	std::thread threadSceneQueue2([&]() {
		queueApplier2.pushToQueue();
	});
	std::thread threadSceneQueue3([&]() {
		queueApplier3.pushToQueue();
	});
	queue.apply();

	threadSceneQueue1.join();
	threadSceneQueue2.join();
	threadSceneQueue3.join();
	return 0;
}
