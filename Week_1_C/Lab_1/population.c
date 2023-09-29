#include <cs50.h>
#include <stdio.h>

int getStartSize(void);
int getFinalSize(int startSize);
int yearsToGetToPopulation(int startSize, int finalSize);

int main(void)
{

    // Prompt for start size
    int startSize = getStartSize();

    // Prompt for end size
    int finalSize = getFinalSize(startSize);

    // Calculate number of years until we reach threshold
    // Print number of years
    printf("Years: %i\n", yearsToGetToPopulation(startSize, finalSize));
}

int getStartSize(void)
{
    int startSize;
    do
    {
        startSize = get_int("Initial population: ");
    }
    while (startSize < 9);
    return startSize;
}

int getFinalSize(int startSize)
{
    int finalSize;
    do
    {
        finalSize = get_int("Final population: ");
    }
    while (finalSize < startSize);
    return finalSize;
}

int yearsToGetToPopulation(int startSize, int finalSize)
{
    int response = 0;
    int population = startSize;
    for (int i = 1; population < finalSize; i++)
    {
        response = i;
        population = population + (population / 3) - (population / 4);
    }
    return response;
}
