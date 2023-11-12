#include "ConsoleInformation.h"

void ConsoleInformation::accountChange(float prevValue, float operation, float curValue)
{
	printf("Was=%f, operation %f, now=%f\n", prevValue, operation, curValue);
}

void ConsoleInformation::calculationsEmulate()
{
	printf("Calculating...\n");
}