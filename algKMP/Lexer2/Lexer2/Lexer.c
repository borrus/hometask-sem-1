#include <stdio.h>
#include <stdlib.h>

void commentsLexer(char* const path)
{
	FILE* file = fopen(path, "r");

	if (file == NULL)
	{
		printf("file is empty");
		return;
	}

	int state = 0;

	while (!feof(file))
	{
		char symbol = '\0';
		fscanf(file, "%c", &symbol);

		switch (state)
		{
		case 0:

			if (symbol == '/')
			{
				state = 1;
			}
			else
			{
				state = 0;
			}

			break;

		case 1:

			if (symbol == '/')
			{
				state = 1;
			}
			else if (symbol == '*')
			{
				state = 2;
			}
			else
			{
				state = 0;
			}

			break;

		case 2:

			if (symbol == '*')
			{
				state = 3;
			}
			else
			{
				state = 2;
				printf("%c", symbol);
			}

			break;

		case 3:

			if (symbol == '/')
			{
				state = 0;
			}
			else if (symbol == '*')
			{
				state = 3;
			}
			else
			{
				state = 2;
			}

			break;

		}
	}
}