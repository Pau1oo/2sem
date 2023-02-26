#define ERROR_OPEN_FILE -3
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "functions.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	FILE* f;

	f = fopen("C:/Users/bukat/Desktop/~/Œ¿Ëœ/2sem/2 Î‡·‡/task/text.txt", "r+t");
	if (f == NULL)
	{
		printf("Error opening file");
		getch();
		exit(ERROR_OPEN_FILE);
	}
}