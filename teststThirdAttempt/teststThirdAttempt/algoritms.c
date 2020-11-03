#include <stdio.h>
#include <stdbool.h>
#include <string.h> 

int file()
{
	FILE* file = fopen("borchus.txt", "r");
	bool flag = true;
	

	if (file == NULL)
	{
		printf("couldnt get file");
		return 1;
	}

	char currentElement = '\0';
	char temp = '\0';
	
	while ((currentElement = fgetc(file)) != EOF)
	{
		if (!flag)
		{
			if (currentElement != temp)
			{
				printf("%c", temp);
			}
		}
		
	flag = false;
	temp = currentElement;
	}

	printf("%c", temp);

	fclose(file);
	return 0;
}
