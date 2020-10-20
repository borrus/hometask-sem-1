#include <stdio.h>
#include <math.h>
#include <stdbool.h>
int fileTask3()
{
	FILE* file;
	file = fopen("source.txt", "r");
	if (file == NULL)
	{
		return 0;
		printf("file is not found");
	}
	char* str[128];
	while (!feof(file))
	{
		if (fgets(str, 126, file))
		{
			printf("%s", str);
		}
	}

	fclose(file);

	return 0;
}

int task1(int* array)
{
	int const length = 5;
	int arrayOfNumbers[5];
	for (int i = 0; i < length; ++i)
	{
		int temp = 0;
		int tem = array[i];
		while (tem != 0)
		{
			++temp;
			tem /= 10;
		}
		arrayOfNumbers[i] = temp;
	}

	int max = -1;
	for (int i = 0; i < length; ++i)
	{
		if (arrayOfNumbers[i] > max)
		{
			max = arrayOfNumbers[i];
		}
	}

	for (int i = 0; i < length; ++i)
	{
		if (arrayOfNumbers[i] == max)
		{
			printf("%d ", array[i]);
		}
	}

	return 0;
}

int file()
{
	FILE* file = fopen("source.txt", "r");
	char start = '\0';
	bool add = false;
	while ((start = fgetc(file)) != EOF)
	{
		if (start == ';')
		{
			add = true;
		}
	}
	if (add)
	{
		printf("%c", start);
	}
	if (start == '\n')
	{
		add = false;
	}

	fclose(file);
}


