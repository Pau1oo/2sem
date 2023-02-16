#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


int inputSize(int* N)
{
	printf("Input number of ram: ");
	while (!scanf_s("%d", N) || *N < 0 || getchar() != '\n')
	{
		printf("Invalid input! Try again: ");
		rewind(stdin);
	}
	return *N;
}

void init(ram** rams, int* N)
{
	char buffer[128];
	*rams = (ram*)malloc(*N * sizeof(ram));

	for (int i = 0; i < *N; i++)
	{
		printf("Input name: ");
		scanf("%127s", buffer);
		*(*rams + i)->brand = (char*)malloc(strlen(buffer) + 1);
		strcpy((*rams)[i].brand, buffer);
		printf("size: ");
		scanf_s("%d", &(*rams)[i].size);
		printf("type: ");
		scanf("%127s", buffer);
		*(*rams + i)->type = (char*)malloc(strlen(buffer) + 1);
		strcpy((*rams)[i].type, buffer);
		printf("frequency: ");
		scanf_s("%d", &(*rams)[i].frequency);
		printf("voltage: ");
		scanf_s("%f", &(*rams)[i].voltage);
	}
}

void print(ram* rams, int* N)
{
	for (int i = 0; i < *N; i++)
	{
		printf("%10s%10d%10s\t%5dMHz\t%.2fV\n", 
			rams[i].brand, rams[i].size, rams[i].type, rams[i].frequency, rams[i].voltage);
	}
}