#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


int inputSize(int* N)
{
	printf("Input number of ram: ");
	while (!scanf_s("%d", N) || *N <= 0 || getchar() != '\n')
	{
		printf("Invalid input!\n");
		rewind(stdin);
		printf("Input number of ram: ");
	}
	return *N;
}

void init(ram** rams, int* N)
{
	char* buffer = malloc(128);
	*rams = (ram*)malloc(*N * sizeof(ram));

	for (int i = 0; i < *N; i++)
	{
		printf("Input name: ");
		scanf("%127s", buffer);
		*(*rams + i)->brand = (char*)malloc(strlen(buffer) + 1);
		strcpy((*rams)[i].brand, buffer);

		printf("size(e.g. 8): ");
		while (!scanf_s("%d", &(*rams)[i].size) || (*rams)[i].size <= 0 || getchar() != '\n')
		{
			printf("Invalid input!\n");
			rewind(stdin);
			printf("size(e.g. 8): ");
		}

		printf("type(e.g. DDR4): ");
		scanf("%127s", buffer);
		*(*rams + i)->type = (char*)malloc(strlen(buffer) + 1);
		strcpy((*rams)[i].type, buffer);

		printf("frequency(e.g. 3200): ");
		while (!scanf_s("%d", &(*rams)[i].frequency) || (*rams)[i].frequency <= 0 || getchar() != '\n')
		{
			printf("Invalid input!\n");
			rewind(stdin);
			printf("frequency(e.g. 3200): ");
		}

		printf("voltage(e.g. 1.3): ");
		while (!scanf_s("%f", &(*rams)[i].voltage) || (*rams)[i].voltage <= 0 || getchar() != '\n')
		{
			printf("Invalid input!\n");
			rewind(stdin);
			printf("voltage(e.g. 1.3): ");
		}
	}
}

void print(ram* rams, int* N)
{
	for (int i = 0; i < *N; i++)
	{
		printf("%10s%5dGb%10s\t%5dMHz\t%.2fV\n", 
			rams[i].brand, rams[i].size, rams[i].type, rams[i].frequency, rams[i].voltage);
	}
}

void add(ram** rams, int* N)
{
	(*N)++;
	char* buffer = malloc(128);
	*rams = (ram*)realloc(*rams, (*N) * sizeof(ram));
	int i = (*N) - 1;

	printf("Input name: ");
	scanf("%127s", buffer);
	*(*rams + i)->brand = (char*)malloc(strlen(buffer) + 1);
	strcpy((*rams)[i].brand, buffer);

	printf("size(e.g. 8): ");
	while (!scanf_s("%d", &(*rams)[i].size) || (*rams)[i].size <= 0 || getchar() != '\n')
	{
		printf("Invalid input!\n");
		rewind(stdin);
		printf("size(e.g. 8): ");
	}

	printf("type(e.g. DDR4): ");
	scanf("%127s", buffer);
	*(*rams + i)->type = (char*)malloc(strlen(buffer) + 1);
	strcpy((*rams)[i].type, buffer);

	printf("frequency(e.g. 3200): ");
	while (!scanf_s("%d", &(*rams)[i].frequency) || (*rams)[i].frequency <= 0 || getchar() != '\n')
	{
		printf("Invalid input!\n");
		rewind(stdin);
		printf("frequency(e.g. 3200): ");
	}

	printf("voltage(e.g. 1.3): ");
	while (!scanf_s("%f", &(*rams)[i].voltage) || (*rams)[i].voltage <= 0 || getchar() != '\n')
	{
		printf("Invalid input!\n");
		rewind(stdin);
		printf("voltage(e.g. 1.3): ");
	}
}

void delete(ram* rams, int* N) 
{
	char* name = malloc(0);
	printf("Input name: ");
	rewind(stdin);
	gets(name);

	for (int i = 0; i < *N; i++)
	{
		if (!strcmp(rams[i].brand, name)) 
		{
			for (int j = i; j < *N - 1; j++) 
			{
				rams[j] = rams[j + 1];
			}
			(*N)--;
			break;
		}
	}
}