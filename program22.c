#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define WORD_LEN 50

int main()
{
    char paragraph[500];
    char words[MAX][WORD_LEN];
    int freq[MAX] = {0};
    int uniqueCount = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Convert to lowercase and remove punctuation
    for (int i = 0; paragraph[i] != '\0'; i++)
    {
        if (ispunct(paragraph[i]))
            paragraph[i] = ' ';
        else
            paragraph[i] = tolower(paragraph[i]);
    }

    char temp[WORD_LEN];
    int k = 0;

    for (int i = 0; i <= strlen(paragraph); i++)
    {
        if (paragraph[i] != ' ' && paragraph[i] != '\0' && paragraph[i] != '\n')
        {
            temp[k++] = paragraph[i];
        }
        else
        {
            if (k != 0)
            {
                temp[k] = '\0';
                int found = 0;

                for (int j = 0; j < uniqueCount; j++)
                {
                    if (strcmp(words[j], temp) == 0)
                    {
                        freq[j]++;
                        found = 1;
                        break;
                    }
                }

                if (!found && uniqueCount < MAX)
                {
                    strcpy(words[uniqueCount], temp);
                    freq[uniqueCount] = 1;
                    uniqueCount++;
                }

                k = 0;
            }
        }
    }

    printf("\nWord Frequencies:\n");
    for (int i = 0; i < uniqueCount; i++)
    {
        printf("%s : %d\n", words[i], freq[i]);
    }

    return 0;
}