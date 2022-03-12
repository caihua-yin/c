#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int i, j, k;
    // First allocate 10 group of results, we can realloc later if it exceeds
    int **result = malloc(10 * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = malloc(10 * sizeof(int));
    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            for (k = j + 1; k < numsSize; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    *returnColumnSizes[*returnSize] = 3;
                    result[*returnSize] = malloc(3 * sizeof(int));
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[k];
                    (*returnSize)++;
                    // TODO: realloc
                }
            }
        }
    }
    return result;
}

void print2dArray(int** array, int size, int *columnSize)
{
    int i, j;
    printf("[");
    for (i = 0; i < size; i++)
    {
        printf("[");
        for (j = 0; j < columnSize[i]; j++)
        {
            printf("%d", array[i][j]);
            if (j + 1 < columnSize[i])
                printf(",");
        }
        printf("]");

        if (i + 1 < size)
            printf(",");
    }
    printf("]\n");
}

int main()
{
    int nums[] = {-1,0,1,2,-1,-4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int **result;
    int returnSize;
    int *returnColumnSizes;
    result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    print2dArray(result, returnSize, returnColumnSizes);

    return 0;
}
