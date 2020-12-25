#include "list.h"
#include <stdio.h>

void printMatrix(int const* const* matrix, int const size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int nearestCityToCity(int const city, List* unVisitedCitites, int const* const* matrix)
{
	Node* nearestCity = unVisitedCitites->root;
	int cityNumber = -1;

	int minDistance = 1000;
	while (nearestCity != NULL)
	{
		int currentDistance = matrix[city][nearestCity->value];
		if (currentDistance > 0 && currentDistance < minDistance)
		{
			minDistance = currentDistance;
			cityNumber = nearestCity->value;
		}

		nearestCity = nearestCity->next;
	}

	return cityNumber;
}

int nearestCityToCountry(int const country, List* unVisitedCitites, List const* const* countries, int const* const* matrix)
{
	Node* cityInCountry = countries[country]->root;

	int minDistance = 1000;
	int countryNumber = -1;

	while (cityInCountry != NULL)
	{
		int nc = nearestCityToCity(cityInCountry->value, unVisitedCitites, matrix);
		int currentDistance = matrix[cityInCountry->value][nc];
		if (currentDistance < minDistance)
		{
			minDistance = currentDistance;
			countryNumber = nc;
		}

		cityInCountry = cityInCountry->next;
	}

	return countryNumber;
}

void task()
{
	FILE* file = fopen("test.txt", "r");

	if (file == NULL)
	{
		return 0;
	}

	int amountOfCities = 0;
	fscanf(file, "%d", &amountOfCities);

	int amountOfRoads = 0;
	fscanf(file, "%d", &amountOfRoads);

	int** matrix = (int**)malloc(amountOfCities * sizeof(int*));
	for (int i = 0; i < amountOfCities; ++i)
	{
		matrix[i] = (int*)malloc(amountOfCities * sizeof(int));
	}

	for (int i = 0; i < amountOfCities; ++i)
	{
		for (int j = 0; j < amountOfCities; ++j)
		{
			matrix[i][j] = 0;
		}
	}

	for (int k = 0; k < amountOfRoads; ++k)
	{
		int i = 0;
		fscanf(file, "%d", &i);

		int j = 0;
		fscanf(file, "%d", &j);

		int len = 0;
		fscanf(file, "%d", &len);

		matrix[i][j] = len;
		matrix[j][i] = len;
	}

	int amountOfCapitals = 0;
	fscanf(file, "%d", &amountOfCapitals);

	List** countries = (List**)malloc(amountOfCapitals * sizeof(List*));
	for (int i = 0; i < amountOfCapitals; ++i)
	{
		countries[i] = initializeList();
	}

	List* unVisitedCitites = initializeList();
	for (int i = 1; i <= amountOfCities; ++i)
	{
		pushBack(unVisitedCitites, i);
	}

	for (int i = 0; i < amountOfCapitals; ++i)
	{
		int capital = 0;
		fscanf(file, "%d", &capital);

		pushBack(countries[i], capital);
		deleteNodeByValue(unVisitedCitites, capital);
	}

	for (int i = 0; i < amountOfCapitals && unVisitedCitites->size > 0; ++i)
	{
		int nc = nearestCityToCountry(i, unVisitedCitites, countries, matrix);

		if (nc > 0)
		{
			pushBack(countries[i], nc);
			deleteNodeByValue(unVisitedCitites, nc);
		}
	}

	for (int i = 0; i < amountOfCapitals; ++i)
	{
		printList(countries[i]);
	}

	printf("\n\n");
	printf("matrix\n");
	printMatrix(matrix, amountOfCities);
}

int main()
{
	task();

	return 0;
}