typedef struct
{
	char brand[50];
	int size;
	char type[10];
	int frequency;
	float voltage;
} ram;

void init(ram** rams, int* N);

int inputSize(int* N);

void print(ram* rams, int* N);

void add(ram** rams, int* N);
