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

char **letterCombinationsRecur(char *digits, int* returnSize)
{
    int num, nletter, i, j;
    char *digitsLeft, *digitsRight;
    char **result, **resultLeft, **resultRight;
    int sizeLeft, sizeRight;
    char numletters[8][5] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    // Handle invalid case
    if (strlen(digits) < 1)
    {
        *returnSize = 0;
        return NULL;
    }
    else if (strlen(digits) == 1)
    {
        num = digits[0] - '0';
        if (num < 2 || num > 9)
        {
            printf("Invalid input!");
            *returnSize = 0;
            return NULL;
        }
        *returnSize = nletter = strlen(numletters[num - 2]);
        result = malloc(nletter * sizeof(char*));
        for (i = 0; i < nletter; i++)
        {
            result[i] = malloc(2 * sizeof(char));
            result[i][0] = numletters[num - 2][i];
            result[i][1] = '\0';
        }
        return result;
    }
    else // strlen(digits) > 1
    {
        // Split digits as digits[0] and digits[1...]
        digitsLeft = malloc(2 * sizeof(char));
        digitsLeft[0] = digits[0];
        digitsLeft[1] = '\0';
        digitsRight = malloc(strlen(digits) * sizeof(char));
        strcpy(digitsRight, digits+1);
        // Get the result for digitsLeft and digitsRight
        resultLeft = letterCombinationsRecur(digitsLeft, &sizeLeft);
        resultRight = letterCombinationsRecur(digitsRight, &sizeRight);
        // Combine and return the result of digitsLeft and digitsRight, then return
        *returnSize = sizeLeft * sizeRight;
        result =  malloc(*returnSize * sizeof(char*));
        for (i = 0; i < sizeLeft; i++)
        {
            for (j = 0; j < sizeRight; j++)
            {
                result[i * sizeRight + j] = malloc(strlen(resultLeft[i]) + strlen(resultRight[j]) + 1);
                strcpy(result[i * sizeRight + j], resultLeft[i]);
                strcat(result[i * sizeRight + j], resultRight[j]);
            }
            free(resultLeft[i]);
        }
		for (j = 0; j < sizeRight; j++)
			free(resultRight[j]);
		free(resultLeft);
		free(resultRight);
        free(digitsLeft);
        free(digitsRight);
        return result;
    }
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

    result = letterCombinationsRecur("23", &size);
    printfStrArr(result, size);
    freeStrArr(result, size);

    size = number2letter("3", &result);
    printfStrArr(result, size);
    freeStrArr(result, size);

    size = number2letter("2345", &result);
    printfStrArr(result, size);
    freeStrArr(result, size);
    
	result = letterCombinationsRecur("2345", &size);
    printfStrArr(result, size);
    freeStrArr(result, size);
    return 0;
}
