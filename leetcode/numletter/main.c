#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int number2letter(char* numstr, char** result)
{
    int num;
    unsigned int i, j, k, nletter, inputsize = 0, outputsize = 0;
    char **input, **output;
    char numletters[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if (strlen(numstr) >= 1)
    {
        num = numstr[0] - '0';
        if (num < 2 || num > 9)
        {
            printf("Invalid input!\n");
            return 0;
        }
        inputsize = nletter = strlen(numletters[num - 2]);
        input = malloc(inputsize * sizeof(char*));
        for (i = 0; i < nletter; i++)
        {
            // We only need store one char plus \0
            input[i] = malloc(2);
            input[i][0] = numletters[num - 2][i];
            input[i][1] = '\0';
        }
    }
    else
        return 0;
    
    for (i = 1; i < strlen(numstr); i++)
    {
        num = numstr[i] - '0';
        if (num < 2 || num > 9)
        {
            printf("Invalid input!\n");
            break;
        }
        
        nletter = strlen(numletters[num - 2]);
        outputsize = inputsize * nletter;
        output = malloc(outputsize * sizeof(char*));

        for (j = 0; j < inputsize; j++)
        {
            for (k = 0; k < nletter; k++)
            {
                output[j * nletter + k] = malloc(strlen(input[j]) + 2);
                strcpy(output[j * nletter + k], input[j]);
                output[j * nletter + k][strlen(input[j])] = numletters[num - 2][k];
                output[j * nletter + k][strlen(input[j]) + 1] = '\0';
            }
        }

        if (input)
        {
            for (i = 0; i < inputsize; i++)
                free(input[i]);
            free(input);
        }
        
        input = output;
        inputsize = outputsize;
        output = NULL;
        outputsize = 0;
    }
    
    result = input;
    return inputsize;
}

int main()
{
    char input[] = "23";
    int i;
    char** result = NULL;
    int size = number2letter(input, result);
    for (i = 0; i < size; i++)
    {
         printf("%s ", result[i]);
    }
    printf("\n");
    return 0;
}
