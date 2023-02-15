#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
	int N; ram* rams = NULL;

	inputSize(&N);
	init(&rams, &N);
	print(rams, &N);
}