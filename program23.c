#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void sortCities(char *cities[], int n)
{
    char *temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(cities[i], cities[j]) > 0)
            {
                temp = cities[i];
                cities[i] = cities[j];
                cities[j] = temp;
            }
        }
    }
}


void freeMemory(char *cities[], int n)
{
    for (int i = 0; i < n; i++)
    {
        free(cities[i]);
    }
}

int main()
{
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    getchar(); 

    char *cities[n];
    char temp[100];

    for (int i = 0; i < n; i++)
    {
        printf("Enter city %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);

        temp[strcspn(temp, "\n")] = '\0'; 

        cities[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
        strcpy(cities[i], temp);
    }

    sortCities(cities, n);

    printf("\nCities in alphabetical order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", cities[i]);
    }

    freeMemory(cities, n);

    return 0;
}