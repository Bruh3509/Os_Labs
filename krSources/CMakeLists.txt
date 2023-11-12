cmake_minimum_required(VERSION 2.26)
project(os_kr)

set(CMAKE_CXX_STANDARD 17)

add_executable(os_kr main.cpp
		BankAccount.cpp
		BankAccount.h
		ConsoleInformation.cpp
		ConsoleInformation.h
		SceneApplier.cpp
		SceneApplier.h
		Queue.cpp
		Queue.h
		QueueApplier.cpp
		QueueApplier.h
		BankAccountQueue.cpp
		BankAccountQueue.h)
