#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printfStrArr(char **input, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
         printf("%s ", input[i]);
    }
    printf("\n");
}

void freeStrArr(char **input, unsigned int size)
{
    unsigned int i;
    if(input)
    {
        for (i = 0; i < size; i++)
        {
            if(input[i])
                free(input[i]);
        }
        free(input);
    }
}

int number2letter(char *numstr, char ***result)
{
    int num;
    unsigned int i, j, k, nletter, inputsize = 0, outputsize = 0;
    char **input, **output;
    char numletters[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if (numstr && strlen(numstr) >= 1)
    {
        num = numstr[0] - '0';
        if (num < 2 || num > 9)
        {
            printf("Invalid input!\n");
            **result = NULL;
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
    {
        **result = NULL;
        return 0;
    }
    
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

        freeStrArr(input, inputsize);

        input = output;
        inputsize = outputsize;
        output = NULL;
        outputsize = 0;
    }
    
    *result = input;
    return inputsize;
}

char **letterCombinations(char *digits, int* returnSize)
{
    int num;
    unsigned int i, j, k, nletter, inputsize = 0, outputsize = 0;
    char **input, **output;
    char numletters[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if (digits && strlen(digits) >= 1)
    {
        num = digits[0] - '0';
        if (num < 2 || num > 9)
        {
            printf("Invalid input!\n");
            *returnSize = 0;
            return NULL;
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
    {
        *returnSize = 0;
        return NULL;
    }
    
    for (i = 1; i < strlen(digits); i++)
    {
        num = digits[i] - '0';
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

        freeStrArr(input, inputsize);

        input = output;
        inputsize = outputsize;
        output = NULL;
        outputsize = 0;
    }
    
    *returnSize = inputsize;
    return input;
}

int main()
{
    char** result = NULL;
    int size = number2letter("23", &result);
    printfStrArr(result, size);
    freeStrArr(result, size);

    result = letterCombinations(NULL, &size);
    printfStrArr(result, size);
    freeStrArr(result, size);

    size = number2letter("3", &result);
    printfStrArr(result, size);
    freeStrArr(result, size);

    size = number2letter("2345", &result);
    printfStrArr(result, size);
    freeStrArr(result, size);
    return 0;
}
