#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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

int nearestCityToCity(int const city, List* unvisitedCitites, int const* const* matrix)
{
	Node* nearestCity = getListRoot(unvisitedCitites);
	int cityNumber = -1;

	int minDistance = _CRT_INT_MAX;

	while (nearestCity != NULL)
	{
		int currentDistance = matrix[city][getNodeValue(nearestCity)];

		if (currentDistance > 0 && currentDistance < minDistance)
		{
			minDistance = currentDistance;
			cityNumber = getNodeValue(nearestCity);
		}

		nearestCity = getNextNode(nearestCity);
	}

	return cityNumber;
}

int nearestCityToCountry(int const country, List* unvisitedCitites, List const* const* countries, int const* const* matrix)
{
	Node* cityInCountry = getListRoot(countries[country]);

	int minDistance = 1000;
	int countryNumber = -1;

	while (cityInCountry != NULL)
	{
		int nearestCity = nearestCityToCity(getNodeValue(cityInCountry), unvisitedCitites, matrix);
		int currentDistance = matrix[getNodeValue(cityInCountry)][nearestCity];

		if (currentDistance < minDistance)
		{
			minDistance = currentDistance;
			countryNumber = nearestCity;
		}

		cityInCountry = getNextNode(cityInCountry);
	}

	return countryNumber;
}

void task()
{
	FILE* file = fopen("test.txt", "r");

	if (file == NULL)
	{
		return;
	}

	int amountOfCities = 0;
	fscanf(file, "%d", &amountOfCities);

	int amountOfRoads = 0;
	fscanf(file, "%d", &amountOfRoads);

	int** matrix = (int**)malloc(amountOfCities * sizeof(int*));

	if (matrix == NULL)
	{
		return;
	}

	for (int i = 0; i < amountOfCities; ++i)
	{
		matrix[i] = (int*)malloc(amountOfCities * sizeof(int));

		if (matrix[i] == NULL)
		{
			return;
		}
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

	if (countries == NULL)
	{
		return;
	}

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

	for (int i = 0; i < amountOfCapitals && getListSize(unVisitedCitites) > 0; ++i)
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